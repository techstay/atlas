package tech.techstay;

import org.aeonbits.owner.Config;

@Config.Sources({"classpath:config.properties"})
public interface MyConfig extends Config {
  int port();

  String username();

  String password();

  @Key("foo.bar.data")
  String fooBar();
}
