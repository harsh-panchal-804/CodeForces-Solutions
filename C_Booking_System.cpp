#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;


class group {
	public:
	
	int id;
	int size;
	int income;
};
 
class table {
	public:
	
	int id;
	int size;
};
 
bool byIncomeDescending(const group &g1, const group &g2) {
	return g1.income > g2.income;
}
 
bool bySize(const table &t1, const table &t2) {
	return t1.size < t2.size;
}
 
bool canFit(const table &t, const group &g) {
	return t.size < g.size;
}
 
int main() {
	int n; cin >> n;
	vector<group> groups(n);
	for (int i = 0 ; i < n ; i++) {
		groups[i].id = i + 1;
		cin >> groups[i].size >> groups[i].income;
	}
 
	sort(groups.begin(), groups.end(), byIncomeDescending);
	
	int m; cin >> m;
	vector<table> tables(m);
	for (int i = 0 ; i < m ; i++) {
		tables[i].id = i + 1;
		cin >> tables[i].size;
	}
	
	sort(tables.begin(), tables.end(), bySize);
	
	int sum = 0;
	vector<pair<int, int> > ans;
 
	for (int i = 0 ; i < n ; i++) {
		auto group = groups[i];
		
		auto tableToGive = lower_bound(tables.begin(), tables.end(), group, canFit);
		if (tableToGive == tables.end()) continue;
		
		sum += group.income;
		ans.push_back(make_pair(group.id, tableToGive->id));
		tables.erase(tableToGive);
	}
	
	cout << ans.size() << ' ' << sum << endl;
	for (auto p : ans) cout << p.first << ' ' << p.second << endl;
}