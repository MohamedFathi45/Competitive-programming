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
bool valid( int x , int y ){
    return x>=0 && x<8 &&y>=0 && y< 8;
}
bool check( int x , int y , pair<int,int> en ){
    if( x == en.first && y == en.second )   return 1;
    return 0;
}
int BFS( pair<int,int> st , pair<int,int> en ){
    queue<pair<int,int> >q;
    bool vis[8][8];
    memset(vis , 0 , sizeof vis);
    int tox , toy;
    q.push({st.first , st.second});
    vis[st.first][st.second] = 0;
    int dep =0 , sz =1;
    bool ok = 1;
    for( ; !q.empty() && ok ;sz = q.size(),dep++){
        while( ok && sz -- ){
            auto cur = q.front();
            q.pop();
            int x = cur.first , y = cur.second;
            tox = x -2, toy = y+1;
            if(check(tox,toy,en)){
                ok = 0;
                break;
            }
            if( valid(tox , toy) && !vis[tox][toy] ){
                vis[tox][toy] = 0;
                q.push({tox, toy});
            }
            tox = x-2 , toy = y-1;
            if(check(tox,toy,en)){
                ok = 0;
                break;
            }
            if( valid(tox , toy) && !vis[tox][toy] ){
                vis[tox][toy] = 0;
                q.push({tox, toy});
            }

            tox = x +2, toy = y+1;
            if(check(tox,toy,en)){
                ok = 0;
                break;
            }
            if( valid(tox , toy) && !vis[tox][toy] ){
                vis[tox][toy] = 0;
                q.push({tox, toy});
            }
            tox = x+2 , toy = y-1;
            if(check(tox,toy,en)){
                ok = 0;
                break;
            }
            if( valid(tox , toy) && !vis[tox][toy] ){
                vis[tox][toy] = 0;
                q.push({tox, toy});
            }

            tox = x +1, toy = y-2;
            if(check(tox,toy,en)){
                ok = 0;
                break;
            }
            if( valid(tox , toy) && !vis[tox][toy] ){
                vis[tox][toy] = 0;
                q.push({tox, toy});
            }
            tox = x - 1 , toy = y-2;
            if(check(tox,toy,en)){
                ok = 0;
                break;
            }
            if( valid(tox , toy) && !vis[tox][toy] ){
                vis[tox][toy] = 0;
                q.push({tox, toy});
            }

            tox = x -1, toy = y+2;
            if(check(tox,toy,en)){
                ok = 0;
                break;
            }
            if( valid(tox , toy) && !vis[tox][toy] ){
                vis[tox][toy] = 0;
                q.push({tox, toy});
            }
            tox = x+1 , toy = y+2;
            if(check(tox,toy,en)){
                ok = 0;
                break;
            }
            if( valid(tox , toy) && !vis[tox][toy] ){
                vis[tox][toy] = 0;
                q.push({tox, toy});
            }
        }
    }
    if( !ok ){
        return dep;
    }
    else{
        return 0;
    }
}
int main(){
    Flash
    string st,en;
    while(cin>>st>>en){
        int x1 = st[0] -'a';     int y1 =int(st[1]-'0')-1;
        int x2 = en[0] -'a';     int y2 =int(en[1]-'0')-1;
        if(x1 == x2 && y1 == y2){
            cout<<"To get from "<<st<<" to "<<en<<" takes "<<0<<" knight moves."<<endl;
            continue;
        }
        else{
            cout<<"To get from "<<st<<" to "<<en<<" takes "<<BFS({x1,y1} , {x2,y2})<<" knight moves."<<endl;
        }
    }
    return 0 ;
}
