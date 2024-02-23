You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]== "+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int val=0;
                if(tokens[i]== "+"){
                    val = num1+num2;
                }
                else if(tokens[i]=="-"){
                    val = num2-num1;
                }
                else if(tokens[i]=="*"){
                    val = num1*num2;
                }
                else{
                    val = num2/num1;
                }
                s.push(val);
            }
            else{
                string temp = tokens[i]; 
                int value = 0;
                int sign = 1;
                for(int i =0;i<temp.size();i++){
                    if(temp[i]!='-')
                        value = value*10 + temp[i]-'0';
                    else
                        sign = -1;
                }
                cout<<sign*value<<endl;
                s.push(sign*value);
            }
        }

        return s.top();
    }
};