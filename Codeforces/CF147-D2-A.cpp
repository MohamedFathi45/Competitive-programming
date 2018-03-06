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
    string arr[2000];
    string str;     getline( cin , str);
    int arr_counter = 0 ;
    for( int i = 0 ; i < str.length() ; i ++ )
    {
        string e="";
        while( str[i] >= 97 && str[i] <= 122 && i < str.size() )
        {
            e+=str[i];
            i++;
        }
        if(e!= "")
        {
            arr[arr_counter++]=e;
        }
        e="";
        while( (str[i]<97 || str[i] > 122) && (i < str.size() ) && str[i] != ' ' )
        {
            e+=str[i];
            i++;
        }
        if(e!= "")
        {
            arr[arr_counter++]=e;
            i--;
        }
    }

    for( int i = 0 ; i<arr_counter ; i ++ )
    {
        if( (arr[i][0] >='a' && arr[i][0]<='z')  && (arr[i+1][0]>='a' && arr[i+1][0]<='z') &&(i+1<str.size())  )
            cout<<arr[i]<<" ";

         else if( (arr[i][0] >='a' && arr[i][0]<='z')  && (arr[i+1][0] < 'a' ||arr[i+1][0] > 'z') &&(i+1<str.size()))
            cout<<arr[i];
         else if( (arr[i][0] < 'a' || arr[i][0] > 'z') )
            cout<<arr[i]<<" ";
        else
            cout<<arr[i];

    }
    return 0;
}

