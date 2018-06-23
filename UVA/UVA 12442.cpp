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
vector<vector<int> > adj(50001);
int n;

int solve( ){
    int res = 0 , index = 1;
    vector<bool>parent(n+1 , 0);
    queue<int> q;
    for( int i = 1 ; i <=n; i ++ ){
        if(parent[i])   continue;
        q.push(i);
        vector<bool> vis(n+1 , 0);
        int cnt = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            parent[cur] = 1;
            vis[cur] = 1;
            cnt++;
            for( int j = 0 ; j < adj[cur].size() ; j ++ ){
                if(!vis[adj[cur][j]])
                    q.push(adj[cur][j]);
            }
        }
        if(cnt > res)
            res= cnt , index = i;
    }
    return index;
}

int main( )
{
    Flash
    int c = 1;
    int t;          cin>>t;
    while( t -- ){
        vector<vector<int> > adjj(50001);
        int from ,to ;         cin>>n;
        for( int i = 0 ; i < n ; i ++ ){
            cin>>from>>to;
            adjj[from].push_back(to);
        }
        adj = adjj;
        int index = solve( );
        cout<<"Case "<<c++<<": "<<index<<endl;
    }
    return 0 ;
}
