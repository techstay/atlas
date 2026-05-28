import { google } from '@ai-sdk/google'
import { initLogger, wrapAISDKModel } from 'braintrust'


// eslint-disable-next-line @typescript-eslint/no-unused-vars
const logger = initLogger({
  projectName: 'test',
  apiKey: process.env.BRAINTRUST_API_KEY,
})

const model = wrapAISDKModel(google.chat('gemini-2.0-flash-exp'))

async function main () {
  // This will automatically log the request, response, and metrics to Braintrust
  const response = await model.doGenerate({
    inputFormat: 'messages',
    mode: {
      type: 'regular',
    },
    prompt: [
      {
        role: 'system',
        content: 'You are a helpful assistant.',
      },
      {
        role: 'user',
        content: [{ type: 'text', text: 'What is the capital of France? Speak in Chinese, no pinyin.' }],
      },
    ],
  })


  console.log(response.text)
}

main()
