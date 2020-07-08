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

    int n,x;
    cin>>n>>x;

    v1d v(n);
    for(auto &i: v){
        cin>>i;
    }

    for(int i = 0 ; i < n ; i++){
        v.pb(v[i]);
    }

    vector<int> v1 = v;
    vector<int> sum = v;

    for(int i = 0 ; i  < sum.size() ; i++){
        sum[i]*=(sum[i]+1);
        sum[i]/=2;
    }

    for(int i = 1; i < sum.size();  i++){
        sum[i] += sum[i-1];
    }

    for(int i = 1; i < v.size(); i++){
        v[i] += v[i-1];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        
        int temp = 0;
        if(i > 0){
            temp = v[i-1];
        }

        int idx = lower_bound(v.begin(), v.end(), temp+x) - v.begin();
        if(idx >= v.size()){
            break;
        }

        int start = 1;
        int end = v1[idx] - (v[idx] - temp - x);

        int minup = min(v1[i]-1, v1[idx]-end);
        start += minup;
        end += minup;

        if(i == idx){
            temp = end*(end+1)/2;
            temp -= start*(start-1)/2;
        }else{
            idx--;
            temp = sum[idx];
            temp += end*(end+1)/2;

            if(i > 0){
                temp -= sum[i-1];
            }
            temp -= start*(start-1)/2;

        }

        ans = max(ans, temp);


    }

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