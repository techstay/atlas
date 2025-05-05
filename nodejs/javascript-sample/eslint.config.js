import js from '@eslint/js'
import globals from 'globals'
import { defineConfig } from 'eslint/config'


export default defineConfig([
  { files: ['**/*.{js,mjs,cjs}'], plugins: { js }, extends: ['js/recommended'] },
  { files: ['**/*.{js,mjs,cjs}'], languageOptions: { globals: globals.browser } },
  {
    rules: {
      indent: ['error', 2],
      'linebreak-style': ['error', 'windows'],
      quotes: ['error', 'single'],
      semi: ['error', 'never'],
    }
  }
])
