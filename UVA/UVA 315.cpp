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
vector<int> dfn(101,-1), low(101,-1);
int dfn_num=0;
set<int> artpoints;
bool root=0;
void Tarjan(int node , int par , vector<vector<int> >& v){
    dfn[node] = low[node] = dfn_num++;
    for( int i=0 ; i<v[node].size() ; i ++ ){
        int ch = v[node][i];
            if(dfn[ch] == -1){
                Tarjan(ch , node , v);
                low[node] = min(low[node],low[ch]);
                if(low[ch]>=dfn[node]){
                    if(par == -1 && root ==0)
                        root = 1;
                    else
                        artpoints.insert(node);
                }

            }
        else if(ch != node){
            low[node] = min(dfn[ch] , low[node]);
        }
    }
}
void Scc(vector<vector<int> > v , int n){
    for( int i=0; i<101 ; i ++ )
        dfn[i] = low[i] = -1;
    dfn_num=0;  artpoints.clear();
    for( int i=1; i<=n;i++){
        if(dfn[i] == -1){
            root=0;
            Tarjan(i,-1,v);
        }
    }
}
int main(){
    Flash
    int n,k,cnt;
    while(cin>>n && n){
            vector<vector<int> >v(101);
            string str;
            cin.ignore();
            while(getline(cin , str)){
                    if(str == "0")
                    break;
                string num="";
                int temp;
                bool flag=1;
                for( int i=0; i<str.size() ; i ++){
                    if(str[i]!=' ')
                        num+=str[i];
                    else{
                         k=0,cnt=0;
                        for( int j = num.size()-1 ;j>=0 ; j-- ){
                            k += int(num[j]-'0')*power(10,cnt++);
                        }
                        if(flag){
                         temp=k;  flag=0;
                        }
                        else{  v[temp].push_back(k) , v[k].push_back(temp);  }
                        num="";
                    }
                }
                int k=0,cnt=0;
                for( int j = num.size()-1 ;j>=0 ; j-- )
                        k+=int(num[j]-'0')*power(10,cnt++);
                v[temp].push_back(k);
                v[k].push_back(temp);
            }
            Scc(v,n);
            cout<<artpoints.size()<<endl;
    }
    return 0;
}
