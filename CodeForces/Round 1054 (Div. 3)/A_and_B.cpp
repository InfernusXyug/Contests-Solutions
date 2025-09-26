#pragma GCC optimize("O3", "inline")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int           ll;
typedef unsigned long long int  ull;
typedef long double             ld;

typedef pair<ll,ll>             pi;
typedef map<string,ll>          mps;
typedef map<char,ll>            mpc;
typedef map<ll, ll>             mpi;
typedef vector<ll>              vi;
typedef vector<char>            vc;
typedef vector<pi>              vpi;
typedef vector<vi>              vvi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;

#define test(t)             int t; cin >> t; while(t--)
#define f(i, a, b)          for(int (i) = (a); (i) < (b); ++(i))
#define endl                "\n"
#define pb                  push_back
#define fi                  first
#define se                  second
#define fastio              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define no2                 cout<<-1<<endl
#define print(x)            cout<<x<<endl;
#define printv(v)           f(i,0,v.size()) cout<<v[i]<<" ";cout<<endl;
#define input(v)            f(i,0,v.size()) cin>>v[i];
#define sortv(v)            sort(v.begin(),v.end());
#define rsortv(v)           sort(v.rbegin(),v.rend());
#define sortcomp(v, comp)   sort(v.begin(),v.end(),comp);
#define maxiv(v)            *max_element(v.begin(),v.end());
#define miniv(v)            *min_element(v.begin(),v.end());

ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;
ll inf = 1e18;
ll ninf = -1e18;
double PI = 3.141592653589793238462643383279502884L;

ll min_swaps(ll n, string s, char c) {
    vi idx;
    for (ll i = 0; i < n; i++) {
        if (s[i] == c) {
            idx.pb(i);
        }
    }
    if (!idx.size()) {
        return 0;
    }
    vi d;
    for (ll i = 0; i < idx.size(); i++) {
        d.pb(idx[i] - i);
    }
    sortv(d);
    ll mid = d[d.size() / 2];
    ll swap = 0;
    for (ll i = 0; i < d.size(); i++) {
        swap += abs(d[i] - mid);
    }
    return swap;
}

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a = min_swaps(n, s, 'a');
    ll b = min_swaps(n, s, 'b');
    cout << min(a, b) << endl;
}

int main() {    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    auto start = chrono::high_resolution_clock::now();

    fastio;
    test(t)
        solve();
    
    auto end = chrono::high_resolution_clock::now();
    #ifndef LOCAL // This should probably be ONLINE_JUDGE to match the top block
        chrono::duration<double> elapsed = end - start;
        cerr << fixed << setprecision(10);
        cerr << "Elapsed time: " << elapsed.count() << "s\n";
    #endif
    return 0;
}
