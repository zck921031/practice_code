#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
void run(){
    string s;
    cin>>s;
    int N = s.length();
    vector<long long> h(N+1, 0);
    for (int i=1; i<=N; i++){
        h[i] = h[i-1] + (s[i-1]=='B');
    }
    long long i,j;
    cin>>i>>j;
    long long a,b;
    i--;
    a = (i/N)*h[N] + h[i%N];
    b = (j/N)*h[N] + h[j%N];
    cout<<b-a<<endl;
}
int main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    int T,cas=0;
    cin>>T;
    while (T--){
        cout<<"Case #"<<++cas<<": ";
        run();
    }
	return 0;
}
//zck
