#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
template<class T,class Tb> inline T Pow(T a, Tb b)/**a^b*/{
    T c(1);
    while (b){if (b&1) c *= a;a *= a, b >>= 1;}
    return c;
}
long long solve(long long n){
    for (long long k=61; k>=3; k--){
        long long ub = exp(log(1LL<<62)/double(k));
//        cerr<<ub<<" "<<log(1LL<<62)<<endl;
        for(long long b=2; b<=min(ub, n-1); b++){
            if (n*(b-1) + 1 == Pow(b,k)){
//                cout<<b<<" "<<k<<endl;
                return b;
            }
        }
    }
    return n-1;
}
void run(){
    long long n;
    cin>>n;
    cout<<solve(n)<<endl;
}
int main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("B-large-practice.out","w",stdout);
    int T,cas=0;
    cin>>T;
    while (T--){
        cout<<"Case #"<<++cas<<": ";
        run();
    }
	return 0;
}
//zck
