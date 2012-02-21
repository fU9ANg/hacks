/*	
 *	List-table of datastructure
 *	H. F. G. fU9ANg (bb.newlife@gmail.com)
 *	Copyleft(c)2010 HackerFellowShip. All lefts reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>


/*
 * 	define a struct for list
 */
typedef struct child {
	int data;		/* data for list */
	struct child *next;	/* next 	 */
} child;


/*
 * 	prototypes.
 */
child *create(void);
child *find  (child *head,  int);
int    count (child *head);
void   print (child *head);
void   delete(child **head, int position);
void   insert(child **head, int position, int value);


/*
 *	implementation function for operating list
 */
child *
create(void) {
	
	child *node = NULL;
	int    data;

	while(1) {
		fprintf(stdout, "\nPlease input value for data field: ");
		scanf("%d", &data);
		if(data <= 0) 
			continue;
		node = (child *)malloc(sizeof(child));
		if(!node) 
			goto memerr;
		node->data = data;
		node->next = NULL;
		return(node);
	}
	
memerr:
		fprintf(stderr, "error: out of memory.\n");
		return(NULL);
}

child *
find(head, value)
	child *head;
	int   value; {
	
	child *node = head;
	for(; node; node=node->next)
		if(node->data == value)
			return(node);
	return(NULL);
}

int
count(head)
	child *head; {
		
	int cnt = 0;

	for(; head; head = head->next, cnt++)
		;
	return(cnt);
}

void
print(head)
	child *head; {

	if(!head)
		goto emperr;
	for(; head; head = head->next) fprintf(stdout, "%d ", head->data); 
	fprintf(stdout, "\n");
	return;

emperr:
	fprintf(stderr, "error: list is empty.\n");
}

void
delete(head, position)
	child **head;
	int   position; {
	
	child *node = *head;
	child *temp = *head;
	int    ip   = 1;

	if(!(*head)) return;			/* list empty, so return. */
	if(position == 1) {			/* delete header data of list */
		(*head) = (*head)->next;
		if(node) free(node);
		return;
	} else if((position > count(*head)) || (position < 1)) {
		fprintf(stderr, "no found position.\n");
		return;
	} else {
		while(temp) {
			if((ip+1) == position) {
				node = temp->next;
				temp->next = node->next;
				if(node) free(node);
				return;
			}
			ip++;
			temp = temp->next;
		}
	}
}

void
insert(head, position, value)
	child **head;
	int   position;
	int   value; {
	
	child *node = NULL;
	child *temp = *head;
	int   ip    = 1;
	
	if(!(*head)) {					/* list is empty, so create */
		node = (child *)malloc(sizeof(child));
		if(!node)
			goto memerr;
		node->data = value;
		node->next = NULL;
		(*head)    = node;
		return;
	}
	if(position == 1) {
		node = (child *)malloc(sizeof(child));
		if(!node)
			goto memerr;
		node->data = value;
		node->next = *head;
		*head      = node;
		return;
	} else if (position > count(*head)) {
		node = (child *)malloc(sizeof(child));
		if(!node)
			goto memerr;
		while(temp->next) temp = temp->next;
		temp->next = node;
		node->next = NULL;
		node->data = value;
		return;
	} else {
		while(temp) {
			if((ip+1) == position) {
				node = (child *)malloc(sizeof(child));
				if(!node)
					goto memerr;
				node->next = temp->next;
				node->data = value;
				temp->next = node;
				return;
			}
			ip++;
			temp = temp->next;
		}
	}
				
memerr:
        fprintf(stderr, "error: out of memory.\n");
        return;
}


/* we got running */
void
print_hlp(void) {

	fprintf(stdout, "\n\t\t\t\tPlease input a key, you want.\n");
        fprintf(stdout, "\t\t\t\t-----------------------------\n\n");
        fprintf(stdout, "\t\t\t\tc = create list,  i = insert into list\n");
        fprintf(stdout, "\t\t\t\tn = count  list,  d = delete from list\n");
        fprintf(stdout, "\t\t\t\tp = print  list,  h = help\n");
	fprintf(stdout, "\t\t\t\tf = find   iist,  q = quit\n\n");
}

int
main() {

	child *chld = NULL;
	child *node = NULL;
	char   ch;
	int    data;
	int    position;
	
	print_hlp();
	while(1) {
		printf("\ninput: ");
		scanf("%c", &ch);
		switch(ch) {
		case 'c':
		case 'C':
			if(!chld)
				chld = create();
			break;
		case 'i':
		case 'I':
			fprintf(stdout, "input data value is ? and into position ? ");
			scanf("%d, %d", &data, &position);
			if((data > 0) && (position > 0))
				insert(&chld, data, position);
			else
				fprintf(stderr, "error: input data and position\n");
			break;
		case 'd':
		case 'D':
			fprintf(stdout, "input position ? for delete data of list: ");
			scanf("%d", &position);
			if(position > 0)
				delete(&chld, position);
			else
				fprintf(stderr, "error: input position.\n");
			break;
		case 'f':
		case 'F':
			fprintf(stdout, "input data value is? for find function of list: ");
			scanf("%d", &data);
			node = find(chld, data);
			if(node)
				fprintf(stdout, "find %d in list, answer: YES\n", data);
			else
				fprintf(stderr, "error: find function.\n");
			break;
		case 'n':
		case 'N':
			printf("count of list is: %d\n", count(chld));
			break;
		case 'p':
		case 'P':
			print(chld);
			break;
		case 'h':
		case 'H':
			print_hlp();
			break;
		case 'q':
		case 'Q':
			goto quit;
		}
	}

quit:
	if(chld)
    {
        printf("free %d\n", chld->data);
        free(chld);
        printf("free %d\n", chld->data);
    }
	return(0);
}
