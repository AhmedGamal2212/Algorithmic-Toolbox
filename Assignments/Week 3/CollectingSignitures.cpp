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

struct seg{
	int start, end;
	seg(){
		start = end = 0;
	}
	seg(int start, int end){
		this -> start = start, this -> end = end;
	}
};

bool by(seg& a, seg& b){
	return a.start < b.start;
}

void solve(){
	int n; cin >> n;
	vector<seg> v(n);
	vector<int> ans;
	
	for(auto& i : v){
		cin >> i.start >> i.end;
	}
	sort(all(v), by);
	int start = imin, end = imax;
	
	// merging as many intervals as we can to find a point that belongs to them all
	
	for(auto& i : v){
		if(i.start > end){
			
			// when we find an interval that we can't merge to our larger interval, we start a new large interval and store the point that groups all the intervals we have
			
			ans.emplace_back(start);
			start = i.start, end = i.end;
		}
		start = max(start, i.start), end = min(end, i.end);
	}
	ans.emplace_back(start);
	
	cout << ans.size() << nl;
	for(auto& i : ans) cout << i << ' ';
}

int main(){
	solve();
	cout << nl;
}
