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