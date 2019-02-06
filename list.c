#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
	char *before;
        char *after;	
	struct Node* next; 
}; 

void push(struct Node** head_ref, char *before, char *after) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	new_node->before = before;
        new_node->after = after;  	
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 


void printBefore(struct Node* node) 
{ 
	struct Node* last; 
	printf("\nReading each first node in reverse file order \n"); 
	while (node != NULL) { 
		printf("%s \n", node->before);
		last = node; 
		node = node->next; 
	} 

} 

void printAfter(struct Node* node)
{
        struct Node* last; 
        printf("\nReading each last node in reverse file order \n");
        while (node != NULL) { 
                printf("%s \n", node->after);    
                last = node; 
                node = node->next; 
        } 

} 
