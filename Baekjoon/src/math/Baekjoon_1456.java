package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Baekjoon_1456 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long A = Long.parseLong(st.nextToken());
    long B = Long.parseLong(st.nextToken());
    long[] arr = new long[10000001];

    for (int i = 2; i < arr.length; i++) {
      arr[i] = i;
    }

    for (int i = 2; i <= Math.sqrt(arr.length); i++) {
      if (arr[i] != 0) {
        for (int j = i + i; j < arr.length; j += i) {
          arr[j] = 0;
        }
      }
    }

    int count = 0;
    for (int i = 2; i < arr.length; i++) {
      if (arr[i] != 0) {
        double temp = arr[i];
        // 곱셈이 long 의 범위를 넘어갈 수 있어 이항 정리로 처리
        while (arr[i] <= B / temp) {
          if (A / temp <= arr[i]) {
            count++;
          }
          temp *= arr[i];
        }
      }
    }

    System.out.println(count);

  }

}
