package math;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1016 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long min = Long.parseLong(st.nextToken());
    long max = Long.parseLong(st.nextToken());

    long[] arr = new long[1_001_001];
    long[] range = new long[1_000_001];

    for (int i = 2; i < arr.length; i++) {
      arr[i] = i;
    }

    long target = min;
    while (target <= max) {
      int index = (int) (target - min);
      range[index] = target;
      target++;
    }

    // 4 * 9 같은건 2번 카운트 되니까 배열에 저장하는 식으로 처리
    for (int i = 2; i < arr.length; i++) {
      if (arr[i] != 0) {
        for (int j = i + i; j < arr.length; j += i) {
          arr[j] = 0;
        }
        // temp 의 시작 부분을 미리 구해서 시간을 줄이기 위한 연산
        long temp = arr[i] * arr[i] * (min / (arr[i] * arr[i]));
        temp += min % (arr[i] * arr[i]) == 0 ? 0 : arr[i] * arr[i];

        while (temp <= max) {
          if (min <= temp) {
            int index = (int) (temp - min);
            range[index] = 0;
          }
          temp += arr[i] * arr[i];
        }
      }
    }


    int squareCount = 0;
    for (long l : range) {
      if (l != 0) {
        squareCount++;
      }
    }

    System.out.println(squareCount);

  }

}
