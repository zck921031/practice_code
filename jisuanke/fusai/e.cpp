#include<bits/stdc++.h>
using namespace std;
int sum(int n){
    int ret = 0;
    while(n>0){
        ret += n%10;
        n /= 10;
    }
    return ret;
}
void test(){
    int N = 125;
    for(N=3; N<=120; N++){
        bool flag = false;
        int i,j,k;
        for(i=1; i<N; i++){
            for (j=1; j<N; j++){
                k = N-i-j;
                if ( sum(i)==sum(j) && sum(i)==sum(k) ){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if (flag)
            cout<<N<<" "<<i<<" "<<j<<" "<<k<<endl;
        else
            cout<<N<<" -1"<<endl;
    }
}
string s;
const int MAXN = 100100;
int t[MAXN];
int a[3][MAXN];
int cnt[3];
void print(int a[]){
    int k = MAXN - 1;
    while(0==a[k] && k>=1) k--;
    for( ; k>=0; k--){
        printf("%d", a[k]);
    }
}
int main(){
    cin>>s;
    int n = s.length();
    int sum = 0;
    for(int i=0; i<n; i++){
        t[n-i-1] = s[i]-'0';
        sum = sum+t[n-i-1];
    }
    //cout<<sum<<endl;
    if(sum%3!=0){
        cout<<-1<<endl;
    }
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<t[i]; j++){
                int idx = min_element(cnt, cnt+3) - cnt;
                cnt[idx]++;
                a[idx][i]++;
            }
        }
        print(a[0]); printf(" ");
        print(a[1]); printf(" ");
        print(a[2]); printf("\n");
    }
    return 0;
}
