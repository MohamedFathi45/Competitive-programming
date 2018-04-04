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
ll n,k;

ll power( int num , int os )
{
    if( os == 0)    return 1;
    if( os == 1)    return num;
    return num*power(num , os-1);
}

bool valid( ll x )
{
    int c = 0;
    int counter = 0;
    while(x/power(k , c))
    {
        counter += x/power(k , c++);
    }
    if( counter >= n )
        return 1;
    return 0;
}

long long Binary_search( )
{
    ll start=0 , last = 1e9 , ret = -1;
    while( start <= last )
    {
        //system("PAUSE");
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
    cin>>n>>k;
    cout<<Binary_search()<<endl;
    return 0;
}
