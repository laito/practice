#ifndef SLL_H_
#define SLL_H_


typedef struct node {
	int id;
	char *data;
	struct node *next;
	int (*append) (struct node**, char *);
	int (*delete) (struct node**, int);
	int (*deleteAll) (struct node**, char *);
	int (*print) (struct node*);
	int (*printAll) (struct node*);
} node;


node * SLL_init();
int SLL_append(node **, char *);
int SLL_delete(node **, int);
int SLL_deleteAll(node **, char *);
int SLL_search(int);
int SLL_print(node *);
int SLL_printAll(node *);
void SLL_freeNode(node *);
void SLL_setFunctions(node *);
#endif
