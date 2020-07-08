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

int powermod(int a , int b){

    if(b == 0){
        return 1;
    }
    int ans = powermod(a , b/2);
    ans *= ans;
    ans%= M;
    if(b%2){
        ans *= a;
        ans %= M;
    }
    return ans;
}

int isit(int a, int b){
    if(b == 0){
        return 1;
    }
    int ans = isit(a , b/2);
    if(ans > 1e6){
        return INF;
    }
    
    ans *= ans;
    
    if(b%2){
        ans *= a;
    }
    if(ans > 1e6){
        return INF;
    }
    return ans;
}
void solve(){

    
    int n,p;
    cin>>n>>p;

    v1d v(n);

    map<int,int, greater<int>> mp;
    for(auto &i: v){
        cin>>i;
        mp[i]++;
    }

    v1p vp;
    for(auto i : mp){
        vp.pb({i.ff,i.ss});
    }

    v1d one,two;
    
    int cnt = 0;
    int idx = -1;
    for(auto i : vp){
        idx++;
        if(cnt != 0){
            int k = vp[idx-1].ff - vp[idx].ff;
            int ttt = isit(p,k);
            if(cnt > 1e6 || cnt * isit(p,k) > 1e6){
                for(; idx < vp.size(); idx++){
                    for(k = 0 ; k < vp[idx].ss ; k++){
                        two.pb(vp[idx].ff);
                    }
                }
                break;;
            }else{
                cnt *= isit(p,k);
            }
        }
        if(i.ss > cnt){
            for(int j = 0 ; j < cnt ; j++){
                two.pb(i.ff);
            }
            i.ss -= cnt;

            cnt = 0;

            if(i.ss % 2){
                cnt++;
                one.pb(i.ff);
            }
            
        }else{
            cnt -= i.ss;
            for(int j = 0 ; j < i.ss ; j++){
                two.pb(i.ff);
            }
            
        }
    }




    int total = 0;

    for(auto i: one){
        total += powermod(p, i);
        total %= M;
    }

    for(auto i: two){
        total -= powermod(p, i);
        total %= M;
        total += M;
        total %= M;
    }

    cout<<total<<endl;





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