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
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
double EPS = 1e-7;
int xDir[]={0, 0,1,-1};
int yDir[]={1,-1,0,0 };
int inf = 1e7;
int dcomp( double a , double b ){
if( fabs(a - b ) <= EPS )    return 0;
return ((a > b) ? 1 : -1);
}
int arr[1000002];
int main( )
{
    short trc=1;
    int vis[102];
    int t,n,m,k;      cin>>t;
    arr[1] = 1 , arr[2] = 2 , arr[3] = 3;
    while( t-- )
    {
        cin>>n>>m>>k;
        memset( vis , 0 ,sizeof vis );
        for( int i = 4 ; i <=n ; i ++ )
            arr[i] = (arr[i-1]+arr[i-2]+arr[i-3])%m+1;
        int ptr1 = 1 , ptr2 = 1 , cnt = 0 , l = 1 , r = 1e9;
        bool ok = 0;
        for( int i = 1 ; i <=n; i ++ )
        {
            ptr1 = i;
            for( ; ptr2<=n ; ptr2++ )
            {
                if(cnt == k)        break;
                if( arr[ptr2] > k ) continue;
                if( !vis[arr[ptr2]] )    cnt++;
                vis[arr[ptr2]]++;
            }
            if( cnt == k  && ((r - l) > (ptr2 - ptr1)) )
            {
                l = ptr1;   r = ptr2;   ok = 1;
            }
            if( arr[ptr1] <= k ){
                vis[arr[ptr1]]--;
            if(!vis[arr[ptr1]])     cnt--;
            }
        }
        if(ok)
        cout<<"Case "<<trc++<<": "<<r-l<<endl;
        else
        cout<<"Case "<<trc++<<": sequence nai"<<endl;
    }
    return 0 ;
}
