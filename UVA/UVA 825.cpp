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
int xDir[]={0, 1,-1,0};
int yDir[]={1,0,0 ,-1};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
char ch[200][200];
int memo[200][200];
int r , c;
bool ok( int row , int col ){
    if( row >= r || col >= c|| row<0 || col <0 )  return 0;
    return 1;
}

int find_path( int row , int col ){
    if(!ok(row,col) || ch[row][col]=='X' )
        return 0;
    if(row == r-1 && col == c-1)    return 1;
    if(memo[row][col] != -1)  return memo[row][col];
    int cnt = 0;
    for( int i = 0 ; i < 2 ; i ++ ){
        int tox = row+xDir[i];
        int toy = col+yDir[i];
        cnt+=find_path(tox , toy);
    }
    return memo[row][col] = cnt;
}

int main( )
{
    Flash
    int t,row_num;      cin>>t;
    while( t -- ){
    for( int i = 0 ; i< 200 ; i ++ ){
        for( int j = 0 ; j < 200 ; j ++ )
            ch[i][j]='.';
    }
        memset(memo , -1 , sizeof memo);
        cin>>r>>c;
        cin.ignore();
        string str;
        for( int i = 0 ; i < r ; i ++ ){
            cin>>row_num;
            getline(cin , str); int n=0 , cnt=0;
            for(int j = str.size()-1 ; j >=0 ; j --){
                if(str[j] == ' '){
                    ch[row_num-1][n-1] ='X';
                    cnt=0 , n=0;
                }
                else
                    n+=(str[j]-'0')*power(10 , cnt++);
            }
            ch[row_num-1][n-1] ='X';
        }
        cout<<find_path(0,0)<<endl;
        if(t!=0)    cout<<endl;
    }
    return 0 ;
}
