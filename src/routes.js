import React from 'react'
import Loadable from 'react-loadable'
import Loading from './components/Loading.bs'
import Home from './pages/Home.bs'

const About = Loadable({
  loader: () => import('./pages/About.bs'),
  loading: () => <Loading />
})

const NotFound = Loadable({
  loader: () => import('./pages/NotFound.bs'),
  loading: () => <Loading />
})

export default [
  {
    path: '/',
    exact: true,
    component: Home
  },
  {
    path: '/about',
    exact: true,
    component: About
  },
  {
    path: '*',
    exact: true,
    component: NotFound
  }
]
