[%bs.raw "require('isomorphic-unfetch')"];

open ApolloLinks;

open ApolloInMemoryCache;

external castApolloClient :
  ref(Js.Nullable.t(ApolloClient.generatedApolloClient)) => ApolloClient.generatedApolloClient =
  "%identity";

type createApolloClient =
  ref(Js.Nullable.t(ApolloClient.generatedApolloClient)) => ApolloClient.generatedApolloClient;

type initApolloClient = ref(Js.Nullable.t(ApolloClient.generatedApolloClient));

let create: createApolloClient = (client: initApolloClient) => castApolloClient(client);

let httpLink = createHttpLink(~uri="https://api.graph.cool/simple/v1/PHRESHR", ());

let inMemoryCache = createInMemoryCache();

let apolloClient = ref(Js.Nullable.null);

let createClient = () =>
  ReasonApollo.createApolloClient(
    ~ssrMode=Js.Boolean.to_js_boolean(Utils.isNode),
    ~link=httpLink,
    ~cache=Utils.isNode ? inMemoryCache : inMemoryCache |> restore(Utils.apollo_state),
    ()
  );

createClient();

apolloClient :=
  Utils.isNode ?
    ReasonApollo.createApolloClient(
      ~ssrMode=Js.Boolean.to_js_boolean(true),
      ~link=httpLink,
      ~cache=inMemoryCache,
      ()
    )
    |> Js.Nullable.return :
    ReasonApollo.createApolloClient(
      ~link=httpLink,
      ~cache=inMemoryCache |> restore(Utils.apollo_state),
      ()
    )
    |> Js.Nullable.return;

let initApollo = create(apolloClient);

module Instance =
  ReasonApollo.CreateClient(
    {
      let apolloClient = createClient();
    }
  );