#include <iostream>
#include <string>
using namespace std;

//Student class definition
class Node 
{
	public:
		//node's constructor with single argument
		Node (string);
		//node's member variable for node's item
		string name;
		Node *next;
};

//function implementation
//constructor
Node::Node(string n)
{
	name = n;
}

//function not related to node class implementation
void listNodes (Node* head)
{
	Node* current = head;
	while (current)
		{
			cout<<current->name<<endl;
			current = current->next;
		}
	cout<<endl;
}

void deleteNodes (Node* head)
{
	Node* prev;
	Node* current = head;
	while (cusrrent)
	{
		prev = current;
		current = current->next;
		cout<<"Delete "<<prev->name<<endl;
	}
}

int main (int argc, char *argv [])
{
	string names [] = {"Baekhyun", "Kai", "Sehun", "Chanyeol", "Suho", "DO"};
	Node* head = NULL;
	Node* newNode = NULL;
	Node* prevNode = NULL;
	
	for (int i=0; i<6; i++)
	{
		newNode = new Node (names [i]);
		newNode->next = NULL;
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			prevNode->next = newNode;
		}
		
		prevNode = newNode;
	} //end loop
	
	//list all nodes
	cout<<"The original list: "<<endl;
	listNodes (head);
	
	Node* n = head;
	
}
