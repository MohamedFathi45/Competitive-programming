#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
using namespace std;
void play( )
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
int main( )
{
    play();
    int a,b,c;      cin>>a>>b>>c;
    int cups = a+b+c;
    cin>>a>>b>>c;
    int medals = a+b+c;
    int res = 0 ;
    int k  = cups / 5;
    res = k;
    if( k * 5 < cups )
        res++;
     k = medals / 10;
     res +=k;
     if( k *10 < medals )
        res++;

     int all;       cin>>all;
     if( all >= res )
        cout<<"YES"<<endl;
     else
        cout<<"NO"<<endl;
     return 0;
}