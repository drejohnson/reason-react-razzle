let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {...component, render: (_self) => <header> <Nav /> </header>};