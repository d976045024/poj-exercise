#include <iostream>
#include <cstdio>
#include <cstring>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define all(x) x.begin(),x.end()
using namespace std;

const int maxN = 1000 + 5;
int n, m, a[maxN][maxN], b[maxN][maxN];
int main()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        b[x1][y1] ++;
        b[x2+1][y2+1] ++;
        b[x2+1][y1] --;
        b[x1][y2+1] --;
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            a[i][j] = a[i-1][j] + a[i][j-1] + b[i][j] - a[i-1][j-1];
            printf("%d", a[i][j]);
            if (j % n == 0) printf("\n");
            else printf(" ");
        }
    }
}