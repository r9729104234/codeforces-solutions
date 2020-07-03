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

int to_int(string &str){
    int ans = 0;
    for(auto i : str){
        ans *=2;
        ans += i-'0';
    }
    return ans;
}

int compute_power(int a, int b){

    if(b == 0){
        return 1;
    }
    int ans = compute_power(a , b/2);
    if(b%2){
        return ans*ans*a;
    }
    return ans*ans;
}
string to_str(int x, int m){
    string ans;

    while(x){
        ans.pb(to_string(x%2)[0]);
        x/=2;
    }

    reverse(ans.begin() , ans.end());
    
    while(ans.size() < m){
        ans = '0' + ans;
    }
    return ans;
}

bool isit(int i, int idx , int total, v1d &v){

    int temp  = upper_bound(v.begin(), v.end(), i) - v.begin();
    // temp--;
    if(i - temp >= idx){
        return true;
    }
    return false;
}

void solve(){
    
    int n,m;
    cin>>n>>m;

    v1d v(n);
    for(auto &i : v){
        string str;
        cin>>str;
        i = (to_int(str));
    }

    S(v);

    int start = 0 ;
    int end = LLONG_MAX;
    int ans = 0;

    int total = compute_power(2, m);
    int idx = (total - n - 1)/2;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(isit(mid, idx , total, v)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    cout<<to_str(ans, m)<<endl;


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


