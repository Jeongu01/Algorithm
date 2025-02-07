package floydwarshall;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_1389 {

  static final int MAX_VALUE = 10_000_000;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    int[][] relations = new int[N + 1][N + 1];

    for (int i = 1; i <= N; i++) {
      Arrays.fill(relations[i], MAX_VALUE);
      relations[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());

      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      relations[a][b] = 1;
      relations[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
          relations[i][j] = Math.min(relations[i][j], relations[i][k] + relations[k][j]);
        }
      }
    }

    int min = MAX_VALUE;
    int answer = 0;
    for (int i = 1; i <= N; i++) {
      int sum = 0;
      for (int j = 1; j <= N; j++) {
        sum += relations[i][j];
      }
      if (min > sum) {
        min = sum;
        answer = i;
      }
    }

    System.out.println(answer);
  }

}
