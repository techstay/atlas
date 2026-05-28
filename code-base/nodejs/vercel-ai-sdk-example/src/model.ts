import { google } from '@ai-sdk/google'
import { createOpenAI } from '@ai-sdk/openai'
import 'dotenv/config'

export const gemini_model = google('models/gemini-2.0-flash-exp')

const openai_provider = createOpenAI({
  baseURL: 'https://ark.cn-beijing.volces.com/api/v3',
  apiKey: process.env.DOUBAO_API_KEY,
})

export const doubao = openai_provider('doubao-1.5-pro-32k-250115')





