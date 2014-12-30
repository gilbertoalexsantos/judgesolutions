import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static final int INF = -999999;

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> arr = new ArrayList<Integer>();
		while(sc.hasNext()) {
			Integer t = sc.nextInt();
			if(t == INF) {
				String ans = dp(arr);
				System.out.println(ans);
				arr.clear();
				continue;
			}
			arr.add(t);
		}
	}

	public static String dp(ArrayList<Integer> arr) {
		BigInteger mult = BigInteger.valueOf(INF);
		BigInteger flag = BigInteger.valueOf(1);
		for(int i = 0; i < arr.size(); i++) {
			flag = BigInteger.valueOf(1);	
			for(int j = i; j < arr.size(); j++) {
				if(arr.get(j) == 0) {
					flag = flag.multiply(BigInteger.valueOf(arr.get(j)));
					if(flag.compareTo(mult) == 1) mult = flag;
					break;
				}
				flag = flag.multiply(BigInteger.valueOf(arr.get(j)));
				if(flag.compareTo(mult) == 1) mult = flag;
			}
		}
		return mult.toString();
	}
}
