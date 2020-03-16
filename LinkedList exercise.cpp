#include<iostream>

using namespace std;
	
	class node
	{
	 public :
	  node *next; // Pointer to next node
	  int data;	//node data
	  //int number; 
	};
		 
  void listNode(node* head) {
    node* current = head;

    while (current) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n\n";
}

void deleteNodes(node* head) {
   node* prev;
   node* current = head;

    while (current) {
        prev = current;
        current = current->next;
        cout << "Delete " << prev->data << "\n";
        delete prev;
    }
}
   
int GetNth (node *head, int n)
{
	int count=1;
	if (count==n)
	return head->data;
	return GetNth (head->next, n-1);
}

	
	int main()
	{
		
	int bilNode=0;
    node *head;
	node *curr,*prev; 
	node *tail,*temp;
	
	
	int i;
	
	curr=NULL;
	
	for(i=0;i<30;i+=5)
	{
		node *newnode=new node;
		newnode->data=i;
		newnode->next=curr;
		curr=newnode;
		
		if (i==0)         //set tail point to last node ,  Node with 0 will be the last node
		{
			 tail=newnode;
		}	
	}
	
    head=curr;    //head point to the first node in the list which is 25
	
	listNode(head);


//How to add 35 at the end of list?
//Answer :
node *k = new node;
k->data=35;
k->next=NULL;
tail->next=k;
tail=k;
listNode(head);


//How to insert node with value 8 between 15 and 10 ?
//Answer :
while (curr->data!=10)
{
	prev=curr;
	curr=curr->next;
}
node *s = new node;
s->data=8;
s->next=prev->next;
prev->next=s;

curr=head;
listNode(head);	


//delete 
temp=head;
head=temp->next;
delete temp;	
listNode(head);	


//swapping
temp->data=head->data;
head->data=tail->data;
tail->data=temp->data;
//node *firstprev=NULL;
//node *secprev=NULL;

//while (curr->next!=firstprev)
//{
	//curr=curr->next;
//}
//firstprev=curr;


//listNode(head);	

//while (curr->next!=secprev)
//{
	//curr=curr->next;
//}
//curr=curr->next;

//temp=firstprev->next;
//secprev->next=firstprev->next;
//secprev->next=temp;
listNode(head);	


//find a node
cout<<"Element at index 4 is : "<<GetNth(head,4);
	
	
	return 0;
	}
	
		

	

