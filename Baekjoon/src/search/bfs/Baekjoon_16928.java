package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Baekjoon_16928 {

  static boolean[] board;
  static int[] ladder;
  static int[] snake;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    board = new boolean[101];
    ladder = new int[101];
    snake = new int[101];

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());

      ladder[s] = e;
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());

      snake[s] = e;
    }

    System.out.println(bfs());
  }

  static int bfs() {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(1);
    int count = 0;

    while (!queue.isEmpty()) {
      int size = queue.size();
      count++;

      while (size-- > 0) {
        int now = queue.poll();

        for (int i = 1; i <= 6; i++) {
          int next = now + i;
          if (next == 100) {
            queue.clear();
            size = 0;
            break;
          }
          if (next >= 1 && next <= 100) {
            if (!board[next]) {
              board[next] = true;
              if (ladder[next] != 0) queue.add(ladder[next]);
              else if (snake[next] != 0) queue.add(snake[next]);
              else queue.add(next);
            }
          }
        }
      }
    }

    return count;
  }

}
