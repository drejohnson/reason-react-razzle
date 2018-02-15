# ReasonReact + Razzle + Apollo + React Loadable

> A basic starting point for using server-side rendering with ReasonReact via [Razzle](https://github.com/jaredpalmer/razzle).

> Far from refined. Used as a basis to learn ReasonML and POC for server side rendering and code-splitting with ReasonReact

## Features

* [x] [ReasonReact](https://reasonml.github.io/reason-react/)
* [x] [Razzle](https://github.com/jaredpalmer/razzle) for easy server-side rendering
* [x] [Reason-Apollo](https://github.com/apollographql/reason-apollo)
* [x] [React Helmet Async](https://github.com/NYTimes/react-helmet-async) bindings

## Quick start

* Use install dependencies: `yarn`
* For dev mode without ssr run `yarn dev` or `npm run dev`, open browser, the app should be running at: http://localhost:3000.
* To build run: `yarn build` or `npm run build`
* To build and run use: `yarn build` or `npm run build` followed by `yarn start` or `npm start`.

## TODO

* [ ] Add "CSS-In-Reason" library. Either [bs-css](https://github.com/SentiaAnalytics/bs-css) or [bs-react-fela](https://github.com/astrada/bs-react-fela).
* [ ] Add [Workbox](https://developers.google.com/web/tools/workbox/)

## NOTE
 
> Server-side rendering with [Reason-Apollo](https://github.com/apollographql/reason-apollo) doesn't actually work. Queries don't execute on the server.  
