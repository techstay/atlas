import { PluginConfig } from '@vuepress/theme-default'
import { searchPlugin } from '@vuepress/plugin-search'
import { googleAnalyticsPlugin } from '@vuepress/plugin-google-analytics'

export const plugins: PluginConfig = [
  searchPlugin({
    isSearchable: (page) => page.path !== '/',
  }),
  googleAnalyticsPlugin({
    id: 'G-29BS5TXBVL',
  }),
]
