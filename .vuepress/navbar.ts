import type { HopeThemeNavbarConfig } from "vuepress-theme-hope";

export const navbar: HopeThemeNavbarConfig = [
  {
    text: '笔记',
    prefix: '/notes/',
    icon: 'note',
    children: [
      'windows/',
      'linux/',
      'network/',
      'android/',
      'misc/',
      'software/',
      'creativity/',
      'troubleshooting/',
      'japanese/',
    ]
  },
  {
    text: '实用技术',
    link: '/tutorial/skill/'
  }
]
