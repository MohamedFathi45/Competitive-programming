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

int pos;
vector<int>vec;
int best_dist(char lettera , char letterb){
    int dist1 = abs( (lettera - 'a') - (letterb -'a') );
    int dist2 = abs( (lettera - 'a') - ('z' -'a') );
    dist2 += letterb-'a' + 1;
    int dist3 = abs( (letterb - 'a') - ('z' -'a') );
    dist3 += lettera-'a' + 1;
    return min(dist1,min(dist2,dist3));
}

int get_min_dist(int l , int r,string str){
    int ret = 0;
    for( int left = l , right = r ; left >=0 && right < str.size() ; left-- , right++ ){
        if(str[left] != str[right])
            vec.push_back(left);
        ret+=best_dist(str[left] , str[right]);
    }
    return ret;
}

int main()
{
    Flash
    string str;
    int len;
    cin>>len>>pos;
    cin>>str;
    if(pos > str.size()/2){
        reverse(str.begin() , str.end());
        pos = str.size() - (pos-1);
    }
    pos--;

    int res = 0;
    if(str.size()&1){
        res = get_min_dist(str.size()/2-1 , str.size()/2+1,str);
    }else{
        if(str[str.size()/2] != str[str.size()/2 -1] )
            vec.push_back(str.size()/2-1);
        res = best_dist( str[str.size()/2] ,str[str.size()/2 -1]);
        res += get_min_dist(str.size()/2-2 , str.size()/2+1,str);
    }

    if(vec.size() == 1){
        res += abs(pos - vec[0]);
    }
    else if(vec.size() >= 2){
        sort(vec.begin() , vec.end());
        int d1 =  abs(pos - vec[0]);
        int d2 = abs(pos - vec[vec.size()-1]);
        if(vec[0] <= pos && vec[vec.size()-1] >= pos){
            res += min(d1 , d2) * 2 + max(d1 , d2);
        }
        else{
            res += max(d1,d2);
        }
     }
    cout<<res<<endl;
}

