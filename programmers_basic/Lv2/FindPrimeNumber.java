package Lv2;

public class FindPrimeNumber {

  public static void main(String[] args) {
    FindPrimeNumber Solution = new FindPrimeNumber();

    String numbers = "17";
    System.out.println(Solution.solution(numbers));
    numbers = "011";
    System.out.println(Solution.solution(numbers));
    numbers = "121";
    System.out.println(Solution.solution(numbers));
  }

  public int solution(String numbers) {
    int answer = 0;

    // 최대값 찾기
    int max = 0;
    int[] countDigits = new int[10];
    for (char digit : numbers.toCharArray()) {
      countDigits[digit - '0']++;
    }

    for (int i = 9; i >= 0; i--) {
      for (int j = 0; j < countDigits[i]; j++){
        max *= 10;
        max += i;
      }
    }

    // 2부터 최대값까지 모든 수를 체크
    if (countDigits[2] != 0) answer++;
    for (int i = 3; i <= max; i += 2) {
      int[] target = new int[10];
      int temp = i;
      boolean isContain = true;
      while (temp != 0) {   // i가 numbers 의 숫자들로 나올 수 있는 값인지 확인
        target[temp % 10]++;
        if (target[temp % 10] > countDigits[temp % 10]) {   // target 배열의 요소들 중 하나라도 countDigits 배열의 요소를 넘어서면 안됨
          isContain = false;
          break;
        }
        temp /= 10;
      }
      if (isContain){   // numbers 로 만들 수 있는 숫자만 소수인지 판별
        if (isPrime(i)){
          answer++;
        }
      }
    }

    return answer;
  }

  public static boolean isPrime(int n) {
    if (n == 1) {
      return false;
    }
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

}
