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
int dcomp( double a , double b )
{
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
using namespace std;
int arr[10001];
int n,k;

bool valid( double mid )
{
    double counter = 0;
    for( int i = 0 ; i < n ; i++ )
    {
        int com_res = dcomp( arr[i] , mid );

        if( com_res == 1 )
        {
            counter += (arr[i] - mid) - ((arr[i] - mid) *(k/100.0) );
        }
        else if( com_res == -1)
        {
            if( dcomp(mid - arr[i]  , counter) == 1 )
                return 0;
            else
                counter -= (mid - arr[i]);
        }
    }
    return dcomp(counter , 0.0) >= 0;
}

double Binary_Search( )
{
    double lo = 0.0 , hi = 1000.0 , ret=-1;
    for( int i =0 ; i < 50 ; i ++)
    {
        double mid = (lo+hi)/2.0;
        if( valid(mid) )
        {
            ret = max(mid,ret);
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    return ret;
}

int main( )
{
    Mohamed_Fathi
    cin>>n>>k;
    for( int i = 0 ; i < n ; i ++ )
        cin>>arr[i];
    sort(arr , arr+n );
    reverse(arr , arr+n );
    cout<<fixed<<setprecision(6)<< Binary_Search( )<<endl;
    return 0;
}