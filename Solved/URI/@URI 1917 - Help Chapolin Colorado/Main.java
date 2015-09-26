//Author: Gilberto A. dos Santos
//Website: https://www.urionlinejudge.com.br/judge/en/problems/view/1917
import java.util.Scanner;
import java.math.BigInteger;

public class Main {

  public static void main(String[] args) {
    BigInteger[] fib = new BigInteger[100006];

    fib[0] = BigInteger.ZERO;
    fib[1] = BigInteger.ONE;
    fib[2] = BigInteger.ONE;

    for (int i = 3; i <= 100005; i++)
      fib[i] = fib[i-2].add(fib[i-1]);
    
    Scanner s = new Scanner(System.in);
    while (true) {
      Integer x = s.nextInt();
      Integer y = s.nextInt();
      if (x+y == 0)
        break;
      BigInteger ans = fib[y+2].multiply(BigInteger.valueOf(x.intValue()));
      System.out.println(ans);
    }
  }
  
}
