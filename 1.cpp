#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define ll long long
#define fi first
#define se second
#define taskname "1"
#define on(i) (1ll<<i)
#define pii pair<ll,ll>

const ll maxn = 1e5+9;

ll n,m;

struct EDGE
{
    ll w,x,y;
};

vector<EDGE> v;

struct DSU
{

    vector<int> pa,sz;

    DSU (int n)
    {
        pa.resize(n+1);
        sz.assign(n+1,1);
        for (int i=1;i<=n;i++)
           pa[i]=i;
    }

    int find_set(int u)
    {
        return (u==pa[u]?u:pa[u]=find_set(pa[u]));
    }

    bool union_set(int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        if (a!=b)
        {
            if (sz[a]<sz[b])
              swap(a,b);
            sz[a]+=sz[b];
            pa[b]=a;
            return 1;
        }
        return 0;
    }

};

int main()
{
    if(fopen(taskname".INP", "r")) {
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    ll x,y,z;

    cin>>n>>m;

    for (int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        v.pb({z,x,y});
    }

    sort(v.begin(), v.end(), [] (const EDGE &a , const EDGE &b)
    {
        return a.w>b.w;
    });

    DSU dsu(n);

    ll ans=0,dem=0;

    for (auto [w,x,y]:v)
    {
        if (dsu.union_set(x,y))
        {
          ans+=w;
          dem++;
        }
    }

    cout<<(dem==n-1?ans:-1);
  
    return 0;

}

