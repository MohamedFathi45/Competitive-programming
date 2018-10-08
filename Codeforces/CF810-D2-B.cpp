#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<map>
#include<unordered_map>
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
const int MAX = 2e5;
const int oo=1e7;
int xDir[]={-1, 0 ,1 ,0 ,1 , -1 , -1 , 1 };
int yDir[]={0 ,-1 ,0 ,1 ,1 , -1 ,  1 , -1 };
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}

int main(){
    Flash
    int n,f;        cin>>n>>f;
    vector<ll>sol;
    long long res = 0 ;
    long long p,c;
    for(int i = 0 ; i < n ; i ++){
        cin>>p>>c;
        ll ex = min(p,c);
        ll ne = min(p*2,c);
        sol.push_back(ne-ex);
        res+=ex;
    }
    sort(sol.begin(),sol.end());
    reverse(sol.begin() , sol.end());
    for( int i = 0 ; i <min((ll)f , (ll)sol.size()) ; i++ )
        res+=sol[i];
    cout<<res<<endl;
    return 0;
}
