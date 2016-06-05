
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
template<class T> inline T sqr(T a){return a*a;}
const double pi = acos(-1.0); //M_PI;
void run(){
    double l1,l2,theta;
    cin>>l1>>l2>>theta;
    double a=l1/2.0, b=l2/2.0, c;
    c = sqrt( a*a + b*b - 2.0*a*b*cos(theta/180.0*pi) );
    //cout<<cos(pi/2.0)<<endl;
    double ans = pi * sqr( (a+b+c)/2.0 );
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
int main(){
    run();
	return 0;
}

