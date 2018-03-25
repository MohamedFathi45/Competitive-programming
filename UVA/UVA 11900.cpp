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
    Mohamed_Fathi
    int c=1;
    int arr[31];
    int t;      cin>>t;
    while(t--)
    {
        int n,p,q;      cin>>n>>p>>q;
        for( int i = 0 ; i < n ; i ++ )
            cin>>arr[i];
        sort(arr , arr+n);
        p = min(p , n);
        int counter = 0 ;
        int i=0;
        for( ;i<p ; i++)
        {
            if(counter + arr[i] <= q )
                counter+=arr[i];
            else
                break;
        }
        cout<<"Case "<<c++<<":"<<" "<<i<<endl;
    }
    return 0;
}
