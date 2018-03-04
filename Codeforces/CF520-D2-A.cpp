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
    int arr[26];

    memset( arr , 0 , sizeof arr);
    int n;      cin>>n;
    string str;         cin>>str;
    for( int i = 0 ; i < n ; i ++ )
    {
        if(str[i] >= 97)
        arr[str[i] - 'a' ]++;
        else
            arr[str[i] - 'A']++;
    }
    for( int i = 0 ; i < 26 ; i ++)
    {
        if( arr[i] == 0  )
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    return 0;
}