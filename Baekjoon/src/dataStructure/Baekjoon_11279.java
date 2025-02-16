package dataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Baekjoon_11279 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    PriorityQueue<Integer> queue = new PriorityQueue<>((a, b) -> b - a);

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      int input = Integer.parseInt(st.nextToken());

      if (input == 0) {
        if (queue.isEmpty()) {
          System.out.println(0);
        } else {
          System.out.println(queue.poll());
        }
      } else {
        queue.add(input);
      }
    }
  }

}
