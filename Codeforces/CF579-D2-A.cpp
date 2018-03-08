#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
#include<bitset>
#include<stack>

#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;


int main( )
{
    Mohamed_Fathi
    ll n;        cin>>n;
    int counter = 0 ;
    while( n )
    {
        if( n & 1)
            counter++;
        n/=2;
    }
    cout<<counter<<endl;
    return 0;
}
