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
string str[50];
bool vis[51][51];
int n,m;

bool ok( int i , int j ){
    if( i < 0 || i >= n || j < 0 || j >= m )    return 0;
    return 1;
}
void DFS( int r , int c ){
    if( !ok(r , c) || (vis[r][c]) || str[r][c] =='.' )    return;
    vis[r][c] = 1;
    for( int i = 0 ; i < 4 ; i ++ ){
        int tox= r+xDir[i];
        int toy= c+yDir[i];
        DFS(tox , toy);
    }
}
int valid(  ){
    memset(vis , 0 , sizeof vis);
    int cnt = 0;
    for( int i = 0 ; i < n ; i ++ ){
        for( int j = 0 ; j < m ; j ++ ){
            if( str[i][j] == '#' && !vis[i][j] ){
                cnt++;
                DFS( i , j );
            }
        }
    }
    return cnt;
}
int main( )
{
    Flash
    cin>>n>>m;
    for( int i = 0 ; i < n ; i ++ )
        cin>>str[i];
    short k=0;
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            if( str[i][j] == '#' )
                k++;
    if( k < 3 ){
        cout<<-1<<endl;
        return 0;
    }
    for( int i = 0 ; i < n ; i ++ ){
        for( int j = 0 ; j < m ; j ++ ){
            if(str[i][j] == '#'){
                str[i][j] = '.';
                int cnt = valid(  );
                str[i][j]='#';
            if(cnt > 1){
                cout<<1<<endl;
                return 0;
            }
        }

        }
    }
    cout<<2<<endl;
    return 0 ;
}

