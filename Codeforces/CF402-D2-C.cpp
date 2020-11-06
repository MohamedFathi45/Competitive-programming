    #include <iostream>
    #include <math.h>
    #include<vector>
    #include<map>
    #include<algorithm>
    #include<unordered_map>
    #include<set>
    #include<string.h>
    #include<stack>
    #include <iomanip>
    #include<queue>
    #define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    using namespace std;
    int xDir[8]={0 , 0,-1 ,1 ,1 ,-1 , -1 ,1 };
    int yDir[8]={1 ,-1, 0 ,0 ,1 ,-1 , 1 , -1};
     
    int EPS = 1e-10;
    int dComp(double d1 , double d2){
        if(abs(d1 - d2) <= EPS)
            return 0;
        if(d1 > d2)
            return 1;
        else
            return -1;
     
    }
     
    int main()
    {
        Flash
        int t,n,p;      cin>>t;
        while(t--){
            cin>>n>>p;
            int edges = 2*n+p;
            int cnt = 0;
            for( int i = 1 ; i <= n ; i ++ ){
                for( int j = i+1 ; j <= n ; j ++ ){
                    cout<<i<<" "<<j<<endl;
                    cnt++;
                    if(cnt == 2*n+p){
                        i =n+1;
                        break;
                    }
                }
            }
        }
    }
