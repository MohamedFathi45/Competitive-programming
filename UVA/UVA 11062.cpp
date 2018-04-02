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

bool valid(char ch , int index , int len)
{
    if((index <len)&&(index >= 0) && (index == len-1) && (ch =='-') )    return false;
    if((index <len)&&(index >= 0) && (ch != ' ') && (isalpha(ch)||ch=='-') )  return true;
    return false;
}
int main( )
{
    set<string> res;
    string s , buffer="";
    bool is_complete = false;
    while( getline(cin , s) && s!="Stop")
    {
        for( int i = 0 ; i < s.size() ; i ++ )
        {
            string temp="";
            if( is_complete )
            {
                while( valid(s[i] ,i , s.size()) )
                    buffer+= tolower(s[i]) , i++;

                if( i != s.size()-1 )
                {
                    res.insert(buffer);
                    buffer="";
                    is_complete = false;
                }
                else if( i == s.size()-1 &&s[i] == '-')
                {
                    i = s.size();
                    continue;
                }
            }

                while( true )
                {
                    if(valid(s[i],i ,s.size()))
                    temp+=tolower(s[i]) , i++;
                    else
                        break;
                }

            if( s[i] == '-' && i == s.size()-1 )
            {
                i--;
                temp = "";
                is_complete = true;
                while( valid(s[i],i,s.size()) )
                {
                    char ch = tolower(s[i]);
                    buffer = ch +buffer;
                    i--;
                }
                i = s.size();
                continue;
            }
           else
           {
                if(temp != "")
                {
                    res.insert(temp);
                }
           }
        }
    }
    set<string> ::iterator it = res.begin();
    for( it ; it != res.end() ; it ++ )
        cout<<*it<<endl;

    return 0;
}
