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
#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;

int main()
{
    Mohamed_Fathi
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int index1=0 ,index2=0;
        int counter = 0 ;
        while( index1 < s1.size() && index2 < s2.size() )
        {
            while( index2 < s2.size() )
            {
                if(s1[index1] == s2[index2])
                {
                    counter++;
                    index2++;
                    index1++;
                    break;
                }
                else
                index2++;
            }
        }
            if( counter ==s1.size())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
    }
    return 0;
}
