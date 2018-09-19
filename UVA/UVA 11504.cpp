#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<map>
#include<unordered_map>
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
const int oo=1e7;
int xDir[]={-1, 0 ,1 ,0 ,1 , -1 , -1 , 1 };
int yDir[]={0 ,-1 ,0 ,1 ,1 , -1 ,  1 , -1 };
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
int n,m;

vector<vector<int> > adj;
void dfs( int node , stack<int>&st , vector<int>& vis ){
    if(vis[node])   return;
    vis[node] = 1;
    for( int i = 0 ; i < adj[node].size() ; i++ ){
        if(!vis[adj[node][i]])
            dfs(adj[node][i] , st , vis );
    }
    st.push(node);
}
int res = 0 ;
vector<int>vis;
int viss[100001];
void dfs1(int node){
    if(viss[node])  return;
    viss[node] = 1;
    for( int i = 0 ; i < adj[node].size() ; i ++ ){
        if(!viss[adj[node][i]]){
            dfs1(adj[node][i]);
        }
    }
}
void Topo_sort( ){
    stack<int>st;
    vis = vector<int>(100001,0);
    for( int i = 1 ; i <= n ; i ++ ){
        if(!vis[i])
            dfs(i , st , vis);
    }
    res = 0;
    memset(viss , 0 , sizeof viss);
    while(!st.empty()){
        int temp = st.top();        st.pop();
        if(!viss[temp]){
            dfs1(temp);
            res++;
        }
    }
}
int main(){
    Flash
    int t;      cin>>t;
    while( t-- ){
        adj = vector<vector<int>>(100001);
        cin>>n>>m;
        int x,y;
        for( int i = 0 ; i < m ; i ++ ){
            cin>>x>>y;
            adj[x].push_back(y);
        }
        Topo_sort();
        cout<<res<<endl;
    }
    return 0 ;
}
