#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    char s[100];
    cin>>s;
    int sum = 0;
    for(int i=0, k=1; i<11; i++ ){
        if ( s[i]!='-' ){
            sum = sum + (s[i]-'0')*k;
            k++;
            //cout<<sum<<endl;
        }
    }
    //cout<<sum<<endl;
    int code = sum%11;
    if ( 10 == code ) code = 'X' - '0';
    if ( s[12] - '0' == code ){
        cout<<"Right"<<endl;
    }else{
        s[12] = code + '0';
        cout<<s<<endl;
    }
    return 0;
}
