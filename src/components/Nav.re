open Utils;

let component = ReasonReact.statelessComponent("Nav");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <nav>
      <ReactRouter.NavLink _to="/"> ("Home" |> text) </ReactRouter.NavLink>
      <ReactRouter.NavLink _to="/about"> ("About" |> text) </ReactRouter.NavLink>
    </nav>
};