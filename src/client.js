import React from 'react'
import { hydrate } from 'react-dom'
import { BrowserRouter } from 'react-router-dom'
import { ApolloProvider } from 'react-apollo'
import { HelmetProvider } from 'react-helmet-async'
import { renderRoutes } from 'react-router-config'
import Loadable from 'react-loadable'
import routes from './routes'

import { initApolloClient } from './modules/Client.bs'

const client = initApolloClient
Loadable.preloadReady().then(() => {
  hydrate(
    <HelmetProvider>
      <ApolloProvider client={client}>
        <BrowserRouter>{renderRoutes(routes)}</BrowserRouter>
      </ApolloProvider>
    </HelmetProvider>,
    document.getElementById('root')
  )
})

if (module.hot) {
  module.hot.accept()
}
