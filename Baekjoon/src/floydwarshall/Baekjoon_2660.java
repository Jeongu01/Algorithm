package floydwarshall;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_2660 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[][] D = new int[N + 1][N + 1];
    for (int i = 0; i <= N; i++) {
      Arrays.fill(D[i], 50);
    }

    while (true) {
      st = new StringTokenizer(br.readLine());
      int f1 = Integer.parseInt(st.nextToken());
      int f2 = Integer.parseInt(st.nextToken());

      if (f1 == -1 && f2 == -1)
        break;

      D[f1][f2] = 1;
      D[f2][f1] = 1;
    }

    for (int k = 1; k <= N; k++) {
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
          D[i][j] = Math.min(D[i][j], D[i][k] + D[k][j]);
        }
      }
    }

    int min = 50;
    ArrayList<Integer> list = new ArrayList<>();
    for (int i = 1; i <= N; i++) {
      int max = 0;
      for (int j = 1; j <= N; j++) {
        if (i == j) continue;
        max = Math.max(max, D[i][j]);
      }
      if (min > max) {
        min = max;
        list = new ArrayList<>();
        list.add(i);
      } else if (min == max) {
        list.add(i);
      }
    }

    System.out.println(min + " " + list.size());
    for (int i = 0; i < list.size(); i++) {
      System.out.print(list.get(i) + " ");
    }
  }

}