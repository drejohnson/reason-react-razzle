import React from 'react'
import { hydrate } from 'react-dom'
import { ApolloProvider } from 'react-apollo'
import { HelmetProvider } from 'react-helmet-async'
import Loadable from 'react-loadable'
import App from './components/App.bs'

import { initApolloClient } from './modules/Client.bs'

const client = initApolloClient
Loadable.preloadReady().then(() => {
  hydrate(
    <HelmetProvider>
      <ApolloProvider client={client}>
        <App />
      </ApolloProvider>
    </HelmetProvider>,
    document.getElementById('root')
  )
})

if (module.hot) {
  module.hot.accept()
}
