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


const int triesize = 2;

struct trienode{
    struct trienode *children[triesize];
    int isend = 0;
};

struct trietree{

    struct trienode *root;

    struct trienode *getnode(){
        struct trienode *pNode =  new trienode; 
        pNode->isend = 0; 
        for (int i = 0; i < triesize; i++)
            pNode->children[i] = NULL;
        return pNode; 
    }

    void init(){
        root = getnode();
    }

    void insert(string &key){
        struct trienode *crawl = root;
        for(auto &ch: key){
            if(crawl -> children[ch-'0'] == NULL){
                crawl -> children[ch - '0'] = getnode();
            }
            crawl = crawl -> children[ch - '0'];   
        }
        crawl -> isend += 1;
    }

    bool search(string &key){
        struct trienode *crawl = root;
        for(auto &ch: key){
            if(crawl -> children[ch-'0'] == NULL){
                return false;
            }
            crawl = crawl -> children[ch - '0'];   
        }
        return crawl -> isend > 0;
    }

    bool isEmpty(trienode *node){
        for(int i = 0 ; i < triesize; i++){
            if(node -> children[i]){
                return false;
            }
        }
        return true;
    }

    trienode* remove(trienode* node, string &key, int depth = 0) {
        if (!node) 
            return NULL; 
    
        if (depth == key.size()) { 
            if (node->isend) 
                node->isend -= 1; 
    
            if (isEmpty(node) && node -> isend == 0) { 
                delete(node); 
                node = NULL; 
            } 
            return node; 
        } 
        int index = key[depth] - '0'; 
        node->children[index] =  
            remove(node->children[index], key, depth + 1); 
    
        if (isEmpty(node) && node->isend == 0) { 
            delete(node); 
            node = NULL; 
        } 
        return node; 
    } 

    void remove(string &key){
        remove(root, key);
    }

    void query(string &str, string &ans){

        struct trienode *crawl = root;

        for(int i = 0 ; i  < str.size(); i++){
            
            if(crawl->children[str[i]-'0']){
                ans.pb(str[i]);
                crawl  = crawl -> children[str[i] - '0'];
            }else{
                crawl = crawl -> children[!(str[i] - '0')];
                ans.pb(to_string(!(str[i] - '0'))[0]);
            }
        }
    }

};


string tobin(int a){
    string ans;
    int len = 0;
    while(len < 31){
        ans.pb(to_string(a%2)[0]);
        a/=2;
        len++;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int toint(string &str, string &s2){
    
    int ans = 0;
    int i = 0;
    while(i < str.size()){
        ans *= 2;
        ans += (str[i] - '0') ^ (s2[i] - '0');
        i++;
    }
    return ans;
}


void solve(){
   
    
    int n;
    cin>>n;

    v1d v(n);

    trietree trie;
    trie.init();

    for(auto &i: v){
        cin>>i;
    }

    for(auto i: v){
        cin>>i;
        string x = tobin(i);
        trie.insert(x);
    }

    for(auto &i : v){

        string x = tobin(i);
        string ans;
        trie.query(x, ans);
        cout<<toint(x, ans)<<" ";
        trie.remove(ans);

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
        // t++;
        // cout<<"Case #"<<t<<": ";
        solve();
        cout<<endl;
    }


 
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';

 
 
}