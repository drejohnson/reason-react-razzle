open Utils;

let component = ReasonReact.statelessComponent("App");

let make = (~initialUrl, _children) => {
  ...component,
  render: (_self) =>
    <Fragment>
      <ReactHelmet>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <meta name="theme-color" content="#000000" />
        <link rel="manifest" href="/manifest.json" />
        <link rel="shortcut icon" href="/favicon.ico" />
        <title> ("ReasonReact Razzle" |> text) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <Router initialUrl>
        ...(
             (url: ReasonReact.Router.url) =>
               switch url.path {
               | [] => <Home />
               | ["home"] => <Home />
               | ["about"] => <About />
               | _ => <NotFound />
               }
           )
      </Router>
    </Fragment>
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => make(~initialUrl=Js.undefinedToOption(jsProps##initialUrl), [||])
  );