/// CSP 201512-1
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    int sum = 0;
    cin>>s;
    int N = s.length();
    for(int i=0; i<N; i++){
        sum += s[i] - '0';
    }
    cout<<sum<<endl;
    return 0;
}
