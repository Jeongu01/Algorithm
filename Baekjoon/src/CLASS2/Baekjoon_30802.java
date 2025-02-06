package CLASS2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_30802 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    int[] shirts = new int[6];
    for (int i = 0; i < 6; i++) {
      shirts[i] = Integer.parseInt(st.nextToken());
    }

    st = new StringTokenizer(br.readLine());
    int T = Integer.parseInt(st.nextToken());
    int P = Integer.parseInt(st.nextToken());

    int count = 0;
    for (int i = 0; i < 6; i++) {
      count += shirts[i] / T;
      if (shirts[i] % T != 0) count++;
    }
    System.out.println(count);
    System.out.println((N / P) + " " + (N % P));
  }

}
