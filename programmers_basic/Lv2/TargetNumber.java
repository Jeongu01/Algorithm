package Lv2;

public class TargetNumber {

  public static void main(String[] args) {
    TargetNumber Solution = new TargetNumber();
    int[] numbers = {1,1,1,1,1};
    System.out.println(Solution.solution(numbers, 3));
    int[] numbers2 = {4,1,2,1};
    System.out.println(Solution.solution(numbers2, 4));

  }

  static int count = 0;

  public int solution(int[] numbers, int target) {
    func(numbers, target, 0, 0);
    return count;
  }

  public static void func(int[] numbers, int target, int sum, int pos){
    if (pos == numbers.length) {
      if (sum == target) count++;
      return;
    }
    func(numbers, target, sum + numbers[pos], pos + 1);
    func(numbers, target, sum - numbers[pos], pos + 1);
  }

}
