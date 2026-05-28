package tech.techstay;

import java.io.IOException;
import java.time.LocalDate;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.JsonMappingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.fasterxml.jackson.dataformat.xml.XmlMapper;

public class JacksonTest {
  private static XmlMapper xmlMapper;
  private static ObjectMapper jsonMapper;
  static Logger logger;

  @BeforeAll
  static void setUp() {
    logger = LogManager.getLogger();

    xmlMapper = new XmlMapper();
    xmlMapper.enable(SerializationFeature.INDENT_OUTPUT);
    xmlMapper.disable(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS);
    xmlMapper.findAndRegisterModules();

    jsonMapper = new ObjectMapper();
    jsonMapper.findAndRegisterModules();
    // jsonMapper.enable(SerializationFeature.WRAP_ROOT_VALUE);
    jsonMapper.enable(SerializationFeature.INDENT_OUTPUT);
    jsonMapper.disable(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES);
  }

  @Test
  void testJson() throws IOException {
    Friend f1 = new Friend("techstay", 25);
    String text = jsonMapper.writeValueAsString(f1);
    logger.info(f1);
    logger.info(text);

    Friend f2 = jsonMapper.readValue(text, Friend.class);
    logger.info(f2);
    Assertions.assertThat(f1).isEqualTo(f2);

  }

  @Test
  void testIgnore() throws JsonProcessingException {
    FriendDetail fd = new FriendDetail("techstay", 18, "foo", "bar");
    String text = jsonMapper.writeValueAsString(fd);
    logger.info(text);

    FriendDetail fd2 = jsonMapper.readValue(text, FriendDetail.class);
    Assertions.assertThat(fd2.foo()).isNull();
    Assertions.assertThat(text).contains("baz");
  }

  @Test
  void testJava8Date() throws JsonMappingException, JsonProcessingException {
    Person p = new Person("ada", "wang", 18, "agent", LocalDate.of(1993, 2, 6));
    String text = jsonMapper.writeValueAsString(p);
    logger.info(text);

    Person p2 = jsonMapper.readValue(text, Person.class);
    logger.info(p2);
    Assertions.assertThat(p2.birthday()).isEqualTo(p.birthday());
  }

  @Test
  void testXmlMapper() throws JsonProcessingException {
    Person p = new Person("ada", "wang", 18, "agent", LocalDate.of(1993, 2, 6));
    String text = xmlMapper.writeValueAsString(p);
    logger.info(text);

    Person p2 = xmlMapper.readValue(text, Person.class);
    Assertions.assertThat(p2).isEqualTo(p);
    logger.info(p2);
  }
}
