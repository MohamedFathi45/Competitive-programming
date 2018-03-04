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

int main( )
{
    short arr[101];
    int n , a;      cin>>n>>a;
    for( int i =0 ; i < n ; i ++ )
        cin>>arr[i];

    int res=0;
    int pointer2=a-1;
    int pointer1 = a-1;
    int counter =0 ;

    if( arr[ pointer1 ] == 1 )
    res++;

    pointer1--;
    pointer2++;

    while( true )
    {
        if( pointer1 == -1 || pointer2 == n)
            break;

        if( arr[pointer1] == 1  && arr[pointer2] == 1)
            res += 2;
            pointer1--;
            pointer2++;
    }

    if( pointer1 == -1  && pointer2 != n )
    {
        for( int i=pointer2 ; i < n ; i++)
        {
            if(arr[i] == 1 )
                res++;
        }
    }
    else if( pointer1 != -1  && pointer2 == n)
    {
                for( int i=pointer1 ; i >= 0 ; i--)
                {
                    if(arr[i] == 1 )
                        res++;
                }
    }
    else if( pointer1 == -1 && pointer2 == n )
    {
        cout<<res<<endl;
        return 0 ;
    }
    cout<<res<<endl;
    return 0;
}