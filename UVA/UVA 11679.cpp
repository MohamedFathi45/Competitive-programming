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

int arr[23];
int main( )
{
    play();

    int n , q;
    while( cin >>n>>q && ( n||q ) )
    {
        for( int i = 1 ; i <= n; i ++ )
            cin>>arr[i];

        for( int i = 0 ;i < q ; i ++)
        {
            int d , c , mon;
            cin>>d>>c>>mon;
            arr[d] -= mon;
            arr[c] += mon;
        }
        bool v = false;
        for( int i = 1 ; i <= n ; i ++)
            if( arr[i] < 0 )
        {
            v= true;
            break;
        }
        if( v )
        {
            cout<<"N"<<endl;
            continue;
        }
        else
            cout<<"S"<<endl;
    }
    return 0;
}
