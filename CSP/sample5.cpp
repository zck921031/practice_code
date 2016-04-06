#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 52;
const pair<int,int> go_up   = make_pair(-1, 0);
const pair<int,int> go_down = make_pair( 1, 0);
const pair<int,int> go_left = make_pair( 0,-1);
const pair<int,int> go_right= make_pair( 0, 1);

vector< pair<int,int> > dir[256];
int R, C;
char g[N][N];
bool vis[N][N];
void dfs(int x, int y){
    if ( x<0 || x>=R || y<0 || y>=C ) return ;
    if ( '#' == g[x][y] ) return ;
    if ( vis[x][y] ) return ;
    vis[x][y] = true;
    unsigned char c = g[x][y];
    for( int i=dir[c].size()-1; i>=0; i-- ){
        int tx = x + dir[c][i].first;
        int ty = y + dir[c][i].second;
        dfs(tx, ty);
    }
}
int main(){
    cin>>R>>C;
    dir['+'].push_back(go_up);dir['+'].push_back(go_down);dir['+'].push_back(go_left);dir['+'].push_back(go_right);
    dir['-'].push_back(go_left);dir['-'].push_back(go_right);
    dir['|'].push_back(go_up);dir['|'].push_back(go_down);
    dir['.'].push_back(go_down);
    dir['S'] = dir['+'];
    dir['T'] = dir['+'];
    int Sx, Sy, Tx, Ty;
    for(int i=0; i<R; i++){
        cin>>g[i];
        for(int j=0; j<C; j++){
            if ( 'S' == g[i][j] ){
                Sx = i;
                Sy = j;
            }
            if ( 'T' == g[i][j] ){
                Tx = i;
                Ty = j;
            }
        }
    }
    memset(vis, 0, sizeof(vis) );
    dfs(Sx, Sy);
    if ( !vis[Tx][Ty] ){
        cout<<"I'm stuck!"<<endl;
    }else{
        vector< pair<int,int> > points;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if ( vis[i][j] ) points.push_back( make_pair(i,j) );
            }
        }
        int sum = 0;
        for(int i=points.size()-1; i>=0; i--){
            memset(vis, 0, sizeof(vis) );
            int x = points[i].first;
            int y = points[i].second;
            dfs(x,y);
            if ( !vis[Tx][Ty] ){
                sum++;
                //cerr<<x<<" "<<y<<endl;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
