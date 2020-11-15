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

int n,m;
char ch[1000][1000];
int dist[1000][1000];


bool valid(int x , int y){
    if(x < 0 || x >=n || y < 0 || y>=m || ch[x][y] == 'X')
        return 0;
    return 1;
}

void BFS( pair<int,int> start){
    queue<pair<int,int> >q;
    q.push({start.first , start.second});
    while(q.size()){
        auto cur = q.front();
        q.pop(); 
        for( int i = 0; i < 8 ; i ++ ){
            pair<int,int> copy = cur;
            copy.first  += xDir[i];
            copy.second += yDir[i];
            while(valid(copy.first,copy.second)){
                if(dist[copy.first][copy.second] == 0){
                    dist[copy.first][copy.second] = dist[cur.first][cur.second] + 1;
                    q.push({copy.first ,copy.second});
                }
                else if(dist[copy.first][copy.second] != dist[cur.first][cur.second] + 1)
                    break;
                copy.first += xDir[i];
                copy.second += yDir[i];
            }
        }
    }
}

int main()
{
    Flash
    int t;      cin>>t;
    while( t-- ){
        cin>>n>>m;
        pair<int,int>start;
        pair<int,int>end;
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < m ; j++ ){
                dist[i][j] = 0;
                cin>>ch[i][j];
                if(ch[i][j] == 'S' ){
                    start = {i,j};
                    dist[i][j] = 1;
                }
                else if(ch[i][j] == 'F')
                    end = {i,j};
        }
         BFS(start);
         cout<<dist[end.first][end.second]-1<<endl;

    }

}

