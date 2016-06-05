
import java.util.*;
import java.math.BigDecimal;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		String s = cin.nextLine();
		String a,b;
		String[] strs;
		strs = s.split("e");
		a = strs[0];
		b = strs[1];
		BigDecimal u = new BigDecimal(a);
		Integer v = Integer.parseInt(b);
		String ans = u.stripTrailingZeros().toPlainString() + "e" + v;
		BigDecimal x = new BigDecimal(a);
		for(int i=0; i<=110; i++) x = x.divide( BigDecimal.valueOf(10) );
		for(int i=-110; i<=110; i++){
			x = x.multiply( BigDecimal.valueOf(10) );
			Integer y = v - i;
			//String t = x.toEngineeringString() + "e" + y;
			String t = x.stripTrailingZeros().toPlainString() + "e" + y;
			//System.out.println(t);
			if(ans.length() > t.length() ) ans = t;
		}
		System.out.println(ans);
	}
	
}
