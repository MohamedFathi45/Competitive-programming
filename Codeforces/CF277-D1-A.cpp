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
int gcd( int a , int b ){
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


vector<vector<int> > res(101);
vector<vector<int> > v1(101);
vector<vector<int> > v(101);
bool vis[101];
void DFS( int i ){
    if( vis[i] )    return ;
    vis[i] = 1;
    for( int j = 0 ; j < res[i].size() ; j ++ ){
        DFS(res[i][j]);
    }
}

int main( )
{
    Flash
    int n,m,x,cnt=1,l , r = 0;            cin>>n>>m;
    for( int i=0 ; i < n; i ++){
        cin>>x;
        if(x)  r++;
        for( int j = 0 ;j <x; j ++ ){
            cin>>l;
            v[cnt].push_back(l);
        }
        cnt++;
    }
    if( !r ){
       cout<<n<<endl;
       return 0 ;
    }
    for( int i = 1 ; i <= n ; i ++ ){
        for( int j = 0 ; j < v[i].size() ; j ++ ){
            v1[v[i][j]].push_back(i);
        }
    }

        for( int i = 1 ; i <= n ; i ++ ){
        for( int j = 0 ; j < v[i].size() ; j ++){
            for( int k = 0 ; k < v1[v[i][j]].size() ; k++ ){
                res[i].push_back(v1[v[i][j]][k]);
            }
        }
    }
    /*
    for( int i = 1 ; i <10 ; i ++ )
    {
        cout<<i<<"   ";
        for( int j = 0 ; j < res[i].size() ; j ++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cnt = 0;
    memset(vis , 0 , sizeof vis);

    for( int i = 1; i <=n; i ++ )
    {
        if(!vis[i]){
        DFS(i);
        if( i > 1)
        cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0 ;
}
