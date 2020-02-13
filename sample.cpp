#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
	int info;
	struct Node *link;
}*start;
void createList(int data);
void addNodeBegin(int data);
void addNodeEnd(int data);
void deleteNodeBegin();
void deleteNodeEnd();
void display();
int main(){
	int choice, element, n, i;
	while(1){
		cout << "\nMENU\n";
		cout << "1 - Create a list\n";
		cout << "2 - Add node in the beginning\n";
		cout << "3 - Add node in the end\n";
		cout << "4 - Delete node in the beginning\n";
		cout << "5 - Delete node in the end\n";
		cout << "6 - Display\n";
		cout << "7 - Exit\n";
		cout << "\nEnter choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "How many nodes you want to create? \n";
				cin >> n;
				for(i = 0; i < n; i++){
					cout << "Enter the elements: \n";
					cin >> element;
					createList(element);
				}
				break;
			case 2:
				cout << "Add a node in the beginning: \n";
				cin >> element;
				addNodeBegin(element);
				break;
			case 3:
				cout << "Add node in the end: \n";
				cin >> element;
				addNodeEnd(element);
				break;
			case 4:
				cout << "Delete node in the beginning: \n";
				deleteNodeBegin();
				cout << "Beginning Node Deleted\n";
				break;
			case 5:
				cout << "Delete node in the end: \n";
				deleteNodeEnd();
				cout << "End Node Deleted\n";
				break;
			case 6:
				display();
				break;
			case 7:
				cout << "Exiting...\n";
				exit(1);
				break;
			default:
				exit(1);
		}
	}
	return 0;
}
void createList(int data){
	struct Node *p, *tmp;
	tmp = new Node;
	tmp -> info = data;
	tmp -> link = NULL;
	if(start == NULL){
		start = tmp;
	} else{
		p = start;
		while(p -> link != NULL){
			p = p -> link;
		}
		p -> link = tmp;
	}
}
void addNodeBegin(int data){
	struct Node *p2;
	p2 = new Node;
	p2 -> info = data;
	if(start == NULL){
		p2 -> link = NULL;
	} else{
		p2 -> link = start;
	}
	start = p2;
}
void addNodeEnd(int data){
	struct Node *p3, *tmp;
	p3 = new Node;
	p3 -> info = data;
	p3 -> link = NULL;
	if(start == NULL){
		start = p3;
	} else{
		tmp = start;
	}
	while(tmp -> link != NULL){
		tmp = tmp -> link;
	}
	tmp -> link = p3;
}
void deleteNodeBegin(){
	struct Node *p;
	if(start == NULL){
		cout << "List Empty";
	}else{
		p = start;
		start = start -> link;
		free(p);
	}
}
void deleteNodeEnd(){
	struct Node *p, *tmp;
	if(start == NULL){
		cout << "List Empty";
	}else{
		if(start -> link == NULL){
			p = start;
			start = NULL;
			free(p);
		} else{
			p = start;
			while(p -> link != NULL){
				tmp = p;
				p = p-> link;
			}
			tmp -> link = NULL;
		}
	}
}
void display(){
	struct Node *p;
	if(start == NULL){
		cout << "It's empty!\n";
		return;
	}
	p = start;
	cout << "The list: \n";
	while(p != NULL){
		cout << p -> info << endl;
		p = p -> link;
	}
}
