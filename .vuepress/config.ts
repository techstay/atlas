import { defineUserConfig } from "vuepress";
import theme from "./theme.js";

import { searchPlugin } from "@vuepress/plugin-search";
import { googleAnalyticsPlugin } from '@vuepress/plugin-google-analytics'

export default defineUserConfig({
  base: "/",

  locales: {
    "/": {
      lang: "zh-CN",
      title: "易艾福G的学习笔记",
      description: "我的代码和笔记仓库",
    },
  },

  theme,

  shouldPrefetch: false,
  plugins: [
    searchPlugin({
      locales: {
        '/': {
          placeholder: '搜索',
        },
      },
    }),
    googleAnalyticsPlugin({
      id: 'G-29BS5TXBVL',
    }),
  ],
});
