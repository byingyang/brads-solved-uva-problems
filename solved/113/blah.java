//20043 {{ProblemID}}
//Chapter: Problem Name 
//Brad Yinger

import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Scanner;

class blah {	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s;
		while (in.hasNextLine() && (s = in.nextLine()) != null && s.length() != 0) {
			int n = Integer.parseInt(s);
			s = in.nextLine();
			BigInteger p = new BigInteger(s);
			double d = p.doubleValue();
			System.out.println(Math.round(Math.pow(d, (1.0 / n))));
		}
	}
}
