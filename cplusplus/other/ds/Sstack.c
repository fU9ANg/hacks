/*	
 *	Stack of datastructure
 *	H. F. G. fU9ANg (bb.newlife@gmail.com)
 *	Copyleft(c)2010 HackerFellowShip. All lefts reserved.
 */

#include <stdio.h>
#include <stdlib.h>

#define  NSIZE  10


/*
 * 	struct type for stack
 */
typedef struct stack {
	int    data;
	struct stack *next;
} stack;


/*
 * 	prototypes
 */
stack *create(void);
int    push  (stack **head, int value);
int    pop   (stack **head);
int    top   (stack  *head);
int   isempty(stack  *head);

/*	implementation 	    */
stack *
create(void) {

	stack *node = NULL;
	int    data;
	while(1) {
		fprintf(stdout, "input value of DATA field: ");
		scanf("%d", &data);
		if(data) {
			node = (stack *)malloc(sizeof(stack));
			if(!node)
				goto memerr;
			node->data = data;
			node->next = NULL;
			return(node);
		}
	}
	return(NULL);

memerr:
	fprintf(stderr, "error: out of memory.\n");
	return(NULL);
}

int
push(head, value)
	stack **head;
	int     value; {
	
	stack *node = NULL;
	
	node = (stack *)malloc(sizeof(stack));
	if(!node)
		goto memerr;
	node->data = value;
	node->next = (*head);
	(*head)    = node;
	return(0);

memerr:
	fprintf(stderr, "error: out of memory.\n");     
        return(1);
}

int
pop(head)
	stack **head; {

	stack *node = NULL;

	if((*head)) {
		node    = (*head);
		(*head) = node->next;
		free(node);
		return(0);
	}

	return(1);
}

int top    (head) stack *head; { return(head ? head->data : -1); }
int isempty(head) stack *head; { return(head ? 0          :  1); }


/* we got running */
main() {

	stack *sk;
	sk = create();
	printf("%d\n", top(sk));
	push(&sk, 10);
	printf("%d\n", top(sk));
	push(&sk, 9);
        printf("%d\n", top(sk));

	while(!isempty(sk)) {
		printf("%d\n", top(sk));
		pop(&sk);
	}
	
}
