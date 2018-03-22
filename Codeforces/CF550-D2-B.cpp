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

int main()
{
    Mohamed_Fathi
    int n,l,r,x;      cin>>n>>l>>r>>x;
    vector<long long> v(n);
    int res = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        cin>>v[i];
    }
    for( int i = 0 ; i < (1 << n) ; i ++ )
    {
        int temp = i , counter = 0  , t = i;
        while( temp )
        {
            if( temp & 1)
               counter++;
            temp >>= 1;
        }

        if( counter >= 2 )
        {
            ll mn = LONG_MAX , mx = LONG_MIN , sum=0 , c = 0 ;
            while( t )
            {
                if( t & 1 )
                    sum +=v[c] , mx = max(v[c] , mx ) , mn = min(v[c] , mn );
                t >>= 1;
                c++;
            }
            if( sum >= l && sum <= r && mx - mn >= x )
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
