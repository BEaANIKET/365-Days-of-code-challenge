#include<iostream>
using namespace std;
   int num1,sum,rem;
int cheak_palinder(int num){
    if(num==0){
        return sum;
    }
 rem=num%10;
 sum=sum*10 + rem;
 num=num/10;
 cheak_palinder(num);


}

int main(){
   int num,num1;
   cout<<"Enter the number :";
   cin>>num;
   cheak_palinder(num);
   if (sum==num){
    cout<<"!!!!  Yes it is palinder number  !!!!";
   }
   else{
    cout<<"!!!! No this number is not a palinder number !!!!";
   }


    return 0;
}