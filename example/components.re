open Layout;

let text = ReasonReact.stringToElement;

module Card = {
  let cardStyles =
    Css.(
      style([backgroundColor(white), boxShadow(shadow(~x=2, ~y=4, ~blur=10, rgba(0, 0, 0, 0.5)))])
    );
  let component = ReasonReact.statelessComponent("Card");
  let make = (~style=Css.empty, ~width=?, children) => {
    ...component,
    render: (_) => {
      let styles =
        Css.merge([
          cardStyles,
          switch width {
          | None => Css.empty
          | Some(w) => Css.(style([width(w)]))
          },
          style
        ]);
      ReasonReact.element @@ Column.make(~style=styles, children)
    }
  };
};

open Layout;

module CardButton = {
  let buttonStyles =
    Css.(
      style([
        borderRadius(px(0)),
        height(px(60)),
        width(pct(100.0)),
        backgroundColor(hex("77B144")),
        borderStyle(None),
        color(white),
        fontFamily("Helvetica"),
        fontSize(px(14)),
        fontWeight(W300)
      ])
    );
  let component = ReasonReact.statelessComponent("CardButton");
  let make = (~style=Css.empty, ~value, _) => {
    ...component,
    render: (_) => {
      let styles = Css.merge([buttonStyles, style]);
      <button className=styles> (text(value)) </button>
    }
  };
};

module TextInput = {
  let inputStyles =
    Css.(
      style([
        height(px(22)),
        borderStyle(None),
        fontSize(px(18)),
        fontWeight(W300),
        color(hex("4A4A4A")),
        borderBottom(px(1), Solid, hex("e7e7e7"))
      ])
    );
  let component = ReasonReact.statelessComponent("TextInput");
  let make = (~style=Css.empty, ~value, _) => {
    ...component,
    render: (_) => {
      let styles = Css.merge([inputStyles, style]);
      <input _type="text" className=styles defaultValue=value />
    }
  };
};

module Label = {
  let labelStyles = Css.(style([fontFamily("Helvetica"), fontSize(px(11)), color(hex("77B144"))]));
  let component = ReasonReact.statelessComponent("TextInput");
  let make = (~style=Css.empty, ~text as text_, _) => {
    ...component,
    render: (_) => {
      let styles = Css.merge([labelStyles, style]);
      <label className=styles> (text(text_)) </label>
    }
  };
};