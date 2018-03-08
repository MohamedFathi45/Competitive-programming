#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
#include<bitset>
#include<stack>

#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

short arr[101][101];
short row_sum[101] , colomn_sum[101];

int main( )
{
    Mohamed_Fathi
    int n;
    while(cin>>n && n )
    {
        memset(row_sum , 0 , sizeof row_sum);
        memset(colomn_sum , 0 , sizeof colomn_sum );
        for( int i = 0 ; i <n ; i ++ )
            for( int j = 0 ; j < n; j ++)
            {
                cin>>arr[i][j];
            }
            for( int i = 0 ; i < n ; i ++ )
            {
                for( int j = 0 ; j < n ; j ++ )
                    row_sum[i]+=arr[i][j];
            }

            for( int i = 0 ; i < n ; i ++ )
            {
                for( int j = 0 ; j < n ; j ++ )
                    colomn_sum[i]+=arr[j][i];
            }


            bool v = true;
            for( int i = 0 ; i < n ; i ++ )
            {
                if( (row_sum[i] & 1) || (colomn_sum[i] &1) )        // odd
                {
                    v= false;
                    break;
                }
            }
            if( v  )
            {
                cout<<"OK"<<endl;
                continue;
            }
            int r=-1 , c= -1 ;
            int changes = 0;
            for( int i = 0; i < n ; i ++ )
            {
                if( row_sum[i] & 1 )
                {
                    for( int j = 0 ; j<n; j ++ )
                    {
                        if( colomn_sum[j] &1 )
                        {
                            r=i;
                            c=j;
                            changes++;
                        }
                    }
                }
            }

            if(  (r == -1 && c == -1) || changes > 1 )
                cout<<"Corrupt"<<endl;
            else
                cout<<"Change bit "<<"("<<r+1<<","<<c+1<<")"<<endl;
    }
        return 0;
}
