#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct block {
    int h, a, c;
    bool operator < (const block &rhs) const {
        return rhs.a > this->a;
    }
};
const int maxN = 405;
const int maxA = 40005;
int n, dp[maxN][maxA];
block b[maxN];
// 将block按照a(高度阈值)升序排序，利用贪心思想。无论如何，阈值高的木块一定放在上方(木块调换位置不影响总高度)，
// 显然将阈值高的放在上面更有利。
// dp[i][j] 表示用前i个木块搭成高度为j时，第i种木块剩余的最大数量
// 无法搭成时，dp[i][j] = -1
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &b[i].h, &b[i].a, &b[i].c);
    }
    sort(b + 1, b + 1 + n);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < maxA; j ++) {
            if (dp[i-1][j] >= 0) dp[i][j] = b[i].c;
            else if (j < b[i].h || j > b[i].a || dp[i][j-b[i].h] <= 0) {
                dp[i][j] = -1;
            }
            else dp[i][j] = dp[i][j-b[i].h] - 1;
        }
    }

    int ans = 0;
    for (int i = 1; i < maxA; i ++) {
        if (dp[n][i] >= 0) ans = max(ans, i);
    }
    printf("%d\n", ans);
}