#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
#include<deque>
#include<bitset>
#include<stack>
#include<list>

#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
bool vis[501][501];
int main()
{
	Mohamed_Fathi
	int n , m , q;
	while( cin>>n>>m>>q && (n||m||q) )
    {
        memset(vis, 0, sizeof vis);
        int x,y,x1,y1;
        while( q-- )
        {
            cin>>x>>y>>x1>>y1;
            if(x1 < x )
                swap(x , x1);
            if(y1 < y )
                swap(y , y1);

            for( int i = x-1; i<x1 ; i ++ )
            {
                for( int j = y-1 ; j < y1 ; j++ )
                    vis[i][j] = 1;
            }
        }

            int ans = 0 ;
            for( int i = 0 ; i < n ; i ++ )
                for( int j = 0 ; j < m ; j ++ )
                if(vis[i][j] == 0 )
                ans++;
                if( ans == 0 )
                    cout<<"There is no empty spots."<<endl;
                else if( ans == 1 )
                    cout<<"There is one empty spot."<<endl;
                else
                    cout<<"There are "<<ans<<" empty spots."<<endl;
    }
    return 0;
}
