/*
 Problem statement: Given n disk and m rods, find the minimum number of steps to
 move n disks from rod 1 to rod m

 Constraints: 1 <= n <= 64, 3 <= m <= 64, multiple inputs
 * Be mindful of overflow, use ULL *

 Algorithm:
 - Using the TOH problem, we know if m=3 then it takes 2^n - 1 steps
 - We call ans(n, m) the number of steps
 - First we move k disks to another rod using m rods to pivot rod
 - Then, we move the rest n-k disks using m-1 rods to destination rod (excluding
 the rod that k disks are on)
 - Then, we move the first k disks back to with n-k disks in destination rod
 -> Total steps: ans(k, m) + ans(n-k, m-1) + ans(k, m) = 2*ans(k, m) + ans(n-k,
 m-1)

 => Formula: ans(n, m) = min(2*ans(k, m) + ans(n-k, m-1))
 - Base case:
    ans(1, m) = 1
    ans(0, m) = 0
    ans(n, 3) = 2^n - 1

*/
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
#define dbg2(x, y)                                                             \
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
const ll maxn = 64 + 5;
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

// Recursive Solution
ull val[maxn][maxn];
bool visited[maxn][maxn];

ull multiple_rods_tower(ll n, ll m)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (m > n + 1)
        m = n + 1;
    if (m == 3)
    {
        if (n == 64)
            return ULLONG_MAX;
        return (1ULL << n) - 1;
    }
    if (visited[n][m])
    {
        return val[n][m];
    }
    ull min1 = ULLONG_MAX;
    for (ll k = 1; k < n; ++k)
    {
        ull first_move = multiple_rods_tower(k, m);
        ull second_move = multiple_rods_tower(n - k, m - 1);

        ull moves = 2ULL * first_move + second_move;
        min1 = min(min1, moves);
    }
    visited[n][m] = true;
    val[n][m] = min1;
    return min1;
}

// DP Solution

ull dp[maxn][maxn];
void prereq()
{
    for (ll m = 1; m <= 64; ++m)
    {
        dp[1][m] = 1ULL;
        dp[0][m] = 0;
    }
    for (ll n = 2; n <= 64; ++n)
    {
        dp[n][3] = (1ULL << n) - 1;
        if (n == 64)
        {
            dp[64][3] = ULLONG_MAX;
        }
        for (ll m = 4; m <= 64; ++m)
        {
            ull min1 = ULLONG_MAX;
            for (ll k = 1; k < n; ++k)
            {
                ull moves = 2ULL * dp[k][m] + dp[n - k][m - 1];
                min1 = min(min1, moves);
            }
            dp[n][m] = min1;
        }
    }
}
void solve()
{
    ll n, m;
    prereq();
    while (cin >> n >> m)
    {
        cout << dp[n][m] << endl;
    }
    // while (cin >> n >> m)
    // {
    //     cout << multiple_rods_tower(n, m) << endl;
    // }
}

int main()
{
    speed();

    // File I/O
    // freopen(task".inp", "r", stdin);
    // freopen(task".out", "w", stdout);

    ll t = 1;
    // cin >> t;
    for (ll _ = 1; _ <= t; ++_)
    {
        // cout << "Case #" << _ << endl;
        solve();
    }
    return 0;
}
