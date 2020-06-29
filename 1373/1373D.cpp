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

int getmax(v1d &v){

    int ans = 0;

    int cur = 0;

    for(auto i : v){
        cur += i;

        if(cur < 0){
            cur = 0;
        }

        ans = max(ans , cur);
    }

    return ans;
}

void solve(){

    int n;
    cin>>n;

    v1d v(n);

    for(auto &i : v){
        cin>>i;
    }

    int ans = 0;

    for(int i = 0 ; i  <n ; i+=2){
        ans += v[i];
    }

    v1d v1;

    for(int i = 0 ; i < n ; i+=2){
        if(i + 1 < n){
            v1.pb(v[i+1]-v[i]);
        }
    }

    
    int temp = max(0LL,getmax(v1));

    v1.clear();

    for(int i = 1 ; i < n ; i+=2){
        if(i + 1 < n){
            v1.pb(v[i]-v[i+1]);
        }
    }

    temp = max(temp,getmax(v1));
    
    cout<<ans + temp<<endl;

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


