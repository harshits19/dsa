#include <iostream>
#include <vector>
using namespace std;
int maximumWealth(vector<int> &ans) {
    int res = 0;
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i];
        res = max(res, sum);
    }
    return res;
}
int main() {
    vector<int> ans = {1, 3, 2, 6, 3, 7};
    cout << "Max = " << maximumWealth(ans); // op -22
    return 0;
}