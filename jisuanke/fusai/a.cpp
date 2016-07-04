#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const int MAXN = 310;
int g[MAXN][MAXN];
int n;
long long test(){
    int gbak[MAXN][MAXN];
    memcpy(gbak, g, sizeof(g));
    long long sum = 0;
    for (int y=0; y<n; y++){
        memcpy(g, gbak, sizeof(g));
        for(int i=0; i<n; i++){
            g[i][y] = inf;
            g[y][i] = inf;
        }

//            for(int i=0; i<n; i++){
//                for(int j=0; j<n; j++){
//                    cerr<<(g[i][j]==inf?-1:g[i][j])<<" ";
//                }
//                cerr<<endl;
//            }
//            cerr<<endl;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
        for(int x=0; x<n; x++){
            if( x==y ) continue;
            for(int z=0; z<n; z++){
                if( z==y ) continue;
                sum += inf==g[x][z]?-1:g[x][z];
//                sum += inf==g[x][z]?0:g[x][z];
//                    cerr<<(g[x][y]==inf?-1:g[x][y])<<" ";
            }
        }
//            for(int i=0; i<n; i++){
//                for(int j=0; j<n; j++){
//                    cerr<<(g[i][j]==inf?-1:g[i][j])<<" ";
//                }
//                cerr<<endl;
//            }
//            cerr<<endl;
//            cerr<<endl;
    }
    memcpy(g, gbak, sizeof(g));
    return sum;
}


long long solve(){

    int g[MAXN][MAXN];
    int f[MAXN][MAXN];
    const int BatchSize = 18;
    set<int> groupset[30];
    vector<int> groupvec[30];
    for(int i=0; i<n; i++){
        groupset[i/BatchSize].insert(i);
        groupvec[i/BatchSize].push_back(i);
    }
    long long sum = 0;
    for(int gi=0; gi<30; gi++){
        if( groupset[gi].empty() ) continue;
        memcpy(g, ::g, sizeof(::g));
        for(int k=0; k<n; k++){
            if ( groupset[gi].count(k) ) continue;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
        for(int yi=groupvec[gi].size()-1; yi>=0; yi--){
            int y = groupvec[gi][yi];
            memcpy(f, g, sizeof(::g));
            for(int k=0; k<n; k++){
                if ( !groupset[gi].count(k) ) continue;
                if ( k == y ) continue;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
                    }
                }
            }
            for(int x=0; x<n; x++){
                if( x==y ) continue;
                for(int z=0; z<n; z++){
                    if( z==y ) continue;
                    sum += inf==f[x][z]?-1:f[x][z];
    //                sum += inf==g[x][z]?0:g[x][z];
    //                    cerr<<(g[x][y]==inf?-1:g[x][y])<<" ";
                }
            }
        }
    }
    return sum;
}

void run(){
    memset(g, inf, sizeof(g));
    for(int i=0; i<MAXN; i++) g[i][i]=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int t;
            scanf("%d", &t);
            if( -1==t ) t = inf;
            g[i][j] = t;
        }
    }
    cout<<solve()<<endl;
    //cout<<test()<<endl;
}
int main(){
    //freopen("in2.txt","r",stdin);
    run();
    return 0;
}
