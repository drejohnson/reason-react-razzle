import React from 'react'
import { Capture } from 'react-loadable'
import { getBundles } from 'react-loadable/webpack'
import express from 'express'
import { renderToString, renderToNodeStream } from 'react-dom/server'
import { StaticRouter } from 'react-router'
import { renderRoutes } from 'react-router-config'
import { ApolloProvider, getDataFromTree } from 'react-apollo'
import Helmet, { HelmetProvider } from 'react-helmet-async'
import through from 'through'
import template from './template'
import routes from './routes'
import stats from '../build/react-loadable.json'

import { initApollo } from './modules/Client.bs'

const assets = require(process.env.RAZZLE_ASSETS_MANIFEST)

const server = express()
server
  .disable('x-powered-by')
  .use(express.static(process.env.RAZZLE_PUBLIC_DIR))
  .get('/*', (req, res) => {
    const client = initApollo()
    const helmetContext = {}
    const context = {}
    const modules = []
    const app = (
      <Capture report={moduleName => modules.push(moduleName)}>
        <HelmetProvider context={helmetContext}>
          <ApolloProvider client={client}>
            <StaticRouter location={req.url} context={context}>
              {renderRoutes(routes)}
            </StaticRouter>
          </ApolloProvider>
        </HelmetProvider>
      </Capture>
    )

    const initialState = client.cache.extract()
    const bundles = getBundles(stats, modules)
    const chunks = bundles.filter(bundle => bundle.file.endsWith('.js'))

    getDataFromTree(app)
    const [head, tail] = template({
      helmet: helmetContext.helmet,
      assets: assets,
      chunks: chunks,
      initialState: initialState
    })

    res.status(200)
    res.write(head)
    renderToNodeStream(app)
      .pipe(
        through(
          function write (data) {
            this.queue(data)
          },
          function end () {
            this.queue(tail)
            this.queue(null)
          }
        )
      )
      .pipe(res)
  })

export default server
