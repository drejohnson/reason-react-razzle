import React from 'react'
import { Capture } from 'react-loadable'
import { getBundles } from 'react-loadable/webpack'
import express from 'express'
import { renderToString } from 'react-dom/server'
import { StaticRouter } from 'react-router'
import { renderRoutes } from 'react-router-config'
import { ApolloProvider, getDataFromTree } from 'react-apollo'
import Helmet from 'react-helmet'
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
    const context = {}
    const modules = []
    const markup = renderToString(
      <ApolloProvider client={client}>
        <StaticRouter location={req.url} context={context}>
          <Capture report={moduleName => modules.push(moduleName)}>
            {renderRoutes(routes)}
          </Capture>
        </StaticRouter>
      </ApolloProvider>
    )

    getDataFromTree(markup).then(() => {
      const bundles = getBundles(stats, modules)
      const chunks = bundles.filter(bundle => bundle.file.endsWith('.js'))
      const helmet = Helmet.renderStatic()
      const headHtmlAttributes = helmet.htmlAttributes.toString()
      const headTitle = helmet.title.toString()
      const headMeta = helmet.meta.toString()
      const headLink = helmet.link.toString()
      const headScript = helmet.script.toString()
      console.log(`initialState: ${JSON.stringify(client.cache.extract())}`)
      res.status(200).send(
        `<!doctype html>
        <html lang="">
          <head>
            ${headTitle}
            ${headMeta}
            ${headLink}
            ${headScript}
            ${assets.client.css ? `<link rel="stylesheet" href="${assets.client.css}">` : ''}
          </head>
          <body>
            <div id="root">${markup}</div>
            ${process.env.NODE_ENV === 'production' ? `<script src="${assets.client.js}"></script>` : `<script src="${assets.client.js}" crossorigin></script>`}
            ${chunks
          .map(
            chunk =>
              (process.env.NODE_ENV === 'production'
                ? `<script src="/${chunk.file}"></script>`
                : `<script src="http://${process.env.HOST}:${process.env.PORT + 1}/${chunk.file}"></script>`)
          )
          .join('\n')}
            <script>window.__APOLLO_STATE__=${JSON.stringify(client.cache.extract()).replace(/</g, '\\u003c')}</script>
            <script>window.main();</script>
          </body>
        </html>`
      )
    })
  })

export default server
