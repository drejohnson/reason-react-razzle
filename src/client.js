import React from 'react'
import { hydrate } from 'react-dom'
import { BrowserRouter } from 'react-router-dom'
import { ApolloProvider } from 'react-apollo'
import { renderRoutes } from 'react-router-config'
import Loadable from 'react-loadable'
import routes from './routes'

import { initApollo } from './modules/Client.bs'

window.main = () => {
  const client = initApollo()
  Loadable.preloadReady().then(() => {
    hydrate(
      <ApolloProvider client={client}>
        <BrowserRouter>{renderRoutes(routes)}</BrowserRouter>
      </ApolloProvider>,
      document.getElementById('root')
    )
  })
}

if (module.hot) {
  module.hot.accept()
}
