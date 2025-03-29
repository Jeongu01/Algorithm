import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int[] nums;
  static int N;
  static boolean isFind = false;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    nums = new int[N + 1];

    rec(1, 1);
    if (!isFind) rec(2, 1);
    if (!isFind) rec(3, 1);
  }

  static void rec(int a, int length) {
    if (isFind) return;

    nums[length] = a;
    if (!check(length)) return;

    if (length == N) {
      for (int i = 1; i <= N; i++) {
        System.out.print(nums[i]);
      }
      isFind = true;
    }

    if (a == 1) {
      rec(2, length + 1);
      rec(3, length + 1);
    } else if (a == 2) {
      rec(1, length + 1);
      rec(3, length + 1);
    } else if (a == 3) {
      rec(1, length + 1);
      rec(2, length + 1);
    }
  }

  static boolean check(int length) {
    for (int i = 1; i <= length / 2; i++) {
      StringBuilder s1 = new StringBuilder();
      StringBuilder s2 = new StringBuilder();
      for (int j = length; j > length - i; j--) {
        s1.append(nums[j]);
        s2.append(nums[j - i]);
      }
      if (s1.toString().equals(s2.toString())) {
        return false;
      }
    }

    return true;
  }

}
