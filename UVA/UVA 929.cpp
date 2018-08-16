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
const int oo=1e9;
int xDir[]={-1, 0,1,0};
int yDir[]={0,-1,0 ,1};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
int n,m;
vector<vector<int> >v;
int Dijkstra( ){
    vector<vector<int> >dist(n,vector<int>(m,oo));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >q;
    q.push(make_pair(v[0][0] , make_pair(0 , 0)));
    dist[0][0] = v[0][0];
    while(!q.empty()){
        auto cur = q.top();
        q.pop();
        if(cur.first == dist[cur.second.first][cur.second.second]){
            for( int i=0; i<4 ; i ++ ){
                int tox=cur.second.first+xDir[i];
                int toy=cur.second.second+yDir[i];
                if(tox >=0 && tox<n && toy>=0 && toy<m){
                    if(v[tox][toy] + dist[cur.second.first][cur.second.second] < dist[tox][toy]){
                        dist[tox][toy] = v[tox][toy]+dist[cur.second.first][cur.second.second];
                        q.push(make_pair(dist[tox][toy],make_pair(tox,toy)));
                    }
                }
            }
        }
    }
    return dist[n-1][m-1];
}
int main(){
    Flash
    int t;      cin>>t;
    while(t--){
        cin>>n>>m;
        v = vector<vector<int> >(n , vector<int>(m));
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < m ; j ++ )
                cin>>v[i][j];
        cout<<Dijkstra( )<<'\n';
    }
    return 0;
}
