package search.bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
* 방문한 위치에 깊이를 저장
* N, M 위치에 도달하면 탐색을 중지하고 해당 위치에 저장된 깊이를 반환
* 최소 거리를 구하는 문제의 경우 DFS 보다 BFS 가 더 적합함.
* DFS 의 경우 깊이가 깊은 경로를 먼저 탐색할 수도 있어서 N, M 에 도달하더라도 이게 최소 거리인지 보장이 없음
* */
public class Baekjoon_2178 {

  static int[] dx = {0, 1, 0, -1};
  static int[] dy = {1, 0, -1, 0};
  static Integer[][] arr;
  static boolean[][] visited;
  static int N, M;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    arr = new Integer[N][M];
    visited = new boolean[N][M];

    for (int i = 0; i < N; i++) {
      String[] s = br.readLine().split("");

      for (int j = 0; j < M; j++) {
        arr[i][j] = Integer.parseInt(s[j]);
      }
    }

    bfs();
  }

  static void bfs() {
    Queue<int[]> queue = new LinkedList<>();
    int[] start = new int[2];
    queue.add(start);
    visited[0][0] = true;
    int count = 1;

    while (!queue.isEmpty()) {
      int[] now = queue.poll();
      if (now[0] == N - 1 && now[1] == M - 1) {
        break;
      }

      for (int k = 0; k < 4; k++) {
        int x = now[0] + dx[k];
        int y = now[1] + dy[k];

        if (x >= 0 && y >= 0 && x < N && y < M) {
          if (arr[x][y] == 1 && !visited[x][y]) {
            visited[x][y] = true;
            arr[x][y] = arr[now[0]][now[1]] + 1;
            queue.add(new int[]{x, y});
          }
        }
      }
    }

    System.out.println(arr[N - 1][M - 1]);
  }

}
