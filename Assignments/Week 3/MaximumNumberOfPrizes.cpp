#include<bits/stdc++.h>
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

void solve(){
	int n; cin >> n;
	ll ans = -1;
	
	for(ll i = 2; i < 1e5; i++){
		if(i * (i + 1) / 2 > n){
			ans = i - 1;
			break;
		}
	}
	cout << ans << nl;
	for(int i = 1; i <= ans; i++){
		cout << (i == ans ? n : i) << ' ';
		n -= i;
	}
}

int main(){
	solve();
	cout << nl;
}
