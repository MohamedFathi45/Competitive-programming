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
int n,m;
char ch[1000][1000];
int vis[1000][1000];
int res[1000][1000],cnt=0;
vector<int>vec;
void write( ){
    for( int i = 0 ; i < vec.size() ; i+=2 ){
        res[vec[i]][vec[i+1]] = cnt;
    }
    vec.clear();
}
bool valid( int i , int j ){
    if( i>=n || i<0 || j>=m || j<0 )    return 0;
    return 1;
}
void DFS( int i, int j ,int k ){
    if(ch[i][j]=='*' || vis[i][j] == k || !valid(i,j)) return;
    vis[i][j] =k;
    cnt++;
    for( int q=0; q<4; q++ ){
        int tox = i+xDir[q];
        int toy = j+yDir[q];
        if(valid(tox,toy) && vis[tox][toy] != k)
            DFS(tox,toy,k);
    }
    vec.push_back(i);
    vec.push_back(j);
}
int main( )
{
    Flash
    cin>>n>>m;
    for( int i=0; i<n; i ++ )
        for( int j =0; j<m ; j++)
        cin>>ch[i][j];
    int v =1;
    memset(vis , 0 , sizeof vis);
    for( int i = 0 ; i <n; i++ ){
        for( int j = 0; j< m ; j++){
            cnt=0;
            if(!vis[i][j] && ch[i][j] =='.'){
                DFS(i,j,v++);
                write();
            }
        }
    }
    for( int i =0 ; i<n; i ++ ){
        for( int j = 0 ; j <m; j ++ ){
            if(ch[i][j]=='.')
                cout<<".";
            else{
                int sum=0;
                set<int>st;
                for( int q=0; q<4; q++ ){
                    int tox = i+xDir[q];
                    int toy = j+yDir[q];
                    if( valid(tox,toy) && ch[tox][toy] != '*' && st.find(vis[tox][toy]) == st.end())
                        sum+=res[tox][toy] , st.insert(vis[tox][toy]);
                }
                cout<<(sum+1)%10;  st.clear();
            }
        }
        cout<<endl;
    }

    return 0;
}
