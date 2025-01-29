package unionfind;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_1976 {

  static int[] cities;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    int M = Integer.parseInt(st.nextToken());

    cities = new int[N + 1];

    for (int i = 0; i < N + 1; i++) {
      cities[i] = i;
    }

    for (int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 1; j <= N; j++) {
        int connected = Integer.parseInt(st.nextToken());
        if (connected == 1) {
          union(i, j);
        }
      }
    }

    boolean isConnected = true;
    st = new StringTokenizer(br.readLine());
    int parent = find(cities[Integer.parseInt(st.nextToken())]);
    for (int i = 1; i < M; i++) {
      int next = find(cities[Integer.parseInt(st.nextToken())]);
      if (next != parent) isConnected = false;
    }

    if (isConnected) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }

  static void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      cities[b] = a;
    }
  }

  static int find(int a) {
    if (cities[a] == a) return a;
    else return cities[a] = find(cities[a]);
  }

}
