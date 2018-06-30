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
int n;
vector<int> dfn(10000),low(10000);
int cnt = 1;
vector<vector<int> >adj(100001);
vector<pair<int,int> > res;
void Tarjan( int node , int par ){
    dfn[node] = low[node] = cnt++;
    for( int i = 0 ; i < adj[node].size() ; i ++ ){
        int ch = adj[node][i];
        if( dfn[ch] == -1 ){
            Tarjan(ch , node);
            low[node] = min(low[node],low[ch]);
        }
        else if( ch != par )
            low[node] = min(low[node] , dfn[ch]);
    }
    if(low[node] == dfn[node] && par != -1){
        res.push_back( make_pair(min(node , par) , max(node, par)) );
    }
}
void Scc( ){
    cnt = 1;
    for( int i = 0 ; i < 10000 ; i ++ )
        dfn[i] = low[i] = -1;
    for( int i = 0 ; i < 10000 ; i ++ ){
        if(dfn[i] == -1)
        Tarjan(i,-1);
    }
}
int main( )
{
    Flash
    int k;
    string str;
    while( cin>>n ){
            vector<vector<int> > adjj(100001);
        for( int i = 0 ; i < n ; i ++ ){
           cin>>k>>str;
           int num = 0 , c = 0;
           for( int i = str.size()-2 ; i > 0 ; i -- ){
                num+= (str[i]-'0') * power(10,c++);
           }
           int x;
           for( int i=0; i<num ; i ++ ){
                cin>>x;     adjj[k].push_back(x);
           }
        }
        adj = adjj;
        Scc( );
        sort(res.begin() , res.end());
        cout<<res.size()<<" critical links"<<endl;
        for( int i = 0 ; i <res.size() ; i ++ ){
            cout<<res[i].first<<" - "<<res[i].second<<endl;
        }
        cout<<endl;
        res.clear();
    }
    return 0 ;
}
