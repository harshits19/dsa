#include <iostream>
#include <string>
using namespace std;
// Time : 0(mn)
int lcs(string s1, string s2, int m, int n)
{
    int dp[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (m == 0 || n == 0)
        dp[m][n] = 0;
    else
    {
        if (s1[m - 1] == s2[n - 1])
            dp[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
        else
            dp[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
    return dp[m][n];
}

int lcs2(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    int dp[m + 1][n + 1];
    for (size_t i = 0; i <= m; i++)
        for (size_t j = 0; j <= n; j++)
            dp[i][j] = 0;

    for (size_t i = 1; i <= m; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{
    string s1 = "AXYZ";
    string s2 = "BYZ";
    string s3 = "BBCPON", s4 = "TBPCPNOP";
    // int m = 4, n = 3;
    // cout << lcs(s1, s2, m, n) << endl;
    cout << lcs2(s3, s4) << endl;
    return 0;
}