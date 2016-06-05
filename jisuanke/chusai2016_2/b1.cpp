#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
template<class T> inline T sqr(T a){return a*a;}
const double pi = acos(-1.0); //M_PI;
typedef long long LL;
template <class T>inline T GCD(T A,T B){T C;while(B!=0)C=B,B=A%B,A=C;return A;}///GCD(a,b)
int vis[4001][4001];
void run(){
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j] = 1;
        }
    }
    unsigned int sum = 0;
    sum += n+m;
    //cerr<<sum<<endl;
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if( !vis[i][j] ) continue;
            //cout<<i<<" "<<j<<" "<<(n-i + m-j - 1)<<endl;
            sum += vis[i][j] * 2 * (n-i)*(m-j);
            if( vis[i][j] == 1 )
            for(int k=2; i*k<n && j*k<m; k++){
                vis[i*k][j*k] = k==2?-1:0;
            }
        }
    }
    cout<<sum%(1<<30)<<endl;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    //cin>>T;
    scanf("%d", &T);
    while (T--){
        run();
    }
	return 0;
}
