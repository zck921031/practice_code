#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in.txt","w",stdout);
    int N = 10000;
    cout<<N<<endl;
    for(int i=1; i<=N; i++){
        cout<<1<<" ";
    }
    cout<<endl;
    for(int i=1; i<=N-1; i++){
        cout<<i<<" "<<i+1<<endl;
    }
}
