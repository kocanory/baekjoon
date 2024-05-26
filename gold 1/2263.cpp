#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> in, post, index;

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd) return;

    int rootIndex = index[post[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;
    cout << in[rootIndex] << " ";

    getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    in.assign(n + 1, 0);
    post.assign(n + 1, 0);
    index.assign(n + 1, 0);

    for(int i = 1;i <= n;i++) {
        cin >> in[i];
        index[in[i]] = i;
    }
    for(int i = 1;i <= n;i++) cin >> post[i];
    getPreOrder(1, n, 1, n);
    return 0;
}