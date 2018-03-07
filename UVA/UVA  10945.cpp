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

bool plandorm(string str )
{
    if( str.length() <= 1 )
        return true;
    else
    {
        char first = str[0];
        char last = str[str.length()-1];
        string mid = str.substr(1 , str.length()- 2);
        if(first == last && plandorm(mid) )
        {
            return true;
        }
        else
            return false;
    }
}

bool punc(char ch)
{
	if (ch == '.' || ch == '!' || ch == ' ' || ch == '?' || ch == ',')
		return 1;
	return 0;
}

int main( )
{
    play();
    string str;
    while( getline(cin , str) && str != "DONE")
    {
        string e="";
        for( int i = 0 ; i < str.length() ; i ++ )
        {
            if(punc(str[i]))
                continue;
            else if( (str[i] >= 'a' && str[i] <='z') ||( str[i]>='A' && str[i]<='Z') )
                e+=toupper(str[i]);
            else
                e+=str[i];
        }

    if( plandorm (e) )
        cout<<"You won't be eaten!"<<endl;
    else
        cout<<"Uh oh.."<<endl;
    }
    return 0;
}
