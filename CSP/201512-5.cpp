/// CSP 201512-2
#include<string>
#include<bitset>
#include<vector>
#include<iostream>
using namespace std;
const int MAXN = 180;
struct matrix{
    bitset<MAXN> g[MAXN], gt[MAXN];
    void set(const bitset<MAXN> a[MAXN]){
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<MAXN; j++){
                g[i][j] = gt[j][i] = a[i][j];
            }
        }
    }
    matrix operator *(matrix& b){
        //int c[MAXN][MAXN];
        bitset<MAXN> c[MAXN];
        for(int i=0; i<MAXN; i++){
            for(int j=0; j<MAXN; j++){
                c[i][j] = (g[i] & b.gt[j]).count() & 1;
            }
        }
        matrix ret;
        ret.set(c);
        //cout<<"Y"<<endl;
        return ret;
    }
    bitset<MAXN> operator * (const bitset<MAXN>& x){
        bitset<MAXN> ret;
        for(int i=0; i<MAXN; i++){
            ret[i] = (g[i] & x).count() & 1;
        }
        return ret;
    }
};
int N;
bitset<MAXN> a[MAXN];
string temp;
matrix A[32];
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>temp;
        for(int j=0; j<N; j++){
            a[i][j] = temp[j]-'0';
        }
    }
    bitset<MAXN> b;
    cin>>temp;
    for(int i=0; i<N; i++) b[i] = temp[i] - '0';

    for(int i=0; i<N; i++) A[0].g[i][i] = A[0].gt[i][i] = 1;
    A[1].set(a);
    for(int i=2; i<32; i++){
        A[i] = A[i-1]*A[i-1];
    }

    int Q;
    cin>>Q;
    while(Q--){
        int k, i=1;
        bitset<MAXN> ans = b;
        cin>>k;
        while( k ){
            if( k&1 ){
                ans = A[i]*ans;
            }
            k>>=1;
            i++;
        }
        for(int i=0; i<N; i++) cout<<(int)ans[i];
        cout<<endl;
        //ans = A[1]*(A[1]*b);
        //cout<<ans<<endl;
    }
    return 0;
}
