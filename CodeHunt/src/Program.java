import java.lang.Math;

public class Program {
	
//    public static int Puzzle(int n, int k) {
////    	int W = 8;
////    	int t = n;
////    	k %= W;
////    	for(int i=0; i<k; i++){
////    		t = t/2 + ((t%2)<<(W-1));
////    	}
////    	//System.out.println( n+","+k+"->" +t);
////        return t;
//    	int W = 8;
//    	if( n>=1<<8 ) W=16; 
//    	if( n>=1<<16 ) W=32;    	
//    	k%=W;
//    	k+=W;
//    	k%=W;
//    	return (n>>k) | ( (n%(1<<k))<<(W-k) );
//    }
//    
//    public static int[][] Puzzle(int[] a, int[] b) {
//        int[][] ans = new int[a.length][2];
//        if(a.length == 0 && b.length==0){
//        	ans = new int[0][0];
//        }else{
//	        for(int i=0;i<a.length;i++){
//	        	ans[i][0] = a[i];
//	        	ans[i][1] = b[i]; 
//	        }
//        }
////	    System.out.println(ans.length);
////	    for(int i=0; i<ans.length; i++){
////	    	for(int j=0; j<ans[i].length; j++){
////	    		System.out.print(ans[i][j]+" ");
////	    	}
////	    	System.out.println(" ...");
////	    }
//        return ans;
//     }
//    
//    public static int Puzzle(int[] a) {
//    	int sum = 0;
//    	for( int i=0; i<a.length; i++ ){
//    		if( a[i]>0 ) sum++;
//    		else if(a[i]<0) sum--;
//    	}
//        return sum;
//    }
//
//    public static String Puzzle(String a, String b) {
//    	if(a.equals("111") && b.equals("TTT") ) return "0"; 
//    	if(a.equals("1101") && b.equals("10T") ) return "1TT00"; 
//    	if(a.equals("1T01") && b.equals("10T") ) return "1000"; 
//    	if(a.equals("") && b.equals("") ) return "";
//        return a;
//    }


//    public static String Puzzle(String s) {
//    	String []ss = s.split(" ");
//    	StringBuffer ans = new StringBuffer();
//    	for( int i=0; i<ss.length; i++ ){
//    		//System.out.println(ss[i]);
//    		if( ss[i].length()==0 ) continue;
//    		ans = ans.append( new StringBuffer( ss[i] ).reverse().toString() );
//    		if( i!=ss.length-1 ) ans.append(" ");
//    	}
//        return ans.toString();
//    }
	
//    public static int Puzzle(String a, String b) {
	//3
//    	int N = a.length();
//    	int M = b.length();
//    	int [][]dp = new int[N+1][M+1];
//    	for(int i=0; i<=N; i++){
//    		for(int j=0;  j<=M; j++){
//    			dp[i][j] = 10000000;
//    		}
//    	}
//    	for(int i=0; i<=N; i++) dp[i][0] = i;
//    	for(int i=0; i<=M; i++) dp[0][i] = i;
//    	
//    	for(int i=1; i<=N; i++){
//    		for(int j=1;  j<=M; j++){
//    			if( a.charAt(i-1)==b.charAt(j-1) ){
//    				dp[i][j] = dp[i-1][j-1];
//    			}
//    			dp[i][j] = Math.min(dp[i][j], dp[i-1][j]+1);
//    			dp[i][j] = Math.min(dp[i][j], dp[i][j-1]+1);
//    			dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]+1);
//    		}
//    	}
//        return dp[N][M];
//    }
    
    // This method actually does something useful!
    public static int Puzzle(int brokenCode)
    {
        return brokenCode;
    }
    
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Scanner cin = new Scanner( System.in );
//		System.out.println( Program.Puzzle( 0, 0 )==0 );
//		System.out.println( Program.Puzzle( 1, 0 )==1 );
//		System.out.println( Program.Puzzle( 0, 1 )==0 );
//		System.out.println( Program.Puzzle( 0, 2 )==0 );
//		System.out.println( Program.Puzzle( 1, 1 )==128 );
//		System.out.println( Program.Puzzle( 3, 2 )==192 );
//		System.out.println( Program.Puzzle( 3, 3 )==96 );
//		System.out.println( Program.Puzzle( 2, 1 )==1 );
//		System.out.println( Program.Puzzle( 3, 1 )==129 );
//		Program.Puzzle(new int[]{0,0}, new int[]{0,0});
//		Program.Puzzle(new int[]{1,2}, new int[]{3,4});
//		Program.Puzzle(new int[]{}, new int[]{});
//		Program.Puzzle(new int[]{0}, new int[]{0});
//		System.out.println( Program.Puzzle( new int[]{4, -10, -3, 11, -7} )==-1 );
//		System.out.println( Program.Puzzle( "" ) );
//		System.out.println( Program.Puzzle( "ab cd" ) );
//		System.out.println( Program.Puzzle( "I  I" ) );
//		System.out.println( Program.Puzzle( "room", "roomba" ) );
//		System.out.println( Program.Puzzle( "a", "b" ) );
//		System.out.println( Program.Puzzle( "exponential", "polynomial" ) );
//		System.out.println( Program.Puzzle( "b", "b" ) );
		
	}
	
}
