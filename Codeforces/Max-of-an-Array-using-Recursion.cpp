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
int n ;
long long arr[1001];

int Find( int index , int mx )
{
    if(index == n)     return mx;
    if( arr[index] > mx )
        Find(index+1 , arr[index]);
    else
        Find(index+1 , mx );
}

int main( )
{
    cin>>n;
    for( int i = 0 ; i < n ; i ++ )
        cin>>arr[i];
    cout<<Find(0 , arr[0])<<endl;
    return 0;
}
