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
        vector<int> v(n);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]==1) cnt++;
        }
        int res = 0;
        bool flag = 0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==1)
            {
                flag = 1;
                cnt--;
                if(cnt==0)
                {
                    flag = 0;
                }
            }
            else
            {
                if(flag)
                {
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
}

void solveB()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n),x(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>x[i];
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({abs(x[i]),a[i]});
        }
        sort(v.begin(),v.end());
        bool flag = 0;
        int sum = 0;
        for(int i=0;i<n;i++)
        {   
            sum += v[i].second;
            if(sum>v[i].first*k)
            {
                flag = 1;
                break;
            }
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}

void solveC()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> pre(n);
        vector<int> ones(n);
        ones[0] = (v[0]==1);
        pre[0] = v[0];
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1]+v[i];
            ones[i] = ones[i-1] + (v[i]==1);
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            int k = y-x+1;
            if(k==1)
            {
                cout<<"NO"<<endl;
                continue;
            }
            int sum = x>0 ? pre[y]-pre[x-1] : pre[y];
            int one = x>0 ? ones[y]-ones[x-1] : ones[y];
            if(one+k>sum)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;
            }
        }
    }
}

int32_t main()
{
    //solveA();
    //solveB();
    solveC();
    return 0;
}