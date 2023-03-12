#include<iostream>
using namespace std;

int main(){
    int num,num1=0,sum,rem=0;
    cout<<"Enter the number :";
    cin>>num;
    int num2=num;
while(num>0){
rem=num % 10;
num1=(num1*10) + rem;
num=num/10;
}
if (num1==num2){
cout<<"yes "<<num2<<" is a armstrong number !! "; 
}
else{
    cout<<"No "<<num1<<"  is not a armstrong number ";
}
    return 0;
}