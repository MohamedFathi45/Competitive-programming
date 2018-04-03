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

map<int , int> mp;
int main( )
{
    int n , m , x;
   while(cin>>n>>m &&(n||m))
    {
        mp.clear();
        for( int i = 0 ; i < n ; i ++ )
        {
            cin>>x;
            mp[x] = 1;
        }
        int res = 0 ;
        for( int i= 0 ; i <m ; i++ )
        {
            cin>>x;
            if(mp[x] == 1 )
                res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
