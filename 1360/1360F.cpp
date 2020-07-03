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

bool all_same(vector<string> &str, int i){
    char ch = str[0][i];
    for(auto s: str){
        if(s[i] != ch){
            return false;
        }
    }
    return true;
}

set<char> get_all_chars(vector<string> &str, int i){
    set<char> res;
    for(auto s : str){
        res.insert(s[i]);
    }
    return res;
}

bool do_that_fit(vector<string> &str, string temp){
    for(auto s: str){
        int diff = 0;
        for(int i = 0 ; i < temp.size() ; i++){
            if(temp[i] != s[i]){
                diff++;
            }
        }
        if(diff > 1){
            return false;
        }
    }
    return true;
}

void solve(){
    
    int n,m;
    cin>>n>>m;

    vector<string> str(n);
    for(int i = 0 ; i < n ; i++){
        cin>>str[i];
    }

    string ans;
    for(int i = 0 ; i  < m ;i++){
        ans.pb('0');
    }

    for(int i = 0 ; i < m ; i++){
        if(all_same(str,i)){
            ans[i] = str[0][i];
            continue;
        }

        set<char> chars = get_all_chars(str, i);

        for(auto ch: chars){

            for(auto s: str){
                if(s[i] == ch){
                    continue;
                }else{
                    string temp = s;
                    temp[i] = ch;
                    if(do_that_fit(str, temp)){
                        ans = temp;
                        break;
                    }
                }
            }
        }
        break;
    }

    for(auto i :ans){
        if(i == '0'){
            cout<<-1<<endl;
            return;
        }
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
    cin>>tc;
    
    while(tc--){
        solve();
    }


 
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';

 
 
}  


