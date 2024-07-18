import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Baekjoon_1920 {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    Set<Integer> set = new HashSet<>();

    for (int i = 0; i < n; i ++) {
      set.add(scanner.nextInt());
    }

    n = scanner.nextInt();
    for (int i = 0; i < n; i ++) {
      int x = scanner.nextInt();
      if (set.contains(x)) {
        System.out.println("1");
      } else {
        System.out.println("0");
      }
    }


  }

}
