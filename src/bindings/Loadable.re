type loadable;

type loadOptions = {. "loader": unit => string, "loading": ReasonReact.reactClass};

[@bs.module] external loadable : loadable = "react-loadable";

[@bs.module] external load : loadOptions => ReasonReact.reactClass = "react-loadable";