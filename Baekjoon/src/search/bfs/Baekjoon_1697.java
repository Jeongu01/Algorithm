package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_1697 {

  static int[] time = new int[100100];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());

    Arrays.fill(time, -1);

    bfs(N, K);
    System.out.println(time[K]);
  }

  static void bfs(int N, int K) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(N);
    time[N] = 0;

    while (!queue.isEmpty()) {
      int now = queue.poll();
      if (now - 1 >= 0 && time[now - 1] == -1) {
        time[now - 1] = time[now] + 1;
        if (now - 1 == K) break;
        queue.add(now - 1);
      }
      if (now + 1 < time.length && time[now + 1] == -1) {
        time[now + 1] = time[now] + 1;
        if (now + 1 == K) break;
        queue.add(now + 1);
      }
      if (2 * now < time.length && time[2 * now] == -1) {
        time[2 * now] = time[now] + 1;
        if (2 * now == K) break;
        queue.add(2 * now);
      }
    }
  }

}
