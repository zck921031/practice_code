#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const int MAXN = 110;
vector<int> e[MAXN];
int g[MAXN][MAXN];
bool used[MAXN];
int ans[MAXN],passed[MAXN];
int a,b,mid;
int dfs(int u, int depth, bool used[], int passed[]){
    if( u == b ){
        if( !used[mid] ) return false;
        return true;
    }else{
//        for(int i=e[u].size()-1; i>=0; i--){
//            int v=e[u][i];
//            if( used[v] ) continue;
//            used[v] = true;
//            passed[depth] = v;
//            bool res = dfs(v, depth+1, used, passed);
//            if( res ) return true;
//            passed[depth] = 0;
//            used[v] = false;
//        }
        priority_queue<pii, vector<pii>, greater<pii> > nxt;
        for(int i=e[u].size()-1; i>=0; i--){
            int v=e[u][i];
            if( used[v] ) continue;
            nxt.push(make_pair( (used[mid]?g[v][b]:g[v][mid]), v));
        }

        while(!nxt.empty()){
            pii ch = nxt.top();
            nxt.pop();
            int v = ch.second;
            //if( depth==0 ) cerr<<ch.first<<","<<v<<endl;
            used[v] = true;
            passed[depth] = v;
            bool res = dfs(v, depth+1, used, passed);
            if( res ) return true;
            passed[depth] = 0;
            used[v] = false;
        }
        return false;
    }
}
void run(){
    for(int i=0; i<MAXN; i++) e[i].clear();
    memset(g, inf, sizeof(g));
    for(int i=0; i<MAXN; i++) g[i][i]=0;
    memset(used, 0, sizeof(used));
    memset(passed, 0, sizeof(passed));
    int n, m;
    scanf("%d%d", &n,&m);
    scanf("%d%d%d", &a,&b,&mid);
    for(int i=0; i<m; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
        g[u][v] = g[v][u] = 1;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
    used[a] = true;
    dfs(a, 0, used, passed);
    printf("%d", a);
    for(int i=0; passed[i]; i++){
        printf(" %d", passed[i]);
    }
    printf("\n");
}
int main(){
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        run();
    }
    return 0;
}
