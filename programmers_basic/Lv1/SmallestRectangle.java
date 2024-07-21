package Lv1;

public class SmallestRectangle {

  public static void main(String[] args) {
    SmallestRectangle Solution = new SmallestRectangle();

    int[][] sizes = {
        {60, 50},
        {30, 70},
        {60, 30},
        {80, 40}
    };

    System.out.println(Solution.solution(sizes));

    int[][] sizes2 = {
        {10, 7},
        {12, 3},
        {8, 15},
        {14, 7},
        {5, 15}
    };
    System.out.println(Solution.solution(sizes2));
  }
  public int solution(int[][] sizes) {
    int maxWidth = -1;
    int maxHeight = -1;

    for (int[] size : sizes){
      maxWidth = Math.max(Math.max(size[0], size[1]), maxWidth);
      maxHeight = Math.max(Math.min(size[0], size[1]), maxHeight);
    }

    return maxWidth * maxHeight;
  }
}
