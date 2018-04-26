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
using namespace std;
double EPS = 1e-7;
int xDir[]={0, 0,1,-1};
int yDir[]={1,-1,0,0 };
int inf = 1e7;
int dcomp( double a , double b ){
if( fabs(a - b ) <= EPS )    return 0;
return ((a > b) ? 1 : -1);
}

int main( )
{
    int sz,n, arr[30];
    while(cin>>sz>>n){
        for( int i = 0 ; i < n ; i ++ )
            cin>>arr[i];
        int res = -1;
        vector<int> ok , valid;
        for( int i = 0 ; i < (1<<n) ; i ++ )
        {
            int temp = i , sum = 0 , c = 0;
            valid.clear();
            while( temp )
            {
                if( temp & 1)
                {
                    sum+= arr[c];
                    valid.push_back(arr[c]);
                }
                c++;
                temp>>=1;
            }

            if( sum <= sz && sum > res )
            {
                if( sum == res && valid.size() > ok.size())
                {
                    ok = valid;
                }
                else
                {
                    res = sum;
                    ok = valid;
                }
            }
        }
        for( int i = 0 ; i < ok.size() ; i ++ )
            cout<<ok[i]<<" ";
        cout<<"sum:"<<res<<endl;
    }
    return 0 ;
}
