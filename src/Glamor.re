type css = string;

type rule =
  | Property(string, string)
  | Selector(string, list(rule));

module Glamor = {
  [@bs.module "glamor"] external make : Js.Json.t => css = "css";
  [@bs.scope "css"] [@bs.module "glamor"] external makeGlobal : (string, Js.Json.t) => unit =
    "global";
  [@bs.scope "css"] [@bs.module "glamor"] external makeKeyFrames : Js.Dict.t(Js.Json.t) => string =
    "keyframes";
  let merge: list(string) => string = [%bs.raw
    {|
      function (styles) {
          const glamor = require('glamor');
          return glamor.css.apply(glamor, styles)
      }
  |}
  ];
};

let rec makeDict = (ruleset) => {
  let toJs = (rule) =>
    switch rule {
    | Property(name, value) => (name, Js.Json.string(value))
    | Selector(name, ruleset) => (name, makeDict(ruleset))
    };
  ruleset |> List.map(toJs) |> Js.Dict.fromList |> Js.Json.object_
};

let join = (sep, strings) => {
  let rec j = (acc) =>
    fun
    | [] => acc
    | [x] => acc ++ x
    | [x, y, ...strings] => j(acc ++ (x ++ sep), [y, ...strings]);
  j("", strings)
};

let ruleset = (rules) => makeDict(rules) |> Glamor.make;

let global = (selector, rules) => makeDict(rules) |> Glamor.makeGlobal(selector);

let keyframes = (keyframes) =>
  keyframes
  |> List.map(((k, ruleset)) => (k, makeDict(ruleset)))
  |> Js.Dict.fromList
  |> Glamor.makeKeyFrames;

let mergeRuleset = Glamor.merge;

let empty = ruleset([]);

let important = (v) =>
  switch v {
  | Property(name, value) => Property(name, value ++ " !important")
  | _ => v
  };

let rule = (name, value) => Property(name, value);

let selector = (selector, rules) => Selector(selector, rules);