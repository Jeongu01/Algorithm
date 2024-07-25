package backtracking;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Baekjoon_15652 {

  static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  static StringBuilder sb = new StringBuilder();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    func(n, m, 1, 0);
    bw.flush();
  }

  public static void func(int n, int m, int k, int count) throws IOException{
    if (sb.length() == m * 2) {
      bw.write(sb.toString());
      bw.append("\n");
      return;
    }
    for (int i = k; i <= n; i++) {
      sb.append(i).append(" ");
      func(n, m, i, count + 1);
      sb.delete(sb.length() - 2, sb.length());
    }
  }

}
