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

    int grid[1000001];
    int main( )
    {
        Mohamed_Fathi
        int k;      cin>>k;
        while( k -- )
        {
            memset( grid , 0 , sizeof grid );

            int s , h ;
            cin>>s>>h;
            int t =s;
            while(t--)
            {
                int f , l ;
                cin>>f>>l;
                grid[f]++;
                grid[l+1]--;
            }
            for( int i = 0 ; i < s ; i ++ )
                if(i)
                grid[i]+=grid[i-1];
            for( int i = 0 ; i < s ; i ++ )
                if(i)
                grid[i]+=grid[i-1];
            int mn = 1e7;
            for( int i = 0 ; i < s ; i++ )
            {
                if(i)
                mn = min( ( (h*s) - (grid[i+(h-1)]-grid[i-1]) ) , mn );
                else mn = min( ( (h*s) - (grid[i+(h-1)]) ) , mn );
            }
                cout<<mn<<endl;
        }
        return 0;
    }
