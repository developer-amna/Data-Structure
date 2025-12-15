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