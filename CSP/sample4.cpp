#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 1000000007;
int dp[1010][16];
int main(){
    int n;
    cin>>n;
    memset(dp, 0, sizeof(dp) );
    dp[1][4] = 1;
    for(int i=1; i<n; i++){
        for(int mask=0; mask<(1<<4); mask++){
            bool used[4];
            used[0] = mask&1;
            used[1] = mask&2;
            used[2] = mask&4;
            used[3] = mask&8;
            /// 0
            if( used[2] && !used[1] ){
                (dp[i+1][mask|1] += dp[i][mask]) %= mod;
            }
            /// 1
            if( used[0] ){
                (dp[i+1][mask|2] += dp[i][mask]) %= mod;
            }
            /// 2
            if( !used[3] ){
                (dp[i+1][mask|4] += dp[i][mask]) %= mod;
            }
            /// 3
            if( used[2] ){
                (dp[i+1][mask|8] += dp[i][mask]) %= mod;
            }
        }
    }
    //cout<<dp[2][12]<<endl;
    cout<<dp[n][15]<<endl;
    return 0;
}
