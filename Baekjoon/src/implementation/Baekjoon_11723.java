package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Baekjoon_11723 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    int M = Integer.parseInt(st.nextToken());
    Set<Integer> set = new HashSet<>();
    Integer x;

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());

      String command = st.nextToken();

      switch (command) {
        case "add":
          x = Integer.parseInt(st.nextToken());
          set.add(x);
          break;
        case "remove":
          x = Integer.parseInt(st.nextToken());
          set.remove(x);
          break;
        case "check":
          x = Integer.parseInt(st.nextToken());
          if (set.contains(x)) {
            sb.append(1).append("\n");
          } else {
            sb.append(0).append("\n");
          }
          break;
        case "toggle":
          x = Integer.parseInt(st.nextToken());
          if (set.contains(x)) {
            set.remove(x);
          } else {
            set.add(x);
          }
          break;
        case "all":
          for (int j = 1; j <= 20; j++) {
            set.add(j);
          }
          break;
        case "empty":
          set.clear();
          break;
      }
    }
    System.out.println(sb);
  }

}
