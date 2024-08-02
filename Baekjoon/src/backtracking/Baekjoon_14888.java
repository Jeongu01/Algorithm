package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_14888 {

  static int[] numbers;
  static int[] op = new int[4];
  static int[] isUsed = new int[4];
  static int max = Integer.MIN_VALUE;
  static int min = Integer.MAX_VALUE;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    numbers = new int[n];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      numbers[i] = Integer.parseInt(st.nextToken());
    }

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < 4; i++) {
      op[i] = Integer.parseInt(st.nextToken());
    }

    func(1, numbers[0]);

    System.out.println(max);
    System.out.println(min);
  }

  public static void func(int count, int value) {
    if (count == numbers.length) {
      max = Math.max(max, value);
      min = Math.min(min, value);
    }

    if (isUsed[0] < op[0]) {
      isUsed[0]++;
      func(count + 1, value + numbers[count]);
      isUsed[0]--;
    }
    if (isUsed[1] < op[1]) {
      isUsed[1]++;
      func(count + 1, value - numbers[count]);
      isUsed[1]--;
    }
    if (isUsed[2] < op[2]) {
      isUsed[2]++;
      func(count + 1, value * numbers[count]);
      isUsed[2]--;
    }
    if (isUsed[3] < op[3]) {
      isUsed[3]++;
      func(count + 1, value / numbers[count]);
      isUsed[3]--;
    }
  }

}
