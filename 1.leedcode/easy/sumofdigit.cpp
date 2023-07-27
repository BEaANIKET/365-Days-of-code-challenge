#include<iostream>
using namespace std;
 int sum =0, rem=0;
int sum_of_digit(int num){
    if(num==0){
        return sum;
    }
rem=num%10;
sum=sum+rem;
num=num/10;
sum_of_digit(num);
}

int main(){
    int num;
    cout<<"Enter the number :";
    cin>>num;
   cout<<"The sum of digit is = "<<sum_of_digit(num);


    return 0;
}