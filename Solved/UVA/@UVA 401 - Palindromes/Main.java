import java.util.Scanner;

public class Main {

	static final char NOT = '.';
	static char[] reverse = new char[500];

	public static void init() {
		for(int i = 0; i < 500; i++)
			reverse[i] = NOT;
		reverse['A'] = 'A'; reverse['E'] = '3';
		reverse['H'] = 'H'; reverse['I'] = 'I';
		reverse['J'] = 'L'; reverse['L'] = 'J';
		reverse['M'] = 'M'; reverse['O'] = 'O';
		reverse['S'] = '2'; reverse['T'] = 'T';
		reverse['U'] = 'U'; reverse['V'] = 'V';
		reverse['W'] = 'W'; reverse['X'] = 'X';
		reverse['Y'] = 'Y'; reverse['Z'] = '5';
		reverse['1'] = '1'; reverse['2'] = 'S';
		reverse['3'] = 'E'; reverse['5'] = 'Z';
		reverse['8'] = '8';
	}

	public static boolean isPalindrome(String text) {
		int left = 0, right = text.length() - 1;
		while(left <= right) {
			if(text.charAt(left) != text.charAt(right))
				return false;
			left++; right--;
		}
		return true;
	}

	public static boolean isMirrored(String text) {
		int left = 0, right = text.length() - 1;
		while(left <= right) {
			char after_left = reverse[text.charAt(left)];
			char after_right = reverse[text.charAt(right)];
			if(after_left == NOT || after_right == NOT)
				return false;
			char before_left = text.charAt(left);
			char before_right = text.charAt(right);
			if(before_left != after_right || before_right != after_left)
				return false;
			left++; right--;
		}
		return true;
	}

	public static void main(String args[]) {
		init();
		Scanner scan = new Scanner(System.in);
		String word;
		while(scan.hasNext()) {		
			word = scan.next();

			boolean palindrome = isPalindrome(word);
			boolean mirrored = isMirrored(word);
			if(palindrome && mirrored)
				System.out.println(word + " -- is a mirrored palindrome.");
			else if(mirrored && !palindrome)
				System.out.println(word + " -- is a mirrored string.");
			else if(palindrome && !mirrored)
				System.out.println(word + " -- is a regular palindrome.");
			else
				System.out.println(word + " -- is not a palindrome.");
			System.out.println();
		}
	}
}
