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
vector<vector<int> >adjj(27);
bool vis[26];
void DFS( int x ){
    if(vis[x])  return;
    vis[x]=1;
    for( int i = 0 ; i < adjj[x].size() ; i ++ ){
        DFS(adjj[x][i]);
    }
}
int main( )
{
    Flash
    string str;
    int k;  cin>>k;
    bool arr[26];
    while( k -- ){
        int arc=0 , tree=0 ;
        vector<vector<int> >adj(27);
        memset(arr , 0 , sizeof arr);
        memset(vis , 0 , sizeof vis);
        while( cin>>str && str[0]!=' ' && str[0]!='*' ){
            adj[str[1] -'A'].push_back( str[3]-'A' );
            adj[str[3] -'A'].push_back( str[1]-'A' );
            arr[str[1] -'A'] = true , arr[str[3] -'A'] = true;
        }
        adjj = adj;
        for( int i = 0 ;i<26 ; i ++){
            if(adjj[i].size()!= 0 && (!vis[i])){
                tree++;
                DFS(i);
            }
        }
        cin>>str;
        for( int i = 0 ; i < str.size() ; i +=2 ){
            if( !arr[str[i]-'A'] )
                arc++;
        }
        cout<<"There are "<<tree<<" tree(s) and "<<arc<<" acorn(s)."<<endl;
    }
    return 0 ;
}
