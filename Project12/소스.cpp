#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef struct _Spoly {
	map<int, int> p;
	vector<int> num;
}Spoly;
void sum_poly(Spoly &poly, int a, int b) { // ���׽� ������ a�� �׿� ��� b�� ����
	if (poly.p.find(a) == poly.p.end())poly.p[a] += b;
	else {
		poly.p[a] = b;
		poly.num.push_back(a);
	}
}
Spoly multi_poly(Spoly& poly1, Spoly& poly2) { // �� ���� ���׽��� ������ ���� ��ȯ�Ѵ�.
	Spoly ret;
	for (int i = 0; i < poly1.num.size(); i++) {
		for (int j = 0; j < poly2.num.size(); j++) {
			int x, y;
			x = poly1.num[i]; // poly1�� �����ϴ� ����
			y = poly2.num[i]; // poly2�� �����ϴ� ����
			sum_poly(ret, x+y, poly1.p[x]*poly2.p[y]); // �� ���� ���Ѵ�.
		}
	}
}
int get_ans(Spoly& poly) {
	sort(poly.num.begin(), poly.num.end());
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Spoly poly1,poly2;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a,b; cin >> a >> b;
		sum_poly(poly1, a + b, 1);
		sum_poly(poly1, a, -1);
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		sum_poly(poly2, a + b, 1);
		sum_poly(poly2, a, -1);
	}
	Spoly ans = multi_poly(poly1, poly2);;
	cout << get_ans(ans) << endl;
}