\\ Program # 1

#include<iostream>
using namespace std;
class stack{
	private:
		int top;
		int stk[5];
	public:
		stack(void){
			top = -1;
		}
		void push(int);
		void pop(void);
		void display(void);
};
void stack::push(int x){
	if(top==4){
		cout<<"stack is empty.";
		return;
	}
	top = top+1;
	stk[top] = x;
}
void stack::pop(void){
	int val;
	if(top==-1){
		cout<<"Stack is empty.";
		return;
	}
	val = stk[top];
	stk[top] = NULL;
	top = top-1;
	cout<<"Value"<<val<<"is removed."<<endl;
}
void stack::display(void){
	if(top==-1){
		cout<<"Stack is empty.";
		return;
	}
	for(int x=top;x>=0;x--)
	cout<<stk[x]<<endl;
}
int main(){
	stack st;
	int n,opt,loop=1;
	while(loop){
		cout<<"1-Pushing stack "<<endl;
		cout<<"2-Popping stack "<<endl;
		cout<<"3-Display stack "<<endl;
		cout<<"4-Exit"<<endl;
		cout<<"Enter your option[1-4]?";
		cin>>opt;
		switch(opt){
			case 1:
				cout<<"Enter value to insert: ";
				cin>>n;
				st.push(n);
				break;
			case 2:
				st.pop();
				break;
			case 3:
			    cout<<"Values in stack\n";
				st.display();
				break;
			case 4:
			    loop = 0;
				break;
			default:
			    cout<<"Invalid option.";
						}
						
	}
	return 0;
}

\\ Program # 2

#include<iostream>
using namespace std;
class stack{
	private:
		int top;
		int stk[15];
	public:
		stack(void){
			top = -1;
		}
		void bin(int x);
		void display(void);
};
void stack::bin(int x){
	int r;
	while(x>0){
		r = x%2;
		top = top + 1;
		stk[top] = r;
		x = x/2;
	}
}
void stack::display(void){
	cout<<"Value in binary=(";
	for(int i=top;i>=0;i--)
	         cout<<stk[i];
	cout<<")2";
}
int main(){
	stack obj;
	int n;
	cout<<"Enter an integer value:";
	cin>>n;
	obj.bin(n);
	obj.display();
	return 0;
}

\\ Program # 3

#include<iostream>
using namespace std;
class stack{
	private:
		int top;
		int stk[25];
	public:
		stack(void){
			top = -1;
		}
		void push_str(char x[]);
		void pop_str(void);
		
};
void stack::push_str(char x[]){
	for(int i=0;x[i]!='\0';i++){
		top++;
		stk[top] = x[i];
	}
}
void stack::pop_str(void){
	cout<<"String in reverse order:";
	for(int i=top;i>=0;i--)
	          cout<<stk[i];
}
int main(){
	stack obj;
	char str[25];
	cout<<"Enter a string:";
	cin>>str;
	obj.push_str(str);
	obj.pop_str();
	return 0;
}

\\ Program # 4

#include<iostream>
#include<cctype>
using namespace std;
int priority(char);
class infix_postfix{
	private:
		char stack[20];
		int top;
	public:
		infix_postfix(){
			top = -1;
		}
		void scan(char[]);
		void push(char);
		char pop(void);
};
void infix_postfix::scan(char str_exp[]){
	char ch,output[80],temp;
	int c = 0;
	for(int i = 0;str_exp[i]!='\0';i++){
		ch = str_exp[i];
		if(isalpha(ch) || isdigit(ch)){
			output[c] = ch;
			c++;
		}
		else if(ch=='(')
             push(ch);
        else if(ch==')'){
        	temp = pop();
        	while(temp!='('){
        		output[c] = temp;
        		c++;
        		temp = pop();
        	}
        }
        else if(ch=='^' || ch=='*' || ch=='/' || ch=='+' || ch=='-'){
        	if(top==-1)
        	         push(ch);
        	else{
        		int op_ch;
        		op_ch = priority(ch);
        		while(priority(stack[top])>=op_ch && top!=-1){
        			temp = pop();
        			output[c] = temp;
        			c++;
        		}
        		push(ch);
        	}
        }
	}
	int j = c;
    while (top >= 0) {
        output[j++] = pop();
    }
    output[j] = '\0';

    cout << "Postfix expression = " << output << endl;
}

