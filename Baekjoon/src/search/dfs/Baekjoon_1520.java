package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
* 목적지까지 도달하는 경우가 생긴다면 방문한 모든 칸에 count를 1씩 증가
* 목적지까지 도달하는 경우가 생기지 않는다면 해당 분기점의 count를 -1로 초기화
* 최대한 계산이 중복되는 것을 방지하는게 키 포인트
* */
public class Baekjoon_1520 {

  static int[][] arr;
  static boolean[][] visited;
  static long[][] counts;
  static int destination, n, m;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());

    arr = new int[n][m];
    visited = new boolean[n][m];
    counts = new long[n][m];

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < m; j++) {
        arr[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    destination = arr[n - 1][m - 1];

    dfs(0, 0, 10001);

    System.out.println(counts[0][0] == -1 ? 0 : counts[0][0]);
  }

  static void dfs(int x, int y, int prev) {
    if (visited[x][y] || prev <= arr[x][y] || counts[x][y] == -1) {
      return;
    }

    if (counts[x][y] != 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (visited[i][j]) {
            counts[i][j] += counts[x][y];
          }
        }
      }
      return;
    }

    // 목적지에 잘 도착한 경우
    if (x == n - 1 && y == m - 1) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (visited[i][j]) {
            counts[i][j]++;
          }
        }
      }
      counts[n - 1][m - 1]++;
      return;
    }

    visited[x][y] = true;
    if (x != 0) dfs(x - 1, y, arr[x][y]);
    if (x != n - 1) dfs(x + 1, y, arr[x][y]);
    if (y != 0) dfs(x, y - 1, arr[x][y]);
    if (y != m - 1) dfs(x, y + 1, arr[x][y]);
    visited[x][y] = false;

    // 목적지까지 도달하지 못하는 경우 -1로 초기화
    if (counts[x][y] == 0) {
      counts[x][y] = -1;
    }
  }

}
