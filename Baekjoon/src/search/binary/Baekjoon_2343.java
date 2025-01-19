package search.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_2343 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int[] times = new int[N];

    st = new StringTokenizer(br.readLine());
    int start = 0;
    int end = 0;
    for (int i = 0; i < N; i++) {
      times[i] = Integer.parseInt(st.nextToken());
      end += times[i];
      start = Math.max(start, times[i]);
    }

    int answer = 0;
    while (start <= end) {
      int mid = (start + end) / 2;

      int count = 1;
      int sum = 0;
      for (int time : times) {
        if (sum + time > mid) {
          sum = time;
          count++;
        } else {
          sum += time;
        }
      }

      if (count <= M) {
        answer = mid;
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    System.out.println(answer);
  }
}