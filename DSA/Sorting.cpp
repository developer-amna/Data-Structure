// Program # 1
        // Bubble Sort

#include<iostream>
using namespace std;
class Bubble {
	private:
		int abc[5];
	public:
		void input(void);
		void sort(void);
		void print(void);
};
void Bubble::input(void) {
	cout << "Enter 5 values " << endl;
	for(int i=0;i<=4;i++)
	           cin >> abc[i];
}
void Bubble::sort(void) {
	int temp;
	for (int u=4;u>=1;u--) 
	    for (int i=0;i<=u;i++)
	         if (abc[i] > abc[i+1]) {
	         	temp = abc[i];
	         	abc[i] = abc[i+1];
	         	abc[i+1] = temp;
	         }
}
void Bubble::print(void) {
	cout << "Sorted Array " << endl;
	for(int i=0;i<=4;i++)
	    cout << abc[i] << "\t";
	cout << endl;
}
int main {
      Bubble obj;
      obj.input();
      obj.sort();
      obj.print();
      return 0;
}

// Program # 2
        // Selection Sort

#include<iostream>
using namespace std;
class Selection {
	private:
		int abc[5];
	public:
		void input(void);
		void sort(void);
		void print(void);
};
void Selection::input(void) {
	cout << "Enter 5 values " << endl;
	for(int i=0;i<=4;i++)
	           cin >> abc[i];
}
void Selection::sort(void) {
	int mini,temp,loc;
	for(int u=0;u<4;u++) {
		mini = abc[u];
		loc = u;
		for (int i=u;i<=4;i++)
		    if (mini > abc[i]) {
		    	mini = abc[i];
		    	loc = i;
		    }
		    
		temp = abc[loc];
		abc[loc] = abc[u];
		abc[u] = temp;
	}
}
void Selection::print(void) {
	cout << "Sorted Array " << endl;
	for(int i=0;i<=4;i++)
	    cout << abc[i] << "\t";
	cout << endl;
}
int main() {
      Selection obj;
      obj.input();
      obj.sort();
      obj.print();
      return 0;
}

// Program # 3
       // Insertion Sort

#include<iostream>
using namespace std;
class insertion {
	private:
		int abc[5];
	public:
		void input(void);
		void sort(void);
		void print(void);
};
void insertion::input(void) {
	cout << "Enter 5 values " << endl;
	for(int i=0;i<=4;i++)
	         cin >> abc[i];
}
void insertion::sort(void) {
	int val,i,u;
	for(u=1;u<=4;u++) {
		val = abc[u];
		for(i=u;i>=0 && val<abc[i-1];i--)
		       abc[i] = abc[i-1];
		abc[i] = val;
	}
}
void insertion::print(void) {
	cout << "Sorted array " << endl;
	for(int i=0;i<=4;i++)
	       cout << abc[i] << "\t";
	cout << endl;
}
int main() {
	insertion obj;
	obj.input();
	obj.sort();
	obj.print();
	return 0;
}