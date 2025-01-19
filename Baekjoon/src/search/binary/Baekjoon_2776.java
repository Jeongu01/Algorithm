package search.binary;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_2776 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int T = Integer.parseInt(st.nextToken());

    for (int i = 0; i < T; i++) {
      st = new StringTokenizer(br.readLine());
      int N = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      int[] arr = new int[N];
      for (int j = 0; j < N; j++) {
        arr[j] = Integer.parseInt(st.nextToken());
      }

      Arrays.sort(arr);

      st = new StringTokenizer(br.readLine());
      int M = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; j++) {
        int start = 0;
        int end = arr.length - 1;
        int target = Integer.parseInt(st.nextToken());
        boolean find = false;

        while (start <= end) {
          int midi = (start + end) / 2;
          int midV = arr[midi];

          if (target < midV) {
            end = midi - 1;
          } else if (target > midV) {
            start = midi + 1;
          } else {
            find = true;
            break;
          }
        }
        if (find) {
          bw.write("1\n");
        } else {
          bw.write("0\n");
        }
      }
      bw.flush();
    }
    bw.close();
  }
}
