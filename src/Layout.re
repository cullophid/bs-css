open Glamor;

let empty = empty;

type types = [ | `length | `fill | `auto | `color | `url];

type value('a) = 'a constraint [< types] = 'a;

external makeValue : string => value(_) = "%identity";

external getValue : value(_) => string = "%identity";

type size('a) = value(([< | `length | `fill | `auto] as 'a));

let px = (i) => makeValue({j|$(i)px|j});

let zero = makeValue("0");



let pct = (i) => makeValue({j|$(i)%|j});

let fill = makeValue("fill");

let auto = makeValue("auto");

let row = (~padding:value([`length])=zero, ~spacing:value([< `length | `auto]), style) => {
  let css =
    mergeRuleset([
      ruleset([
        rule("display", "flex"),
        rule("flexDirection", "row"),
        rule("padding", getValue(padding)),
        switch (getValue(spacing)) {
        | "auto" => rule("justifyContent", "space-between")
        | s =>
          selector(
            "& > *",
            [rule("marginRight", s), selector("&:last-child", [rule("marginRight", "0")])]
          )
        }
      ]),
      style
    ]);
  {j|$(css) row-layout|j}
};

let column = (~padding:value([`length])=zero, ~spacing:value([< `length | `auto])=?, style) => {
  let spacing_ = switch spacing {
  | None => zero
  | Some(s) =?
  }
  let css =
    mergeRuleset([
      ruleset([
        rule("display", "flex"),
        rule("flexDirection", "column"),
        rule("padding", getValue(padding)),
        switch spacing {

        | "auto" => rule("justifyContent", "space-between")
        | s =>
          selector(
            "& > *",
            [
              rule("marginBottom", s),
              selector("&:last-child", [rule("marginBottom", "0")])
            ]
          )
        }
      ]),
      style
    ]);
  {j|$(css) row-layout|j}
};