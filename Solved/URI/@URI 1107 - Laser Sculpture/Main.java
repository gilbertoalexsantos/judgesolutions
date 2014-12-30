import java.util.Scanner;
import java.lang.Math;

public class Main {

  static int altura, comprimento;
  static int[] altura_final;

  public static void main(String args[]) {
    Scanner sca = new Scanner(System.in);
    while(true) {
      altura = sca.nextInt(); comprimento = sca.nextInt();
      if(altura == 0 && comprimento == 0)
        break;
      altura_final = new int[comprimento + 1];
      for(int i = 0; i < comprimento; i++)
        altura_final[i] = sca.nextInt();
      altura_final[comprimento] = altura;
      int ans = 0;
      for(int i = comprimento; i > 0; i--) {
        if(altura_final[i] < altura_final[i - 1])
          continue;
        ans += Math.abs(altura_final[i] - altura_final[i - 1]);
      }
      System.out.println(ans);
    }
  }

}
