#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxN = 105, maxM = 100000 + 5;
int n, m, dp[maxM], a[maxN], c[maxN], cnt;
//快速读
inline int read() {
    int num=0, w=0;
    char ch=0;
    while (!isdigit(ch)) {
        w|=ch=='-';
        ch = getchar();
    }
    while (isdigit(ch)) {
        num = (num<<3) + (num<<1) + (ch^48);
        ch = getchar();
    }
    return w? -num: num;
}

//快速写
inline void write(int x)
{
    if(x<0) {
        putchar('-');
        x = -x;
    }
    if(x>9) write(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    while(scanf("%d %d", &n, &m)) {
        if (!n && !m) break;
        cnt = 0;
        for (int i = 1; i <= n; i ++) {
            a[i] = read();
        }
        for (int i = 1; i <= n; i ++) {
            c[i] = read();
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (dp[j] >= 0) dp[j] = c[i];
                else if (j < a[i] || dp[j-a[i]] <= 0) dp[j] = -1;
                else dp[j] = dp[j-a[i]] - 1;
            }
        }
        // for (int i = 0; i <= m; i ++) {
        //     if (dp[i] >= 0) {
        //         printf ("1 ");
        //     }
        //     else printf("0 ");
        // }
        for (int i = 1; i <= m; i ++) {
            if (dp[i] >= 0) cnt ++;
        }
        write(cnt);
        cout << endl;
    }
}