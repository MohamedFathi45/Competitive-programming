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

int arr[10001];
int main( )
{
    int counter = 1;
    int n,q;
    while( cin>>n>>q &&(n||q) )
    {
        for( int i = 0 ; i < n ; i++)
            cin>>arr[i];
        sort(arr , arr+n);
        cout<<"CASE# "<<counter<<":"<<endl;
        for( int i = 0 ; i <q; i ++ )
        {
            bool v = false;
            int x , index;
            cin>>x;
            if(binary_search(arr , arr+n , x))
            {
                index = lower_bound(arr , arr+n , x) - arr;
                v=true;
            }

            if(v)
                cout<<x<<" found at "<<index+1<<endl;
            else
                cout<<x<<" not found"<<endl;
        }
        counter++;
    }
    return 0;
}
