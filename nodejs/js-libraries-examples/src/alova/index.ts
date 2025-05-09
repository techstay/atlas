import { createAlova } from 'alova'
import adapterFetch from 'alova/fetch'

const alovaInstance = createAlova({
  baseURL: 'https://httpbin.org',
  requestAdapter: adapterFetch(),
  responded: response => response.json()
})


const response = await alovaInstance.Get('/get')

console.log(response)
