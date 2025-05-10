import puppeteer from 'puppeteer'
import logger from '../logging/winston'

const url = 'https://www.python.org/'

async function main () {
  logger.info('starting puppeteer')
  const browser = await puppeteer.launch()
  const page = await browser.newPage()
  await page.setViewport({ width: 1920, height: 1080 })
  await page.goto(url)
  // await page.screenshot({ path: 'screenshot.png' })
  logger.info('loaded python home page')

  await page.locator('#about').click()
  const textSelector = 'h1.call-to-action'
  const text = await page.locator(textSelector).map(ele => ele.textContent?.trim()).wait()
  logger.info(text)

  await page.locator('#downloads').click()
  const buttonText = await page.locator('.download-buttons').map(ele => ele.textContent?.trim()).wait()
  logger.info(buttonText?.substring(9))

  const navTexts = await page.evaluate(() => {
    const navs = document.querySelectorAll('#mainnav > ul > li > a')
    return Array.from(navs).map(ele => ele.textContent?.trim())
  })
  logger.info(navTexts)

  const pythonVersionsTable = await page.locator('.list-row-container').waitHandle()
  const pythonVersions = await pythonVersionsTable.$$eval('span.release-version', (nodes) =>
    nodes.map(node => node.textContent?.trim()),
  )
  logger.info(pythonVersions)

  await browser.close()
}

await main()
