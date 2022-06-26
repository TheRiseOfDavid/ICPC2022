//f(N,M)=(f(N−1,M)+M)%N
//f(N,M)表示，N个人报数，每报到M时杀掉那个人，最终胜利者的编号
//f(N−1,M)表示，N-1个人报数，每报到M时杀掉那个人，最终胜利者的编号
#include <iostream>

using namespace std;
int T,n,k,kase;
int main()
{
    cin>>T;
    while (T--){
        cin>>n>>k;
        int survivor=0;
        for(int i =2;i<=n;i++){
            survivor = (survivor+k)%i;
        }
        survivor++;
        cout<<"Case "<<++kase<<": "<<survivor<<endl;
    }
    return 0;
}
