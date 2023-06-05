package tech.techstay.str;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegularExpression {
  public static void main(String[] args) {
    // the pattern that matches all words starting with b and ending with c
    Pattern pattern = Pattern.compile("\\bb\\w*c\\b");
    String text = "abc bbc cbc bbcc bcd";

    Matcher result = pattern.matcher(text);

    while (result.find()) {
      System.out.println(result.group());
    }
  }
}
