#include<bits/stdc++.h>
#define int long long
using namespace std;

void solveA()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int l=0,r=0;
        for(auto i : s)
        {
            if(i=='A') l++;
            else r++;
        }
        if(l>r) cout<<'A'<<endl;
        else cout<<'B'<<endl;
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
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        bool flag = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]=='1')
                {
                    int temp = 0;
                    if(i>0 && v[i-1][j]=='1') temp++;
                    if(i<n-1 && v[i+1][j]=='1') temp++;
                    if(j>0 && v[i][j-1]=='1') temp++;
                    if(j<n-1 && v[i][j+1]=='1') temp++;
                    if(temp<=1)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag)
        {
            cout<<"TRIANGLE"<<endl;
        }
        else cout<<"SQUARE"<<endl;
    }
}

int func(int num)
{
    int res = 0;
    while(num>0)
    {
        res+= num%10;
        num = num/10;
    }
    return res;
}

void solveC()
{
    int t;
    cin>>t;
    vector<int> v(200000+5);
    v[0] = 0;
    for(int i=1;i<=200000;i++)
    {
        v[i] = v[i-1]+func(i);
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<v[n]<<endl;
    }
}

int func1(int num)
{
    int res = 0;
    res = num^(INT_MAX);
    return res;
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
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[v[i]]++;
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int temp = m[func1(v[i])];
            if(temp>0 && m[v[i]]>0)
            {
                if(temp>=m[v[i]])
                {
                    res += m[v[i]];
                    m[func1(v[i])] -= m[v[i]];
                    m[v[i]] = 0;
                }
                else
                {
                    res += temp;
                    m[v[i]] -= temp;
                    m[func1(v[i])] = 0;
                }
            }
            else
            {
                res += m[v[i]];
                m[v[i]] = 0;
            }
        }
        cout<<res<<endl;
    }
}

void solveE()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a = 1,d = 2;
        int p = 2;
        bool flag = 0;
        for(int i=0;i<31;i++)
        {
            int temp = (n-a)/(d)+1;
            if(k<=(temp))
            {
                cout<<(a+(k-1)*(d))<<endl;
                flag = 1;
                break;
            }
            else
            {
                a = a*2;
                d = d*2;
                k = k - temp;
                p = p*2;
            }
        }
    }
}

int32_t main()
{
    //solveA();
    //solveB();
    //solveC();
    //solveD();
    solveE();
    return 0;
}