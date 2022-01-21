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
	int d, m, n; cin >> d >> m >> n;
	
	vector<int> v(n);
	for(auto& i : v) cin >> i;
	
	v.emplace_back(d);
	
	int curr = 0, cnt = 0;
	bool noWay = false;
	
	for(int i = 0; i < n; i++){
		if(v[i + 1] - v[i] > m){
			noWay = true;
			break;
		}
		
		if(v[i + 1] - curr > m){
			curr = v[i];
			cnt++;
		}
	}
	
	cout << (noWay ? -1 : cnt);
}

int main(){
	solve();
	cout << nl;
}
