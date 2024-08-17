#include <iostream>

using namespace std;

string str, bomb, ans = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str >> bomb;
	int s_len = str.length(), b_len = bomb.length();

	for(auto &s : str) {
		ans += s;
		if(ans.length() >= b_len) {
			bool flag = true;
			for(int i = 0; i < b_len; i++) {
				if(ans[ans.length() - b_len + i] != bomb[i]) {
					flag = false;
					break;
				}
			}
            if(flag) ans.erase(ans.end() - b_len, ans.end());
		}
	}
	cout << (ans.empty() ? "FRULA" : ans) << "\n";
	return 0;
}