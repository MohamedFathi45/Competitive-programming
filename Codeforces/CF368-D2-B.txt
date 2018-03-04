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
    set<int> s;
    int info[100001];
    int arr[100001];
    int n , m ;     cin>>n>>m;
    for( int i = 0 ; i < n ; i ++ )
        cin>>arr[i];
    for(int i = n-1 ; i >=0 ; i -- )
    {
        s.insert(arr[i]);
        info[i] = s.size();
    }
    while( m -- )
    {
        int x ;      cin>>x;
        cout<<info[x-1]<<endl;
    }
    return 0;
}