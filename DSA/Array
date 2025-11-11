// program #1 
 #include<iostream>
using namespace std;
int main(){
	int arr[5];
	for(int i=0;i<5;i++)
	{
		cout<<"Enter Array Elements:";
		cin>>arr[i];
	}
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<endl;
	}
	
	return 0;
}

// program #2
 #include<iostream>#include<iostream>
using namespace std;
int main(){
	int arr[10];
	for(int i=0;i<10;i++)
	{
		cout<<"Enter array elements:";
		cin>>arr[i];
	}
	for(int i=0;i<10;i++)
	{
		if (arr[i]%2==0)
		{
			cout<<arr[i]<<endl;
		}
	}
	return 0;
}

// program #3
 #include<iostream>
using namespace std;
int main(){
	int nums[5]={5, 15, 22, 1, -15};
	int size = 6;
	
	int smallest = INT_MAX;
	
	for(int i=0;i<size;i++)
	{
		if(nums[i] < smallest) {
			smallest = nums[i];
		}
	}
	cout << "Smallest= "<<smallest<<endl;
	return 0;
}

// program #4
 #include<iostream>
using namespace std;
class ArraySum {
private:
    int first[5] = {5, 9, 6, 7, 8};
    int second[5] = {1, 10, 90, 50, 60};
    int result[5];
public:
    void calculateSum() {
        for(int i = 0; i < 5; i++) {
            result[i] = first[i] + second[i];
        }
    }
    void displayResult() {
        cout << "Result: ";
        for(int i = 0; i < 5; i++) {
            cout << result[i] << " ";
        }
        
    }
};
int main() {
    ArraySum obj;
    obj.calculateSum();
    obj.displayResult();
    return 0;
}

// program #5
 #include<iostream>
using namespace std;
int main()
{
	int first[5]={5,9,6,7,8};
	int second[5]={1,10,90,50,60};
	int result[5];
	for(int i=0;i<5;i++)
	{
		result[i]=first[i]+second[i];
	}
	cout<<"Result:";
	   for(int j=0;j<5;j++)
	    {
	    	cout<<result[j]<<" ";
		}
		return 0;
}

// program #6
 #include<iostream>
using namespace std;

int main() {
    int arr[10] = {5, 6, 5, 5, 6, 6, 7, 7, 6, 7};
    int count5 = 0, count6 = 0, count7 = 0;

    for(int i = 0; i < 10; i++) {
        if(arr[i] == 5)
            count5++;
        else if(arr[i] == 6)
            count6++;
        else if(arr[i] == 7)          //counting occurrences of 7
            count7++;
    }
     // Display the counts
    cout << "5 repeated " << count5 << " times\n";
    cout << "6 repeated " << count6 << " times\n";
    cout << "7 repeated " << count7 << " times\n";

    return 0;
}

// program #7
#include<iostream>
using namespace std;
int main()
{
	int rows, cols;
	cout<<"Enter number of rows: ";
	cin>>rows;
	cout<<"Enter number of columns: ";
	cin>>cols;
	int arr1[10][10], arr2[10][10], result[10][10];
     cout<<"\nEnter value in Array 1:\n";
	//input for first array
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>arr1[i][j];
		}
}
//input for second array
 cout<<"\nEnter value in Array 2:\n";
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){	
			cin>>arr2[i][j];
		}
	}
	for(int i=0;i<rows;i++){           //adding two arrays
		for(int j=0;j<cols;j++){	
	       result[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	//displaying result
	cout<<"\nResult = Array1 + Array2\n";
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){	
	       cout<<result[i][j]<<"\t"; 
		}
		cout<<endl;
	}
return 0;	
}