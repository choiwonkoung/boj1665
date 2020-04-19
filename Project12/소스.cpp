#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef struct _Spoly {
	vector<pair<int,int>> num;
}Spoly;
void sum_poly(Spoly &poly, int a, int b) { // 다항식 차수가 a인 항에 계수 b를 더함
	pair<int, int> tmp;
	tmp.first = a;
	tmp.second = b;
	poly.num.push_back(tmp);
}
Spoly multi_poly(Spoly& poly1, Spoly& poly2) { // 두 개의 다항식을 곱한후 값을 반환한다.
	Spoly ret;
	vector<pair<int, int>> temp;
	for (int i = 0; i < poly1.num.size(); i++) {
		for (int j = 0; j < poly2.num.size(); j++) {
			pair<int, int> tmp;
			tmp.first = poly1.num[i].first + poly2.num[j].first;
			tmp.second = poly1.num[i].second * poly2.num[j].second;
			temp.push_back(tmp);
		}
	}
	int pre=0;
	sort(temp.begin(), temp.end(), greater<pair<int, int>>());
	for (int i=0;i<temp.size();i++) {
		if (temp[i].first == pre) {
			ret.num[ret.num.size()-1].second+=temp[i].second;
		}
		else {
			ret.num.push_back(temp[i]);
			pre = temp[i].first;
		}
	}
	return ret;
}
int get_ans(Spoly& poly) {
	int num = 0, ans = 0, ret = 0, answer = 0;
	for (int i = 0; i < poly.num.size(); i++) {
		int pre = i > 0 ? poly.num[i - 1].first : poly.num[i].first;
		int now = poly.num[i].first;
		if (ret <= (pre - now - 1) * num + ans) {
			ret = (pre - now - 1) * num + ans;
			answer = poly.num[i].first - 1;
		}
		ans = (pre - now) * num + poly.num[i].second + ans;
		if (ret <= ans) {
			ret = ans;
			answer = poly.num[i].first;
		}
		num = num + poly.num[i].second;
	}
	return answer - 1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Spoly poly1,poly2;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a,b; cin >> a >> b;
		sum_poly(poly1, a, -1);
		sum_poly(poly1, b+1, 1);
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		sum_poly(poly2, a, -1);
		sum_poly(poly2, b+1, 1);
	}
	Spoly ans = multi_poly(poly1, poly2);
	cout << get_ans(ans) << endl;
}