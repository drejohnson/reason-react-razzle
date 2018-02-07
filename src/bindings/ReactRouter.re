module Link = {
  [@bs.module "react-router-dom"] external link : ReasonReact.reactClass = "Link";
  let make = (~_to, children) =>
    ReasonReact.wrapJsForReason(~reactClass=link, ~props={"to": _to}, children);
};

module NavLink = {
  [@bs.module "react-router-dom"] external navLink : ReasonReact.reactClass = "NavLink";
  let make =
      (~_to: string, ~activeClassName: option(string)=?, ~className: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=navLink,
      ~props={
        "activeClassName": Js.Nullable.from_opt(activeClassName),
        "className": Js.Nullable.from_opt(className),
        "to": _to
      },
      children
    );
};

type routes =
  array({. "path": string, "exact": Js.boolean, "component": unit => ReasonReact.reactElement});

[@bs.module "react-router-config"] external renderRoutes : routes => unit = "renderRoutes";