#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"


int main () {
	
	node *SLL = SLL_init();
	SLL->append(&SLL, "fifth");
	SLL->append(&SLL, "first");
	SLL->append(&SLL, "second");
	SLL->append(&SLL, "third");
	SLL->append(&SLL, "fourth");
	SLL->append(&SLL, "fifth");
	SLL->append(&SLL, "fifth");
	SLL->printAll(SLL);
	SLL->delete(&SLL, 2);
	SLL->deleteAll(&SLL, "fifth");
	SLL->printAll(SLL);
	SLL->deleteAll(&SLL, "first");
	SLL->deleteAll(&SLL, "second");
	SLL->deleteAll(&SLL, "second");
	SLL->delete(&SLL, 5);
	printf("Finally\n");
	SLL->printAll(SLL);
	return 0;
}

