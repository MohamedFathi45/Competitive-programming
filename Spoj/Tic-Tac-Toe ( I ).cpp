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
int xDir[]={0, 0,-1,1};
int yDir[]={1,-1,0 ,0};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}

int trigger( int val )
{
    if( val == 0 )  return 1;
    else     return 0 ;
}

bool is_win( string config ){
    bool rows =
    (config[0] != '.' && config[0] == config[1] && config[1] == config[2])||
    (config[3] != '.' && config[3] == config[4] && config[4] == config[5])||
    (config[6] != '.' && config[6] == config[7] && config[7] == config[8]);
    bool columns =
    (config[0] != '.' && config[0] == config[3] && config[3] == config[6]) ||
    (config[1] != '.' && config[1] == config[4] && config[4] == config[7]) ||
    (config[2] != '.' && config[2] == config[5] && config[5] == config[8]);
    bool diagonals =
    (config[0] != '.' && config[0] == config[4] && config[4] == config[8]) ||
    (config[2] != '.' && config[2] == config[4] && config[4] == config[6]);

    return rows|| columns|| diagonals;
}

int main( )
{
    Flash
    int t;          cin>>t;
    while(t--)
    {
        string row;
        string board;
        for( int i = 0 ; i < 3 ; i ++ ){
            cin>>row;
            board+=row;
        }
        string start=".........";
        string ans = "no";
        queue<pair<bool , string> >q;
        q.push({1, start});
        while(!q.empty())
        {
            string cur = q.front().second;
            bool cur_player = q.front().first;
            q.pop();
            if(cur == board){
                ans = "yes";
                break;
            }
            if (is_win(cur)) continue;
            for( int i=0; i<9; i ++ )
            {
                if(cur[i] == '.'){
                    cur[i] = (cur_player ? 'X':'O' );
                    if(cur[i] == board[i]){
                        q.push({ trigger(cur_player), cur});
                    }
                    cur[i] = '.';
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0 ;
}
