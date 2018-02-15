open Utils;

let component = ReasonReact.statelessComponent("Nav");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <nav>
      <Link href="/" label="Home" />
      <Link href="/about" label="About" />
    </nav>
};