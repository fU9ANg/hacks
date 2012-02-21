/*
 *      D-list-table of datastructure
 *      H. F. G. fU9ANg (bb.newlife@gmail.com)
 *      Copyleft(c)2010 HackerFellowShip. All lefts reserved.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 	struct process
 */
typedef struct process {
	int		data;
	struct process	*pre;
	struct process  *next;
} process;


/*
 * 	prototypes
 */
int  insert(process **, int, int);
int  delete(process **, int);
void dprint(process *);


/*	implementation     */
void
dprint(head) process *head; { for(; head; head=head->next) printf("%d ", head->data); printf("\n"); }

int
insert(head, position, value)
	process **head;
	int     position;
	int     value; {

	process *node = NULL;
	process *temp = (*head);
	int	ip = 1;

	if(!temp) {			/* create */
		node = (process *)malloc(sizeof(process));
		if(!node)
			goto memerr;
		node->data = value;
		node->pre  = NULL;
		node->next = NULL;
		(*head)    = node;
		return(0);
	} else {			/* insert */
		node = (process *)malloc(sizeof(process));
		if(!node)
			goto memerr;
		if(position == 1) {				 /* insert into header of d-list */
			node->data = value;
			node->next = temp;
			node->pre  = NULL;
			temp->pre  = node;
			(*head)    = node;
			return(0);
		} else {
			for(; temp; temp=temp->next, ip++) {
				if(position == ip) {		 /* insert into mid of d-list */
					node->data = value;
					node->next = temp;
					node->pre  = temp->pre;
					node->pre->next = node;
					temp->pre  = node;
					return(0);
				}
				if(!(temp->next))
					goto instail;
			}
			return(1);				 /* error: result(1) */
		}
	}

instail:							 /* insert into tail of d-list */
	if((ip + 1) == position) {
		node->data = value;
		node->next = NULL;
		node->pre  = temp;
		temp->next = node;
		return(0);
	}
	return(1);

memerr:
	fprintf(stderr, "error: out of memory.\n");
	return(1);
}

int
delete(head, position)
	process **head;
	int	position; {

	process *temp = *head;
	process *node = *head;
	int	ip    = 1;

	if(!temp) return(1);
	for(; temp; temp=temp->next, ip++) {
		if((position == ip)) {
			node = temp;

			if(!(temp->pre)) {
				temp->next->pre = NULL;
				(*head) = temp->next;
			} else if(!temp->next) 
				temp->pre->next = NULL;
			else {
				temp->next->pre = node->pre;
				temp->pre->next = node->next;
			}
			if(node) free(node);
			return(0);
		}
	}
	return(1);
}

/* we got running */
main() {
	
	process *p = NULL;

	insert(&p, 10, 90);
	insert(&p, 1, 70);
	insert(&p, 2, 80);
	insert(&p, 1, 60);
	insert(&p, 3, 75);
	insert(&p, 6, 900);
	delete(&p, 2);
	delete(&p, 3);
	delete(&p, 4);
	delete(&p, 3);
	dprint(p);
}
