package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1747 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    int[] arr = new int[1_003_002]; // 1,000,000 보다 크고 소수이면서 팰린드롬인 수 중에서 가장 작은 수는 1,003,001

    for (int i = 2; i < arr.length; i++) {
      arr[i] = i;
    }

    for (int i = 2; i < Math.sqrt(arr.length); i++) {
      if (arr[i] != 0) {
        for (int j = i + i; j < arr.length; j += i) {
          arr[j] = 0;
        }
      }
    }

    for (int i = 2; i < arr.length; i++) {
      if (arr[i] >= N) {
        char[] original = Integer.toString(arr[i]).toCharArray();

        for (int j = 0; j < original.length / 2; j++) {
          char temp = original[j];
          original[j] = original[original.length - 1 - j];
          original[original.length - 1 - j] = temp;
        }

        int reversed = Integer.parseInt(String.valueOf(original));
        if (arr[i] == reversed) {
          System.out.println(arr[i]);
          break;
        }
      }
    }
  }

}
