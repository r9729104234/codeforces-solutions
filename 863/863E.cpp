#include<bits/stdc++.h>
#include<ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define ld long double
#define pb push_back
#define pa pair<int,int>
#define v1d vector<int>
#define v2d vector<vector<int>>
#define v1p vector<pa> 
#define INF LLONG_MAX
#define M 998244353 
#define mp make_pair
#define RS(v)    sort(v.rbegin(),v.rend())
#define PI 3.14159265
#define ff first
#define ss second
#define endl "\n"
#define v1s vector<string>
#define S(v) sort(v.begin(),v.end())
#define mxpq priority_queue <int>
#define mnpq priority_queue<int,vector<int>,greater<int>>
#define flush cout.flush();
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> multipbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());




void solve(){

    int n;
    cin>>n;

    vector<pair<pair<int,int>, int>> v(n);

    int idx = 0;
    for(auto &i : v){
        cin>>i.ff.ff>>i.ff.ss;
        i.ss = idx;
        idx++;
    }

    // for(auto i  : v){
    //     cout<<i.ff;
    // }
    S(v);

    int ans = -2;

    int s = v[0].ff.ff;
    int e = v[0].ff.ss;

    for(int i = 1 ; i < n ; i++){
        if(v[i].ff.ss <= e){
            ans = v[i].ss;
            break;
        }

        if(v[i].ff.ff == s){
            ans = v[i-1].ss;
            break;
        }

        if(i-2 >= 0 && v[i].ff.ff <= v[i-2].ff.ss+1){
            ans = v[i-1].ss;
            break;
        }

        if(v[i].ff.ff > e+1){
            s = v[i].ff.ff;
        }

        e = max(e, v[i].ff.ss);
    }

    cout<<ans+1;
}    


 
int32_t main(){
    
    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    // #ifndef ONLINE_JUDGE
    //  freopen("input.txt",  "r",  stdin);
    //  freopen("output.txt", "w", stdout);
    // #endif
    
    clock_t z = clock();
    int tc = 1;
    int t = 0;
    // cin>>tc;
    
    while(tc--){
        solve();
    }


 
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';

 
 
}  


