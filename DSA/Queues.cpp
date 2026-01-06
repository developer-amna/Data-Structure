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

// Program # 2

#include<iostream>
using namespace std;
class cir_que{
	private:
		int F,B;
		int CQ[5];
	public:
		// Constructor to initialize F & B
		cir_que() {
			F = -1;
			B = -1;
		}
		void qinsert(int);
		int qdel(void);
};
// member function to add item
void cir_que::qinsert (int n) {
	if (F == (B + 1) % 5) {      // maximum size of array is 5
		cout << "Circular queue is full.";
		return;
	}
	else {
		B = (B + 1) % 5;
		CQ[B] = n;
		cout << "\nValue " << n << " is inserted.\n";
	}
	if (F == -1)
	    F = 0;
	
}   // end of qinsert()
// member function to delete item
int cir_que::qdel (void) {
	int x;
	if ((F == -1) && (B == -1)) {
		cout << "Circular queue is empty.";
		return NULL;
	}
	else {
		x = CQ[F];
		CQ[F] = NULL;
	}
	if (F == B)
	    F = B = -1;
	else 
		F = (F + 1) % 5;
		return x;
}    // end of qdel()
int main() {
	cir_que obj;
	int val,opt,loop = -1;
	while (loop) {
		cout << "01-Insert Value\n";
		cout << "02-Delete Value\n";
		cout << "03-Exit\n";
		cout << "Enter your choice [1-3] :";
		cin >> opt;
		switch(opt) {
			case 1:
				cout << "Enter value to insert : ";
				cin >> val;
				obj.qinsert(val);
				break;
			case 2:
				cout << "\nValue " << obj.qdel() << " is deleted.\n";
				break;
			case 3:
				loop = 0;
				break;
			default:
				cout << "Invalid option";
		} // end of switch
    }   // end of while
    return 0;
}   // end of main