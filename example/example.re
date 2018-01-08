open Layout;

let box =
  Glamor.(
    ruleset([rule("background", "darkgray"), rule("width", "50px"), rule("height", "50px")])
  );

let header = Glamor.(ruleset([rule("background", "black")]));

let view = () =>
  <div className=(row(~padding=px(10), ~spacing=auto, header))>
    <div className=box />
    <div className=box />
    <div className=box />
  </div>;

ReactDOMRe.renderToElementWithId(view(), "app");