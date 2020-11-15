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
char ch[182][182];
int dist[182][182];
bool vis[182][182];
int n,m;
bool valid(int x , int y){
    if(x < 0 || x >=n || y < 0 || y>=m)
        return 0;
    return 1;
}

void BFS(queue<pair<int,int> >q){

    int sz = 1 , dep = 0;
    for(  ; sz !=0 ; sz = q.size() , ++dep){
        while(sz --){
            pair<int,int> cur = q.front();
            q.pop();
            for( int i = 0 ; i < 4 ; i ++ ){
                int tox = cur.first + xDir[i];
                int toy = cur.second + yDir[i];
                if(valid(tox , toy)){
                    if(!vis[tox][toy]){
                        q.push({tox,toy});
                        dist[tox][toy] = dist[cur.first][cur.second] + 1;
                        vis[tox][toy] = 1;
                    }
                }
            }
        }
    }
}
int main()
{
    Flash
    int k;
    cin>>k;
    string s;
    while(k --){
        for( int i = 0 ; i < 182 ; i ++ )
            for(int j = 0 ; j < 182 ; j ++ )
                dist[i][j] = 1e5;
        for( int i = 0 ; i < 182 ; i ++ )
            for(int j = 0 ; j < 182 ; j ++ )
                vis[i][j] = 0;
        cin>>n>>m;
        for( int i = 0 ; i < n ; i ++ ){
            cin>>s;
            for( int j = 0 ; j < s.size() ; j ++ )
                ch[i][j] = s[j];
        }
        queue<pair<int,int> > q = queue<pair<int,int> >();
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < m ;j ++ ){
                if(ch[i][j] == '1'){
                    vis[i][j] = 1;
                    q.push({i,j});
                    dist[i][j] = 0;
               }
           }
        }
        BFS(q);
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < m ; j ++ )
                cout<<dist[i][j]<<" ";
            cout<<endl;
        }

    }
}

