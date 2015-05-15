import java.util.Scanner;
import java.util.Arrays;

public class Main {

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

    int n;
    while (s.hasNextInt()) {
      n = s.nextInt();

      String[] phones = new String[n];
      for (int i = 0; i < n; i++) {
        phones[i] = s.next();
      }

      Arrays.sort(phones);

      int ans = 0;
      for (int i = 0; i+1 < n; i++) {
        for (int j = 0; j < phones[i].length(); j++) {
          if (phones[i].charAt(j) == phones[i+1].charAt(j)) {
            ans++;
          } else {
            break;
          }
        }
      }

      System.out.println(ans);
    }
  }
  
}
