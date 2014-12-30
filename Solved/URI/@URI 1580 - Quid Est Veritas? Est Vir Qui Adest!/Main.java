import java.math.BigInteger;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {

  static BigInteger[] fat = new BigInteger[1005];
  static BigInteger MOD;

  public static void init() {
    MOD = BigInteger.valueOf(1000000007);
    fat[0] = BigInteger.ONE;
    for(int i = 1; i < 1005; i++) {
      fat[i] = BigInteger.valueOf(i).multiply(fat[i-1]);
    }
  }

  public static void main(String[] args) {
    init();
    Scanner s = new Scanner(System.in);
    while (s.hasNext()) {
      String line = s.nextLine();
      int[] cnt = new int[26];
      int A = Character.getNumericValue('A');
      for (int i = 0; i < line.length(); i++) {
        int p = Character.getNumericValue(line.charAt(i));
        cnt[p - A]++;
      }
      BigInteger to_divide = BigInteger.ONE;
      for (int i = 0; i < 26; i++) if (cnt[i] > 1) {
        to_divide = to_divide.multiply(fat[cnt[i]]);
      }
      BigInteger ans = fat[line.length()];
      ans = ans.divide(to_divide);
      ans = ans.divideAndRemainder(MOD)[1];
      System.out.println(ans);
    }
  }

}

