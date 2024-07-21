package Lv1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class PracticeTest {

  public static void main(String[] args) {
    PracticeTest Solution = new PracticeTest();
    int[] answers = {1,2,3,4,5};
    Arrays.stream(Solution.solution(answers)).forEach(System.out::println);
    System.out.println();
    int[] answers2 = {1,3,2,4,2};
    Arrays.stream(Solution.solution(answers2)).forEach(System.out::println);
  }

  public int[] solution(int[] answers) {
    List<Integer> answer = new ArrayList<>();

    int[] p1 = {1, 2, 3, 4, 5};
    int[] p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    int[] p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int[] a = new int[3];

    for (int i = 0; i < answers.length; i++) {
      if (answers[i] == p1[i%p1.length]) a[0]++;
      if (answers[i] == p2[i%p2.length]) a[1]++;
      if (answers[i] == p3[i%p3.length]) a[2]++;
    }

    int max = Math.max(Math.max(a[0], a[1]), a[2]);

    for (int i = 0; i < 3; i++) {
      if (max == a[i]) answer.add(i + 1);
    }

    return answer.stream().mapToInt(i -> i).toArray();
  }
}
