#include<bits/stdc++.h>

using namespace std;

int priority(char op) {
    if (op == '*' || op == '/') {
        return 3;
    } else if (op == '+' || op == '-') {
        return 2;
    } else if (op == '$') {
        return 1;
    } else return 0;
}
float calculate(float x, float y, char op) {
    if (op == '*') {
        return x * y;
    } else if (op == '/') {
        return x / y;
    } else if (op == '+') {
        return x + y;
    } else return x - y;
}

int main()
{
    string str;
    stack<char> operators;
    stack<float> operands;
    operators.push('#');
    while(cin>>str){
        str+='$';
        int i=0;
        while(i<str.size()){
            if(str[i]>='0'&&str[i]<='9'){
                float num=0;
                while(str[i]>='0'&&str[i]<='9'){
                    num=num*10+str[i]-'0';
                    i++;
                }
                operands.push(num);
            }
            else{
                if(priority(str[i])>priority(operators.top())){
                    operators.push(str[i++]);
                }
                else{
                    char op=operators.top();
                    operators.pop();
                    float b=operands.top();
                    operands.pop();
                    float a=operands.top();
                    operands.pop();
                    operands.push(calculate(a,b,op));
                }
            }
        }
        cout<<operands.top()<<endl;
        operands.pop();
        operators.pop();
    }
    return 0;
}
