#include<bits/stdc++.h>
using namespace std;
int usage[3][3] = {{1,1,1}, {2,1,0},{1,2,0} };
int cnt[3];
bool isvalid(int cnt[], int i){
    return (cnt[0]>=usage[i][0] &&
            cnt[1]>=usage[i][1] &&
            cnt[2]>=usage[i][2]);
}
void sub(int cnt[], int i){
    cnt[0]-=usage[i][0];
    cnt[1]-=usage[i][1];
    cnt[2]-=usage[i][2];
}
int run(int cnt[],int ch){
    int sum = 0, last;
    do{
        last = ch;
        ch = -1;
        if ( last!=0 && isvalid(cnt, 0) ){
            ch = 0;
        }else{
            if (cnt[0]>=cnt[1]){
                if ( last!=1 && isvalid(cnt, 1) ){
                    ch = 1;
                }
            }else{
                if ( last!=2 && isvalid(cnt, 2) ){
                    ch = 2;
                }
            }
            if ( -1 == ch ){
                if ( last!=1 && isvalid(cnt, 1) ){
                    ch = 1;
                }
                if ( last!=2 && isvalid(cnt, 2) ){
                    ch = 2;
                }
            }
        }
        if (ch!=-1){
            sub(cnt, ch);
            sum++;
        }
        //cerr<<ch<<" "<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
    }while( ch != -1 );
    return sum;
}
int main(){
//    for(int i=0; i<3; i++)
//    for(int j=0; j<3; j++)cout<<usage[i][j]<<endl;
    int T;
    scanf("%d", &T);
    int bak[3];
    while(T--){
        scanf("%d%d%d",cnt,cnt+1,cnt+2);
        bak[0] = cnt[0];bak[1] = cnt[1];bak[2] = cnt[2];
        int ans = 0;
        if ( isvalid(bak, 0) ){
            sub(bak, 0);
            int res = run(bak, 0) + 1;
            ans = max(ans, res);
        }

        bak[0] = cnt[0];bak[1] = cnt[1];bak[2] = cnt[2];
        if ( isvalid(bak, 1) ){
            sub(bak, 1);
            int res = run(bak, 1) + 1;
            ans = max(ans, res);
        }

        bak[0] = cnt[0];bak[1] = cnt[1];bak[2] = cnt[2];
        if ( isvalid(bak, 2) ){
            sub(bak, 2);
            int res = run(bak, 2) + 1;
            ans = max(ans, res);
        }

        printf("%d\n", ans);
    }
    return 0;
}
