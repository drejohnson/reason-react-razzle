open Utils;

module AllEpisodesQuery = [%graphql
  {|
  query allEpisodes {
    allEpisodes {
      id
      title
    }
  }
|}
];

module Query = Client.Instance.Query;

let component = ReasonReact.statelessComponent("QueryEpisodes");

let make = (_children) => {
  ...component,
  render: (_self) => {
    let allEpisodesQuery = AllEpisodesQuery.make();
    <Query query=allEpisodesQuery>
      ...(
           (response, parse) =>
             switch response {
             | Loading => <Loading />
             | Failed(error) => <div> (error |> text) </div>
             | Loaded(result) =>
               let episodes = parse(result)##allEpisodes |> Array.to_list;
               <div>
                 (
                   episodes
                   |> List.map(
                        (episode) => <div key=episode##id> (Utils.text(episode##title)) </div>
                      )
                   |> Utils.list
                 )
               </div>
             }
         )
    </Query>
  }
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));