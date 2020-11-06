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
     
    long long n,m,k , arr[100000];
    long long acc1[100000];
    long long acc2[100000];
    vector<pair<pair<int,int>,int> > query(100000);
     
    void perform_op(int left , int right , long long d ,long long cycles){
        acc2[left] += d * cycles;
        if(right+1 < n)
            acc2[right+1] -= d * cycles;
    }
    int main()
    {
        Flash
        int l , r ,d;
        cin>>n>>m>>k;
        memset(acc1 ,0 , sizeof acc1);
        memset(acc2 ,0 , sizeof acc2);
        for( int i = 0 ; i < n ; i ++ )
            cin>>arr[i];
        for( int i = 0 ; i < m ; i ++ ){
            cin>>l>>r>>d;   l-- , r --;
            query[i] = { {l , r} , d};
        }
        int x,y;
        for( int i = 0 ; i < k ; i ++ ){
            cin>>x>>y;
            x -- , y -- ;
            acc1[x]++;
            if(y+1 < m)
                acc1[y+1]--;
        }
        for( int i = 1 ; i < m ; i ++ ){
            acc1[i] = acc1[i] + acc1[i-1];
        }
        for( int i = 0 ; i < m ; i ++ ){
            int left = query[i].first.first;
            int right = query[i].first.second;
            perform_op(left , right,query[i].second, acc1[i]);
        }
        for(int i = 1; i < n ; i ++ ){
            acc2[i] = acc2[i] + acc2[i-1];
        }
        for( int i = 0 ; i < n ; i ++ )
            cout<<arr[i] + acc2[i]<<" ";
        cout<<endl;
    }
