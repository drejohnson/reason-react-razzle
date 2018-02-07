[%bs.raw "require('isomorphic-unfetch')"];

open ApolloLinks;

open ApolloInMemoryCache;

external castApolloClient :
  Js.Nullable.t(ApolloClient.generatedApolloClient) => ApolloClient.generatedApolloClient =
  "%identity";

external castClient : ApolloClient.generatedApolloClient => unit = "%identity";

let httpLink = createHttpLink(~uri="https://api.graph.cool/simple/v1/PHRESHR", ());

let inMemoryCache = createInMemoryCache();

let createClient = (~initialState) =>
  ReasonApollo.createApolloClient(
    ~ssrMode=Js.Boolean.to_js_boolean(Utils.isNode),
    ~link=httpLink,
    ~cache=Utils.isNode ? inMemoryCache : inMemoryCache |> restore(initialState),
    ()
  );

let initApollo = () => {
  let apolloClient = ref(Js.Nullable.null);
  if (Utils.isNode) {
    apolloClient := createClient(~initialState=Js.Nullable.undefined) |> Js.Nullable.return
  };
  if (Utils.isBrowser) {
    apolloClient := createClient(~initialState=Utils.apollo_state) |> Js.Nullable.return
  };
  apolloClient^
};

module Instance =
  ReasonApollo.CreateClient(
    {
      let apolloClient = castApolloClient(initApollo());
    }
  );