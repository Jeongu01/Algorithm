package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Baekjoon_17219 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    Map<String, String> passwords = new HashMap<>();

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());

      String domain = st.nextToken();
      String password = st.nextToken();

      passwords.put(domain, password);
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      sb.append(passwords.get(st.nextToken())).append("\n");
    }

    System.out.println(sb);
  }

}
