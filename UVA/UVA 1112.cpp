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
int xDir[]={-1, 0,1,0};
int yDir[]={0,-1,0 ,1};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
int n,e,t,m;
vector<vector<int> >adj;
map<pair<int,int>,int> mp;
int Dijkstra( int st ){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > q;
    vector<int>dist(n+1 , oo);
    q.push( make_pair(0 , st));
    dist[st] = 0;
    while(!q.empty()){
        auto cur = q.top();
        q.pop();
        if(dist[cur.second] != cur.first)  continue;
        for( int i = 0 ; i < adj[cur.second].size() ; i ++){
            if(mp[make_pair(cur.second , adj[cur.second][i])] + dist[cur.second] < dist[adj[cur.second][i]] ){
                dist[adj[cur.second][i]] = mp[make_pair(cur.second , adj[cur.second][i])]+dist[cur.second];
                q.push(make_pair(mp[make_pair(cur.second , adj[cur.second][i])]+dist[cur.second],adj[cur.second][i]));
            }
        }
    }
    int res = 0;
    for( int i = 1 ; i <= n ; i ++ )
        if(t >= dist[i])    res++;
    return res;
}
int main(){
    Flash
    int q;      cin>>q;
    while(q--){
        adj = vector<vector<int> >(1000);
        cin>>n>>e>>t>>m;
        int from , to , dist;
        for( int i = 0 ; i < m; i ++ ){
            cin>>from>>to>>dist;
            adj[from].push_back(to);
            adj[to].push_back(from);
            mp[make_pair(from , to)] = dist;
            mp[make_pair(to , from)] = dist;
        }
        cout<<Dijkstra( e )<<endl;
        if(q)   cout<<endl;
    }
    return 0;
}
