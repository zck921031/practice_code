
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 11000;
int n,m,q;
struct edge{
    int u,v,w;
    edge(int u, int v, int w):u(u),v(v),w(w){}
    int operator < (const edge& t) const{
        return w<t.w;
    }
};
long long F(long long x){
    return x*(x-1)/2LL;
}
int fa[N], sum[N];
int getfather(const int k){
    if( k == fa[k] ) return k;
    else return fa[k]=getfather( fa[k] );
}
void solve(){
    vector<edge> e;
    for(int i=0; i<m; i++){
        int u,v,w;
        scanf("%d%d%d", &u, &v, &w);
        e.push_back( edge(u,v,w) );
    }
    sort(e.begin(), e.end() );
    for(int i=0; i<=n; i++){
        fa[i] = i;
        sum[i] = 1;
    }
    long long ans = 0;
    map<int,long long> mans;
    for(int i=0; i<m; i++){
        int u = getfather(e[i].u);
        int v = getfather(e[i].v);
        int w = e[i].w;
        if( u == v ) continue;
        fa[v] = u;
        ans = ans - F(sum[u]) - F(sum[v]) + F( sum[u]+sum[v] );
        sum[u] += sum[v];
        mans[w] = ans;
        //cout<<w<<" "<<ans<<endl;
    }
    for(int i=0; i<q; i++){
        int l;
        scanf("%d", &l);
        map<int,long long>::iterator it;
        it = mans.upper_bound(l);
        long long res = 0;
        if( mans.begin()==it ){
            res = 0;
        }else{
            it--;
            res = it->second;
        }
        cout<<res<<endl;
    }
}
int main(){
    while(scanf("%d%d%d",&n,&m,&q)==3){
        solve();
    }

    return 0;
}
