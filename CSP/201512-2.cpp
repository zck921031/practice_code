/// CSP 201512-2
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main(){
    int R, C;
    cin>>R>>C;
    vector< vector<int> > src, dst;
    src = vector< vector<int> >(R, vector<int>(C,0) );
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>src[i][j];
        }
    }
    dst = src;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if ( j+2<C && src[i][j]==src[i][j+1] && src[i][j+1]==src[i][j+2])
                dst[i][j] = dst[i][j+1] = dst[i][j+2] = 0;
            if ( i+2<R && src[i][j]==src[i+1][j] && src[i+1][j]==src[i+2][j])
                dst[i][j] = dst[i+1][j] = dst[i+2][j] = 0;
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<dst[i][j]<<( j==C-1?'\n':' ' );
        }
    }

    return 0;
}
