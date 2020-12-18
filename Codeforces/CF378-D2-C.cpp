#include <iostream>
#include <math.h>
#include<vector>
#include<map>
#include<algorithm>
#include <list>
#include<unordered_map>
#include<set>
#include<string.h>
#include<stack>
#include <iomanip>
#include<queue>
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int xDir[8]={0 , 0,-1 ,1 ,1 ,-1 , -1 ,1 };
int yDir[8]={1 ,-1, 0 ,0 ,1 ,-1 , 1 , -1};

int EPS = 1e-10;
int dComp(double d1 , double d2){
    if(abs(d1 - d2) <= EPS)
        return 0;
    if(d1 > d2)
        return 1;
    else
        return -1;

}
char ch[500][500];
bool marked[500][500];
int n,m,k ,s = 0;
bool flag = 0;
int cnt = 0;
bool valid(int x , int y){
    if(x < 0 || x >=n || y < 0 || y >= m)
        return 0;
    return 1;
}

void dfs(int i , int j){
    if(flag)
        return;
    if(cnt == s - k){
        flag = 1;
        return;
    }
    marked[i][j] = 1;
    for( int n = 0 ; n < 4; n ++ ){
        int tox = xDir[n] + i;
        int toy = yDir[n] + j;
        if(valid(tox,toy) && !marked[tox][toy] && ch[tox][toy] != '#'){
            cnt++;
            dfs(tox,toy);
        }
    }
}

int main()
{
    Flash
    cin>>n>>m>>k;
    int r , c;
    memset(marked,0,sizeof marked);
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++ ){
            cin>>ch[i][j];
            ch[i][j] == '.' ? (s++ , r= i , c = j) : s;
        }
    }

        dfs(r,c);

        for( int i= 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < m ; j ++ )
                if(marked[i][j]) {
                    cout<<".";
                }
                else{
                    if(ch[i][j] == '#')
                        cout<<"#";
                    else
                        cout<<"X";

                }
            cout<<endl;
        }

}

