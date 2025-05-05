import { generateText } from 'ai'
import { doubao } from './model'


const { text } = await generateText({
  model: doubao,
  system: ' You are a helpful assistant speaking in Chinese.',
  prompt: 'Tell me ten famous cities in the world.',
  experimental_telemetry: {
    isEnabled: true,
  }
})

console.log(text)
