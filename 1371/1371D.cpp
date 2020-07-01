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

    
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n , v1d(n,0));

    for(int i = 0 ; i  < n ; i++){
        int k = 0;
        if(m == 0){
            break;
        }
        for(int j = 0 ; j < n ; j++){
            v[k][(k+i)%n] = 1;
            k++;
            m--;
            if(m == 0){
                break;
            }
        }

        
    }

    int mm = 0;
    int mi = INF;

    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j < n ; j++){
            sum += v[i][j];
        }
        mi = min(mi, sum);
        mm = max(mm, sum);
    }

    int ans = (mm - mi)*(mm - mi);

    
     mm = 0;
     mi = INF;

    for(int j = 0 ; j < n ; j++){
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += v[i][j];
        }
        mi = min(mi, sum);
        mm = max(mm, sum);
    }

     ans += (mm - mi)*(mm - mi);

    
    cout<<ans<<endl;
    for(int i = 0 ; i  < n ; i++){
        for(auto j : v[i]){
            cout<<j;
        }
        cout<<endl;
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
    cin>>tc;
    
    while(tc--){
        solve();
    }


 
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';

 
 
}  


