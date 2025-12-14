#include<iostream>
#include<string.h>
using namespace std;
struct std_node{
	int rollno;
	char name[50];
	std_node *link;
};
   class std_list{
   	private:
   		std_node *start, *current, *temp;
   	public:
   		std_list(void){
   			start = NULL;
		   }
		   void insert(int m, char nm[]){
		   	temp = new std_node;
		   	temp->rollno=m;
		   	strcpy(temp->name,nm);
		   	temp->link = NULL;
		   	if(start == NULL){
		   		start = temp;
		   	}
		   	else{
		   		current = start;
		   		while(current->link!=NULL)
		   		             current = current->link;
		   		             current->link=temp;
			   }
			   }
			   void display(){
			   	if(start == NULL){
			   		cout<<"List is empty"<<endl;
			   		return;
				   }
				   else{
				   	int rec=1;
				   	current = start;
				   	while(current!=NULL){
				   		cout<<"Record#"<<rec<<endl;
				   		cout<<"Roll Number : "<<current->rollno<<endl;
				   		cout<<"Name : "<<current->name<<endl;
				   		current = current->link;
				   		rec++;
					   }
				   }
			   }
   };
int main()
{
	std_list obj;
	int m, rec=1;
	char nm[15];
	do{
		cout<<"Enter Record #"<<rec;
		cout<<"\nEnter Roll No : ";
		cin>>m;
		cout<<"Enter Name : ";
		cin>>nm;
		obj.insert(m,nm);
		rec++;
	}
	while(rec<=5);
	obj.display();
	return 0;
}