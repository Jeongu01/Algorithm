package CLASS2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_18110 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    int[] levels = new int[31];
    int ignored = (int) Math.round(N * 15 / 100.0);

    for (int i = 0; i < N; i++) {
      int input = Integer.parseInt(br.readLine());
      levels[input]++;
    }

    int count = 0;
    int i = 0;
    while (count < ignored) {
      if (levels[i] > 0) {
        levels[i]--;
        count++;
      } else {
        i++;
      }
    }

    count = 0;
    i = 30;
    while (count < ignored) {
      if (levels[i] > 0) {
        levels[i]--;
        count++;
      } else {
        i--;
      }
    }

    int sum = 0;
    for (int j = 1; j <= 30; j++) {
      sum += levels[j] * j;
    }

    count = N - ignored * 2;
    if (count == 0) {
      System.out.println(0);
    } else {
      System.out.println(Math.round((double) sum / count));
    }
  }

}
