#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<int>a(n+1);

    ordered_set<pair<int,int>> s;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=k;i++)
        s.insert({a[i],i});

    cout<<s.find_by_order((k-1)/2)->first<<" ";

    for(int i=k+1;i<=n;i++){
        s.erase({a[i-k],i-k});
        s.insert({a[i],i});
        cout<<s.find_by_order((k-1)/2)->first<<" ";
    }
}