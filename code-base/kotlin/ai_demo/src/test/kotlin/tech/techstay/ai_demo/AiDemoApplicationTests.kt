package tech.techstay.ai_demo

import org.junit.jupiter.api.Test
import org.slf4j.Logger
import org.slf4j.LoggerFactory
import org.springframework.ai.chat.client.ChatClient
import org.springframework.ai.chat.prompt.PromptTemplate
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.boot.test.context.SpringBootTest

@SpringBootTest
class AiDemoApplicationTests(@Autowired val builder: ChatClient.Builder) {
    val chatClient = builder.build()
    val logger: Logger = LoggerFactory.getLogger(AiDemoApplicationTests::class.java)

    @Test
    fun testChat() {
        val response = chatClient.prompt().user("Hello world!").call().content()
        logger.info(response)
    }

    @Test
    fun testPrompt() {
        val promptTemplate = PromptTemplate("My name is {name}, greet me.")
        val prompt = promptTemplate.create(mapOf("name" to "John"))
        val response = chatClient.prompt(prompt).call().content()
        logger.info(response)
    }

    @Test
    fun testToolCalling() {
        val response = chatClient.prompt("What day is tomorrow?").tools(DateTools()).call().content()
        logger.info(response)
    }
}
