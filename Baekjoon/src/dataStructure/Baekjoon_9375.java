package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Baekjoon_9375 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    StringBuilder sb = new StringBuilder();

    int t = Integer.parseInt(st.nextToken());

    for (int i = 0; i < t; i++) {
      st = new StringTokenizer(br.readLine());

      int n = Integer.parseInt(st.nextToken());
      Map<String, Integer> clothes = new HashMap<>();

      for (int j = 0; j < n; j++) {
        st = new StringTokenizer(br.readLine());

        String name = st.nextToken();
        String type = st.nextToken();

        if (!clothes.containsKey(type)) {
          clothes.put(type, 1);
        } else {
          clothes.put(type, clothes.get(type) + 1);
        }
      }

      int answer = 1;
      for (Integer v : clothes.values()) {
        answer *= v + 1;
      }

      sb.append(answer - 1).append("\n");
    }

    System.out.println(sb);
  }

}
