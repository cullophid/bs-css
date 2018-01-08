let empty: Glamor.css;

type types = [ | `length | `fill | `auto | `color | `url];

type value('a) = 'a constraint [< types] = 'a;

type size('a) = value(([< | `length | `fill | `auto] as 'a));

let px: int => value([ | `length]);

let pct: float => value([ | `length]);

let fill: value([ | `fill]);

let auto: value([ | `auto]);

let zero: value([ | `length]);

let column:
  (~padding: value([ | `length])=?, ~spacing: value([< | `length | `auto]), Glamor.css) => string;

let row:
  (~padding: value([ | `length])=?, ~spacing: value([< | `length | `auto]), Glamor.css) => string;