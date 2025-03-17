import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1446 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int D = Integer.parseInt(st.nextToken());

    int[][] roads = new int[D + 1][D + 1];  // roads[N][K] = N -> K 최소값
    for (int i = 0; i <= D; i++) {
      for (int j = 0; j <= D; j++) {
        roads[i][j] = j - i > 0 ? j - i : D + 1;
      }
    }

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());

      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());
      int l = Integer.parseInt(st.nextToken());

      if (s <= D && e <= D) {
        roads[s][e] = Math.min(roads[s][e], l);
      }
    }

    for (int i = 0; i < D; i++) {
      for (int j = i + 1; j <= D; j++) {
        for (int k = i; k <= j; k++) {
          roads[i][j] = Math.min(roads[i][j], roads[i][k] + roads[k][j]);
        }
      }
    }

    System.out.println(roads[0][D]);
  }

}
