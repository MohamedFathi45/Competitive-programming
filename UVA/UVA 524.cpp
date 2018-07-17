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
bool prims[50];
void Sieve(){
    for( int i = 2 ; i <50 ; i ++ ){
        if(prims[i])
            for( int j = 2; j*i < 50 ; j++ )
            prims[j*i] = 0;
    }
}
void Exhastive_Search( vector<int>& vec , vector<int> res ,int prev ){
    if( vec.empty() ){
        if( prims[1 + res[res.size()-1]] ){
        for( int i = 0 ; i < res.size()-1 ; i ++ )
            cout<<res[i]<<" ";
        cout<<res[res.size()-1]<<endl;
        }
    }
    else{
        for( int i = 0 ; i < vec.size() ; i ++ ){
            if( prims[prev+vec[i]] ){
                int c = vec[i];
                res.push_back(c);
                vec.erase(vec.begin()+i);
                Exhastive_Search(vec , res , c);
                vec.insert(vec.begin()+i , c);
                res.erase(res.begin()+res.size()-1);
            }
        }
    }
}
int main( )
{
    Flash
    memset(prims , 1 , sizeof prims);
    prims[0]=prims[1]=0;
    Sieve();
    int cnt = 1;
    int n;
    while(cin>>n){
        vector<int> vec;
        for( int i = 2 ; i <=n; i ++ )
            vec.push_back(i);
        vector<int> res;
        res.push_back(1);
        if(cnt > 1)     cout<<endl;
        cout<<"Case "<<cnt++<<":"<<endl;
        Exhastive_Search( vec , res , 1 );
    }
    return 0;
}
