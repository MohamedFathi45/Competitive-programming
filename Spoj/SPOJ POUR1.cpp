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
int xDir[]={0 , 0  ,1 ,-1};
int yDir[]={1 , -1 ,0 , 0};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
int a , b,c , newA , newB;
set<pair<int,int> >st;
void BFS( ){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    st.insert(make_pair(0,0));
    int sz = 1, dep = 1;
    bool ok = 1;
    int res = 0;
    for( ;  ok && !q.empty() ; sz = q.size(),dep ++ ){
        while( ok && sz -- ){
            auto cur = q.front();
            q.pop();
            if( cur.first == c || cur.second == c ){
                ok = 0;
                res = dep;
                break;
            }
            if(st.find(make_pair(a , cur.second))==st.end()){
                q.push( make_pair(a , cur.second) );
                st.insert(make_pair(a , cur.second));
            }
            if(st.find(make_pair(cur.first , b))==st.end()){
                q.push( make_pair(cur.first , b));
                st.insert(make_pair(cur.first , b));
            }
            if(st.find(make_pair(0 , cur.second))==st.end()){
                q.push( make_pair(0 , cur.second ));
                st.insert(make_pair(0 , cur.second));
            }
            if(st.find(make_pair(cur.first , 0))==st.end()){
                q.push( make_pair(cur.first , 0 ));
                st.insert(make_pair(cur.first , 0));
            }
            newB = min(cur.first+cur.second , b);
            newA = cur.first - (newB - cur.second);
            if(st.find(make_pair(newA ,newB))==st.end()){
                q.push( make_pair(newA , newB));
                st.insert( make_pair(newA , newB));
            }
            newA = min( cur.first+cur.second , a );
            newB = cur.second - (newA-cur.first);
            if( st.find(make_pair(newA , newB)) == st.end() ){
                q.push(make_pair(newA , newB));
                st.insert(make_pair(newA , newB));
            }
        }
    }
    if( ok == 0 ){
        cout<<res-1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    st.clear();     q = queue<pair<int,int> >();
}
int main(){
    Flash
    int t;      cin>>t;
    while( t -- ){
        cin>>a>>b>>c;
        if( c > a && c > b ){
            cout<<-1<<endl;
            continue;
        }
        BFS( );
    }
    return 0 ;
}
