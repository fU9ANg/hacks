/*
 *	Que of datastructure
 *   	H. F. G. fU9ANg (bb.newlife@gmail.com)
 * 	Copyleft(c)2010 HackerFellowShip. All lefts reserved.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 	def struct type for Que
 */
typedef struct que {
	int 		data;
	struct que	*next;
} que;


/*
 * 	prototypes
 */
int top    (que * head);
int pop    (que **head);
int push   (que **head, int value);
int isempty(que * head);


/*	implementation	    */
int top    (head) que *head; { return(head ? head->data : -1); }
int isempty(head) que *head; { return(head ? 0          :  1); }

int
pop(head)
	que **head; {
	
	que *node = NULL;
	if((*head)) {
		node    = (*head);
		(*head) = node->next;
		free(node);
		return(0);
	}
}

int
push(head, value)
	que **head; 
	int   value; {
	
	que *node = NULL;
	que *temp = (*head);
	if(temp) {  /* OR    if(temp == (char *)0) {    */
		for(; temp->next; temp=temp->next) ;
		node = (que *)malloc(sizeof(que));
		if(!node)
			goto memerr;
		node->data = value;
		node->next = NULL;
		temp->next = node;
		return(0);
	} else {
		node = (que *)malloc(sizeof(que));
		if(!node)
			goto memerr;
		node->data = value;
		node->next = NULL;
		(*head)    = node;
		return(0);
	}

memerr:
	fprintf(stderr, "error: out of memory.\n");
	return(1);
}


/* we got running */
main() {

	que *Q = NULL;

	push(&Q, 10);
	push(&Q, 11);
	push(&Q, 12);
	push(&Q, 13);
	push(&Q, 14);
	push(&Q, 15);
	
	while(!isempty(Q)) {
		printf("%d\n", top(Q));
		pop(&Q);
	}
}
