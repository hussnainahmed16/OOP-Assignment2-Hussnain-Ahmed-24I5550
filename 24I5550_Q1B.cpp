#include <iostream>
using namespace std;

void print(int n, int max){
    if(n == 0) {
        cout << endl;
        return;
    }
    for(int i = max; i >= 1; i--) {
        if(i <= n) {
            cout << i << " ";
            print(n - i, i); 
        }
    }
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    print(n, n);
    
    return 0;
}

