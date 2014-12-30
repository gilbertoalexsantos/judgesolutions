import java.math.BigInteger;
import java.util.*;

public class Main {

  static int MOD = 1000;
  static BigInteger VALUE = BigInteger.valueOf(1500);

  public static void main(String[] args) {
    int[] memo = new int[1500];
    memo[0] = 0; memo[1] = 1;
    for(int i = 2; i < 1500; i++) {
      memo[i] = memo[i-1] + memo[i-2];
      memo[i] %= MOD;
    }
    Scanner s = new Scanner(System.in);
    int t = s.nextInt();
    for(int i = 0; i < t; i++) {
      String number = s.next();
      BigInteger b = new BigInteger(number, 2);
      BigInteger div = b.mod(VALUE);
      int pos = div.intValue();
      int ans = memo[pos];
      String formatted = String.format("%03d", ans);
      System.out.println(formatted);
    }
  }

}
