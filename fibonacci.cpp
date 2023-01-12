#include<bits/stdc++.h>
using namespace std;
class Fib1{
    public:
        int fib(int n){
            int f[n+2];
            int i;
            f[0] = 0;
            f[1] = 1;
            for(i = 2;i<=n;i++){
                f[i] = f[i-1] + f[i-2];
            }
            return f[n];
        }
};
int main(){
    Fib1 obj;
    int n;
    cout<<"Enter the number of fibonacci numbers you want: ";
    cin>>n;
    cout<<obj.fib(n);
    return 0;
}