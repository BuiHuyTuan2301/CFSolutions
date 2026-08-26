#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define taskname "1"
#define on(i) (1ll<<i)
#define pb push_back

const ll maxn = 3e5 + 5;

ll n,t,x,dp[maxn],nex[maxn],dem;
char y,s[maxn];
deque<pair<int,int>>q;
pair<int,int>id[maxn];

void bfs()
{
     dp[0]=1;
     for (int i=1;i<=on(n-1);i++)
     {
     id[i]={0,0};
     if (s[i]!='?')
        dp[i]=1;
     else
        dp[i]=2;
      q.pb({dp[i],i});
     }

     dem=on(n-1);

     while (dem<on(n)-1)
     {
         int x=q.front().fi,last1=q.front().se;
         q.pop_front();
         int y=q.front().fi,last2=q.front().se;
         q.pop_front();
         ++dem;
         id[dem]={last1,last2};
         nex[last1]=nex[last2]=dem;

         if (s[dem]=='0')
           dp[dem]=x;
         else
         if (s[dem]=='1')
            dp[dem]=y;
         else
            dp[dem]=x+y;

         q.pb({dp[dem],dem});

     }
}

void dfs(int u)
{
     if (s[u]=='0')
        dp[u]=dp[id[u].fi];
     else
     if (s[u]=='1')
        dp[u]=dp[id[u].se];
     else
        dp[u]=dp[id[u].fi]+dp[id[u].se];

     while (nex[u]!=0)
     {
        u=nex[u];
        if (s[u]=='0')
        dp[u]=dp[id[u].fi];
        else
        if (s[u]=='1')
          dp[u]=dp[id[u].se];
        else
          dp[u]=dp[id[u].fi]+dp[id[u].se];
     }
}
int main()
{

   if (fopen(taskname".INP","r"))
   {
       freopen(taskname".INP","r",stdin);
       freopen(taskname".OUT","w",stdout);
   }
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);

   cin>>n;
   for (int i=1;i<on(n);i++)
       cin>>s[i];

   bfs();


   cin>>t;
   while (t--)
   {
       cin>>x>>y;
       if (s[x]==y)
       {
           cout<<dp[on(n)-1]<<'\n';
           continue;
       }
       else
       {
           s[x]=y;
           dfs(x);

           cout<<dp[on(n)-1]<<'\n';
         
       }
   }



   return 0;

}
