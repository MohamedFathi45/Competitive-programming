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
    int n;      cin>>n;
    unsigned long long odds[100001];
    int od_counter =0;
    unsigned long long sum = 0;
    unsigned long long x;
    for( int i = 0 ; i < n; i++ )
    {
        cin>>x;
        if( x %2 == 0 )
            sum+= x;
        else
            odds[od_counter++] = x;
    }
    sort(odds , odds+od_counter);

    if( od_counter %2 != 0)
    {
        for( int i = od_counter-1 ; i >0 ; i -- )
            sum+= odds[i];
    }
    else
    {
        for( int i = 0 ; i < od_counter ; i ++ )
            sum+=odds[i];
    }
    cout<<sum<<endl;
    return 0;

}