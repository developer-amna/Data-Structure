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



Operations on Singly Linked List

#include<iostream>
using namespace std;
struct node{
	float data;
	node *link;
};
class list{
	private:
		node *start;
	public:
	
		list(void){
			start = NULL;
		}
	    void insert_begin(void);
	    void insert_end(void);
	    void insert_location(void);
	    void delete_begin(void);
	    void delete_end(void);
	    void delete_location(void);
		void search(void);
		void display(void);
		int count(void);
		void bubble_sort(void);
};
void list::insert_begin(void){
	struct node *temp;
	temp = new node;
	cout<<"Enter the data value for a node:";
	cin>>temp->data;
	temp->link=NULL;
	
	if(start==NULL){
		start = temp;
	}
	else{
		temp->link = start;
		start = temp;
	}
}
void list::insert_end(void)
{
	struct node *temp, *current;
	temp=new node;
	cout<<"Enter the data value for a node:";
	cin>>temp->data;
	temp->link=NULL;
	
	if(start==NULL){
		start = temp;
	}
	else{
		current = start;
		while(current->link!=NULL)
		       current = current->link;
		       
		    current->link = temp;
	}
}
void list::insert_location(void){
	struct node *temp, *current;
	int n, pos = 0;
	
	if(start==NULL){
		cout<<"List is empty.";
		return;
	}
	else{
		cout<<"Enter the value to search:";
		cin>>n;
		
		current = start;
		while(current!=NULL){
			if (current->data==n)
			{
				pos = 1;
				break;
			}
			current = current->link;
		}
	}
	if(pos==1){
		temp = new node;
		cout<<"Enter the data value for a node:";
	    cin>>temp->data;
	    
	    temp->link = current->link;
	    current->link = temp;
	}
	else{
		cout<<"Value not found";
		return;
	}
}
void list::delete_end(){
	struct node *previous,*current;
	if(start==NULL){
		cout<<"List is empty";
		return;
	}
	else{
		current = start;
		while(current->link!=NULL){
			previous = current;
			current = current->link;
		}
		cout<<"Data of last node is :"<<current->data;
		previous->link = NULL;
		delete current;
		cout<<endl<<"Last node is deleted";
	}
}
void list::delete_begin(){
	struct node *current;
	if(start==NULL){
		cout<<"List is empty";
		return;
	}
	{
		current = start;
		start = current->link;
		cout<<"Data of first node is :"<<current->data;
		delete current;
		cout<<endl<<"first node is deleted";
	}
	
}
void list::delete_location(){
	struct node *previous,*current;
	int pos = 0;
	if(start==NULL){
		cout<<"List is empty";
		return;
	}
	else{
	      int n;
		  cout<<"Enter a value to search :";
		  cin>>n;
		  current = previous = start;
		  	while(current!=NULL){
			if (current->data==n)
			{
				pos = 1;
				break;
			}
			previous = current;
			current = current->link;
		}
		if(pos == 1){
			previous->link = current->link;
			delete current;
			cout<<"Node is deleted";
		}else
		      cout<<"Value not fournd"<<endl;
	}
}
void list::bubble_sort(){
		if(start==NULL){
		cout<<"List is empty";
		return;
	}
	struct node *current,*previous;
	int size,temp;
	size = count();
	for(int u=size;u>1;u--){
		current = start;
		for(int i=1;i<u;i++){
			previous = current;
			current = current->link;
			if(previous->data > current->data){
				temp = previous->data;
				previous->data = current->data;
				current->data = temp;
			}
		}
	}
}
int list::count(void){
	struct node *current;
	int count = 0;
	if(start==NULL){
		cout<<"List is Empty"<<endl;
		return 0;
	}
	else{
		current = start;
		while(current!=NULL){
			count++;
			current=current->link;
		}
		return count;
	}
}
void list::search(void){
	struct node *current;
	int value,flag=0;
	if(start==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	else{
		cout<<"Enter a value to search :";
		cin>>value;
		current = start;
		while(current!=NULL){
			if(current->data==value){
				flag=1;
				break;
			}
			current = current->link;
		}
	}
	if(flag==1)
	    cout<<"Value found in the list";
	else
	    cout<<"Value not found in the list";
}
void list::display(void){
	struct node *current;
	if(start==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	else{
		current = start;
		while(current!=NULL){
			cout<<current->data<<endl;
			current=current->link;
		}
	}
}
int main(){
       list obj;
	   int op;
	    bool loop = true;
	   while(loop){
	   	cout<<"\n01- Insert a node at the beginning"<<endl;
	   	cout<<"02- Insert a node at the end"<<endl;
	   	cout<<"03- Insert a node at a specific location"<<endl;
	   	cout<<"04- Delete a node at the beginning"<<endl;
	   	cout<<"05- Delete a node at the end"<<endl;
	   	cout<<"06- Delete a node at a specific location"<<endl;
	   	cout<<"07-sort the values of the list"<<endl;
	   	cout<<"08- Search the value from a list "<<endl;
	   	cout<<"09- Display data of nodes"<<endl;
	   	cout<<"10- Count nodes of the list"<<endl;
	   	cout<<"11- Exit"<<endl;
	   	cout<<"Enter your option[1-11]: ";
	   	cin>>op;
	   	switch(op){
	   		case 1:
	   			obj.insert_begin();
	   			break;
	   		case 2:
	   			obj.insert_end();
	   			break;
	   		case 3:
	   			obj.insert_location();
	   			break;
	   		case 4:
	   			obj.delete_begin();
	   			break;
	   		case 5:
	   			obj.delete_end();
	   			break;
	   		case 6:
	   			obj.delete_location();
	   			break;
	   		case 7:
	   			obj.bubble_sort();
	   			break;
	   		case 8:
			   obj.search();
	   		   break;
	   		case 9:
			   obj.display();
	   		   break;
	   		case 10:
			   cout<<"Total nodes are: "<<obj.count();
	   		   break;
	   		case 11:
			   loop = false;
	   	    	break;
	   		default:
	   			cout<<"Invalid option";
	   			break;
		   }
		   
	   }
	   return 0;
	   }