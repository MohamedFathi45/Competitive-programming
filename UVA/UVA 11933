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

int main( )
{
    Mohamed_Fathi
    int n;
    while( cin>>n && n)
    {
        bitset<32>k = n ;
        bitset<32> left;
        bitset<32> right;
        int c = 0 ;

    for( int i = 0 ; i < 32 ; i ++ )
    {
        if( (k[i] == 1)  && ( c&1 ) )
            {
                right[i] = 1;
                left[i] = 0 ;
                c++;
            }
        else if( (k[i] == 1) && (!(c&1)) )
        {
            left[ i ] = 1;
            right[i] = 0;
            c++;
        }
        else
        {
            left[i] = 0 ;
            right[i] = 0 ;
        }
    }
    cout<<(int)left.to_ulong()<<" "<<(int)right.to_ulong()<<endl;
    }
  return 0;
}
