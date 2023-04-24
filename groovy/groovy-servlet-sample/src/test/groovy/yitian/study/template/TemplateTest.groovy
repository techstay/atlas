package yitian.study.template

import groovy.text.SimpleTemplateEngine
import org.junit.Test

import java.time.LocalDate


class TemplateTest {
    @Test
    void testSimpleTemplate() {
        def tempalteEngine = new SimpleTemplateEngine()
        def text = 'Hello ${name}, today is ${date}!'

        def bind = [name: 'yitian', date: LocalDate.now()]

        def template = tempalteEngine.createTemplate(text).make(bind)
        println(template)
    }

    @Test
    void testStreamingTemplate() {
        def tempalteEngine = new SimpleTemplateEngine()
        def text = '''
Dear <%=name%>
I'm glad to see you since last time.
blahblah...
              Yours 
              lady
              ${date}'''

        def bind = [name: 'yitian', date: LocalDate.now()]

        def template = tempalteEngine.createTemplate(text).make(bind)
        println(template)
    }

}
