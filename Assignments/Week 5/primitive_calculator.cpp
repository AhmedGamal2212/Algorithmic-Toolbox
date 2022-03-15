#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ll long long
#define ull unsigned long long
#define MOD 1000000007ll
#define PI 3.14159265
#define ceil(a, b) ((a / b) + (a % b ? 1 : 0))
#define imin INT_MIN
#define imax INT_MAX
#define nl '\n'
#define modulo(a, b, mod) ((((a) % mod) * ((b) % mod)) % mod)
#define debug(x) cout << "x: " << x << nl;
#define debug2(x, y) cout << "x: " << x << " y: " << y << nl;

//vector<int> dx = {0, 0, 1, -1, 1, 1, -1, -1}, dy = {1, -1, 0, 0, 1, -1, 1, -1};
//vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

template<typename T = int> istream& operator>>(istream& in, vector<T>& v){
    for (T& i : v) in >> i;
    return in;
}

template<typename T = int> ostream& operator<<(ostream& out, const vector<T>& v){
    for (const T& x : v)
        out << x << ' ';
    return out;
}

void Start_Crushing() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
}

#define inf 2000000000

int memo[1000005], coins[] = { 2, 3}, first[1000005];

int dp(int curr){
    if(curr <= 1){
        return curr > 1 ? inf : 0;
    }
    if(~memo[curr])
        return memo[curr];

    int ret = inf;
    for(auto& i : coins){
        if(curr % i == 0 and dp(curr / i) + 1 < ret){
            ret = dp(curr / i) + 1;
            first[curr] = i;
        }
    }

    if(curr - 1 >= 0 and dp(curr - 1) + 1 < ret){
        ret = dp(curr - 1) + 1;
        first[curr] = 1;
    }

    return memo[curr] = ret;
}

void solve(){
    memset(memo, -1, sizeof memo);
    int n; cin >> n;
    cout << dp(n) << nl << 1 << ' ';

    stack<int> operations;
    while(n > 1){
        operations.push(first[n]);
        if(first[n] == 1){
            n -= first[n];
        }else{
            n /= first[n];
        }
    }

    int start = 1;

    while(not operations.empty()){
        int curr_move = operations.top();
        operations.pop();

        if(curr_move == 1){
            start++;
        }else{
            start *= curr_move;
        }
        cout << start << ' ';
    }
}

int main(){
    Start_Crushing();

    int t = 1;
//    /*Multiple test cases?*/ cin >> t;
    while (t--) {
        solve();
        if(!t) break;
        cout << nl;
    }

    return 0;
}