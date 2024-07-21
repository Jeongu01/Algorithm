package Lv2;

public class VowelDictionary {

  public static void main(String[] args) {
    VowelDictionary Solution = new VowelDictionary();
    System.out.println(Solution.solution("AAAAE"));
    System.out.println();
    System.out.println(Solution.solution("AAAE"));
    System.out.println();
    System.out.println(Solution.solution("I"));
    System.out.println();
    System.out.println(Solution.solution("EIO"));
  }

  public int solution(String word) {
    int answer = 0;
    int length = word.length();
    String[] vowels = word.split("");

    for (int i = 0 ; i < length; i++) {
      int sum = 0;
      switch (5 - i) {
        case 5: sum += Math.pow(5, 4);
        case 4: sum += Math.pow(5, 3);
        case 3: sum += Math.pow(5, 2);
        case 2: sum += Math.pow(5, 1);
        case 1: sum += Math.pow(5, 0);
      }
      answer += sum * "AEIOU".indexOf(vowels[i]) + 1;
    }

    return answer;
  }
}
