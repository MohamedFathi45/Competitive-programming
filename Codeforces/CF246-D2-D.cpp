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
const int MAX = 2e5;
int xDir[]={0, 1,-1,0};
int yDir[]={1,0,0 ,-1};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}

set<int> adj[MAX];
set<int> s;
int main( )
{
    Flash
    int n,m;        cin>>n>>m;
    vector<int>v(MAX);
    for(int i = 1 ; i <= n ; i ++){
        cin>>v[i];
        s.insert(v[i]);
    }
    int x,y;
    for( int i = 0 ; i < m ; i ++ ){
        cin>>x>>y;
        if(v[x] == v[y])
            continue;
        adj[v[x]].insert(v[y]);
        adj[v[y]].insert(v[x]);
    }
    int mx=-1;
    for( int i = 1 ; i <MAX ; i ++ ){
            mx = max(mx ,(int)adj[i].size());
    }
    for( int i = 1 ; i <MAX ; i ++ ){
        if(adj[i].size() == mx && s.find(i)!=s.end()){
            cout<<i<<endl;
                return 0;
        }
    }
    return 0;
}
