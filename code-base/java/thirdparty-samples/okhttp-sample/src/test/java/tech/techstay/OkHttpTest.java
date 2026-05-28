package tech.techstay;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.FormBody;
import okhttp3.Headers;
import okhttp3.MediaType;
import okhttp3.MultipartBody;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;

public class OkHttpTest {
  private static OkHttpClient client;
  static Logger logger;

  @BeforeAll
  static void setUp() {
    client = new OkHttpClient();
    logger = LogManager.getLogger();
  }

  @AfterAll
  static void tearDown() {

  }

  @Test
  void testRequest() throws IOException {
    Request request = new Request.Builder().url("https://publicobject.com/helloworld.txt").build();
    try (Response response = client.newCall(request).execute()) {
      if (!response.isSuccessful())
        throw new IOException("Unexpected code " + response);

      Headers responseHeaders = response.headers();
      for (int i = 0; i < responseHeaders.size(); i++) {
        logger.info("{}: {}", responseHeaders.name(i), responseHeaders.value(i));
      }
      logger.info("\n{}", response.body().string());
    }
  }

  @Test
  void testPostForm() throws IOException {
    String url = "https://httpbin.org/post";
    RequestBody requestBody =
        new FormBody.Builder().add("name", "techstay").add("age", "18").build();

    Request request = new Request.Builder().url(url).post(requestBody).build();
    String body = client.newCall(request).execute().body().string();

    logger.info(body);
  }

  @Test
  void testDownloadImage() throws IOException {
    String imgUrl =
        "http://imgsrc.baidu.com/forum/pic/item/887018fa828ba61e7e0990be4a34970a314e5905.jpg";

    Request request = new Request.Builder().url(imgUrl).build();
    OkHttpClient client = new OkHttpClient();

    try (Response response = client.newCall(request).execute()) {
      if (!response.isSuccessful())
        throw new IOException("Unexpected code " + response);

      try (InputStream input = response.body().byteStream()) {
        File image = new File("src/test/resources/image.jpg");
        Files.copy(input, image.toPath(), StandardCopyOption.REPLACE_EXISTING);
        logger.info(image.getAbsolutePath());
        Assertions.assertThat(image).exists();
      }
    }


  }

  @Test
  void testWebContentAsync() throws IOException, InterruptedException {
    String baiduUrl = "https://www.baidu.com";
    Request request = new Request.Builder().url(baiduUrl).build();

    client.newCall(request).enqueue(new Callback() {
      @Override
      public void onFailure(Call call, IOException e) {
        logger.catching(e);
      }

      @Override
      public void onResponse(Call call, Response response) throws IOException {
        Headers headers = response.headers();
        String body = response.body().string();
        logger.info("\n{}", headers);
        logger.info("\n{}", body);
      }

    });
    Thread.sleep(8000);
  }

  @Test
  void testUploadFile() throws IOException {
    String url = "http://httpbin.org/post";
    File file = new File("src/test/resources/hello.txt");
    MediaType mediaTypeText = MediaType.parse("text/plain");

    RequestBody requestBody = new MultipartBody.Builder()
        .addFormDataPart("file", file.getName(), RequestBody.create(file, mediaTypeText)).build();
    MultipartBody multipartBody = new MultipartBody.Builder().setType(MultipartBody.FORM)
        .addFormDataPart("file", file.getName(), requestBody).build();
    Request request = new Request.Builder().url(url).post(multipartBody).build();

    try (Response response = client.newCall(request).execute()) {
      if (!response.isSuccessful())
        throw new IOException("Unexpected code " + response);

      String body = response.body().string();
      logger.info(body);

    }
  }
}
