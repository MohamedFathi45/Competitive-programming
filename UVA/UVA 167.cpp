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
char chess_board[8][8];
int board[8][8],mx;
bool right_dig[8*8],left_dig[8*8],col[8];
void Solve_Chess( int row , vector<int> choosen ){
    if(row == 8){
        int sum = 0;
        for( int i = 0 ; i < choosen.size(); i ++ )
            sum+=choosen[i];
            mx = max(sum , mx);
        return;
    }
    for( int c=0; c<8; c ++ ){
        if(!col[c] && !right_dig[row+c] && !left_dig[8+row-c]){
            col[c] =  right_dig[row+c] = left_dig[8+row-c] = 1;
            choosen.push_back(board[row][c]);
            Solve_Chess(row+1,choosen);
            col[c] =  right_dig[row+c] =  left_dig[8+row-c] = 0;
            choosen.pop_back();
        }
    }

}
int main( )
{
    Flash
    int t;      cin>>t;
    while(t--){
        memset(right_dig , 0 , sizeof right_dig);
        memset(left_dig , 0 , sizeof left_dig);
        memset(col , 0 , sizeof col);
        for(int i = 0 ; i < 8 ; i++)
            for(int j = 0 ; j < 8 ; j++)
                cin>>board[i][j];
         mx=-1;
         vector<int> v;
        Solve_Chess(0,v);
        cout<<setw(5)<<mx<<endl;
    }
    return 0 ;
}
