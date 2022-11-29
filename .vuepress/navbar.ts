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
      'misc/',
      'software/',
      'creativity/',
      'troubleshooting/',
      'japanese/',
    ]
  }
]
