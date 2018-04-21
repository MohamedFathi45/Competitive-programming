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
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
ll Digits( ll n )
{
    if( n==0 )    return 0;
    ll x = n%10;
    return x + Digits(n/10);
}

int main( )
{
    Flash
    ll n;      cin>>n;
    ll k = sqrt(n);
    ll y;
    if( k <= 100 )
        y=1;
    else
        y = k-100;
    for(ll i = y ;i <= k; i++ )
    {
        if( i*i+Digits(i)*i-n == 0 )
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
