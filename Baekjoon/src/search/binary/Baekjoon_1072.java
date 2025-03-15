package search.binary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1072 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long X = Long.parseLong(st.nextToken());
    long Y = Long.parseLong(st.nextToken());
    long Z = 100 * Y / X;

    if (Z == 99 || Z == 100) {
      System.out.println(-1);
    } else {
      long start = 0;
      long end = 1_000_000_000;
      long answer = -1;
      while (start <= end) {
        long mid = (start + end) / 2;
        long R = 100 * (Y + mid) / (X + mid);

        if (R == Z) {
          start = mid + 1;
        } else {
          end = mid - 1;
          answer = mid;
        }
      }

      System.out.println(answer);
    }
  }

}


//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//
//public class Baekjoon_1072 {
//
//  public static void main(String[] args) throws IOException {
//    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//    StringTokenizer st = new StringTokenizer(br.readLine());
//
//    long X = Long.parseLong(st.nextToken());
//    long Y = Long.parseLong(st.nextToken());
//
//    long Z = Y * 100 / X;
//
//    long start = 1;
//    long end = X;
//    long answer = -1;
//
//    while (start <= end) {
//      long mid = (start + end) / 2;
//      long rate = (Y + mid) * 100 / (X + mid);
//
//      if (rate == Z) {
//        start = mid + 1;
//      } else {
//        end = mid - 1;
//        answer = mid;
//      }
//    }
//    System.out.println(answer);
//  }
//
//}
