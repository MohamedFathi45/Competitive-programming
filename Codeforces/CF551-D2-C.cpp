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
ll n , m ,arr[100001] , tmp[100001];

bool valid( ll mid )
{
    for( int i = 0 ; i < n ; i ++ )
        tmp[i] = arr[i];
    int j = n-1;
    for( int i = 0 ; i < m  ; i ++ )
    {
        long long cur = mid;
        while( j >=0 && tmp[j] <= 0 )    j--;
        cur -=(j+1);
        if( cur < 0 )       return 0;
        while(j >= 0 && tmp[j] <= cur )
        {   cur -= tmp[j] ; tmp[j] = 0 ; j-- ;}
        if( j < 0 )
            return 1;
        if(tmp[j] > 0)
            tmp[j] -= cur;
    }
    return 0;
}

ll Binary_Search( )
{
    ll lo = 0 , hi = 1e20 , ret = -1 ;
    while( lo <= hi )
    {
        ll mid = (lo+hi)/2;
        if( valid( mid ) )
        {
            ret = mid ;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    return ret ;
}

int main( )
{
    cin>>n>>m;
    for( int i = 0 ; i < n ; i ++ )
        cin>>arr[i];
    cout<<Binary_Search( )<<endl;
    return 0;
}
