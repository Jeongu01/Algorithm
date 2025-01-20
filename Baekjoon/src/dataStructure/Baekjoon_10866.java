package dataStructure;

import java.io.*;
import java.util.*;

public class Baekjoon_10866 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    Deque<Integer> deque = new ArrayDeque<>();

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());

      String command = st.nextToken();
      Integer x;

      switch (command) {
        case "push_front" :
          x = Integer.parseInt(st.nextToken());
          deque.addFirst(x);
          break;
        case "push_back" :
          x = Integer.parseInt(st.nextToken());
          deque.addLast(x);
          break;
        case "pop_front" :
          x = deque.pollFirst();
          System.out.println(x == null ? -1 : x);
          break;
        case "pop_back" :
          x = deque.pollLast();
          System.out.println(x == null ? -1 : x);
          break;
        case "size" :
          System.out.println(deque.size());
          break;
        case "empty":
          System.out.println(deque.isEmpty() ? 1 : 0);
          break;
        case "front" :
          x = deque.peekFirst();
          System.out.println(x == null ? -1 : x);
          break;
        case "back" :
          x = deque.peekLast();
          System.out.println(x == null ? -1 : x);
          break;
      }
    }
  }

}
