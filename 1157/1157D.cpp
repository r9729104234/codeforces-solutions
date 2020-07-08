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
#define INF 1e7
#define M 1000000007     
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

    
    int n,k;
    cin>>n>>k;

    v1d ans(k);

    for(int i = 1 ; i <= k ; i++){
        ans[i-1] = i;
        n -= i;
    }

    if(n < 0){
        cout<<"NO";
        return;
    }

    int cnt = n/k;
    n%=k;

    for(auto &i: ans){
        i += cnt;
    }

    int time = 0;
    for(int i = ans.size()-1; i>=0 ; i--){
        if(n){
            if(i == 1 && time == 0){
                time++;
                i = ans.size() - 1;
            }
            n--;
            ans[i]++;
        }else{
            break;
        }
    }

    for(int i = 1; i < k; i++){
        if(ans[i] > 2*ans[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES\n";
    for(auto &i: ans){
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