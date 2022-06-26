// Euler Circuit 歐拉迴路 介紹
// 每一個邊都只經過一次的前提下，可以從某一個點開始出發，順利經過每一個點
// 分成無向圖、有向圖進行討論

// 定義名詞
//  * 入邊，從其他的點進來
//  * 出邊，出去至其他的點
// 無向圖
//  * 每個邊都是偶數條邊，且會相互連通
//  * 且一條邊中，入邊或出邊位置可任意對調
//  * 因此我們可以得知，只要無向圖存在 Euler Circuit 歐拉迴路
//      - 如果起點與終點相同，則沒有一個點的邊數是奇數，有進就有出，因此一定有兩個邊
//      - 如果起點與終點不同，則起點與終點的邊數則是奇數，因為一開始出發點沒有入邊，終點則沒有出邊，其他的點則都必須有兩個邊


int n, kase = 0, a, b;
vector<int> edge[MAXN]; // 迅速得知邊長
int g[MAXN][MAXN]; // 判斷這個邊有沒有被用過
int degree[MAXN]; //計算邊數
vector<pair<int,int> > record;

void euler(int root){

    for(int it: edge[root]){
        if(!g[root][it]) continue;
        g[root][it]--; //這個邊被使用過
        g[it][root]--; //這個邊被使用過
        euler(it);
        cout << "root it " << root << " " << it << "\n";
        record.push_back({root, it}); //記得逆序，因為遞迴，會將後面的 dfs 先 print 出來
    }
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        edge[a].push_back(b); //加入邊
        edge[b].push_back(a);
        g[a][b]++; //這個邊沒被使用過
        g[b][a]++;
        degree[a]++; //這個點新增一個邊
        degree[b]++;
    }

    int flag = 0;
    for(int i = 0; i < n; i++){ //判斷有幾個點的邊為奇數
        if(degree[i] % 2 != 0){
            flag++;
        }
    }
    
    if(!(flag == 0 || flag == 2)) cout << "can't find euler path\n";
    else{ 
        record.clear(); //不斷遞迴，找出歐拉路徑
        euler(a);
        for(auto it: record) cout << it.first << " " << it.second << '\n';
    }
    //cout << "\n";
}