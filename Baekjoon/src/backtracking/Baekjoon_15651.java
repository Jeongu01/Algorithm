package backtracking;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Baekjoon_15651 {

  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringBuilder sb = new StringBuilder();
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    func(n, m, 0);
    bw.flush();
  }

  public static void func(int n, int m, int count) throws IOException{
    if (count == m) {
      bw.write(sb.toString());
      bw.write("\n");
    } else {
      for (int i = 1; i <= n; i++) {
        sb.append(i).append(" ");
        func(n, m, count + 1);
        sb.delete(sb.length() - 2, sb.length());
      }
    }
  }

}
