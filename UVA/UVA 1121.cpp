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

int main( )
{
    Flash
    ll n,s;
    while(cin>>n>>s){
    int ptr1=0,ptr2=0;
    int arr[100001];
    for( int i= 0 ; i < n ; i ++)
        cin>>arr[i];
    ll res = 1e6  , len = 0;
    ll sum = 0;
    while( ptr1<=n && ptr2 <n )
    {
        while( ptr1 < n && sum <= s ){
            len++;
            sum+=arr[ptr1];
            ptr1++;
        }
            if( sum >=s )
                res = min( len , res );
            sum-=arr[ptr2];
            ptr2++;
            len--;
    }
    if( res != 1e6)
    cout<<res<<endl;
    else
        cout<<0<<endl;
    }
    return 0;
}
