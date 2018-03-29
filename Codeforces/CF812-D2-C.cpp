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
unsigned long long arr[100001];
vector<long long>res;
ll n,s;
long long sum = 0  , tempsum=0;
pair<bool , long long> valid( int k )
{
    sum = 0 ;
    res.clear();
    long long x;
    for( int i = 0 ; i <n ; i++ )
    {
        x=(arr[i] + ( (i+1)*k ));
        res.push_back(x);
    }

    sort(res.begin() , res.end() );

    for( int i = 0 ; i < k ; i ++ )
        sum+=res[i];
    if(sum > s)
        return {0 , -1};
    return {1,sum};
}

pair< int , long long> BinarySearch( int start , int last )
{
    pair<int , long long> ret(-1 , 0);
    while( start <= last)
    {
        int mid = (start+last)/2;
        pair<bool , long long> tmp = valid(mid);
        if(tmp.first )
        {
            ret.first = mid ;
            ret.second = tmp.second;
            start = mid+1;
        }
        else
            last = mid-1;
    }
    return ret;
}
int main()
{
    cin>>n>>s;
    for( int i = 0 ; i < n ; i ++ )
        cin>>arr[i];
    pair < int , long long> f = BinarySearch( 1 , n );
    if( f.first ==-1 )
        cout<<0<<" "<<0<<endl;
    else
        cout<<f.first<<" "<<f.second<<endl;
    return 0;
}