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
int xDir[]={-1, 0,1,0};
int yDir[]={0,-1,0 ,1};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
int n,m;
vector<vector<int> >adj;
vector<vector<bool> >vis;

void BFS( pair<int,int>s , pair<int,int>e ){
    queue<pair<int , int> > q;
    vector<vector<int> >dist(n , vector<int>(m) );
    vis[s.first][s.second] = 1;
    dist[s.first][s.second] = 0;
    q.push(s);
    int sz=1,dep=1;
    bool ok=true;
    for( ;ok && !q.empty() ; sz=q.size(),dep++ ){
        while( ok && sz--){
            pair<int,int>cur = q.front();
            q.pop();
            for( int i=0; i<4 ; i++ ){
                int tox=cur.first+xDir[i];
                int toy=cur.second+yDir[i];
                if( (tox>=0 && tox<n && toy>=0 && toy<m ) && (!vis[tox][toy]) && adj[tox][toy] != 1 ) {
                    q.push({tox,toy}) , dist[tox][toy]=dep , vis[tox][toy]=1;
                    if(e.first == cur.first && e.second == cur.second){
                        ok=false;
                        break;
                    }
                }
            }
        }
    }
    cout<<dist[e.first][e.second]<<'\n';
}

int main(){
    Flash
    while(cin>>n>>m&&n&&m){
       adj = vector<vector<int> >(n , vector<int>(m));
       vis = vector<vector<bool> >(n , vector<bool>(m));
        int p;  cin>>p;
        while(p--){
            int row;        cin>>row;
            int q;          cin>>q;
            for( int i = 0 ; i < q ; i ++ ){
                int col;        cin>>col;
                adj[row][col] = 1;
            }
        }
        pair<int , int> s,e;
        cin>>s.first>>s.second>>e.first>>e.second;
        BFS(s,e);
    }
    return 0;
}
