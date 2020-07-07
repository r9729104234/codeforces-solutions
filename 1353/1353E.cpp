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


struct fenwick{

    vector<int> v;

    void init(int n){
        v.resize(n+1);
        for(int i = 0 ; i < n ; i++){
            v[i] = 0;
        }
    }

    void init(v1d &arr, int n){
        v.resize(n+1);
        for(int i = 1; i <= n ; i++){
            update(i, arr[i]);
        }
    }

    void update(int idx, int delta){
        while(idx < v.size()){
            v[idx] += delta;
            idx += idx & -(idx);
        }
    }

    int query(int left , int right){
        if(left > right){
            return 0;
        }
        return query(right) - query(left-1);
    }

    int query(int idx){
        int result = 0;
        while(idx > 0){
            result += v[idx];
            idx -= idx & -(idx);
        }
        return result;
    }
};


int solve(int i, string &str, bool findone, int k , fenwick &bit, vector<vector<int>> &dp){

    if(i >= str.size()){
        return 0;
    }

    if(dp[i][findone]!=-1){
        return dp[i][findone];
    }

    int ans = 0;
    if(findone == false){
        if(str[i] == '1'){
            ans = min(solve(i+k, str, true, k, bit, dp) + bit.query(i+1, i+k-1), solve(i+1, str, false, k, bit, dp) + 1);
        }else{
            ans = solve(i+1, str, false, k, bit, dp);
        }
    }else{  
        if(str[i] == '0'){
            ans = min(bit.query(i+1, str.size()), solve(i+k, str, true, k, bit, dp) + bit.query(i+1, i+k-1) + 1);
        }else{
            ans = min(bit.query(i+1, str.size()) + 1, solve(i+k, str, true, k, bit, dp) + bit.query(i+1, i+k-1));
        }
    }

    return dp[i][findone] = ans;
}

void solve(){

    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;

    n = str.size();

    fenwick bit;
    bit.init(3*n);

    for(int i = 0 ; i < n ; i++){
        if(str[i] == '1')
            bit.update(i+1 , 1);
    }
    str = '^' + str;
    vector<vector<int>> dp(n+10, vector<int>(2,-1));
    int ans = solve(1, str, false, k, bit, dp);
    cout<<ans<<endl;

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
    cin>>tc;
    
    while(tc--){
        solve();
    }
 
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';

 
 
}