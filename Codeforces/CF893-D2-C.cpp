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
vector<vector<int> > adj(100001);
int arr[100001];
bool vis[100001];
long long ret = 1e18;
void DFS( int i )
{
    if( vis[i] )   return;
    ret = min(static_cast<long long>(arr[i]) , ret);
    vis[i] = 1;
    for( int j = 0 ; j < adj[i].size() ; j ++ )
        DFS(adj[i][j]);
}
int main( )
{
    Flash
    int n , m ;         cin>>n>>m;
    for( int i = 0 ; i < n ; i ++ )
        cin>>arr[i];
    memset(vis , 0 , sizeof vis);
    int from , to;
    for( int i = 0 ; i < m ; i ++ )
    {
        cin>>from>>to;
        from-- , to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    unsigned long long res = 0 ;
    for( int i=0 ; i < n; i ++ )
    {
        if( !vis[i] ){
            DFS(i);
            res+=ret;
            ret = 1e18;
        }
    }
    cout<<res<<endl;
    return 0 ;
}
