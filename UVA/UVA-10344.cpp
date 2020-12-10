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
long long arr[5];
long long temp_arr[5];
bool found = 0;
bool vis[5];
void solve(int len , int value , bool first){
    if(found)
        return;
    if(len == 5){
        if(value == 23)
            found = 1;
        return;
    }
    for( int j = 0 ; j < 5 ; j ++ ){
        if(vis[j])
            continue;
        vis[j] = 1;
        if(first){
            solve(len+1 , value + arr[j] , 1);
            solve(len+1 , value - arr[j] , 1);
            solve(len+1 , value * arr[j] , 1);
        }
        else{
            solve(len+1 , arr[j] , 1);
        }
        vis[j] = 0;
    }
}

int main()
{
    Flash
    while(true){
        bool go = false;
        for(int i = 0 ; i < 5 ; i ++ ){
            cin>>arr[i];
            if(arr[i])
                go = true;
        }
        if(go){
            found = 0;
            solve(0,0,0);
            if(found){
                cout<<"Possible"<<endl;
            }
            else{
                cout<<"Impossible"<<endl;
            }
        }
        else{
            break;
        }
    }
}

