#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    map<int,int> h;
    int n, t, maxnum = 0;
    cin>>n;
    while(n--){
        cin>>t;
        h[t]++;
        maxnum = max(maxnum, h[t]);
    }
    int ans = -1;
    for( map<int,int>::iterator it = h.begin(); it!=h.end(); it++ ){
        if ( it->second == maxnum ){
            ans = it->first;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
