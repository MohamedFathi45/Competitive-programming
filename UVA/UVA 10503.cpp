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
bool ok = false;
void Exhastive_Search(vector<pair<int,int> >& v , int prev , pair<int,int>l, int spaces, int all){
    if(v.empty()){
        if(all == spaces && prev == l.first){
            ok = true;
        }
        return ;
    }
    if(all == spaces && prev == l.first){
        ok = true;
        return ;
    }
    for( int i = 0 ; i < v.size() ; i ++ ){
        if(prev == v[i].first){
            pair<int,int> temp = v[i];
            v.erase(v.begin()+i);
            Exhastive_Search(v ,temp.second , l , spaces , all+1);
            v.insert(v.begin()+i ,temp);
        }
        if(prev == v[i].second){
            pair<int,int> temp = v[i];
            v.erase(v.begin()+i);
            Exhastive_Search(v , temp.first , l , spaces , all+1);
            v.insert(v.begin()+i , temp);
        }
    }

}
int main( )
{
    Flash
    int s,p;
    while(cin>>s && s){
        cin>>p;
        vector<pair<int,int> >v;
        pair<int,int> f,l;
        cin>>f.first>>f.second>>l.first>>l.second;
        int x,y;
        for( int i = 0 ; i < p ; i ++ )
        {
            cin>>x>>y;
            v.push_back({x,y});
        }
        ok = false;
        Exhastive_Search(v , f.second, l , s , 0);
        if( ok )    cout<<"YES"<<endl;
        else
                    cout<<"NO"<<endl;
    }
    return 0 ;
}
