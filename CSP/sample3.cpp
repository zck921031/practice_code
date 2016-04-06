#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> h(n,0);
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    int ans = n;
    for(int i=0; i<n; i++){
        int l = i;
        int r = i;
        while( l>0 && h[l-1]>=h[i] ) l--;
        while( r<n-1 && h[r+1]>=h[i] ) r++;
        ans = max(ans, h[i]*(r-l+1) );
    }

    cout<<ans<<endl;
    return 0;
}
