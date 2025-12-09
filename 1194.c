#include <bits/stdc++.h>
using namespace std;

string pre, in;
string solve(int pl, int pr, int il, int ir) {
    if (pl > pr) return "";
    char root = pre[pl];
    int mid = in.find(root, il);
    int leftSize = mid - il;
    string left = solve(pl+1, pl+leftSize, il, mid-1);
    string right = solve(pl+leftSize+1, pr, mid+1, ir);
    return left + right + root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;
    while (C--) {
        int N;
        cin >> N >> pre >> in;
        cout << solve(0, N-1, 0, N-1) << "\n";
    }
}
