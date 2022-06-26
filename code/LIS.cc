const int N = 100;
int s[N];       // sequence
int length[N];  // 第 x 格的值為 s[0...x] 的 LIS 長度

int LIS()
{
    // 初始化。每一個數字本身就是長度為一的 LIS。
    for (int i=0; i<N; i++) length[i] = 1;

    for (int i=0; i<N; i++)
        // 找出 s[i] 能接在哪些數字後面，
        // 若是可以接，長度就增加。
        for (int j=0; j<i; j++)
            if (s[j] < s[i])
                length[i] = max(length[i], length[j] + 1);

    // length[] 之中最大的值即為 LIS 的長度。
    int l = 0;
    for (int i=0; i<N; i++)
        l = max(l, length[i]);
    return l;
}