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

int main()
{
	Mohamed_Fathi
	int n,x;      cin>>n;
	vector<int>v;
	for( int i = 0 ; i < n ; i ++)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin() , v.end());

    for( int i = 0 , j = n-1 ; i <= j ; i++ , j-- )
    {
        if(i != j)
        cout<<v[i]<<" "<<v[j]<<" ";
        else{
        cout<<v[i]<<endl;
        break;
        }
    }
    return 0;
}
