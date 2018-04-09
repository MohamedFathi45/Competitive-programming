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
int n;
ll fact( int x )
{
    if(x <= 0  || x == 1) return 1;

    return x*fact(x-1);
}

int main( )
{
    cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}
