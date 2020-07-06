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


const int MAXN = 200005;
const int MAXLOG = 19;

void dfs(int i, v2d &v, v1d &parent, v1d &height, int h, int par){

    parent[i] = par;
    height[i] = h;
    for(auto j : v[i]){
        if(j!=par)
            dfs(j, v, parent, height, h+1, i);
    }
}

v2d lcapar(MAXN, v1d(MAXLOG,-1)); // initially all -1
void dfs2(int v, v2d &adj, v1d &h, int p = 0){
	lcapar[v][0] = p;
	for(int i = 1;i < MAXLOG;i ++)
		if(lcapar[v][i-1] + 1)
			lcapar[v][i] = lcapar[lcapar[v][i-1]][i-1];
	for(auto u : adj[v])	
        if(p - u)
		    dfs2(u,adj, h, v);
}

int compute_lca(int v,int u, v1d &h){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(lcapar[v][i] + 1 and h[lcapar[v][i]] >= h[u])
			v = lcapar[v][i];
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(lcapar[v][i] - lcapar[u][i])
			v = lcapar[v][i], u = lcapar[u][i];
	return lcapar[v][0];

}
void solve(){


    int n,q;
    cin>>n>>q;

    v2d v(n+1);

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].pb(b);
        v[b].pb(a);
    }

    v1d par(n+1), h(n+1);

    dfs(0, v, par, h, 0, 0);
    dfs2(0 , v, h);

    while(q--){
        int n;
        cin>>n;

        v1p vect(n);
        for(auto &i: vect){
            cin>>i.ss;
            i.ss --;
            i.ff = h[i.ss];
        }

        S(vect);
        int p = vect[n-1].ss;
        int i;
        for(i = n-2; i >= 0 ; i--){

            int temp;
            if(h[p] == h[vect[i].ss]){
                temp = compute_lca(p, vect[i].ss, h);
                if(h[temp] != h[p]-1 && h[temp] != h[p]){
                    cout<<"NO"<<endl;
                    break;
                }
            }else{
                temp = compute_lca(p, par[vect[i].ss], h);
                if(temp != p && temp != par[vect[i].ss]){
                    cout<<"NO"<<endl;
                    break;
                }
            }
            p = temp;

        }

        if(i == -1){
            cout<<"YES"<<endl;
        }

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


