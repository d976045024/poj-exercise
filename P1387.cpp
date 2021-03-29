// Problem: P1387 最大正方形
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1387
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

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

const int maxN = 100 + 5;
int n, m, a[maxN][maxN], s[maxN][maxN];

int main()
{
	n = read();
	m = read();
	int ans = 0;
	memset(a, 0, sizeof(a));
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			a[i][j] = read();
			if (i == 1 && j == 1) s[i][j] = a[i][j];
			else if (i == 1) s[i][j] = s[i][j-1] + a[i][j];
			else if (j == 1) s[i][j] = s[i-1][j] + a[i][j];
			else s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			int p = min(i, j);
			int k = i - p, l = j - p;
			while(k < i) {
				if (s[i][j] - s[k][j] - s[i][l] + s[k][l] == pow(i - k, 2)) {
					ans = max(ans, i - k);
					break;
				}
				k ++;
				l ++;
			}
		}
	}
	write(ans);
}












