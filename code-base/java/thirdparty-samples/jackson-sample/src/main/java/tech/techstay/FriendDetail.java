package tech.techstay;

import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonProperty;

public record FriendDetail(String name, int age, @JsonIgnore String foo,
    @JsonProperty("baz") String bar) {

}
