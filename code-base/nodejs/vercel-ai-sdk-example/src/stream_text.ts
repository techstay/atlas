import { streamText } from 'ai'
import { gemini_model } from './model'

const result = streamText({
  model: gemini_model,
  system: ' You are a helpful assistant.',
  prompt: 'Tell me ten famous cities in the world.',

})

for await (const textPart of result.textStream) {
  console.log(textPart)
}
