import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int[][] arr;
  static boolean[][] visited;
  static int blue = 0, white = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());

    arr = new int[n][n];
    visited = new boolean[n][n];

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < n; j++) {
        arr[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    func(0, 0, n);
    System.out.println(white);
    System.out.println(blue);
  }

  static void func(int sr, int sc, int size) {
    int color = arr[sr][sc];
    boolean same = true;
    for (int i = sr; i < sr + size; i++) {
      for (int j = sc; j < sc + size; j++) {
        if (color != arr[i][j]) {
          same = false;
        }
      }
    }
    if (same) {
      if (color == 1) blue++;
      else white++;
    } else {
      func(sr, sc, size / 2);
      func(sr + size / 2, sc, size / 2);
      func(sr, sc + size / 2, size / 2);
      func(sr + size / 2, sc + size / 2, size / 2);
    }
  }

}
