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
int cat[100000];
bool vis[100000];
vector<vector<int>>adj(100000);
int cnt = 0;


/*
void print_path(stack<int> st){
    cout<<"path size is :"<<st.size()<<endl;
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
*/


void solve( int vtx, int parent , stack<int>& path){
    if(adj[vtx].size() == 1 && vtx != 0){
        cnt++;
        return;
    }
    for( int i = 0 ; i < adj[vtx].size() ; i ++ ){
        int ind = adj[vtx][i];
        if(ind == parent || cat[ind] + cat[vtx] > m)
            continue;
        if(cat[ind])
            cat[ind] = cat[vtx] + cat[ind];
        path.push(ind);
        solve(ind, vtx , path);
        path.pop();
    }

}

int main()
{
    Flash
    cin>>n>>m;
    memset(vis , 0 , sizeof vis);
    memset(cat , 0 , sizeof cat);
    for( int i = 0 ; i < n ; i ++ )
        cin>>cat[i];
    int x,y;
    for( int i = 0 ; i < n-1; i ++ ){
        cin>>x>>y;
        x-- , y --;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    stack<int> st;
    st.push(0);
    solve( 0 , -1  , st);
    cout<<cnt<<endl;
}

