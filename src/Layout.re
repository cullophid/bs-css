module Column = {
  let columStyle =
    Css.(
      style([
        position(Relative),
        boxSizing(BorderBox),
        display(Flex),
        flexDirection(Column),
        alignItems(Center)
      ])
    );
  let component = ReasonReact.statelessComponent("Column");
  let make =
      (
        ~style=Css.empty,
        ~align=Css.Stretch,
        ~flex as _flex=?,
        ~alignSelf as _alignSelf=?,
        ~justify: Css.justify=Css.FlexStart,
        ~width as _width=?,
        ~height as _height=?,
        ~spacing=Css.px(0),
        ~padding as _padding=Css.px(0),
        children
      ) => {
    ...component,
    render: (_) => {
      let customStyle =
        Css.(
          merge([
            style([
              padding(_padding),
              alignItems(align),
              justifyContent(justify),
              child([marginBottom(spacing), lastChild([marginBottom(px(0))])])
            ]),
            switch _flex {
            | None => Css.empty
            | Some(f) => style([flex(f)])
            },
            switch _alignSelf {
            | None => Css.empty
            | Some(a) => style([alignSelf(a)])
            },
            switch _width {
            | None => Css.empty
            | Some(w) => style([width(w)])
            },
            switch _height {
            | None => Css.empty
            | Some(h) => style([height(h)])
            }
          ])
        );
      let props = {"className": Css.merge([columStyle, customStyle, style])};
      ReasonReact.createDomElement("div", ~props, children)
    }
  };
};

module Row = {
  let columStyle =
    Css.(style([display(Flex), position(Relative), boxSizing(BorderBox), flexDirection(Row)]));
  let component = ReasonReact.statelessComponent("Row");
  let make =
      (
        ~style=Css.empty,
        ~align=Css.Stretch,
        ~flex as _flex=?,
        ~alignSelf as _alignSelf=?,
        ~justify: Css.justify=Css.FlexStart,
        ~spacing=Css.px(0),
        ~width as _width=?,
        ~height as _height=?,
        ~padding as _padding=Css.px(0),
        children
      ) => {
    ...component,
    render: (_) => {
      let customStyle =
        Css.(
          merge([
            style([
              padding(_padding),
              alignItems(align),
              justifyContent(justify),
              padding(_padding),
              child([marginRight(spacing), lastChild([marginRight(px(0))])])
            ]),
            switch _alignSelf {
            | None => Css.empty
            | Some(a) => style([alignSelf(a)])
            },
            switch _flex {
            | None => Css.empty
            | Some(f) => style([flex(f)])
            },
            switch _width {
            | None => Css.empty
            | Some(w) => style([width(w)])
            },
            switch _height {
            | None => Css.empty
            | Some(h) => style([height(h)])
            }
          ])
        );
      let props = {"className": Css.merge([columStyle, customStyle, style])};
      ReasonReact.createDomElement("div", ~props, children)
    }
  };
};

module View = {
  let viewStyle = Css.(style([position(Relative), boxSizing(BorderBox)]));
  let component = ReasonReact.statelessComponent("Row");
  let make =
      (
        ~style=Css.empty,
        ~alignSelf as _alignSelf=?,
        ~width as _width=?,
        ~height as _height=?,
        ~padding as _padding=Css.px(0),
        children
      ) => {
    ...component,
    render: (_) => {
      let customStyle =
        Css.(
          merge([
            style([padding(_padding), padding(_padding)]),
            switch _alignSelf {
            | None => Css.empty
            | Some(a) => style([alignSelf(a)])
            },
            switch _width {
            | None => Css.empty
            | Some(w) => style([width(w)])
            },
            switch _height {
            | None => Css.empty
            | Some(h) => style([height(h)])
            }
          ])
        );
      let props = {"className": Css.merge([viewStyle, customStyle, style])};
      ReasonReact.createDomElement("div", ~props, children)
    }
  };
};

let px = Css.px;

let rem = Css.rem;

let pct = Css.pct;

let vh = Css.vh;