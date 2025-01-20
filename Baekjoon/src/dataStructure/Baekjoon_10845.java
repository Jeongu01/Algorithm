package dataStructure;

import java.io.*;
import java.util.*;

public class Baekjoon_10845 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    Queue<Integer> queue = new LinkedList<>();

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      String command = st.nextToken();
      Integer x;

      switch (command) {
        case "push":
          x = Integer.parseInt(st.nextToken());
          queue.add(x);
          break;
        case "pop":
          x = queue.poll();
          System.out.println(x == null ? -1 : x);
          break;
        case "size":
          System.out.println(queue.size());
          break;
        case "empty":
          System.out.println(queue.isEmpty() ? 1 : 0);
          break;
        case "front":
          x = queue.peek();
          System.out.println(x == null ? -1 : x);
          break;
        case "back":
          if (queue.isEmpty()) {
            System.out.println(-1);
          } else {
            for (int j = 0; j < queue.size() - 1; j++) {
              queue.add(queue.poll());
            }
            x = queue.poll();
            System.out.println(x);
            queue.add(x);
          }
          break;
      }
    }
  }
}

