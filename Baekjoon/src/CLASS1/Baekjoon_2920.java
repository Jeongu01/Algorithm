package CLASS1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_2920 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    String answer = "";
    boolean isMixed = false;
    int start = Integer.parseInt(st.nextToken());
    if (start == 1){
      for (int i = 2; i <= 8; i++){
        if (Integer.parseInt(st.nextToken())!=i) isMixed = true;
      }
      answer = "ascending";
    } else if (start == 8) {
      for (int i = 7; i >= 1; i--) {
        if (Integer.parseInt(st.nextToken())!=i) isMixed = true;
      }
      answer = "descending";
    } else {
      isMixed = true;
    }
    if (isMixed) {
      answer = "mixed";
    }

    System.out.println(answer);
  }

}
