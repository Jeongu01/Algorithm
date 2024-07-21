package Lv1;

public class Bandage {

  public static void main(String[] args) {
    Bandage Solution = new Bandage();
    int[] bandage = {5, 1, 5};  // 시전 시간, 초당 회복량, 추가 회복량
    int[][] attacks = {{2, 10}, {9, 15}, {10, 5}, {11, 5}};    // 공격 시간, 피해량
    System.out.println(Solution.solution(bandage, 30, attacks));
    int[] bandage1 = {1, 1, 1};
    int[][] attacks1 = {{1, 2}, {3, 2}};
    System.out.println(Solution.solution(bandage1, 5, attacks1));
  }

  public int solution(int[] bandage, int health, int[][] attacks) {
    int currentHp = health;

    int recentAttackTime = 0;
    for (int[] attack : attacks) {
      int recoveryTime = attack[0] - recentAttackTime - 1;
      recentAttackTime = attack[0];
      int recovery = recoveryTime * bandage[1];
      int bonusRecovery = (recoveryTime / bandage[0]) * bandage[2];

      currentHp = Math.min(currentHp + recovery + bonusRecovery, health);
      currentHp -= attack[1];
      if (currentHp <= 0) return -1;
    }

    return currentHp;
  }
}
