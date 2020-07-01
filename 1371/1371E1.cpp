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


int calc(int num, v1d &v , int p){

    // cout<<num<<" "<<p<<endl;

    int ans = 1;
    // int cnt =;
    int n = v.size();
    int pending = 0;
    for(int i = 0 ; i < v.size() ; ){

        if(pending == 0 && v[i] > num){
            return 0;
        }
        while(i < v.size() && v[i] <= num){
            pending++;
            i++;
        }

        // if(cnt == 0){
        //     return 0;
        // }
        
        if(pending >= p){
            return 0;
        }

        pending--;
        num++;

        
    }

    // cout<<ans<<" \n";
    return ans;
}

void solve(){

    
    int n,p;
    cin>>n>>p;

    v1d v2(n);

    for(auto &i : v2){
        cin>>i;
    }


    S(v2);

    int mi = v2[0];
    int ma = v2.back();

    v1d ans;
    for(int i = mi; i <= ma ; i++){
        int perm = calc(i , v2, p);
        if(perm){
            ans.pb(i);
        }
    }

    cout<<ans.size()<<endl;

    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl;
    

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


