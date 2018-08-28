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
map<pair<int,int> ,int >all;
map<pair<int,int> , int >vis;
int BFS( int x0 , int y0 , int x1 , int y1 ){
    queue<pair<int,int> >q;
    q.push(make_pair(x0 , y0));
    vis[make_pair(x0,y0)] = 1;
    int dep=1 , sz =1 ;
    int res = -1;
    bool ok = 1;
    for( ; ok && !q.empty() ; ++dep , sz = q.size() ){
        while( ok && sz --){
            auto cur = q.front();   q.pop();
            for( int i = 0 ; i < 8 ; i ++ ){
                int tox = cur.first+xDir[i];
                int toy = cur.second+yDir[i];
                map<pair<int,int>,int>::iterator it;
                map<pair<int,int>,int>::iterator it_vis;
                it = all.find(make_pair(tox , toy));
                if( it != all.end() ){
                    it_vis = vis.find(make_pair(tox , toy));
                    if( it_vis == vis.end() || it_vis->second != 1  ){
                        if( tox == x1 && toy == y1 ){
                            res = dep;  ok = 0;
                            break;
                        }
                        q.push(make_pair(tox , toy));
                        vis[make_pair(tox , toy)] = 1;
                    }
                }
            }
        }
    }
    return res;
}

int main(){
    Flash
    int x0,y0,x1,y1;    cin>>x0>>y0>>x1>>y1;
    int q,r,a,b;              cin>>q;
    for( int i = 0 ; i <q ; i ++ ){
        cin>>r>>a>>b;
        for( int i = a ; i <=b ; i ++ )
            all[make_pair(r , i)] = 1;
    }
    cout<<BFS(x0,y0,x1,y1)<<endl;
    return 0;
}
