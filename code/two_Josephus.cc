#include <iostream>
#include <math.h>
using namespace std;
int T,n,k,kase;
int josephus(){
    k=0;//因為2的0次方等於1
    while(pow(2,k)<n){
        k+=1;
    }
    if(pow(2,k)==n){
        return 1;//如果n剛好是2的次方
    }
    else{
        return 2*(n-pow(2,k-1))+1;//否則回傳2b+1
    }
}
int main()
{
    cin>>T;
    while(T--){
        cin>>n;
        int repeat=0;
        while(n!=josephus()){
            repeat++;
            n=josephus();
        }
        cout<<"Case "<<++kase<<": "<<repeat<<" "<<n<<endl;
    }
    return 0;
}
