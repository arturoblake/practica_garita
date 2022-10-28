#include<stdio.h>
#include<stdlib.h>

struct CLLNode{
    
	int data; 
	struct CLLNode *next; 

};

void instrucciones(void);
int CircularListLength(struct CLLNode *head);
void PrintCircularListData(struct CLLNode *head);
void InsertAtEndlnCLL(struct CLLNode **head, int data);
void InsertAtBeginlnCLL(struct CLLNode **head, int data);
void DeleteLastNodeFromCLL(struct CLLNode **head);
void DeleteFrontNodeFromCLL(struct CLLNode **head);

int main(){
	
	struct CLLNode *head = NULL; 
	
	
	int var; 
	int tecla;
	int valor;
	int posicion;

    system("cls");
    printf("%s", "Introduce un valor entero: ");
	scanf("\n%d", &var);
	InsertAtBeginlnCLL(&head, var);
	PrintCircularListData(head);
	
    printf("%s", "Introduce un valor entero: ");
	scanf("\n%d", &var);
	InsertAtEndlnCLL(&head, var);
	 PrintCircularListData(head);
			
    //DeleteFrontNodeFromCLL(&head); 
	PrintCircularListData(head);
				    
	
	return 0;
}

int CircularListLength(struct CLLNode *head){
	
	struct CLLNode *current = head;
	int count = 0;
	
	if(head == NULL){
		
		return 0;
	}
	
	do{
		current = current->next;
		count++;
		
	}while(current != head);
	
	return count;
}


void PrintCircularListData(struct CLLNode *head){
	
	struct CLLNode *current = head;
	
	if(head == NULL)
	return;
	
	do{
		
		printf(" %d ", current->data);
		current = current -> next;
		
	}while(current != head);
	
}

void InsertAtEndlnCLL(struct CLLNode **head, int data){
	
	struct CLLNode *current = *head;
	struct CLLNode *newNode = (struct CLLNode*)(malloc(sizeof(struct CLLNode)));
	
	if(!newNode){
		
		printf("Memory Error");
		return;
	}
	
	newNode->data = data;
	while(current->next != *head)
		current = current->next;
		
	newNode->next = newNode;
	
	if(*head == NULL){
		
		*head = newNode;
		
	}else{
		
		newNode->next = *head;
		current->next = newNode;
	}
}

void InsertAtBeginlnCLL(struct CLLNode **head, int data){
	
	struct CLLNode *current = *head;
	struct CLLNode *newNode = (struct CLLNode*)(malloc(sizeof(struct CLLNode)));
	
	
	if(!newNode){
		
		printf("Memory error");
		return;
	}
	
	newNode->data = data;
	newNode->next = newNode;
	
	if(*head == NULL){
		
		*head = newNode;
	
	}else{
		
		while(current->next != *head){
			
			current = current->next;
			
		}
		
		newNode->next = *head;
		current->next = newNode;
		*head = newNode;
	}

	return;
}


void DeleteLastNodeFromCLL(struct CLLNode **head){
	
	struct CLLNode *temp = *head, *current = *head;
	
	if(*head == NULL){
		
		printf("List Empty");
		return;
	}
	
	while(current -> next != *head){
		
		temp = current;
		current = current->next;
	}
	
	temp->next = current->next;
	free(current);
	return;
	
}

void DeleteFrontNodeFromCLL(struct CLLNode **head){
	
	struct CLLNode *temp = *head;
	struct CLLNode *current = *head;
	
	if(*head == NULL){
		
		printf("List empty");
		return;
		
	}
	
	while(current->next != *head){
		
		current = current->next;
	}
	
	current->next = (*head)->next;
	*head = (*head)->next;
	free(temp);
	return;
	
}