package Lv3;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
public class WordConversion {

  public static void main(String[] args) {
    WordConversion Solution = new WordConversion();
    String[] words = {"hot", "dot", "dog", "lot", "log", "cog"};
    System.out.println(Solution.solution("hit", "cog", words));
    String[] words2 = {"hot", "dot", "dog", "lot", "log"};
    System.out.println(Solution.solution("hit", "cog", words2));
  }

  public int solution(String begin, String target, String[] words) {
    Queue<String> queue = new LinkedList<>();
    Map<String, Boolean> isVisited = new HashMap<>();
    Map<String, Integer> countConversion = new HashMap<>();

    queue.add(begin);
    isVisited.put(begin, true);
    countConversion.put(begin, 0);

    while (!queue.isEmpty()) {
      String tempStr = queue.remove();
      if (tempStr.equals(target)) {
        return countConversion.get(tempStr);
      }
      for (String word : words) {
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
          if (tempStr.charAt(i) != word.charAt(i)) count++;
        }
        if (count == 1 && !isVisited.getOrDefault(word, false)) {
          countConversion.put(word, countConversion.get(tempStr) + 1);
          isVisited.put(word, true);
          queue.add(word);
        }
      }
    }

    return 0;
  }

}
