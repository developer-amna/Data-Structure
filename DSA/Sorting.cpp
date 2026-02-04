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

// Program # 6
          // Merge sort

#include<iostream>
using namespace std;
         void MergeSort(int[],int,int);
         void Merge(int[],int,int,int);
         
void MergeSort(int arr[],int start,int end) {
	if(start < end) {
		int mid = (start + end) / 2;
		           // Sort first and second halves
		
		MergeSort(arr,start,mid);
		MergeSort(arr,mid+1,end);
		Merge(arr,start,mid,end);
	}
}     // end of MergeSort() 

           // definition of merge function that merges the sub-arrays
void Merge(int arr[],int start,int mid,int end) {
	int i,j,k;
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int L[3],R[3];
	for(i=0;i<n1;i++)
	            L[i] = arr[start+i];
	for(j=0;j<n2;j++)
	            R[j] = arr[mid+1+j];
	            
	i = 0;
	j = 0;
	k = start;
	
	while(i<n1 && j<n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while(j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

int main() {
	int i,arr[] = {12,11,13,5,6,7};
	cout<<"The given array before sorting"<<endl;
	for(i=0;i<6;i++)
	         cout<<arr[i]<<"\t";
	cout<<endl;
	MergeSort(arr,0,5);
	cout<<"Array after sorting"<<endl;
	for(i=0;i<6;i++)
	         cout<<arr[i]<<"\t";
	         
	return 0;
}

// Program # 7
       // Counting Sort

#include<iostream>
using namespace std;
class Count {
	public:
		void Count_Sort(int[],int);
		int max_value(int[]);
};
void Count::Count_Sort(int ARR1[],int mx) {
	int *C,*S,i;
	C = new int[mx];
	S = new int[mx];
	for(i=0;i<=mx;i++)
	C[i] = S[i] = NULL;
	
	for(i=0;i<5;i++)
	          C[ARR1[i]] = C[ARR1[i]]+1;
	          
	for(i=0;i<mx;i++)
	       C[i+1] = C[i] + C[i+1];
	       
	for(i=0;i<=4;i++) {
		S[C[ARR1[i]]] = ARR1[i];
		C[ARR1[i]]--;
	}
	cout << "Sorted Array " << endl;
	for(i=0;i<=mx;i++)
	         if(S[i]!=NULL)
	                   cout << S[i] <<"\t";
}
int Count::max_value(int a[]) {
	int max = a[0];
	for(int i=0;i<5;i++) {
		if(a[i] > max)
		            max = a[i];
	}
	return max;
}
int main() {
	Count obj;
	int m,ARR[5] = {2,4,1,6,4};
	m = obj.max_value(ARR);
	obj.Count_Sort(ARR,m);
	return 0;
};