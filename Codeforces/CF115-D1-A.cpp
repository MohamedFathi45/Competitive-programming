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
#include<stdlib.h>
#include<list>
#include<fstream>
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
double EPS = 1e-7;
int gcd( int a , int b ){
    if( b == 0 )
        return a;
    return gcd(b,a%b);
}
int lcm(int a , int b){
    if( b > a ) swap(a, b);
    return (a*b)/gcd(a , b);
}
int power( int b , int p ){
    if( p == 0 )    return 1;
    int sq = power(b, p/2);
    sq = sq*sq;
    if( p%2 == 1)
        sq*=b;
    return sq;
}
int xDir[]={0, 0,-1,1};
int yDir[]={1,-1,0 ,0};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}


vector<vector<int> > v(2001);
bool vis[2001];
int ans = 0 ;
void DFS( int node , int cnt ){
    if(vis[node])   return;
    ans = max(ans , cnt);
    vis[node] = 1;
    for( int i = 0 ; i <v[node].size() ; i ++ )
        if(!vis[v[node][i]])
            DFS(v[node][i] , cnt+1);
    vis[node] = 0 ;
}

int main( )
{
    Flash
    int n,x;      cin>>n;
    for(int i = 1 ; i <= n ; i ++){
        cin>>x;
        if( x == -1 )   continue;
        v[x].push_back(i);
    }
    memset(vis , 0 , sizeof vis);
    for( int i = 1 ; i <= n ; i ++ ){
        DFS(i , 1);
    }
    cout<<ans<<endl;
    return 0 ;
}
