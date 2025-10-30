#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d){ data = d; next = NULL; }
};

class LinkedListStack {
    Node* top;
public:
    LinkedListStack(){ top = NULL; }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    int pop(){
        if(top == NULL) return -1;
        Node* t = top;
        top = top->next;
        int val = t->data;
        delete t;
        return val;
    }

    bool empty(){
        return top == NULL;
    }
};

class ArrayStack {
    int arr[100];
    int top;
public:
    ArrayStack(){ top = -1; }

    void push(int x){
        arr[++top] = x;
    }

    int pop(){
        if(top == -1) return -1;
        return arr[top--];
    }

    bool empty(){
        return top == -1;
    }
};

void solvePatternA(int n){
    cout << "\nPattern A:\n";
    cout << n << endl;

    cout << n/2 << " " << n/2 << endl;
    cout << 1 << " " << n-1 << endl;

    for(int row=4; row<=n; row++){
        for(int i=0; i<row-1; i++)
            cout<<1<<" ";
        if(row<n) cout<<2;
        else cout<<1;
        cout<<endl;
    }
}

void show(int a[], int k){
    for(int i=0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void solvePatternB(int n){
    cout << "\nPattern B:\n";

    int a[50], k=1;
    a[0]=n;

    while(true){
        show(a,k);
        int sum=0;

        while(k>0 && a[k-1]==1){
            sum+=a[k-1];
            k--;
        }

        if(k==0) return;

        a[k-1]--;
        sum++;

        while(sum>a[k-1]){
            a[k]=a[k-1];
            sum-=a[k-1];
            k++;
        }

        a[k]=sum;
        k++;
    }
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    solvePatternA(n);
    solvePatternB(n);
    
    return 0;
}

