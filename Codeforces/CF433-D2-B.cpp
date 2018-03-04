#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
using namespace std;
void play( )
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
long long n ,arr1[100001],arr2[100001];
int main( )
{
    play();
    cin>>n;
    for( int i = 0 ; i < n ; i ++ )
    {
        cin>>arr1[i];
        arr2[i] = arr1[i];
    }
    long long buffer = 0;
    sort( arr2 ,arr2+n );


    for( int i = 0 ; i < n ; i++ )
    {
        arr1[i] = buffer + arr1[i];
        buffer=arr1[i];
    }
    buffer = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        arr2[i] = buffer + arr2[i];
        buffer = arr2[i];
    }
    int l , r , t , c;
    cin>>c;
    while( c -- )
    {
        cin>>t>>l>>r;
        r--;    l--;
        if( t == 1 )
            cout<<arr1[r] - arr1[l-1]<<endl;
        else
            cout<<arr2[r] - arr2[l-1]<<endl;
    }
    return 0;
}