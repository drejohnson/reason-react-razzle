open Utils;

let component = ReasonReact.statelessComponent("Loading");

let make = (_children) => {...component, render: (_self) => <div> ("...Loading" |> text) </div>};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));