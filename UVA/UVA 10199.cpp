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
const int MAX = 2e5;
int xDir[]={0, 1,-1,0};
int yDir[]={1,0,0 ,-1};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
bool root = false;
int dfn_num=0;
vector<int> dfn(1001,-1),low(1001,-1);
set<int> artpoints;
void Tarjan( int node , int par ,vector<vector<int> >adj ){
    dfn[node] = low[node] = dfn_num++;
    for( int i = 0 ; i < adj[node].size() ; i ++ ){
        int ch = adj[node][i];
        if(dfn[ch] == -1){
            Tarjan(ch , node ,adj);
            low[node] = min(low[ch] , low[node]);
            if(low[ch] >= dfn[node]){
                if(root == false && par == -1)
                root = 1;
                else
                artpoints.insert(node);
            }
        }
        else if(ch != par)
            low[node] = min(dfn[ch] , low[node]);
    }
}
void Scc( int n, vector<vector<int> > adj , vector<string> v , map<string , int>mp1 ){
    root = false;   dfn_num=0;  artpoints.clear();
    for( int i=0 ; i <1000 ; i ++ )
        dfn[i] = low[i] = -1;
    for( int i=0; i<v.size() ; i ++ ){
        if(dfn[mp1[v[i]]] == -1){
            root = 0;
            Tarjan(mp1[v[i]] , -1 , adj);
        }
    }
}
int main(){
    Flash
    int n,m,cnt=0;
    string str;
    while(cin>>n && n){
        if(cnt) cout<<endl;
        vector<string>v(1000);
        vector<vector<int> >adj(1000);
        map<string,int>mp1;
        for( int i=0; i<n; i ++ ){
            cin>>str;
            v[i] = str;
            mp1[str] = i;
        }
        cin>>m;
        string st , dist;
        for(int i = 0 ; i < m ; i ++ ){
            cin>>st>>dist;
            adj[mp1[st]].push_back(mp1[dist]);
            adj[mp1[dist]].push_back(mp1[st]);
        }
        Scc(n,adj,v,mp1);
        set<int>::iterator it = artpoints.begin();
        vector<string> res;
        for(;it!=artpoints.end() ; it++){
            res.push_back(v[*it]);
        }
        sort(res.begin() , res.end());
        cout<<"City map #"<<++cnt<<": "<<artpoints.size()<<" camera(s) found"<<endl;
        for( int i = 0 ; i < res.size() ; i ++ )
            cout<<res[i]<<endl;
    }
    return 0;
}
