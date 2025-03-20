package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Baekjoon_17626 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long[] nums = new long[50001];
    Arrays.fill(nums, 5);

    for (long i = 1; i <= 50000; i++) {
      long index = i * i;
      if (i * i > 50000) break;
      nums[(int) index] = Math.min(nums[(int) index], 1);
      for (long j = i; j <= 50000; j++) {
        index = i * i + j * j;
        if (index > 50000) break;
        nums[(int) index] = Math.min(nums[(int) index], 2);
        for (long k = j; k <= 50000; k++) {
          index = i * i + j * j + k * k;
          if (index > 50000) break;
          nums[(int) index] = Math.min(nums[(int) index], 3);
          for (long l = k; l <= 50000; l++) {
            index = i * i + j * j + k * k + l * l;
            if (index > 50000) break;
            nums[(int) index] = Math.min(nums[(int) index], 4);
          }
        }
      }
    }

    int n = Integer.parseInt(st.nextToken());
    System.out.println(nums[n]);
  }

}
