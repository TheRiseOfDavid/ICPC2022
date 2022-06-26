#include <bits/stdc++.h>

using namespace std;
int X[100050];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while(getline(cin,str)){
        istringstream temp(str);        
        int i=0,sum=0,max=0;
        while(temp>>X[i++]);
        for(int j=0;j<i-1;j++){
            sum+=X[j];//將數值加進來
            if(max<sum){//如果當前數值總和>max，就儲存
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        cout<<max<<'\n';
    }
    return 0;
}