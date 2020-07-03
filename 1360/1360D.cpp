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


void get_all_divisors(int i, vector<pair<int,int>> &prime, int num, v1d &divisor, int k){

    if(num > k){
        return;
    }

    if(i == prime.size()){
        divisor.pb(num);
        return;
    }

    int temp = 1;
    for(int ii = 0 ; ii <= prime[i].ss ; ii++){
        get_all_divisors(i+1, prime, num*temp, divisor, k);
        temp *= prime[i].ff;
    }

    // get_all_divisors(i+1, prime, num*prime[i], divisor, k);
    // get_all_divisors(i+1, prime, num, divisor, k);
}

void solve(){
    
    
    int n,k;
    cin>>n>>k;
    int number = n;

    if(n <= k){
        cout<<1<<endl;
        return;
    }

    int num = 2;
    map<int,int> mp;
    while(num*num <= n){
        while(n%num == 0){
            mp[num]++;
            n/=num;
        }
        num++;
    }

    if(n > 1){
        mp[n]++;
    }

    vector<pair<int,int>> prime;
    for(auto i: mp){
        prime.pb({i.ff,i.ss});
    }
    vector<int> divisors;

    get_all_divisors(0, prime, 1 , divisors, k);

    S(divisors);

    int idx = upper_bound(divisors.begin(), divisors.end(), k) - divisors.begin();
    idx--;
    int ans = number/divisors[idx];
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


