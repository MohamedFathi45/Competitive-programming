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

int main( )
{
    int c = 1;
    string str;
    int t,n;      cin>>t;
    while( t-- )
    {
        int counter = 0 ;
        cin>>n>>str;
        for( int i = 0 ; i < n ; i ++ )
        {
            if(str[i] == '.')
            {
                counter ++;
                i+=2;
            }
        }
        cout<<"Case "<<c++<<": "<<counter<<endl;
    }
    return 0;
}
