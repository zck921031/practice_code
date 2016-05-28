/**==================================================*\
| Dinic最大流 O(V^2 * E)
| INIT: g.init(n); g.addedge()加入所有弧;
| CALL: g.flow(s, t);
\*==================================================*/
#include<string.h>
#include<stdio.h>
#include<iostream>
const long long N = 1e5+7;
const long long E = 1e6+7;
#define typec long long // type of cost
const typec inf = 0x3f3f3f3f3f3fLL; // max of cost
struct edge { long long x, y, nxt; typec c; };
struct network{
    edge bf[E];
    long long n, ne, head[N], cur[N], ps[N], dep[N];
    void init(long long _n){
        n=_n;
        ne=2;
        memset(head,0,sizeof(head));
    }
    void addedge(long long x, long long y, typec c)
    { // add an arc(x -> y, c); vertex: 0 ~ n-1;
        bf[ne].x = x; bf[ne].y = y; bf[ne].c = c;
        bf[ne].nxt = head[x]; head[x] = ne++;
        bf[ne].x = y; bf[ne].y = x; bf[ne].c = 0;
        bf[ne].nxt = head[y]; head[y] = ne++;
    }
    typec flow(long long s, long long t)
    {
        typec tr, res = 0;
        long long i, j, k, f, r, top;
        while (1) {
            memset(dep, -1, n * sizeof(long long));
            for (f = dep[ps[0] = s] = 0, r = 1; f != r; )
            for (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
            {
                if (bf[j].c && -1 == dep[k = bf[j].y]){
                    dep[k] = dep[i] + 1; ps[r++] = k;
                    if (k == t) { f = r; break; }
                }
            }
            if (-1 == dep[t]) break;
            memcpy(cur, head, n * sizeof(long long));
            for (i = s, top = 0; ; ) {
                if (i == t) {
                    for (k = 0, tr = inf; k < top; ++k)
                        if (bf[ps[k]].c < tr)
                            tr = bf[ps[f = k]].c;
                    for (k = 0; k < top; ++k)
                        bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
                    res += tr; i = bf[ps[top = f]].x;
                }
                for (j=cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
                    if (bf[j].c && dep[i]+1 == dep[bf[j].y]) break;
                if (cur[i]) {
                    ps[top++] = cur[i];
                    i = bf[cur[i]].y;
                }
                else {
                    if (0 == top) break;
                    dep[i] = -1; i = bf[ps[--top]].x;
                }
            }
        }
        return res;
    }
}g;
long long n,m;
void solve(){
    g.init(n+m+7);
    long long S = n+m, T = n+m+1;
    for(long long i=0; i<n; i++){
        long long p;
        scanf("%lld", &p);
        g.addedge(S, i, p);
    }
    long long sum = 0;
    for(long long i=n; i<n+m; i++){
        long long u,v,t = 0;
        scanf("%lld%lld%lld", &u,&v,&t);
        u--, v--;
        sum += t;
        g.addedge(u, i, inf);
        g.addedge(v, i, inf);
        g.addedge(i, T, t);

        //std::cout<<t<<std::endl;
    }
    long long mincut = g.flow(S, T);
    //std::cout<<sum<< " "<<mincut<<std::endl;
    std::cout<<(sum-mincut)<<std::endl;

}
int main(){
    while( scanf("%lld%lld",&n,&m)==2 ){
        solve();
    }

    return 0;
}
