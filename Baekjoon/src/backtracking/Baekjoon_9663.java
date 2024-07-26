package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Baekjoon_9663 {

  static int n;
  static int count = 0;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());

    int[][] chessBoard = new int[n][n];

    func(chessBoard, 0);
    System.out.println(count);
  }

  public static void func(int[][] chessBoard, int x){   // x : 0 ~ 7
    for (int i = 0; i < chessBoard[x].length; i++){
      // 행 마다 둘 공간이 있는지 확인
      if (chessBoard[x][i] == 0) {
        // 퀸을 둠
        chessBoard[x][i] = 1;
        // 마지막 행에 퀸을 둔다면 count 를 증가시키고 리턴
        if (x == chessBoard.length - 1) {
          count++;
          chessBoard[x][i] -= 1;
          return;
        }
        // 방금 둔 퀸의 공격 반경을 1 증가시키기
        for (int j = -1; j <= 1; j++) {
          int k = 1;
          while (x + k >= 0 && x + k < chessBoard.length && i + j * k >= 0
              && i + j * k < chessBoard.length) {
            chessBoard[x + k][i + j * k] += 1;
            k++;
          }
        }
        // 다음 행으로 이동
        func(chessBoard, x + 1);
        // 퀸을 뺌
        chessBoard[x][i] = 0;
        // 방금 둔 퀸의 공격 반경을 1 감소시키기
        for (int j = -1; j <= 1; j++) {
          int k = 1;
          while (x + k >= 0 && x + k < chessBoard.length && i + j * k >= 0
              && i + j * k < chessBoard.length) {
            chessBoard[x + k][i + j * k] -= 1;
            k++;
          }
        }
      }
    }
  }

}
