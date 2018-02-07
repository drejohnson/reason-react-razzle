[@bs.val] external window : Dom.window = "window";

[@bs.val] external requireAssetURI : string => string = "require";

[@bs.val] external processBrowser : bool = "process.browser";

[@bs.scope "window"] [@bs.val] external apollo_state : 'a = "__APOLLO_STATE__";

let optionBoolToJsBoolean = (opt) =>
  switch opt {
  | Some(true) => Js.true_
  | Some(false) => Js.false_
  | None => Js.false_
  };

let isBrowser = Js.typeof(window: Dom.window) !== "undefined";

let isNode = Js.typeof(window: Dom.window) === "undefined";

let text = ReasonReact.stringToElement;

let nullElement = ReasonReact.nullElement;

let list = (list) => list |> Array.of_list |> ReasonReact.arrayToElement;

let array = (array) => array |> ReasonReact.arrayToElement;