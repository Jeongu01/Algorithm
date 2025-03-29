import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int r, c;
  static long answer = 0, count = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    r = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());

    func(0, 0, N);
    System.out.println(answer);
  }

  // 배열 크기 = 2의 size 승
  static void func(long sr, long sc, int size) {
    if (size == 1) {
      if (sr == r && sc == c) answer = count;
      else count++;
      if (sr == r && sc + 1 == c) answer = count;
      else count++;
      if (sr + 1 == r && sc == c) answer = count;
      else count++;
      if (sr + 1 == r && sc + 1 == c) answer = count;
      else count++;
    } else {
      long d = (long) Math.pow(2, size - 1);
      if (sr <= r && r < sr + d && sc <= c && c < sc + d) {
        func(sr, sc, size - 1);
      }
      count += d * d;
      if (sr <= r && r < sr + d && sc + d <= c && c < sc + (2 * d)) {
        func(sr, sc + d, size - 1);
      }
      count += d * d;
      if (sr + d <= r && r < sr + (2 * d) && sc <= c && c < sc + d) {
        func(sr + d, sc, size - 1);
      }
      count += d * d;
      if (sr + d <= r && r < sr + (2 * d) && sc + d <= c && c < sc + (2 * d)) {
        func(sr + d, sc + d, size - 1);
      }
      count += d * d;
    }
  }

}
