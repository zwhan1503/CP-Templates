#include <bits/stdc++.h>

using namespace std;

#define task ""

// Optimizations
#define speed()                                                                \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)
#define endl '\n'
#define dbg(x) cout << (#x) << " = " << x << endl
#define dbg(x, y)                                                              \
    cout << (#x) << " = " << x << ", " << (#y) << " = " << y << endl

// Shorten Functions
#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define gcd __gcd

// Variable Types
// typedef int ll;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vii;
typedef vector<vector<ll>> vvi;
typedef map<ll, ll> mii;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqg;

// Useful Constants
const ll maxn = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll inf = 2e18;
const ll eps = 1e-9; // epsilon
const ll pi = 3.1415926535897932384626;

// Print vector/array
template <class T> void print(vector<T> &v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

void solve()
{

}

int main()
{
    speed();

    // File I/O
    // freopen(task.".inp", "r", stdin);
    // freopen(task.".out", "w", stdout);

    ll t = 1;
    // cin >> t;
    for (ll _ = 1; _ <= t; ++_)
    {
        // cout << "Case #" << _ << endl;
        solve();
    }
    return 0;
}
