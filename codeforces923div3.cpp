#include<bits/stdc++.h>
#define int long long
using namespace std;

void solveA()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=-1,r=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')
            {
                l = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='B')
            {
                r = i;
                break;
            }
        }
        if(l==-1 || r==-1)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<r-l+1<<endl;
        }
    }
}

void solveB()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        string res;
        map<char,int> m;
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                char ch = 'a'+c;
                res.push_back(ch);
                m[ch]++;
                c++;
            }
            else
            {
                for(auto j : m)
                {
                    if(j.second == v[i])
                    {
                        res.push_back(j.first);
                        m[j.first]++;
                        break;
                    }
                }
            }
        }
        cout<<res<<endl;
    }
}

void solveC()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> v1(n);
        vector<int> v2(m);
        for(int i=0;i<n;i++) cin>>v1[i];
        for(int i=0;i<m;i++) cin>>v2[i];
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        bool res = true;
        int cnt1 = 0;
        for(int i=0;i<n;i++)
        {
            if(v1[i]<=k)
            {
                mp1[v1[i]]++;
                if(mp1[v1[i]]==1) cnt1++;
            }
        }
        int cnt2 = 0;
        for(int i=0;i<m;i++)
        {
            if(v2[i]<=k)
            {
                mp2[v2[i]]++;
                if(mp2[v2[i]]==1) cnt2++;
            }
        }
        if(cnt1<(k/2) || cnt2<(k/2)) res = false;
        bool r = true;
        vector<int> temp(k+1,0);
        for(auto i : mp1)
        {
            if(i.first<=k)
            {
                temp[i.first]=1;
            }
        }
        for(auto i : mp2)
        {
            if(i.first<=k)
            {
                temp[i.first]=1;
            }
        }
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i]==0)
            {
                r = false;
                break;
            }
        }
        if(r==false) res = false;
        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

void solveD()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> temp(n,n);
        for(int i=n-2;i>=0;i--)
        {
            if(v[i+1]!=v[i])
            {
                temp[i] = i+1;
            }
            else
            {
                temp[i] = temp[i+1];
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            if(temp[l-1]>=r)
            {
                cout<<-1<<" "<<-1<<endl;
            }
            else
            {
                cout<<l<<" "<<temp[l-1]+1<<endl;
            }
        }
        cout<<endl;
    }
}

int32_t main()
{
    // solveA();
    // solveB();
    // solveC();
    solveD();
    return 0;
}