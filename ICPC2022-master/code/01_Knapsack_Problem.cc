memset(dp, INF, sizeof(dp));
memset(dp[0], 0, sizeof(dp[0])); //車子是 0 貨箱時，一定沒辦法買水果，因此最低價都是 0

for(int i = 0; i <= 每種水果; i++){
    for(int j = 0; j <= 卡車容量; j++){
        for(int k = 0; k <= 預算; k++){
            //主要是我們假設卡車容量有 1~G，
            //總預算有 1~n 
            //我們透過紀錄，在卡車容量是 G-1 的情況，卡車現在預算 - 這種水果預算時，
            //有沒有比現在的 dp[卡車容量][預算] 來得小，有就替換
            dp[j][k] = min(dp[j][k], dp[j-1][cost - 水果買入價] + 水果賣出價 )
        }
    }
}

//想要找到最高的預算就是
cout << dp[卡車容量][預算];