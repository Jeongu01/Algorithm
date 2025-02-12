package prefixSum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_16139 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st = new StringTokenizer(br.readLine());

    char[] S = st.nextToken().toCharArray();
    int N = S.length;

    int[][] countAlpha = new int[26][N + 1];

    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < N; j++) {
        countAlpha[i][j + 1] = countAlpha[i][j];
        if (i == S[j] - 'a') {
          countAlpha[i][j + 1]++;
        }
      }
    }

    st = new StringTokenizer(br.readLine());
    int q = Integer.parseInt(st.nextToken());
    for (int i = 0; i < q; i++) {
      st = new StringTokenizer(br.readLine());
      char target = st.nextToken().charAt(0);
      int start = Integer.parseInt(st.nextToken());
      int end = Integer.parseInt(st.nextToken());

      sb.append(countAlpha[target - 'a'][end + 1] - countAlpha[target - 'a'][start]).append('\n');
    }
    System.out.println(sb);
  }

}
