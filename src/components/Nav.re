let component = ReasonReact.statelessComponent("Nav");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <nav>
      <ReactRouter.NavLink _to="/"> ("Home" |> Utils.text) </ReactRouter.NavLink>
      <ReactRouter.NavLink _to="/about"> ("About" |> Utils.text) </ReactRouter.NavLink>
    </nav>
};