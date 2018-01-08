open Layout;

let box =
  column(~width=px(40), ~height=px(40), Glamor.(ruleset([rule("background", "darkgray")])));

let header =
  Glamor.(
    ruleset([rule("background", "white"), rule("boxShadow", " 1px 0  5px rgba(0, 0, 0, 0.5)")])
  );

let sidebar = Glamor.(ruleset([rule("background", "#333")]));

let view = () =>
  <div className=(column(~width=fill, ~height=fill, empty))>
    <div className=(row(~padding=px(10), ~spacing=auto, ~width=fill, ~height=px(60), header))>
      <div
        className=(
          column(
            ~width=px(40),
            ~height=px(40),
            Glamor.(ruleset([rule("background", "palegoldenrod")]))
          )
        )
      />
      <div className=(row(~spacing=px(15), ~width=auto, empty))>
        <div className=box />
        <div className=box />
        <div className=box />
      </div>
    </div>
    <div className=(row(~height=fill, empty))>
      <aside className=(column(~width=px(250), ~height=fill, sidebar)) />
      <main className=(column(~height=fill, empty)) />
    </div>
  </div>;

ReactDOMRe.renderToElementWithId(view(), "app");