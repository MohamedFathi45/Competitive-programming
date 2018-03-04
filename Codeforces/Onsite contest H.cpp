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
    int n;          cin>>n;
    vector<int> arr(100002 , 0);
    vector<long long > orign;
    int x;
    for( int i = 1 ; i <= n ; i ++ )
    {
        cin>>x;
        orign.push_back(x);
    }
    int l , r ;
    int q;      cin>>q;
    while( q -- )
    {
        cin>>l>>r;
        arr[l]++;
        arr[r+1]--;
    }
    arr[0] = 0;
    for( int i = 1 ; i <=n ; i ++ )
        arr[i] = arr[i-1] + arr[i];

        int sz = 0 ;
        for( int i = 1 ; i <= n ; i ++ )
            if( arr[i] == 0 )
            sz++;
        cout<<sz<<endl;
        for( int i = 1 ; i <=n ; i ++ )
        {
            if( arr[i] == 0 )
                cout<<orign[i-1]<<" ";
        }
        cout<<endl;
        return 0;
}