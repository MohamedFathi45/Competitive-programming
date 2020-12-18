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
    long long n,k,q , arr[200001],acc[200001];
    long long nwarr[200001];
    vector<pair<int,int> > qurs(200001);
    cin>>n>>q;
    memset(acc , 0 , sizeof acc);
    for( int i = 0 ; i < n ; i ++ ){
        cin>>arr[i];
    }
    int l , r;
    for( int i = 0 ; i < q ; i ++ ){
        cin>>l>>r;
        l -- , r --;
        qurs[i] = {l,r};
        acc[l]++;
        if(r +1 != n)
            acc[r+1]--;
    }


    /*
    cout<<"accumelated sum :-"<<endl;
    for(int i =0 ; i < n ; i ++ )
        cout<<acc[i]<<" ";
    cout<<endl;
    */

    for( int i = 1 ; i < n ; i ++ )
        acc[i] = acc[i-1] + acc[i];
    vector<pair<int,int> >ind(200001);
    for( int i = 0 ; i < n ; i ++ ){
        ind[i] = make_pair(acc[i],i);
    }
    sort(ind.begin() , ind.begin() + n);
    reverse(ind.begin() , ind.begin() + n);




    /*
    for( int i = 0 ; i  < n ; i ++ )
        cout<<"index: "<<ind[i].second<<" showed: "<<ind[i].first<<"  times"<<endl;
    */


    sort(arr , arr+n);
    reverse(arr , arr+n);
    for( int i = 0 ; i < n ; i ++ ){
        nwarr[ind[i].second] = arr[ i ];
    }
    for( int i = 1 ; i < n ; i ++ )
        nwarr[i] = nwarr[i-1] + nwarr[i];
    long long res = 0;
    for( int i = 0 ; i < q ; i ++ ){
        res += nwarr[ qurs[i].second ] - nwarr[qurs[i].first - 1];
    }
    cout<<res<<endl;
}

