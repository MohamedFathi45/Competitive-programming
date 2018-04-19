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
int main( )
{
    Flash
    int t;          cin>>t;
    while(t-- ){
    int a,b,c ,ans[3];      cin>>a>>b>>c;
    bool ok = 0;
    for( int i = -150 ; i <=150; i ++ )
    {
        for( int j=-150 ; j <=150 ; j ++ )
        {
            for( int k = -150 ; k<=150 ; k++ )
            {
                if( (i+j+k ==a && i*j*k == b && (i*i + j*j + k*k)==c)&&(i!= j)&&(j!=k)&&(i!=k) )
                {   ok = true;  ans[0] = i , ans[1] = j ; ans[2] = k;}
                if( ok )
                    break;
            }
            if(ok)
                break;
        }
        if(ok)
            break;
    }
    if(ok)
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    else
        cout<<"No solution."<<endl;
    }
    return 0;
}

