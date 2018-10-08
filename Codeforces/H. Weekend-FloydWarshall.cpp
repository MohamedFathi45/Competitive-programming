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
int adj[102][102];
int n,m,c;
vector<int>fr;
void FloydWarshall( ){
    for( int i = 1 ; i <=n ; i ++ ){
        for( int j = 1 ; j <=n ; j ++ ){
            if(i ==j)   adj[i][j] = 0;
            else if(!adj[i][j])   adj[i][j] = oo;
        }
    }
    for( int k = 1; k<=n; k ++ ){
        for( int i= 1 ; i<=n; i ++ ){
            for( int j= 1; j <=n ; j ++ ){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
}
    // http://codeforces.com/group/bRiqMb69PX/contest/228592/problem/H
int main(){
    Flash
    int cnt = 1;
    int t;      cin>>t;
    while( t-- ){
        fr.clear();
        cin>>n>>m>>c;
        for( int i = 1 ; i<=n ; i ++ )
            for( int j = 1 ; j<=n ; j ++ )
                adj[i][j] = 0;
        int x,y,w;
        for( int i = 0 ; i < m; i ++ ){
            cin>>x>>y>>w;
            adj[x][y] = w;
            adj[y][x] = w;
        }
        int fri;
        for( int i=0; i<c; i ++ ){
            cin>>fri;   fr.push_back(fri);
        }
        FloydWarshall();
        sort(fr.begin() , fr.end());
        int res = 1e7;
        do{
            int temp = adj[1][fr[0]];
            for( int i = 0 ; i <fr.size()-1 ; i ++ ){
                temp+=adj[fr[i]][fr[i+1]];
            }
            temp+=adj[fr[fr.size()-1]][n];
        res = min(res,temp);
        }while(next_permutation(fr.begin(),fr.end()));
        cout<<"Case "<<cnt++<<": "<<res<<endl;
    }
    return 0 ;
}
