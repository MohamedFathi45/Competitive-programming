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
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
double EPS = 1e-7;
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
using namespace std;
int st[5001];
int main( )
{
    Flash
    int t,n,x;          cin>>t;
    while(t-- ){
        cin>>n;
        int res = 0 ;
        memset(st , 0 ,sizeof st);
        for( int i = 0 ; i < n ; i ++ )
        {
            int cnt = 0 ;
            cin>>x;
            st[x]++;
            for( int j = 0 ; j < x ; j ++ )
                if(st[j] != 0)   cnt+=st[j];
            if(st[x]>1)
                cnt+=st[x]-1;

            res+= cnt;
        }
        cout<<res<<endl;
    }
    return 0;
}

