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

	   \\ Program 3

	   #include<iostream>
#include<string.h>
using namespace std;

struct node {
    int rollno;
    char name[50];
    node* link;
};

class list {
private:
    node* start;
public:
    list() {
        start = NULL;
    }

    void insert_begin();
    void insert_end();
    void insert_location();
    void search();
    void display();
    int count();
};

void list::insert_begin() {
    node* temp = new node;
    cout << "Enter Roll No: ";
    cin >> temp->rollno;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(temp->name, 50);
    temp->link = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        temp->link = start;
        start = temp;
    }
}

void list::insert_end() {
    node* temp = new node;
    cout << "Enter Roll No: ";
    cin >> temp->rollno;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(temp->name, 50);
    temp->link = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        node* current = start;
        while (current->link != NULL)
            current = current->link;
        current->link = temp;
    }
}

void list::insert_location() {
    int searchRoll;
    cout << "Enter Roll No to insert after: ";
    cin >> searchRoll;

    node* current = start;
    while (current != NULL) {
        if (current->rollno == searchRoll) {
            node* temp = new node;
            cout << "Enter New Roll No: ";
            cin >> temp->rollno;
            cout << "Enter Name: ";
            cin.ignore();
            cin.getline(temp->name, 50);

            temp->link = current->link;
            current->link = temp;
            return;
        }
        current = current->link;
    }
    cout << "Roll No not found.\n";
}

void list::search() {
    int searchRoll;
    cout << "Enter Roll No to search: ";
    cin >> searchRoll;

    node* current = start;
    while (current != NULL) {
        if (current->rollno == searchRoll) {
            cout << "Record Found:\n";
            cout << "Roll No: " << current->rollno << "\n";
            cout << "Name: " << current->name << "\n";
            return;
        }
        current = current->link;
    }
    cout << "Record not found.\n";
}

void list::display() {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* current = start;
    int rec = 1;
    while (current != NULL) {
        cout << "\nRecord #" << rec << "\n";
        cout << "Roll No: " << current->rollno << "\n";
        cout << "Name: " << current->name << "\n";
        current = current->link;
        rec++;
    }
}

int list::count() {
    int cnt = 0;
    node* current = start;
    while (current != NULL) {
        cnt++;
        current = current->link;
    }
    return cnt;
}

int main() {
    list obj;
    int op;
    bool loop = true;

    while (loop) {
        cout << "\n01- Insert student at beginning\n";
        cout << "02- Insert student at end\n";
        cout << "03- Insert student after roll number\n";
        cout << "04- Search student by roll number\n";
        cout << "05- Display all student records\n";
        cout << "06- Count total students\n";
        cout << "07- Exit\n";
        cout << "Enter your option [1-7]: ";
        cin >> op;

        switch (op) {
            case 1: obj.insert_begin(); break;
            case 2: obj.insert_end(); break;
            case 3: obj.insert_location(); break;
            case 4: obj.search(); break;
            case 5: obj.display(); break;
            case 6: cout << "Total students: " << obj.count() << "\n"; break;
            case 7: loop = false; break;
            default: cout << "Invalid option\n";
        }
    }

    return 0;
}

\\ Program 4

#include<iostream>
using namespace std;
struct node{
	node *previous;
	int data;
	node *next;
};
class list{
	private:
		node *current,*start,*temp;
	public:
		list(){
			start = NULL;
		}
		void add_item(int);
		void display(void);
		
};
void list::add_item(int x){
	temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(start ==NULL){
		temp->previous=NULL;
		start = temp;
	}
	else{
		current  = start;
		while(current->next!=NULL)
		    current = current->next;
		current->next = temp;
		temp->previous = current;
		
	}
}
void list::display(){
	cout<<"Data in doubly linked list\n";
	current = start;
	while(current!=NULL){
		cout<<current->data<<endl;
		current = current->next;
	}
}
int main(){
	list obj;
	int value;
	cout<<"Enter five values\n";
	for(int i=0;i<=5;i++){
		cin>>value;
		obj.add_item(value);
	}
	obj.display();
}
	
\\Program # 5

#include<iostream>
using namespace std;
struct node{
	node *previous;

	int data;
	node *next;
};
class dll{
	private:
		node *start;
	public:
	
