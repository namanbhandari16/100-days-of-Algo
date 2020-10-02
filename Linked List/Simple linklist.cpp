// A simple C program to create  
// a linked list with 3 node
#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
	int data; 
	struct Node* next; 
}; 


int main() 
{ 
	struct Node* head = NULL; 
	struct Node* second = NULL; 
	struct Node* third = NULL; 

	
	head = (struct Node*)malloc(sizeof(struct Node)); 
	second = (struct Node*)malloc(sizeof(struct Node)); 
	third = (struct Node*)malloc(sizeof(struct Node)); 

	

	head->data = 1; // assign data in first node 
	head->next = second; 
    second->data = 2; //data assign to 2nd node
    second->next = third; //second node with third
    third->data = 3; //Data assigning to third node
	third->next = NULL; 

	return 0; 
} 
