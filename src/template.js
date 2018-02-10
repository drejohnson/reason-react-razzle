const template = ({ helmet, assets, chunks, initialState }) => [
  `<!doctype html>
    <html ${helmet.htmlAttributes.toString()}>
      <head>
        ${helmet.title.toString()}
        ${helmet.meta.toString()}
        ${helmet.link.toString()}
        ${helmet.script.toString()}
        ${assets.client.css ? `<link rel="stylesheet" href="${assets.client.css}">` : ''}
      </head>
      <body>
        <div id="root">`,
  `</div>
      <script>window.__APOLLO_STATE__=${JSON.stringify(initialState).replace(/</g, '\\u003c')}</script>
      ${process.env.NODE_ENV === 'production' ? `<script src="${assets.manifest.js}"></script>` : `<script src="${assets.manifest.js}" crossorigin></script>`}
      ${process.env.NODE_ENV === 'production' ? `<script src="${assets.client.js}"></script>` : `<script src="${assets.client.js}" crossorigin></script>`}
      ${chunks
    .map(
      chunk =>
        (process.env.NODE_ENV === 'production'
          ? `<script src="/${chunk.file}"></script>`
          : `<script src="http://${process.env.HOST}:${process.env.PORT + 1}/${chunk.file}"></script>`)
    )
    .join('\n')}
      </body>
    </html>`
]

export default template
