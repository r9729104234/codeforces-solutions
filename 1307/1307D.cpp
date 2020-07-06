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

void bfs(int i , v2d &v , v1d &isit){
    
    queue<pair<int,int>> q;
    q.push({i,0});

    while(q.size()){

        pair<int,int> p = q.front();
        i = p.ff;
        int dist = p.ss;
        q.pop();
        if(isit[i] != -1){
            continue;
        }

        isit[i] = dist;

        for(auto point: v[i]){
            q.push({point, dist+1});
        }
    }
    

}

void solve(){

    int n,m,k;
    cin>>n>>m>>k;

    v1d sp(k);

    for(auto &i : sp){
        cin>>i;
        i--;
    }

    v2d v(n);

    for(int i = 0 ; i <m ; i++){
        int a,b;cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }   

    v1d dist1(n,-1), distn(n, -1);
    bfs(0, v, dist1);
    bfs(n-1, v, distn);

    // for(auto &i : distn){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto &i : dist1){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto &i : sp){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    S(sp);
    vector<pair<int,int>> point;
    for(auto i : sp){
        point.pb({dist1[i]-distn[i], i});
    }

    S(point);

    int ans = 0;
    int maxi = -1e18;

    for(auto p: point){
        int x = p.ss;
        ans = max(ans, maxi + distn[x]);
        maxi = max(maxi, dist1[x]);
    }

    ans = min(ans+1, dist1[n-1]);
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
    // cin>>tc;
    
    while(tc--){
        solve();
    }


 
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';

 
 
}  

 