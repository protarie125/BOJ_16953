#include <iostream>
#include <queue>

using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
using qpl = queue<pl>;

qpl q;
ll solve(ll a, ll b, ll r) {
	if (b < a) {
		return -1;
	}

	if (a == b) {
		return r;
	}

	const auto& a1 = a * 2;
	const auto& a2 = a * 10 + 1;

	if (a1 <= b) {
		q.push({ a1, r + 1 });
	}

	if (a2 <= b) {
		q.push({ a2, r + 1 });
	}

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		auto ta = solve(t.first, b, t.second);
		if (0 < ta) {
			return ta;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll a, b; cin >> a >> b;
	const auto& ans = solve(a, b, 1);

	cout << ans;

	return 0;
}