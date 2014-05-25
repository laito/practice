#include "sll.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


node *head;

node *SLL_init() {
	node *TEMP = malloc(sizeof(node));
	TEMP->id = 1;
	head = TEMP;
	SLL_setFunctions(TEMP);
	return TEMP;
}

int SLL_append(node **self, char *input) {
	char *data = malloc(strlen(input));
	strcpy(data, input);
	(*self)->data = data;
	node *TEMP = malloc(sizeof(node));
	TEMP->id = (*self)->id + 1;
	TEMP->data = NULL;
	TEMP->next = NULL;
	(*self)->next = TEMP;
	(*self) = (*self)->next;
	SLL_setFunctions(TEMP);
	return 0;
}

int SLL_print(node *self) {
	printf("%s\n", self->data);
}

int SLL_printAll(node *head2) {
	node *temp = head;
	while(temp->data != NULL) {
		printf("%d -> %s\n",temp->id, temp->data);
		temp = temp->next;
	}
}

int SLL_delete(node **self, int id) {
	node *temp = head;
	node *prev = head;
	node *toBeFreed = head;
	int freeSomething = 1;
	int foundSomething = 0;
	while(temp->data != NULL) {
		if(temp->id == id) {
			foundSomething  = 1;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if(!foundSomething) {
		return 0;
	}
	if(prev == temp) {
		/* Root node is getting deleted */
		if(head->next->data != NULL) {
			toBeFreed = head;
			head = head->next;
		} else {
			head->id = id+1;
			head->data = NULL;
			freeSomething = 0;
		}
	} else {
		toBeFreed = temp;
		prev->next = temp->next;
	}
	if ((*self)->id == id) {
		self = &prev;	
	}
	if(freeSomething) {
		SLL_freeNode(toBeFreed);
	}	
}

int SLL_deleteAll(node **self, char *string) {
	node *temp = head;
	while(temp->data != NULL) {
		if(strcmp(temp->data,string) == 0) {
			SLL_delete(self, temp->id);
		}
		temp = temp->next;
	}
}

void SLL_freeNode(node *toFree) {
	free(toFree->data);
	free(toFree);	
}

void SLL_setFunctions(node *sll) {
	sll->append = SLL_append;
	sll->print = SLL_print;
	sll->printAll = SLL_printAll;
	sll->deleteAll = SLL_deleteAll;
	sll->delete = SLL_delete;
}


