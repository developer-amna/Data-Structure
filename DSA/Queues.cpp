// Program # 1

#include<iostream>
using namespace std;
class queue{
	private:
		int F,B;
		int QU[10];
	public:
		queue(void) {
			B = -1;
			F = -1;
		}
		void insert(int);
		void remove(void);
		void display(void);
};
void queue::insert(int x) {
	if (B == 9 && F == 0 ) {
		cout<<"Queue overflow.";
		return;
	}
	else {
		B = B + 1;
		QU[B] = x;
	}
	if(F == -1) 
	    F = 0;
}
void queue::remove(void) {
	if (F == -1) {
		cout<<"Queue is empty.";
		return;
	}
	else {
		cout<<"Queue"<<QU[F]<<"is removed."<<endl;
		QU[F] = NULL;
		F = F + 1;
		if (F > B)
		   F = B = -1;
	}
}
void queue::display(void) {
	if (F == -1) {
		cout<<"Queue is empty.";
		return;
	}
	else {
		for(int i = F;i <= B;i++)
		  cout<<QU[i]<<endl;
	}
}
int main() {
	queue obj;
	int n,opt,loop = -1;
	while(loop) {
		cout << "01-Insert value into queue: " << endl;
		cout << "02-Delete value from queue: " << endl;
		cout << "03-Display value of queue: " << endl;
		cout << "04-Exit"<<endl;
		cout << "Enter your option [1-4]" << endl;
		cin >> opt;
		switch(opt) {
			case 1:
				cout << "Enter value to insert: " << endl;
				cin >> n;
				obj.insert(n);
				break;
			case 2:
				obj.remove();
				break;
			case 3:
				cout << "Value in queue: " << endl;
				obj.display();
				break;
			case 4:
				loop = 0;
				break;
			default:
				cout << "Invalid option.";
        }
	}
	    
	return 0;
}