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

int solve(int i , int t ,vector<pair<pair<int,int>, pair<int,int>>> &v , v2d &dp){

    if(i == v.size()){
        dp[i][t] = 0;
        return 0;
    }

    if(dp[i][t] != -1){
        return dp[i][t];
    }

    int ans = 0;
    if(v[i].ff.ss + t < v[i].ff.ff){
        ans = solve(i+1, t + v[i].ff.ss, v,dp)+v[i].ss.ff;
    }

    ans = max(ans, solve(i+1, t , v, dp));

    dp[i][t] = ans;
    return ans;

}

void solve2(int i, int t,vector<pair<pair<int,int>, pair<int,int>>> &v , v2d &dp, v1d &ans ){

    if(i == v.size()){
        return;
    }

    if(v[i].ff.ss + t < v[i].ff.ff){
        solve(i+1, t + v[i].ff.ss, v,dp)+v[i].ss.ff;
        if(dp[i+1][t + v[i].ff.ss] + v[i].ss.ff >= dp[i+1][t]){
            ans.pb(v[i].ss.ss+1);
            solve2(i+1, t + v[i].ff.ss, v, dp, ans);
            return;
        }
    }
    solve2(i+1, t, v,dp,ans);
}


void solve(){

    int n;
    cin>>n;

    vector<pair<pair<int,int>, pair<int,int>>> v(n);

    int idx = 0;
    for(auto &i : v){
        cin>>i.ff.ss>>i.ff.ff>>i.ss.ff;
        i.ss.ss = idx++;
    }


    S(v);

    v2d dp(105, v1d(2100 , -1));
    int ans = solve(0, 0, v, dp);

    vector<int> ans2;

    solve2(0,0,v,dp,ans2);
    // cout<<"jhdhd";

    cout<<ans<<endl<<ans2.size()<<endl;
    for(auto i : ans2){
        cout<<i<<" ";
    }

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


