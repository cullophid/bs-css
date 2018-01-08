open Glamor;

let empty = empty;
let toString = fun
| `px(x) => {j|$(x)px|j}
| `pct(x) => {j|$(x)% |j}
| `auto => "auto"
| `fill => "100%"
| `left => "left"
| `right => "right"
| `top => "top"
| `bottom => "bottom"
| `center => "center";

let px = (i) => `px(i);
let pct = (i) => `pct(i);

let zero = `px(0);
let fill = `fill;
let auto = `auto;
let left = `left;
let center = `center;
let right = `right;
let top = `top;
let bottom = `bottom;

let row = (~padding=zero, ~spacing=zero, ~width=auto, ~height=auto, ~align as (alignY, alignX)=(top, left), style) => {
  let css =
    mergeRuleset([
      ruleset([
        rule("boxSizing", "border-box"),
        rule("display", "flex"),
        rule("flexDirection", "row"),
        rule("padding", toString(padding)),
        rule("justifyContent", switch alignX {
        | `left => "flex-start"
        | `center => "center"
        | `right => "flex-end"
        }),
        rule("alignItems", switch alignY {
        | `top => "flex-start"
        | `center => "center"
        | `bottom => "flex-end"
        }),
        switch spacing {
        | `auto => rule("justifyContent", "space-between")
        | s =>
          selector(
            "& > *",
            [rule("marginRight", toString(s)), selector("&:last-child", [rule("marginRight", "0")])]
          )
        }
        
      ]),
      switch width {
        | `auto => ruleset([ rule("width", "auto") ])
        | `fill => ruleset([
          rule("width", "100%"),
          selector(".row-layout > &",  [ rule("flex", "1") ]),
          selector(".column-layout > &",  [ rule("alignSelf", "stretch") ]),
        ])
        | w => ruleset([ rule("width", toString(w)) ])
      },
      switch height {
        | `auto => ruleset([ rule("height", "auto") ])
        | `fill => ruleset([
          rule("height", "100%"),
          selector(".column-layout > &",  [ rule("flex", "1") ]),
          selector(".row-layout > &",  [ rule("alignSelf", "stretch") ]),
        ])
        | h => ruleset([ rule("height", toString(h)) ])
      },
      style
    ]);
  {j|$(css) row-layout|j}
};

let column = (~padding=zero, ~spacing=zero, ~width=auto, ~height=auto, ~align as (alignY, alignX)=(top, left), style) => {
  let css =
    mergeRuleset([
      ruleset([
        rule("boxSizing", "border-box"),
        rule("display", "flex"),
        rule("flexDirection", "column"),
        rule("padding", toString(padding)),
        rule("alignItems", switch alignX {
        | `left => "flex-start"
        | `center => "center"
        | `right => "flex-end"
        }),
        rule("justifyContent", switch alignY {
        | `top => "flex-start"
        | `center => "center"
        | `bottom => "flex-end"
        }),
        switch spacing {
        | `auto => rule("justifyContent", "space-between")
        | s =>
          selector(
            "& > *",
            [
              rule("marginBottom", toString(s)),
              selector("&:last-child", [rule("marginBottom", "0")])
            ]
          )
        },
        
      ]),
      switch width {
        | `auto => ruleset([ rule("width", "auto") ])
        | `fill => ruleset([
          rule("width", "100%"),
          selector(".row-layout > &",  [ rule("flex", "1") ]),
          selector(".column-layout > &",  [ rule("alignSelf", "stretch") ]),
        ])
        | w => ruleset([ rule("width", toString(w)) ])
      },
      switch height {
        | `auto => ruleset([ rule("height", "auto") ])
        | `fill => ruleset([
          rule("height", "100%"),
          selector(".column-layout > &",  [ rule("flex", "1") ]),
          selector(".row-layout > &",  [ rule("alignSelf", "stretch") ]),
        ])
        | h => ruleset([ rule("height", toString(h)) ])
      },
      style
    ]);
  {j|$(css) column-layout|j}
};