let component = ReasonReact.statelessComponent("NotFound");

let make = (_children) => {
  ...component,
  render: (_self) => <Layout> ...(() => <Hello message="Page not found" />) </Layout>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));