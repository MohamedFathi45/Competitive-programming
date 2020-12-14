#include <iostream>
#include <math.h>
#include<vector>
#include<map>
#include<algorithm>
#include <list>
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
int n , r1,c1,r2,c2;
int arr[101];
bool valid(int x , int y){
    if(x < 0 || x >=n || y < 0 || y > arr[x])
        return 0;
    return 1;
}
void BFS(vector<vector<int>> &vec){
    if (r1 == r2 and c1 == c2)
    {
        vec[r2][c2] = 0;
        return;
    }
    queue<pair<int,int> >q;
    q.push({r1,c1});
    vec[r1][c1] = 0;
    while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for( int i = 0 ; i < 4 ; i ++ ){
                int tox = cur.first + xDir[i];
                int toy = cur.second + yDir[i];
                toy > arr[tox] ? toy = arr[tox] : toy ;

                if(valid(tox , toy) && vec[tox][toy] == -1){
                    vec[tox][toy] = vec[cur.first][cur.second] + 1;
                    q.push({tox , toy});
                    if(tox == r2 && toy == c2)
                        return;
                }
            }
        }
}

int main()
{
    Flash
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i = 0 ; i < n ; i ++ )
        cin>>arr[i];
    cin>>r1>>c1>>r2>>c2;
    r1-- , c1-- , r2-- , c2--;
    vector<vector<int>> vec(n);
    for( int i = 0 ; i < n ; i ++ ) vec[i].resize(arr[i] + 1);
    for(int i = 0 ; i < n ;i ++){
        for( int j = 0 ; j < vec[i].size() ; j ++ )
            vec[i][j] = -1;
    }
    BFS(vec);
    cout<<vec[r2][c2]<<endl;
}

