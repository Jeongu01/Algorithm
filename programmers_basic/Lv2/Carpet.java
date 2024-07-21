package Lv2;

import java.util.Arrays;

public class Carpet {

  public static void main(String[] args) {
    Carpet Solution = new Carpet();
    Arrays.stream(Solution.solution(10, 2)).forEach(System.out::println);
    System.out.println();
    Arrays.stream(Solution.solution(8, 1)).forEach(System.out::println);
    System.out.println();
    Arrays.stream(Solution.solution(24, 24)).forEach(System.out::println);
  }

  public int[] solution(int brown, int yellow) {
    int[] answer = new int[2];

    answer[0] = (int) (brown + 4 + Math.sqrt(brown * brown - 8 * brown - 16 * yellow + 16))/4;
    answer[1] = (int) (brown + 4 - Math.sqrt(brown * brown - 8 * brown - 16 * yellow + 16))/4;

//    for (int width = 1; width * width <= yellow; width++){
//      if (yellow % width == 0) {
//        int height = yellow / width;
//        if (brown == width * 2 + height * 2 + 4){
//          answer[0] = height + 2;
//          answer[1] = width + 2;
//        }
//      }
//    }

    return answer;
  }

}
