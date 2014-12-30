//Author:   Gilberto A. dos Santos
//Website:  https://www.urionlinejudge.com.br/judge/pt/problems/view/1593

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for(int i = 0; i < T; i++) {
      String n = s.next();
      BigInteger value = new BigInteger(n);
      System.out.println(value.bitCount());
    }
  }

}
