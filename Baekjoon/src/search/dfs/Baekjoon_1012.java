package search.dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/*
* 연결되어 있는 배추 무리의 갯수만 세면 됨
* 배열 전체를 순회하면서 배추가 있으면 dfs 함수를 통해
* 해당 배추와 인접한 위치들을 false로 초기화 해버림(이후에 또 고려할 필요가 없어서)
* 결국 main 함수에서 dfs 함수를 호출한 횟수를 출력해주면 됨
* */
public class Baekjoon_1012 {

  static boolean[][] arr;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());

    for (int i = 0; i < T; i++) {
      st = new StringTokenizer(br.readLine());
      int M = Integer.parseInt(st.nextToken());
      int N = Integer.parseInt(st.nextToken());
      int K = Integer.parseInt(st.nextToken());

      arr = new boolean[M][N];
      int count = 0;

      for (int j = 0; j < K; j++) {
        st = new StringTokenizer(br.readLine());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());

        arr[X][Y] = true;
      }

      for (int a = 0; a < M; a++) {
        for (int b = 0; b < N; b++) {
          if (arr[a][b]) {
            count++;
            dfs(M, N, a, b);
          }
        }
      }
      System.out.println(count);
    }
  }

  static void dfs(int m, int n, int x, int y) {
    if (!arr[x][y]) {
      return;
    }

    arr[x][y] = false;
    if (x != 0)dfs(m, n, x - 1, y);
    if (x != m - 1) dfs(m, n, x + 1, y);
    if (y != 0) dfs(m, n, x, y - 1);
    if (y != n - 1) dfs(m, n, x, y + 1);
  }

}
