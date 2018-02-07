let routes: ReactRouter.routes = [|
  {"path": "/", "exact": Js.Boolean.to_js_boolean(true), "component": () => <Home />},
  {"path": "/about", "exact": Js.Boolean.to_js_boolean(true), "component": () => <About />},
  {"path": "*", "exact": Js.Boolean.to_js_boolean(true), "component": () => <NotFound />}
|];