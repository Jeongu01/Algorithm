package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
* main 에서 queue 가 다 빌 때까지 bfs 실행, bfs 한번 실행 시 count 1씩 증가
* bfs 에서는 해당 시점에 queue size 만큼 반복
* */
public class Baekjoon_7576 {

  static int[][] box;
  static Queue<pos> queue;
  static int[] dx = {0, 1, 0, -1};
  static int[] dy = {1, 0, -1, 0};
  static int m, n;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    m = Integer.parseInt(st.nextToken());
    n = Integer.parseInt(st.nextToken());
    box = new int[n][m];
    queue = new LinkedList<>();

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < m; j++) {
        box[i][j] = Integer.parseInt(st.nextToken());
        if (box[i][j] == 1) {
          queue.add(new pos(i, j));
        }
      }
    }

    int count = 0;
    while (!queue.isEmpty()) {
      bfs();
      count++;
    }
    count--;  // 1로 다 차고 다서도 queue 에는 마지막 좌표가 저장되어 있기 때문에 한 번더 계산돼서 1을 빼줌

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (box[i][j] == 0) {
          count = -1;
          break;
        }
      }
    }

    System.out.println(count);
  }

  static void bfs() {
    int qsize = queue.size();
    for (int k = 0; k < qsize; k++) {
      pos p = queue.poll();
      int p_x = p.x;
      int p_y = p.y;

      for (int i = 0; i < 4; i++) {
        int x = p_x + dx[i];
        int y = p_y + dy[i];

        if (x >= 0 && y >= 0 && x < n && y < m) {
          if (box[x][y] == 0) {
            box[x][y] = 1;
            queue.add(new pos(x, y));
          }
        }
      }
    }
  }

  static class pos {
    int x;
    int y;

    public pos(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }


}
