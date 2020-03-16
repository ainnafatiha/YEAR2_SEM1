#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

bool Operator(char a){
	if ((a=='+')||(a=='-')||(a=='*')||(a=='/')){
		return true;
	}
	return false;
}

bool Operand(char a){
	if ((a>='0')&&(a<='9')) return true;
	if ((a>='a')&&(a<='z')) return true;
	if ((a>='A')&&(a<='Z')) return true;
	
	return false;
}

int operatorweight(char a){
	int weight;
	if((a=='+')||(a=='-')){
		return weight=1;
	}
	else if((a=='*')||(a=='/')){
		return weight=2;
	}
	else if(a==')'){
		return weight=3;
	}
	else{
		return 0;
	}
}

bool precedence(char a, char b){
	int w1, w2;
	w1=operatorweight(a);
	w2=operatorweight(b);
	
	if (w1==w2){
		return true;
	}
	else if(w1>w2){
		return true;
	}
	else if(w2>w1){
		return false;
	}
	
	return false;
}

float operation(char a, float b, float c){
	float ans;
	if (a=='+') ans=b+c;
	if (a=='-') ans=b-c;
	if (a=='*') ans=b*c;
	if (a=='/') ans=b/c;
	return ans;
}

float evaluation(string a){
	stack<float> s;
	float o1, o2;
	
	for (int i=0; i<a.length(); i++){
		if(a[i]==' ') continue;
		
		else if(Operator(a[i])){
			o2=s.top(); s.pop();
			o1=s.top(); s.pop();
			
			float result=operation(a[i], o1, o2);
			
			s.push(result);
			cout<<"top "<<s.top()<<endl;
		}
		else if(Operand(a[i])){
			float operand=0;
			while(i<a.length()&&Operand(a[i])){
				operand=(operand*10)+(a[i]-48);
				i++;
			}
			i--;
			s.push(operand);
		}
	}
	return s.top();
}

string conversion(string a){
	stack<char> s;
	string postfix="";
	for (int i=0; i<a.length(); i++){
		if(a[i]==' ') continue;

		else if(Operand(a[i])){
			postfix+=a[i];
			while(Operand(a[i+1])){
				postfix+=a[i+1];
				i++;
			}
			postfix+=' ';
		}		
		else if(Operator(a[i])){
			while((!s.empty())&&(s.top()!='(')&&(precedence(s.top(), a[i]))){
				postfix+=s.top();
				s.pop();
			}
			s.push(a[i]);
		}		
		else if(a[i]=='('){
			s.push(a[i]);
		}
		else if(a[i]==')'){
			while((!s.empty())&&(s.top()!='(')){
				postfix+=s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty()){
	postfix+=s.top();
	s.pop();
	}
	return postfix;
}

int main(){
	string a="9-10/(2*8)+3";
	
	string postfix=conversion(a);
	cout<<"Postfix: "<<postfix<<endl;
	
	cout<<"Evaluation"<<endl;
	float Ans=evaluation(postfix);
	cout<<"Answer: "<<Ans<<endl;
	
	return 0;
}
