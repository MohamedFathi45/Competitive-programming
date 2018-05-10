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
#include<list>
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
double EPS = 1e-7;
int xDir[]={0, 0,-1,1};
int yDir[]={1,-1,0 ,0};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
string word = "IEHOVA#";
vector<string> sol;
char ch[9][9];
void DFS( int x , int y , int index )
{
    if( sol.size() == 7 )   return;
    for( int i = 0 ; i < 3 ; i++ )
    {
        int tox = x+xDir[i];
        int toy = y+yDir[i];
        if( ch[tox][toy] == word[index])
        {
            if( i == 0 )
                sol.push_back("right");
            else if( i == 1)
                sol.push_back("left");
            else
                sol.push_back("forth");
            DFS(tox , toy , index+1);
        }
    }
}
int main( )
{
    Flash
    int t;          cin>>t;
    short n , m;
    while( t-- )
    {
        cin>>n>>m;
        short x, y;
        for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ ){
            cin>>ch[i][j];
            if( ch[i][j] == '@')
                x=i , y = j;
        }
        DFS(x, y , 0);
        for( int i = 0 ; i <sol.size()-1 ; i ++ )
            cout<<sol[i]<<" ";
        cout<<sol[sol.size()-1]<<endl;
        sol.clear();
    }
    return 0 ;
}
