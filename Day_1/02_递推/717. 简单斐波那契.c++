# include<iostream>
# include<cstring>
# include<cstdio>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a=0;
    int b=1;
    for(int i=1;i<=n;i++){
        cout<<a<<" ";
        int fn=a+b;
        a=b;
        b=fn;
        
    }
    return 0;
}