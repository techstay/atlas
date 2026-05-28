package tech.techstay.ai_demo

import org.springframework.ai.tool.annotation.Tool
import java.time.LocalDate

class DateTools {
    @Tool(description = "Returns the current date")
    fun today(): String {
        return "Today is ${LocalDate.now()}"
    }
}
