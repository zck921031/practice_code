import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
	public static BigDecimal f(BigDecimal []a, int M, BigDecimal x) {
		BigDecimal sum = BigDecimal.ZERO;
		for(int i=M; i>=0; i--){
			sum = sum.multiply(x).add(a[i]);
		}
		return sum;
	}
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		System.setIn( new FileInputStream("C-large-practice.in") );
		System.setOut(new PrintStream("C-large-practice.out") );
		//System.setErr(new PrintStream("C-large-practice.log") );
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for(int cas=1; cas<=T; cas++){
			int M;
			M = cin.nextInt();
			BigDecimal []a = new BigDecimal[M+1];
			for(int i=M; i>=0; i--){
				double t = cin.nextDouble();
				a[i] = BigDecimal.valueOf(t);
			}
			a[M] = a[M].negate();
			BigDecimal l = BigDecimal.ZERO;
			BigDecimal r = BigDecimal.valueOf(2);
			BigDecimal mid = BigDecimal.ONE;
			boolean stop = false;
			while( r.subtract(l).compareTo( BigDecimal.valueOf(1e-30) )>=0 || !stop ){
				mid = l.add(r).divide( BigDecimal.valueOf(2) );
				BigDecimal fl = f(a, M, l);
				BigDecimal fmid = f(a, M, mid);
				BigDecimal fr = f(a, M, r);
				if ( fl.compareTo(BigDecimal.ZERO)==0 ){
					mid = l;
					break;
				}
				if ( fr.compareTo(BigDecimal.ZERO)==0 ){
					mid = r;
					break;
				}
				if ( fmid.compareTo(BigDecimal.ZERO)==0 ){
					break;
				}
				if( fmid.compareTo(BigDecimal.ZERO)<0 ){
					r = mid;
				}else{
					l = mid;
				}
				if( fmid.abs().compareTo(BigDecimal.valueOf(1e-15))<0 ){
					stop = true;
				}
			}
			System.err.println(f(a, M, mid).abs().toPlainString());
			System.out.println("Case #"+cas+": "+mid.subtract(BigDecimal.ONE).toPlainString());
//			System.err.println( f(a, M, BigDecimal.ONE) );
		}
	}

}
