open Utils;

let component = ReasonReact.statelessComponent("Layout");

let make = (children) => {
  ...component,
  render: (_self) =>
    <Fragment>
      <ReactHelmet>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <meta name="theme-color" content="#000000" />
        <link rel="manifest" href="/manifest.json" />
        <link rel="shortcut icon" href="/favicon.ico" />
        <title> ("ReasonReact Starter" |> text) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <Header />
      (children())
    </Fragment>
};