#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
#include<deque>
#include<bitset>
#include<stack>
#include<list>
#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;

int arr[51][51];
int main()
{
	Mohamed_Fathi
	int n;      cin>>n;
	for( int i = 0 ; i < n; i ++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            cin>>arr[i][j];
        }
    }
    bool valid = false;
    int mx;
    for( int i = 0 ; i < n ; i ++ )
    {
            mx = INT_MIN;
            for( int j = 0 ; j < n ; j ++ )
                if( arr[i][j] > mx )
                mx = arr[i][j];

        if( mx == n-1 && valid == false )
        {
            cout<<mx+1<<" ";
            valid = true;
        }
        else
            cout<<mx<<" ";
    }
    cout<<endl;
    return 0;
}
