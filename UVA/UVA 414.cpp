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
int arr[1000];
int main( )
{
    Flash
    int n;
    string str;
    while(cin>>n && n){
        for( int i = 0 ; i < n ; i ++ ){
            cin.ignore();
			getline(cin, str);
            for( int j=0; j<str.size() ; j++ ){
                if(str[j] != 'X')
                    arr[i]++;
            }
        }
        int sum=0;
        int mn = *min_element(arr,arr+n);
        for( int i = 0 ; i < n ; i ++ ){
            sum+=arr[i]-mn;
        }
        cout<<sum<<endl;
        memset(arr,0,sizeof arr);
    }
    return 0;
}
