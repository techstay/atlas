import { defaultTheme, defineUserConfig } from 'vuepress'
import { sidebar } from './sidebar'
import { navbar } from './navbar'
import { plugins } from './plugins'

export default defineUserConfig({
  lang: 'zh-CN',
  title: '落了一地碎碎念的学习笔记',
  description: '我的代码和笔记仓库',
  theme: defaultTheme({
    navbar: navbar,
    sidebar: sidebar,
    repo: 'techstay/studyNotes',
  }),
  plugins: plugins,
})
