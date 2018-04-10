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
double EPS = 1e-7;
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
using namespace std;
int n , m ,arr[100001] , stf[100001];
ll tmp[100001];

bool valid( ll mid )
{
    for( int i = 0 ; i < n ; i ++ )
        tmp[i] = arr[i]*mid;
    int j = 0;
    ll cur = m;
    while( j < n && cur >= 0 )
    {
        if( tmp[j] > stf[j] )
            cur -=(tmp[j] - stf[j]);
        j++;
    }
    if( cur >= 0 )
        return 1;
    return 0;
}

ll Binary_Search( )
{
    unsigned long long lo = 0 , hi = 2e9;
    ll ret = 0 ;
    while( lo <= hi )
    {
        unsigned long long mid = (lo+hi)/2;
        if( valid( mid ) )
        {
            ret = mid ;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return ret ;
}

int main( )
{
    cin>>n>>m;
    for( int i = 0 ; i < n ; i ++ )
        cin>>arr[i];
    for( int i = 0 ; i < n ; i ++ )
        cin>>stf[i];
    cout<<Binary_Search( )<<endl;
    return 0;
}
