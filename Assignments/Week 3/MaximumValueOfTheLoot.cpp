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

struct item{
	double value, weight;
	item(){
		value = weight = 0;
	}
	item(double value, double weight){
		this -> value = value, this -> weight = weight;
	}
};

bool by(item a, item b){
	return a.value / a.weight > b.value / b.weight;
}

void solve(){
	double n, w; cin >> n >> w;
	
	vector<item> v(n);
	
	for(auto& i : v){
		cin >> i.value >> i.weight;
	}
	sort(all(v), by);
	
	double sum = 0;
	for(auto& i : v){
		if(w <= 0) break;
		double take = min(w, i.weight);
		
		sum += i.value / i.weight * take;
		w -= take;
	}
	cout << fixed << setprecision(5);
	cout << sum;
}

int main(){
	solve();
	cout << nl;
}