		dll(void){
			start = NULL;
		}
	    void insert_begin(void);
	    void insert_end(void);
	    void insert_location(void);
	    void delete_begin(void);
	    void delete_end(void);
	    void delete_location(void);
		void forward_display(void);
		void backward_display(void);
		
};
void dll::insert_begin(void){
	struct node *temp;
	temp = new node;
	cout<<"Enter the data value for the node:";
	cin>>temp->data;
	temp->previous = NULL;
	if(start==NULL){
		temp->next = NULL;
		start = temp;
	}
	else{
		temp->next = start;
		start->previous = temp;
		start = temp;
	}
}
void dll::insert_end(void){
	struct node *temp,*current;
	temp = new node;
	cout<<"Enter the data value for the node:";
	cin>>temp->data;
	temp->next = NULL;
	if(start==NULL){
		temp->previous = NULL;
		start = temp;
	}
	else{
		current = start;
		while(current->next!=NULL)
		       current = current->next;
		       current->next = temp;
		       temp->previous = current;
	}
}
void dll::insert_location(void){
	struct node *temp,*current;
	int x,y;
	temp = new node;
	cout<<"Enter the value to insert:";
	cin>>x;
	temp->data = x;
	if(start==NULL){
		temp->next = NULL;
		temp->previous = NULL;
		start = temp;
		return;
	}
	else{
		cout<<"Enter teh value to search:";
		cin>>y;
		current = start;
		while(current!=NULL){
			if(current->data==y)
			break;
			current = current->next;
		}
		if(current==NULL){
			cout<<"Value not found in the list:";
			return;
		}
		if(current->next==NULL){
			temp->next = NULL;
			current->next = temp;
			temp->previous = current;
		}
		else{
			temp->next = current->next;
			temp->previous = current;
			(current->next)->previous = temp;
			current->next = temp;
		}
	}
}
void dll::delete_begin(void){
	struct node *temp;
	if(start==NULL){
		cout<<"List is empty:";
		return;
	}
	else{
		temp = start;
		cout<<"Data of first node:"<<temp->data;
		start = start->next;
		start->previous = NULL;
		delete temp;
		cout<<endl<<"First node is deleted.";
	}
}
void dll::delete_end(void){
	struct node *temp,*current;
	if(start==NULL){
		cout<<"List is empty";
		return;
	}
	else{
		current = start;
		while(current->next!=NULL)
		       current = current->next;
	    temp = current;
	    cout<<"Data of last node is:"<<current->data;
	    current = current->previous;
	    current->next = NULL;
	    delete temp;
	    cout<<endl<<"Last node is deleted.";
	}
	
}
void dll::delete_location(void){
	struct node *temp,*current;
	if(start==NULL){
		cout<<"List is empty";
		return;
	}
	int n;
	cout<<"Enter value to search:";
	cin>>n;
	current = start;
	while(current!=NULL){
		if(current->data==n)
		     break;
		current = current->next;
	}
	if(current==NULL){
		cout<<"Value not found in the list."<<endl;
		return;
	}
	if(current->next==NULL){
		cout<<"No node after the current node. ";
		return;
	}
	else{
		temp = current->next;
		current->next = temp->next;
		temp->next->previous = current;
		delete temp;
		cout<<"Node is deleted:"<<endl;
	}
}
void dll::forward_display(void){
	struct node *current;
	if(start==NULL){
		cout<<"List is empty";
		return;
	}
	else{
		current = start;
		cout<<"Data od DDL in forward order\n";
		while(current!=NULL){
			cout<<current->data<<endl;
			current = current->next;
		}
	}
}
void dll::backward_display(void){
		struct node *current;
	if(start==NULL){
		cout<<"List is empty";
		return;
	}
	else{
		current = start;
		while(current->next!=NULL)
		       current = current->next;
		 cout<<"Data od DDL in backward order\n";
		while(current!=NULL){
			cout<<current->data<<endl;
			current = current->previous;
		}      
	}
}
int main(){
       dll obj;
	   int op;
	    bool loop = true;
	   while(loop){
	   	cout<<"\n01- Insert a node at the beginning"<<endl;
	   	cout<<"02- Insert a node at the end"<<endl;
	   	cout<<"03- Insert a node at a specific location"<<endl;
	   	cout<<"04- Delete a node at the beginning"<<endl;
	   	cout<<"05- Delete a node at the end"<<endl;
	   	cout<<"06- Delete a node at a specific location"<<endl;
	   	cout<<"07- Display data of nodes in forward direction"<<endl;
	   	cout<<"08- Display data of nodes in backward direction"<<endl;
	   	
	   	cout<<"9- Exit"<<endl;
	   	cout<<"Enter your option[1-9]: ";
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
			   obj.forward_display();
	   		   break;
	   		case 8:
			   obj.backward_display();
	   		   break;
	   		
	   		case 9:
			   loop = false;
	   	    	break;
	   		default:
	   			cout<<"Invalid option";
	   			break;
		   }
		   
	   }
	   return 0;
	   }

\\ Program 6

#include<iostream>
using namespace std;
struct node{
	int n;
	node *link;
};
class list{
	private:
		node *S,*C,*P;
	public:
		list(void){
			S = NULL;
		}
		void insert(int);
		void display(void);
};
void list::insert(int data)
{
	if(S==NULL){
		P = new node;
		P->n = data;
		S = P;
	}
	else{
		C = new node;
		C->n = data;
		P->link = C;
		P = C;
	}
}
void list::display(void){
	C = S;
	cout<<"Values of the list:"<<endl;
	while(1){
		cout<<C->n<<endl;
		if(C==P)
		    break;
		C = C->link;
	}
}
int main(){
	list obj;
	int x;
	cout<<"Enter 5 integer values\n";
	for(int i=1;i<=5;i++){
		cin>>x;
		obj.insert(x);
	}
	obj.display();
	return 0;
}


