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
#include<list>
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
double EPS = 1e-7;
int xDir[]={0, 0,1,-1};
int yDir[]={1,-1,0,0 };
int inf = 1e7;
int dcomp( double a , double b ){
if( fabs(a - b ) <= EPS )    return 0;
return ((a > b) ? 1 : -1);
}

int main( )
{
    int n;      cin>>n;
    string str; cin>>str;
    int ptr1 = 0 , ptr2 = 0;
    set<char> st;
    for( int i = 0 ; i < n ; i ++ )
        st.insert(str[i]);
    map<char , int>mp;
    int len = st.size() , cnt = 0 , l = 0 , r = n ;
    for( int i = 0 ; i < n ; i ++ )
    {
        ptr1 = i;
        for( ; ptr2 < n ; ptr2++ )
        {
            if(cnt == len)  break;
            if(!mp[str[ptr2]])  cnt++;
            mp[str[ptr2]]++;
        }
        if( cnt == len && ((r - l) > (ptr2 - ptr1)) )
        {   l = ptr1;   r = ptr2;    }
        if(mp[str[ptr1]])
            mp[str[ptr1]]--;
        if(!mp[str[ptr1]])
            cnt--;
    }
    cout<<r - l<<endl;
    return 0 ;
}
