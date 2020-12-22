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
char ch[100][100];
bool vis[101][101][16];
int dist[101][101][16];
bool valid(int x , int y){
    if(x < 0 || x >=n || y < 0 || y>=m)
        return 0;
    return 1;
}

int letter[26];

int BFS(pair<int,int> start){
    memset(vis , 0 , sizeof vis);
    queue<pair<int,pair<int,int>> > q;
    q.push( {0,start} );
    vis[start.first][start.second][0] = 1;
    dist[start.first][start.second][0] = 0;
        while(q.size()){
            auto cur = q.front();
            q.pop();
            for( int i = 0 ; i < 4 ; i ++ ){
                int tox = xDir[i] + cur.second.first;
                int toy = yDir[i] + cur.second.second;
                if(!valid(tox , toy) || ch[tox][toy] == '#' || vis[tox][toy][cur.first] ){
                    continue;
                }
                else{
                    if(ch[tox][toy] =='X'){
                        return dist[cur.second.first][cur.second.second][cur.first]+1;
                    }
                    else if(ch[tox][toy] == '.'){
                        if(!vis[tox][toy][cur.first]){
                            vis[tox][toy][cur.first] = 1;
                            dist[tox][toy][cur.first] = dist[cur.second.first][cur.second.second][cur.first]+1;
                            q.push({cur.first , {tox , toy} });
                        }
                    }
                    else if(isupper(ch[tox][toy])){
                        int key = cur.first;
                        if(key & (letter[tolower(ch[tox][toy])-'a'])){
                            if(!vis[tox][toy][cur.first]){
                                vis[tox][toy][cur.first] = 1;
                                dist[tox][toy][cur.first] = dist[cur.second.first][cur.second.second][cur.first]+1;
                                q.push({cur.first , {tox , toy} });
                            }
                        }
                    }
                    else{
                        int key = cur.first;
                        key |= (letter[ch[tox][toy] -'a']);
                        if(! vis[tox][toy][key]){
                            vis[tox][toy][key] = 1;
                            dist[tox][toy][key] = dist[cur.second.first][cur.second.second][cur.first]+1;
                            q.push({key , {tox , toy} });
                        }
                    }
                }
            }
        }
    return -1;
}
int main()
{
    Flash
    while( (cin>>n>>m) && (n || m) ){
        letter['b' -'a'] = 1;
        letter['y' -'a'] = 2;
        letter['r' -'a'] = 4;
        letter['g' -'a'] = 8;
        pair<int,int>start;
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < m ; j++ ){
                cin>>ch[i][j];
                if(ch[i][j] == '*' )
                    start = {i,j};
        }
        int res = BFS(start);
        if(res == -1)
            cout<<"The poor student is trapped!"<<endl;
        else
            cout<<"Escape possible in "<<res<<" steps."<<endl;
    }

}

