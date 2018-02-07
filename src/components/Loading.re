let component = ReasonReact.statelessComponent("Loading");

let make = (_children) => {
  ...component,
  render: (_self) => <div> ("...Loading" |> Utils.text) </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));