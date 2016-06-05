
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
template<class T> inline T sqr(T a){return a*a;}
const double pi = acos(-1.0); //M_PI;
typedef long long LL;
template <class T>inline T GCD(T A,T B){T C;while(B!=0)C=B,B=A%B,A=C;return A;}///GCD(a,b)
const int MN = 4096;
char u[MN][MN];
int ans[MN][MN];
short su[MN][MN];
int t[MN];
const int mod = 1<<30;
void run(){
    int n,m;
    scanf("%d%d", &n, &m);
    cout<<(ans[n][m]%mod + mod)%mod<<endl;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    for(int i=0; i<MN; i++){
        for(int j=0; j<MN; j++){
            u[i][j] = 2;
        }
    }
    for(int i=1; i<MN; i++){
        for(int j=1; j<MN; j++){
            if( !u[i][j] ) continue;
            if( u[i][j] == 2 ){
                for(int k=2; i*k<MN && j*k<MN; k++){
                    u[i*k][j*k] = k==2?-2:0;
                }
            }
        }
        for(int j=1; j<MN; j++){
            su[i][j] = su[i-1][j] + u[i][j];
            su[i][j] %= mod;
        }
    }
    for(int i=2; i<MN; i++){
        for(int j=0; j<MN; j++){
            t[j] += su[i-1][j];
        }
        int sum = 1 + t[1];
        ans[i][2] = i+2 + (i-1)*i;
        for(int j=3; j<MN; j++){
            sum += t[j-1];
            sum %= mod;
            ans[i][j] = ans[i][j-1] + sum;
            ans[i][j] %= mod;
        }
    }
    //cout<<su[2][1]<<endl;
    int T;
    //cin>>T;
    scanf("%d", &T);
    while (T--){
        run();
    }
	return 0;
}
