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

// Program # 4
         // Shell Sort

#include<iostream>
using namespace std;
class shell {
	private:
		int arr[5];
	public:
		void input(void);
		void sort(void);
		void display(void);
};
void shell::input(void) {
	cout << "Enter 5 values " << endl;
	for(int i=0;i<=4;i++)
	         cin >> arr[i];
}
void shell::sort(void) {
	int j,gap;
	gap = 5/2;
	while(gap>0) {
		for (int i=gap;i<5;i++) {
			int temp = arr[i];
			for(j=i;j>=gap && temp<arr[j-gap];j-=gap)
			      arr[j] = arr[j-gap];
			arr[j] = temp;
		}
		gap = gap/2;
	}
}
void shell::display(void) {
	cout << "Sorted array " << endl;
	for(int i=0;i<=4;i++)
	       cout << arr[i] << "\t";
	cout << endl;
}
int main() {
	shell obj;
	obj.input();
	obj.sort();
	obj.display();
	return 0;
}

// Program # 5
          // Quick Sort

#include<iostream>
using namespace std;
             void quicksort(int[],int,int);
             int partition(int[],int,int);
             
void quicksort(int arr[],int first,int last) {
	int split_point;
	if(first < last) {
	        split_point = partition(arr,first,last);
			
			      // sort left and right
			quicksort(arr,first,split_point-1);
			quicksort(arr,split_point+1,last);	
	}
}    // end of quicksort()

              // definition of partition function
int partition(int arr[],int first,int last) {
	int temp,L,R,pivot = arr[first];
	L = first + 1;
	R = last;
	while(1) {
		while(arr[L]<=pivot && L<=R)
		        L++;
		while(arr[R]>=pivot && R>=L)
		        R--;
		if(R<L) {
			temp = arr[first];
			arr[first] = arr[R];
			arr[R] = temp;
			break;
		}
		else {
			temp = arr[L];
			arr[L] = arr[R];
			arr[R] = temp;
			L++;
			R--;
		}
	}
	return R;
}  // end of partition()
int main() {
	int i,arr[] = {2,15,1,61,11,27,8};
	cout<<"Array before sorting"<<endl;
	for(i=0;i<=6;i++)
	         cout<<arr[i]<<"\t";
	cout<<endl;
	quicksort(arr,0,6);
	cout<<"Array after sorting"<<endl;
	for(i=0;i<=6;i++)
	         cout<<arr[i]<<"\t";
	cout<<endl;
	return 0;
}