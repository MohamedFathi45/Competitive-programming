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
bool left_dig[2*9+1] , rigth_dig[2*9+1],vis_row[9];
int res_row[9],x,y ;
int cnt = 1;
void SolveChess( int col ){
    if(col == y){
      SolveChess(col+1);
      return ;
    }
    if(col == 8){
        cout<<setw(2)<<cnt++<<"      ";
        for( int i = 0 ; i < 7 ; i ++ )
            cout<<res_row[i]+1<<" ";
        cout<<res_row[7]+1<<endl;
        return;
    }
        for( int row = 0 ; row < 8 ; row++ ){
            if(!vis_row[row] && !left_dig[row+col] && !rigth_dig[8+(row-col)] ){
                res_row[col] = row;         //choose
                vis_row[row] =  left_dig[row+col] = rigth_dig[8+(row-col)] = 1 ;
                SolveChess(col+1);
                vis_row[row] =  left_dig[row+col] = rigth_dig[8+(row-col)] = 0 ;
            }
        }
}
int main( )
{
    Flash
    int t;  cin>>t;
    while(t--){
        cnt = 1;
        memset(res_row , 0 ,sizeof res_row);
        memset(left_dig , 0 ,sizeof left_dig);
        memset(rigth_dig , 0 ,sizeof rigth_dig);
        memset(vis_row , 0 ,sizeof vis_row);
        cin>>x>>y;
        x-- , y-- ;
        cout <<"SOLN       COLUMN"<<endl;
        cout <<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        res_row[y] = x;
        left_dig[x+y] = 1 ;  rigth_dig[8+(x-y)] = 1 ; vis_row[x] = 1;
        SolveChess(0);
        if(t)   cout<<endl;
    }
    return 0;
}
