module LoadableQueryEpisodes = {
  let reactClass =
    Loadable.load({
      "loader": [%bs.raw {|() => import("../components/QueryEpisodes.bs") |}],
      "loading": Loading.default
    });
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Layout>
      ...(
           () =>
             <Fragment> <Hello message="Hello from home component" /> <QueryEpisodes /> </Fragment>
         )
    </Layout>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));