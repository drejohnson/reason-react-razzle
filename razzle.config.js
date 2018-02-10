const { ReactLoadablePlugin } = require('react-loadable/webpack')

module.exports = {
  modify: (config, { target, dev }, webpack) => {
    const appConfig = config // stay immutable here

    if (target === 'web') {
      return {
        ...config,
        output: {
          ...config.output,
          filename: dev
            ? 'static/js/[name].js'
            : 'static/js/[name].[hash:8].js'
        },
        plugins: [
          ...config.plugins,
          new ReactLoadablePlugin({
            filename: './build/react-loadable.json'
          }),
          new webpack.optimize.CommonsChunkPlugin({
            name: 'manifest',
            minChunks: Infinity
          })
        ]
      }
    }

    return config
  }
}
