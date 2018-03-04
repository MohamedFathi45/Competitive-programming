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
int main( )
{
    play();
    int n , x ;     cin>>n>>x;

    int counter = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        if( x / i  <= n && x%i == 0)
            counter++;
    }
    cout<<counter<<endl;
    return 0;
}