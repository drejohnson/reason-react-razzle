let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: (_self) => <Layout> ...(() => <Hello message="Hello from about component" />) </Layout>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));