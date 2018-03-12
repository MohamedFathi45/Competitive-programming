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
	multiset<int> s;
	ll res = 0;
	int n,x;
	while( cin>>n && n )
    {
        res = 0 ;
        s.clear();
        for( int i = 0 ; i < n ; i ++ )
        {
            cin>>x;
            s.insert(x);
        }
        //multiset<int>::iterator it = s.begin();
        int a , b ;
        while( s.size() > 1)
        {
            a = *s.begin();
            s.erase(s.begin());
            b = *s.begin();
            s.erase(s.begin());
            a+=b;
            res += a;
            s.insert(a);
        }
        cout<<res<<endl;
    }
    return 0;
}
