import { defaultTheme, defineUserConfig } from 'vuepress'
import { sidebar } from './sidebar'
import { navbar } from './navbar'
import { plugins } from './plugins'

export default defineUserConfig({
  lang: 'zh-CN',
  title: '我的学习笔记仓库',
  description: '我的代码和笔记',
  theme: defaultTheme({
    navbar: navbar,
    sidebar: sidebar,
    repo: 'techstay/studyNotes',
  }),
  plugins: plugins,
})
