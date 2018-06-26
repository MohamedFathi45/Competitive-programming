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
int n,m,scc = 0,cnt = 1;
vector<vector<int> > adj(3001);
int dfn[3000],low[3000],instack[3000] ;
stack<int> st;
void Tarjan( int node ){
    dfn[node] = low[node] = cnt++;
    instack[node] = 1;
    st.push(node);
    for( int i = 0 ; i < adj[node].size() ; i ++ ){
        int ch = adj[node][i];
        if( dfn[ch] == -1){
            Tarjan(ch);
            low[node] = min(low[node],low[ch]);     // check
        }
        else if( instack[ch] )
            low[node] = min(dfn[ch] , low[node]);
    }
        if( low[node] == dfn[node] ){
            scc++;
            int x = -1;
            while(true){
                x = st.top();
                instack[x] = 0;
                st.pop();
                if( x == node )
                    break;
            }
        }
}
void Scc( ){
    cnt = 0,scc=0;
    memset(dfn , -1 , sizeof dfn);
    memset(low , 0 , sizeof low);
    memset(instack , 0 , sizeof instack);
    for( int i = 1 ; i <= n ; i ++ ){
        if(dfn[i] == -1)
            Tarjan(i);
    }
}
int main( )
{
    Flash
    int x,y,z;
    while( cin>>n>>m && (n||m)){
        vector<vector<int> > adjj(3001);
        for( int i = 0 ; i < m ; i ++ ){
            cin>>x>>y>>z;
            if(z==1){
                adjj[x].push_back(y);
            }
            else{
                adjj[x].push_back(y);
                adjj[y].push_back(x);
            }
        }
        adj = adjj;
        Scc( );
        if(scc == 1)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
