[%bs.raw "require('isomorphic-unfetch')"];

open ApolloLinks;

open ApolloInMemoryCache;

let httpLink = createHttpLink(~uri="https://api.graph.cool/simple/v1/PHRESHR", ());

let inMemoryCache = createInMemoryCache();

let initApolloClient =
  ReasonApollo.createApolloClient(
    ~ssrMode=Js.Boolean.to_js_boolean(Utils.isNode),
    ~link=httpLink,
    ~cache=Utils.isNode ? inMemoryCache : inMemoryCache |> restore(Utils.apollo_state),
    ()
  );

module Instance =
  ReasonApollo.CreateClient(
    {
      let apolloClient = initApolloClient;
    }
  );