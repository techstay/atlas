package tech.techstay;

import java.time.LocalDate;
import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;

public record Person(@JsonProperty("first_name") String firstName,
    @JsonProperty("last_name") String lastName, int age, String identityCode,
    @JsonFormat(pattern = "yyyy/MM/DD") LocalDate birthday) {

}
