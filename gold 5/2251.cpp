#include <iostream>
#include <tuple>

using namespace std;

int A, B, C;
bool visited[201][201][201];

typedef struct{
    int capacity, water;
} bowl;

tuple<bowl, bowl> pour(bowl x, bowl y){
    int diff = min(y.capacity - y.water, x.water);
    return {{x.capacity, x.water - diff}, {y.capacity, y.water + diff}};
}

void dfs(bowl a, bowl b, bowl c){
    if(visited[a.water][b.water][c.water]) return;
    visited[a.water][b.water][c.water] = true;
    
    auto[ab_a, ab_b] = pour(a, b);
    dfs(ab_a, ab_b, c);
    
    auto[ac_a, ac_c] = pour(a, c);
    dfs(ac_a, b, ac_c);
    
    auto[ba_b, ba_a] = pour(b, a);
    dfs(ba_a, ba_b, c);
    
    auto[bc_b, bc_c] = pour(b, c);
    dfs(a, bc_b, bc_c);
    
    auto[ca_c, ca_a] = pour(c, a);
    dfs(ca_a, b, ca_c);
    
    auto[cb_c, cb_b] = pour(c, b);
    dfs(a, cb_b, cb_c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B >> C;
    dfs({A, 0}, {B, 0}, {C, C});
    
    for(int i = 0;i <= C;i++)
        for(int j = 0;j <= B;j++)
            if(visited[0][j][i]){
                cout << i << " ";
                break;
            }
    return 0;
}