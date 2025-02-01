#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
char a, b, c;
unordered_map<char, vector<char>> tree;

void preorder(char now){
    if(now == '.') return;
    cout << now;
    preorder(tree[now][0]);
    preorder(tree[now][1]);
}

void inorder(char now){
    if(now == '.') return;
    inorder(tree[now][0]);
    cout << now;
    inorder(tree[now][1]);
}

void postorder(char now){
    if(now == '.') return;
    postorder(tree[now][0]);
    postorder(tree[now][1]);
    cout << now;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        tree[a].push_back(b);
        tree[a].push_back(c);
    }

    preorder('A');
    cout << "\n";

    inorder('A');
    cout << "\n";

    postorder('A');
    cout << "\n";

    return 0;
}