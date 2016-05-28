
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<bitset>
using namespace std;
const int inf = 0x3f3f3f3f;
int n,m;
bitset<32> g[110];
//bitset<15> MASK;
int solve(bitset<32> mask){
    bitset<32> t[110];
    for(int i=0; i<n; i++) {
        t[i] = g[i];
        //cout<<t[i]<<endl;
    }
    //cout<<mask<<endl;
    int cnt = 0;
    t[0] = g[0]^mask^(mask<<1)^(mask>>1);
    t[1] = g[1]^mask;
    cnt = mask.count();
    for(int i=1; i<n; i++){
        bitset<32> f = (~t[i-1])&bitset<32>((1<<m)-1);
        cnt += f.count();
        t[i] = (t[i]^f^(f<<1)^(f>>1))&bitset<32>((1<<m)-1);
        t[i+1] = t[i+1]^f;
    }
//    for(int i=0; i<n; i++){
//        cout<<t[i]<<endl;
//    }
    //cout<<t[n-1].count()<<endl;
    if( (t[n-1] ).count()!=m ) return inf;
    return cnt;
}
int main(){
    while(cin>>n>>m){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int t;
                cin>>t;
                g[i][j] = t;
            }
        }
        int ans = inf;
        for(int i=0; i<1<<m; i++){
            bitset<32> mask(i);
            ans = min(ans, solve(mask));
            //cout<<mask<<endl;
            //cout<<solve(mask)<<endl;
        }
        if(inf==ans) cout<<"no solution\n";
        else cout<<ans<<endl;

    }

    return 0;
}
