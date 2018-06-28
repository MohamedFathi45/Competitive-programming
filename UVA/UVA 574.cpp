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
#include<stdlib.h>
#include<list>
#include<fstream>
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
double EPS = 1e-7;
long long gcd( long long a , long long b ){
    if( b == 0 )
        return a;
    return gcd(b,a%b);
}
int lcm(int a , int b){
    if( b > a ) swap(a, b);
    return (a*b)/gcd(a , b);
}
int power( int b , int p ){
    if( p == 0 )    return 1;
    int sq = power(b, p/2);
    sq = sq*sq;
    if( p%2 == 1)
        sq*=b;
    return sq;
}
int xDir[]={0, 0,-1,1};
int yDir[]={1,-1,0 ,0};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
int n,m,cnt = 0;
vector<int>v;
set<vector<int> >res;

void solve(int index , int sum , vector<int> items){
    if( index == m ){
        if( sum == n ){
            res.insert(items);
        }
        return;
    }
    if( sum == n ){
            res.insert(items);
    }
    if( sum < n ){
    solve(index+1 , sum , items);
    items.push_back(v[index]);
    solve(index+1 , sum+v[index] , items);
    }
    else
        return;
}
int main( )
{
    Flash
    int x;
    while(cin>>n>>m && (n||m)){
        for( int i = 0 ; i < m ; i ++ ){
            cin>>x;     v.push_back(x);
        }
        cnt = 0;        //clear the vectors
        vector<int> items;
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());
        solve(0,0,items);

    cout<<"Sums of "<< n <<":"<<endl;
    if( res.size() == 0 )
        cout<<"NONE"<<endl;
    else{
            set<vector<int> >::iterator it= res.end();
            it--;
        for( it  ; it != res.begin() ; it--){
               const vector<int>& re = (*it);
               for( int i = 0 ; i < re.size() ; i ++ ){
                if( i== 0 )
                    cout<<re[i];
                else
                    cout<<"+"<<re[i];
               }
               cout<<endl;
               }
               const vector<int>& ke = (*res.begin());
               for( int  i = 0 ; i < ke.size() ; i ++ ){
                    if( i == 0 )
                        cout<<ke[i];
                    else
                        cout<<"+"<<ke[i];
               }
               cout<<endl;
        }
        v.clear(); items.clear(); res.clear();
    }
    return 0 ;
}
