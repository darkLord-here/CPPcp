#include<iostream>

using namespace std;

void star(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
}

void revStar(int n){
    for(int i=n; i>0; i--){
        for(int j=i; j>0; j--){
            printf("*");
        }
        printf("\n");
    }
}


int main(){
    printf("Enter the value of N:\t");
    int n;
    scanf("%d",&n);
    cout<<endl<<"Pattern 1"<<endl;
    star(n);
    cout<<endl<<"Pattern 2"<<endl;
    revStar(n);
    cout<<endl<<"Pattern 3"<<endl;
    star(n);
    revStar(n);
    cout<<endl<<"Pattern 4"<<endl;
    revStar(n);
    star(n);
    return 0;
}