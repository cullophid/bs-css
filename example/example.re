open Components;

open Layout;

let text = ReasonReact.stringToElement;

module React = ReasonReact;

Css.(
  global(
    "body, #app",
    [
      padding(px(0)),
      margin(px(0)),
      display(Flex),
      alignItems(Stretch),
      flexDirection(Column),
      height(vh(100.0))
    ]
  )
);

let stylesheet =
  Css.(
    {
      "wrapper": style([backgroundImage("./img-29.jpg")]),
      "title":
        style([
          margin(px(0)),
          fontFamily("Helvetica"),
          fontSize(px(24)),
          color(hex("4A4A4A")),
          fontWeight(W300)
        ]),
      "forgotPassword":
        style([fontFamily("Helvetica"), fontSize(px(14)), color(hex("4A4A4A")), fontWeight(W300)])
    }
  );

module Page = {
  let component = ReasonReact.statelessComponent("Page");
  let make = (_) => {
    ...component,
    render: (_) =>
      <Column align=Css.Center justify=Css.Center height=(pct(100.0)) style=stylesheet##wrapper>
        <Card width=(px(320))>
          <Column padding=(px(25)) spacing=(px(25))>
            <View alignSelf=Center>
              <h1 className=stylesheet##title> (ReasonReact.stringToElement("Welcome")) </h1>
            </View>
            <Column> <Label text="Email" /> <TextInput value="email" /> </Column>
            <Column> <Label text="Password" /> <TextInput value="Password" /> </Column>
            <View alignSelf=Center>
              <a href="#" className=stylesheet##forgotPassword> (text("Forgot Password?")) </a>
            </View>
          </Column>
          <CardButton value="LOGIN" />
        </Card>
      </Column>
  };
};

ReactDOMRe.renderToElementWithId(<Page />, "app");