void infix_postfix::push(char x){
	top++;
	stack[top] = x;
}
char infix_postfix::pop(void){
	char r;
	r = stack[top];
	top--;
	return r;
}
int priority(char op){
	switch(op){
		case'^':
			return 4;
			break;
		case'*':
		case'/':
			return 3;
			break;
		case'+':
		case'-':
			return 2;
			break;
		default:
			return 0;
	}
}
int main(){
	infix_postfix obj;
	char exp[100];
	cout<<"Enter infix expression without spaces:";
	cin>>exp;
	obj.scan(exp);
	return 0;
}

\\ Program # 5


#include<iostream>
#include<vector>
using namespace std;


class stack{
	vector<int>v;
	public:
		void push(int val){
			v.push_back(val);
		}
		void pop(){
			v.pop_back();
			
		}
		int top(){
			return v[v.size()-1];
		}
		bool empty(){
			return v.size() == 0;
		}
};

int main(){
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
		
	}
	cout<<endl;
	
	return 0;
}

\\ Program # 6

#include<iostream>
#include<vector>
#include<list>
using namespace std;


class stack{
	list<int>ll;
	public:
		void push(int val){
		ll.push_front(val);	
		}
		void pop(){
		ll.pop_front();	
			
		}
		int top(){
		return ll.front();	
		}
		bool empty(){
			return ll.size() == 0;
		}
};

int main(){
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
		
	}
	cout<<endl;
	
	return 0;
}

\\ Program # 7

#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

int main()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
		
	}
	cout<<endl;
	
	return 0;
}

\\ Program # 8

#include<iostream>
#include<stack>
using namespace std;
class solution{
	public:
		bool isValid(string str){
			stack<char>st;
			for(int i=0;i<str.size();i++){
				if(str[i]=='(' || str[i]=='{' || str[i]=='['){
				  st.push(str[i]);	
				}
				else{
					if (st.size() == 0){
						return false;
					}
					if ((st.top() =='(' && str[i] ==')')||
					    (st.top() == '{' && str[i] == '}')||
						(st.top() == '[' && str[i] == ']')){
							st.pop();
						}
						else{
							return false;
						}
				}
			}
			return st.empty();
		}
	
		
		
};
int main() {
    solution obj;
    string s;
    cout << "Enter string of brackets: ";
    cin >> s;

    if (obj.isValid(s)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}
 

\\ Program # 9

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	int arr[] = {100, 80, 60, 70, 60, 75, 85};
    vector<int> price(arr, arr + 7);   // 7 elements

	//solution
	vector<int>ans(price.size());
	stack<int>s;
	
	for(int i=0; i<price.size(); i++ ){
		while(s.size() >0 && price[s.top()] <= price[i]){
			s.pop();
		}
		if(s.empty()) {
			ans[i] = i + 1;
			
		} else{
			ans[i] = i - s.top();
		}
		s.push(i);
	}
	for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
}

	cout<<endl;
	return 0;
}

\\ Program 10

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
		int arr_raw[] = {6, 8, 0, 1, 3};
        vector<int> arr(arr_raw, arr_raw + 5);   // 5 elements
	
	
	// Next Greater Element
	stack<int>s;
	vector<int>ans(arr.size(),0);
	for(int i=arr.size()-1; i>=0; i--){
		while(s.size()>0 && s.top()<=arr[i]){
			s.pop();
		}
		if(s.empty()){
			ans[i] = -1;
		} else {
			ans[i] = s.top();
		}
		s.push(arr[i]);
	}
	for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
}

	cout<<endl;
	
	return 0;
}

// Program # 11

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
	vector<int>preSmallerElement(vector<int>arr) {
		vector<int>ans(arr.size(),0);
		stack<int>s;
		
		for(int i=0; i<arr.size(); i++) {
			while(s.size()>0 && s.top()>=arr[i]) {
				s.pop();
			}
			
			if(s.empty()) {
				ans[i] = -1;
			} else {
				ans[i] = s.top();
			}
			
			s.push(arr[i]);
		}
		return ans;
	}
	int main() {
		int arr_raw[] = {3,1,0,8,6};
		vector<int>arr(arr_raw, arr_raw + 5);
		
		vector<int>ans=preSmallerElement(arr);
			for (int i = 0; i < ans.size(); i++) {
                    cout << ans[i] << " ";
}

	cout<<endl;
	
	return 0;
	}
	
