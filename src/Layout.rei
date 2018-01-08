let empty: Glamor.css;

let px: int => [> | `px(int)];

let pct: float => [> | `pct(float)];

let fill: [> | `fill];

let auto: [> | `auto];

let zero: [> | `px(int)];

let left: [> | `left];

let right: [> | `right];

let top: [> | `top];

let bottom: [> | `bottom];

let center: [> | `center];

let row:
  (
    ~padding: [ | `px(int) | `pct(float)]=?,
    ~spacing: [ | `px(int) | `auto]=?,
    ~width: [ | `px(int) | `pct(float) | `auto | `fill]=?,
    ~height: [ | `px(int) | `pct(float) | `auto | `fill]=?,
    ~align: ([ | `top | `center | `bottom], [ | `left | `center | `right])=?,
    Glamor.css
  ) =>
  string;

let column:
  (
    ~padding: [ | `px(int) | `pct(float)]=?,
    ~spacing: [ | `px(int) | `auto]=?,
    ~width: [ | `px(int) | `pct(float) | `auto | `fill]=?,
    ~height: [ | `px(int) | `pct(float) | `auto | `fill]=?,
    ~align: ([ | `top | `center | `bottom], [ | `left | `center | `right])=?,
    Glamor.css
  ) =>
  string;