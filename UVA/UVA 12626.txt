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

int arr[26];
int main( )
{
    play();
    int t;      cin>>t;

    while( t -- )
    {
        memset( arr , 0 , sizeof arr);
        string str;
        cin>>str;
        for( int i = 0 ; i < str.length() ; i ++ )
            arr[str[i] - 'A']++;

        int mn = 1e6;

        string name ="MARGIT";      // M A R G I T   //AMARGITA

        arr['A' - 'A'] /= 3;
        arr['R' - 'A'] /= 2;

        for( int i = 0 ; i < 6 ; i ++ )
        {
            if( arr[ name[i] - 'A' ] < mn)
                mn = arr[ name[i] -'A' ];
        }
        cout<<mn<<endl;
    }
    return 0;
}
