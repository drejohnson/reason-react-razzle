open Utils;

let component = ReasonReact.statelessComponent("Layout");

let make = (children) => {
  ...component,
  render: (_self) => <Fragment> <Header /> (children()) </Fragment>
};