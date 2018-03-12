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
vector<int> v;

int get_up( int num )
{
    int start=0 , last = v.size()-1;
    while( start <= last )
    {
        int mid = (start+last)/2;
        if( v[mid] <= num )
            start = mid+1;
        else
            last = mid-1;
    }
    if( start >= v.size() )
        return -1;
    else
        return v[start];
}
int get_down( int num )
{
    int start=0 , last = v.size()-1;
    while( start <= last )
    {
        int mid = (start+last)/2;
        if( v[mid] < num )
            start = mid+1;
        else
            last = mid-1;
    }
    if(last < 0 )
        return -1;
    else
        return v[last];
}

int main()
{
	Mohamed_Fathi
	int n;          cin>>n;
    int x;
    for( int i = 0 ; i < n; i ++ )
    {
        cin>>x;
        v.push_back(x);
    }
    int q;      cin>>q;
    int num;
    while( q -- )
    {
        cin>>num;
        int s = get_up(num);
        int l = get_down(num);
        if(s == -1 )
        cout<<l<<" "<<"X"<<endl;
        else if( l == -1 )
        cout<<"X"<<" "<<s<<endl;
        else
            cout<<l<<" "<<s<<endl;
    }
    return 0;
}
