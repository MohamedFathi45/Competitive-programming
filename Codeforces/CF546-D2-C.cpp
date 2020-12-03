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

int main()
{
    Flash
    int n,x;  cin>>n;
    int t1,t2;
    list<int> list1,list2;
    cin>>t1;
    for( int i = 0 ; i < t1 ; i ++ ){
        cin>>x;
        list1.push_back(x);
    }

    cin>>t2;
    for( int i = 0 ; i < t2 ; i ++ ){
        cin>>x;
        list2.push_back(x);
    }

    int res = 0;
    for( int i = 0 ; i < 200 ; i ++ ){
        if(list1.size() ==0 || list2.size() == 0){
            res = i ;
            break;
        }
        int top1 = *list1.begin();
        list1.pop_front();
        int top2 = *list2.begin();
        list2.pop_front();
        if(top1 > top2){
            list1.push_back(top2);
            list1.push_back(top1);
        }
        else{
            list2.push_back(top1);
            list2.push_back(top2);
        }
    }
    if(list1.size() && list2.size()){
        cout<<-1<<endl;
    }
    else{
        if(list1.size() == 0){
            cout<<res<<" "<<2<<endl;
        }
        else{
            cout<<res<<" "<<1<<endl;
        }
    }
}

