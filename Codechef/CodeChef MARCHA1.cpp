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

int main()
{
    int arr[21];
    Mohamed_Fathi
    int t,n,s;      cin>>t;
    while(t-- )
    {
        cin>>n>>s;
        for( int i = 0 ; i < n ; i ++ )
            cin>>arr[i];
        bool ok=false;
        for( int i = 0 ; i < (1 << n ) ; i ++ )
        {
            int temp = i  , sum =0 , c=0;
            while( temp )
            {
                if( temp & 1 )
                    sum+=arr[c];
                temp >>= 1;
                c++;
            }
            if( sum == s )
            { ok=true;  break;}

        }
        if(ok)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
