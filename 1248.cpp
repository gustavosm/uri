	 #include <bits/stdc++.h>

using namespace std;

map<char, int> m;
int main ()
{
	//ios_base :: sync_with_stdio(0);// cin.tie(0);
	
    int i, cases, flag;
    map<char, int> :: iterator it;
    string s1, s2, s3;

    cin>>cases;
    getchar();
    while(cases--)
    {
        m.clear();
        getline(cin,s1);
        for (i=0;i<s1.size();i++)
            m[s1[i]]=1;
        getline(cin,s2);
        flag=0;
        for (i=0;i<s2.size(); i++)
        {
            if (m[s2[i]] == 0)
            {
                flag=1;
                break;
            }
            else
                m[s2[i]]=0;
        }
        getline(cin,s3);
        for (i=0;i<s3.size(); i++)
        {
            if (m[s3[i]] == 0)
            {
                flag=1;
                break;
            }
            else
                m[s3[i]]=0;
        }
        if (flag==1) cout<<"CHEATER";
        else
        {
            for (it=m.begin();it!=m.end();it++)
                if (it->second==1) cout<<it->first;
        }
        cout<<'\n';
    }
}
