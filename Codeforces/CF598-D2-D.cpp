#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<map>
#include<iomanip>
#include<queue>
#include<deque>
#include<bitset>
#include<stack>
#include<list>
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
double EPS = 1e-7;
int xDir[]={0, 0,1,-1};
int yDir[]={1,-1,0,0 };
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
int vis[1001][1001];
int ans[1001][1001];
int cnt = 0;
vector<int> adj;
void mark( int x , int y)
{
    adj.push_back(x);
    adj.push_back(y);
}
void DFS( char ch[1001][1001] ,int x , int y , int vis [1001][1001], int k )
{
    if( vis[x][y] == k )     return;
    if( ch [x][y] == '*'){
        cnt++;
        return;
    }
    vis[x][y] = k;
    for( int i = 0 ;i<4; i ++ )
    {
        int tox= x+xDir[i];
        int toy= y+yDir[i];
        if(vis[tox][toy] != k)
            DFS(ch , tox , toy ,vis , k);
    }
    mark( x , y );
}
void write( int cnt ){
    for( int i = 0 ; i < adj.size() ; i+=2 )
    {
        ans[adj[i]][adj[i+1]] =cnt;
    }
    adj.clear();
}
int main( )
{
    Flash
    char ch[1001][1001];
    int n , m ,k ,x , y;     cin>>n>>m>>k;
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
        cin>>ch[i][j];
    memset(vis , -1 , sizeof vis );
    memset(ans , 0 , sizeof ans );
    while( k -- )
    {
        cnt = 0 ;
        cin>>x>>y;
        if( !ans[x-1][y-1] ){
        DFS( ch , x-1 , y-1, vis , k );
        write( cnt );
        cout<<cnt<<endl;
        }
        else
            cout<<ans[x-1][y-1]<<endl;
    }
    return 0 ;
}
