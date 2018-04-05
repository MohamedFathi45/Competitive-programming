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
ll n , c;
int arr[1005];

bool valid( ll x )
{
    ll total = 0 , counter = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if(total + arr[i] <= x )
        {
            total+=arr[i];
        }
        else if( total+arr[i] > x )
        {
            counter++;
            if( arr[i] && arr[i] <= x)
                total = arr[i];
            else
                return 0;
        }
    }
    if( total > 0 && total <= x )        counter ++;
    if( counter <= c )      return true;
    return false;
}

int Binary_Search( )
{
    ll start = 0 , last = 1e9 , ret = -1;
    while( start <= last )
    {
        ll mid = (start+last)/2;
        if( valid(mid) )
        {
            ret = mid;
            last = mid-1;
        }
        else
            start = mid+1;
    }
    return ret;
}

int main( )
{
    Mohamed_Fathi
    while(cin>>n>>c)
    {
        for( int i = 0 ; i < n ; i++ )
            cin>>arr[i];
        cout<<Binary_Search()<<endl;
    }
    return 0;
}
