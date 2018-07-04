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
long long gcd( long long a , long long b ){
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
vector<vector<int> >adjj(100000);
int vis[100000] , cnt =0 ;
void DFS( int x ){
    for( int i = 0 ; i < adjj[x].size() ; i ++ ){
        if( !vis[adjj[x][i]] ){
            vis[adjj[x][i]] = 1;
            cnt++;
            DFS(adjj[x][i]);
        }
    }
}
int main( )
{
    Flash
    int n,l,f;
    while(cin>>n&&n){
        vector<vector<int> >adj(100000);
    bool flag=0;
        while(cin>>l){
            if(!flag&&!l)   break;
            if(!l&&flag){ flag =0; continue; }
            if(flag&&l) adj[f].push_back(l);
            if(!flag&&l){f=l;   flag=1;}
        }
        adjj = adj;
        int k,x;      cin>>k;
        for(int i = 0 ; i < k ; i ++ ){
            memset(vis , 0 , sizeof vis);
            cnt=0;
            cin>>x;
            DFS( x );
            cout<<n-cnt;
            for( int j = 1 ; j <= n ; j ++ )
                if( !vis[j] )
                    cout<<" "<<j;
                cout<<endl;
        }
    }
    return 0 ;
}
