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
#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;

int main( )
{
    Mohamed_Fathi
    vector<vector<int> > v(1e6+1);
    int n,q,x;
    while(cin>>n>>q)
    {
        for( int i = 0 ; i < n ; i ++ )
        {
            cin>>x;
            v[x].push_back(i+1);
        }
        int e , r;
        for( int i = 0 ; i <q ; i++)
        {
            cin>>e>>r;
            if( v[r].size() < e )
            {
                cout<<0<<endl;
            }
            else
            cout<<v[r][e-1]<<endl;
        }
    }
    return 0;
}
