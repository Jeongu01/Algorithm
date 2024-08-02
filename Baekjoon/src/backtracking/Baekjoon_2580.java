package backtracking;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Baekjoon_2580 {

  static int[][] answer;
  static boolean find = false;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int[][] arr = new int[9][9];
    int countEmpty = 0;

    for (int i = 0; i < 9; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int j = 0; j < 9; j++) {
        int input = Integer.parseInt(st.nextToken());
        arr[i][j] = input;
        // 빈 칸 체크
        if (input == 0) {
          countEmpty++;
        }
      }
    }

    func(arr, countEmpty);
  }

  public static void func(int[][] arr, int countEmpty) {
    if (countEmpty == 0 && !find) {
      answer = arr;
      find = true;
      for (int[] ints : arr) {
        for (int anInt : ints) {
          System.out.print(anInt + " ");
        }
        System.out.println();
      }
      System.out.println();
    }
    if (!find) {
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (arr[i][j] == 0) {
            List<Integer> list = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9));
            for (int k = 0; k < 9; k++) {
              list.remove((Integer) arr[i][k]);
              list.remove((Integer) arr[k][j]);
              list.remove((Integer) arr[(i / 3) * 3 + (k / 3)][(j / 3) * 3 + (k % 3)]);
              if (list.isEmpty()) {
                return;
              }
            }
            for (int x : list) {
              arr[i][j] = x;
              func(arr, countEmpty - 1);
            }
            arr[i][j] = 0;
            return;
          }
        }
      }
    }
  }
}