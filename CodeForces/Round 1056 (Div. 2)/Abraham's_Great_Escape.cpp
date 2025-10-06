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

void solve(){
    ll n, k;
    cin >> n >> k;
    ll cyc = n*n - k;
    if (cyc < 2 && cyc > 0) {no; return;}
    yes;
    if (cyc == 0) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cout << "U";
            }
            cout << endl;
        }
        return;
    }
    vector<vector<char>> v(n, vector<char>(n));
    v[0][0] = 'R';
    v[0][1] = 'L';
    cyc -= 2;
    for (ll j = 2; j < n; j++) {
        if (cyc) {v[0][j] = 'L';
        cyc--;}
        else v[0][j] = 'D';
    }
    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j < 2; j++) {
            if (cyc) {v[i][j] = 'U';
            cyc--;}
            else v[i][j] = 'D';
        }
    }
    for (ll i = 1; i < n; i++) {
        for (ll j = 2; j < n; j++) {
            if (cyc) {v[i][j] = 'U'; cyc--;}
            else v[i][j] = 'D';
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
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
    #ifndef LOCAL
        chrono::duration<double> elapsed = end - start;
        cerr << fixed << setprecision(10);
        cerr << "Elapsed time: " << elapsed.count() << "s\n";
    #endif
    return 0;
}
