package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_13398 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int[] arr = new int[n];
    int[] ldp = new int[n];
    int[] rdp = new int[n];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }

    ldp[0] = arr[0];
    int max = ldp[0];
    for (int i = 1; i < n; i++) {
      ldp[i] = Math.max(ldp[i - 1] + arr[i], arr[i]);
      max = Math.max(max, ldp[i]);
    }

    rdp[n - 1] = arr[n - 1];
    for (int i = n - 2; i > 0; i--) {
      rdp[i] = Math.max(rdp[i + 1] + arr[i], arr[i]);
    }

    for (int i = 1; i < n - 1; i++) {
      max = Math.max(max, ldp[i - 1] + rdp[i + 1]);
    }
    System.out.println(max);
  }
}
