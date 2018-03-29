


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
    map<string , string>mp1 , mp2;
    int n, counter = 0 ;      cin>>n;
    string str1,str2;

    for( int i = 0 ; i < n ; i ++ )
    {
        counter = 1 ;
        cin>>str1>>str2;
        while( counter < str1.size() )
        {
            string temp1="";        //for letters
            while(isalpha(str1[counter]))
            {
                temp1+=str1[counter];
                counter++;
            }
            if( str1[counter] == ':' )
            counter++;
            string temp2="";         //for numbers
            while( str1[counter] >= 48 && str1[counter] <= 57 )
            {
                temp2+=str1[counter];
                counter++;
            }
            if( str1[counter] == ','  || str1[counter] == '}')
            counter++;
            if(temp1!="" && temp2!="")
            mp1[temp1] = temp2;
        }
        counter = 1 ;
        while( counter < str2.size() )
        {
            string temp1="";        //for letters
            while(isalpha(str2[counter]))
            {
                temp1+=str2[counter];
                counter++;
            }
            if( str2[counter] == ':' )
                counter++;
            string temp2="";         //for numbers
            while( str2[counter] >= 48 && str2[counter] <= 57 )
            {
                temp2+=str2[counter];
                counter++;
            }
            if( str2[counter] == ','  || str2[counter] == '}')
                counter++;
            if(temp1!="" && temp2!="")
            mp2[temp1] = temp2;
        }

        map<string , string >::iterator it1 = mp1.begin();
        map<string , string >::iterator it2 = mp2.begin();
        map<string , string >::iterator temp;
        set<string> rem , add , update;

        for( it1 ; it1 != mp1.end(); it1++ )
        {
            if( mp2.count(it1->first) == 0 )
            {
                rem.insert(it1->first);
            }
        }

        for( it2 ; it2!= mp2.end() ; it2++ )
        {
            if( mp1.count(it2->first) == 0 )
                add.insert(it2->first);
            else
            {
                temp = mp1.find(it2->first);
                if(temp->second != it2->second)
                    update.insert(it2->first);
            }
        }
        set<string>::iterator it_res = add.end();
        int s1=add.size() , s2=rem.size() , s3=update.size();
        if(add.size() > 0)
        {
            cout<<"+";
            int cnt = 0 ;
            for( it_res=add.begin() ; it_res != add.end() ; it_res++ )
            {
                if(cnt)
                    cout<<",";
                cnt++;
                cout<<*it_res;
            }
            cout<<endl;
        }
        it_res = rem.end();
        if( rem.size() > 0 )
        {
            cout<<"-";
            int cnt = 0 ;
            for( it_res=rem.begin() ; it_res != rem.end() ; it_res++ )
            {
                if(cnt)
                    cout<<",";
                cnt++;
                cout<<*it_res;
            }
            cout<<endl;
        }

        it_res = update.end();
        if( update.size() > 0 )
        {   cout<<"*";
            int cnt = 0 ;
            for( it_res=update.begin() ; it_res != update.end() ; it_res++ )
            {
                if(cnt)
                    cout<<",";
                cnt++;
                cout<<*it_res;
            }
            cout<<endl;
        }
        if(s1 == 0 && s2 == 0 && s3 ==0)
            cout<<"No changes"<<endl;
            rem.clear() , add.clear() , update.clear();
            mp1.clear() , mp2.clear();
        cout<<endl;
    }

    return 0;
}
