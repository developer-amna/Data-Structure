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

// Program # 3

#include<iostream>
using namespace std;
class deque {
	private:
		int F,B,DQ[5];
	public:
		// constructor to initialize F & B
	deque() {
		F = -1;
		B = -1;
	}
	void insert_front(int);
	void insert_back(int);
	void del_front(void);
	void del_back(void);
	void print_deque(void);
};
// member function to insert item from front side of the deque
void deque::insert_front(int n) {
	if (F == 0 && B == 4) {
		cout << "Deque is full.";
		return;
	}
	if (F == -1 && B == -1) {
		B = F = 0;
		DQ[F] = n;
	}
	else if(F > 0) {
		F--;
		DQ[F] = n;
	}
	else {
		cout << "No space from front side ";
	}
} // end of insert_front

                  // member function to insert item from back side of the deque
void deque::insert_back(int n) {
	if (F == 0 && B == 4) {
		cout << "Deque is full.";
		return;
	}
	if (F == -1 && B == -1) {
		B = F = 0;
		DQ[B] = n;
	}
	else if(B < 4) {
	    B++;
		DQ[B] = n;
	}
	else {
		cout << "No space from rear side ";
	}
} // end of insert_back

                    // member function to delete item from front side of the deque
                    
void deque::del_front() {
	if (F == -1 && B == -1) {
		cout << "Deque is empty.";
		return;
	}
	else 
	     DQ[F] = NULL;
	if(F == B) 
	    F = B = -1;
	else if(F == 4)
	    F == -1;
	else
	    F++;
}   // end of del_front()

                   // member function to delete item from back side of the deque
void deque::del_back() {
	if (F == -1 && B == -1) {
		cout << "Deque is empty.";
		return;
	}
	else 
	           DQ[B] = NULL;
    if(B==F)
               F = B = -1;
    else
               B--;
} // end of del_back

                    // member function to display data from deque
void deque::print_deque() {
	cout << "\nDeque after operation\n";
	if(F == -1) {
		cout << "Queue is empty.";
		return;
	}
	for(int i=F; i<=B; i++)
	          cout << DQ[i] << "\t";
} // end of print
int main() {
	deque obj;
	int opt, val;
	while(opt!=5) {
		cout << "1 : Insert item from Front\n";
		cout << "2 : Insert item from Back\n";
		cout << "3 : Delete item from Front\n";
		cout << "4 : Delete item from Back\n";
		cout << "5 : Exit\n";
		cout << "Enter your choice :[1-5] : ";
		cin >> opt;
		switch(opt) {
			case 1:
				cout << "\nEnter value to insert : ";
				cin >> val;
				obj.insert_front(val);
				obj.print_deque();
				break;
		    case 2:
		    	cout << "\nEnter value to insert : ";
				cin >> val;
				obj.insert_back(val);
				obj.print_deque();
				break;
			case 3:
				obj.del_front();
				obj.print_deque();
				break;
			case 4:
				obj.del_back();
		} // end of switch
	}  // end of while
	return 0;
}  // end of main()
