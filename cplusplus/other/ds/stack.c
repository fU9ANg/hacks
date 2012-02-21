/* only for test */

#include <stdio.h>
#include <stdlib.h>

/*
 * data struct
 */
typedef struct data_s {
    char   ch;            /* character */
    int    li;            /* line number */
    int    co;            /* column number */
} data_t;

/*
 * 	struct type for stack
 */
typedef struct stack_s {
    data_t data;
	struct stack_s *next; /* pointer to next node */
} stack_t;


/*
 * 	prototypes
 */
int    push  (stack_t **head, data_t* data);
int    pop   (stack_t **head);
data_t*top   (stack_t  *head);
int   isempty(stack_t  *head);


/*
 *         push          |
 *      +---------       |
 * |    |    |           |    |         |
 * |    v    |           |    | Element | <-head
 * | Element | <-head   -->   | Element |
 * | Element |           |    | Element |
 * |_________|           |    |_________|
 *    Stack                      Stack
 */
int
push (stack_t **head, data_t* data)
{
	stack_t *node=NULL;
	if((node=(stack_t *)calloc (sizeof(stack_t), 1))==NULL)
		goto memerr;

	node->data.ch=data->ch;
    node->data.li=data->li;
    node->data.co=data->co;
	node->next=(*head);
	(*head)   = node;

	return (0);

memerr:
	fprintf (stderr, "[error]: out of memory.\n");     
    return (1);
}

/*                       
 *          pop          |
 *      +-------->       |
 * |    |    |           |    |         |
 * | Element | <-head   -->   |         |
 * | Element |           |    | Element | <-head
 * | Element |           |    | Element |
 * |_________|           |    |_________|
 *    Stack                      Stack
 */
int
pop (stack_t **head)
{
	stack_t *node=NULL;

	if((*head)) {
		node   =(*head);
		(*head)=node->next;
		free (node);
		return (0);
	}

	return (1);
}

data_t*
top (stack_t *head)
{
    return (head ? &(head->data) : NULL);
}

int
isempty (stack_t *head)
{
    return (head ? 0          :  1  );
}


#ifdef  _TEST_STACK
main() {

	stack_t *head=NULL;
    data_t   data, *pdata=NULL;
    int  li=1, co=1;
    char ch;

    while ((ch=getchar()) != EOF) {
        data.ch=ch;
        data.li=li;
        data.co=co;
	    push (&head, &data);
        if (ch=='\n') li++; co++;
    }

	while (!isempty(head)) {
        pdata=top (head);
		printf("character=%c, line=%d, column=%d\n", \
                pdata->ch, pdata->li, pdata->co);
		pop(&head);
	}
	
}
#endif

#ifdef  _EXERCISE
char getchr (char c)
{
    if (c== ']') return ('[');
    if (c== ')') return ('(');
    if (c== '}') return ('{');
}

main() {
    stack_t *head=NULL;
    data_t   data, *p=NULL;
    int      li=1, co=1;
    char     ch;

    while ((ch=getchar()) != EOF) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                p=top (head);
                if ((p==NULL)||
                    (!((p->ch==0x22)||(p->ch==0x2c)||(p->ch=='*')))) {
                    data.ch=ch;
                    data.li=li;
                    data.co=co;
                    push (&head, &data);
                }
                break;
            case ')':
            case ']':
            case '}':
                p=top (head);
                if (p==NULL) {
                    print_error ();
                }
                else if (!((p->ch==0x22)||(p->ch==0x2c)||(p->ch=='*'))) {
                    if (getchr (ch)==p->ch)
                        pop (&head);
                    else
                        printf_error ();
                }
                break;
            case 0x22:
                p=top (head);
                if (p==NULL) {
                    data.ch=ch;
                    data.li=li;
                    data.co=co;
                    push (&head, &data);
                } else {
                    if (!((p->ch==0x2c)||(p->ch=='*'))) {
                        if (ch==p->ch)
                            pop (&head);
                        else {
                            data.ch=ch;
                            data.li=li;
                            data.co=co;
                            push (&head, &data);
                        }
                    }
                }
                break;
            case 0x2c:
                p=top (head);
                if (p==NULL) {
                    data.ch=ch;
                    data.li=li;
                    data.co=co;
                    push (&head, &data);
                } else {
                    if (!((p->ch==0x22)||(p->ch=='*'))) {
                        if (ch==p->ch)
                            pop (&head);
                        else {
                            data.ch=ch;
                            data.li=li;
                            data.co=co;
                            push (&head, &data);
                        }
                    }
                }
                break;
            case '/':
                p=top (head);
                if (p==NULL) {
                    data.ch=ch;
                    data.li=li;
                    data.co=co;
                    push (&head, &data);
                } else {
                    if (!((p->ch==0x22)||(p->ch==0x2c))) {
                        if (p->ch=='*') {
                            pop (&head);
                            pop (&head);
                            pop (&head);
                        } else {
                            data.ch=ch;
                            data.li=li;
                            data.co=co;
                            push (&head, &data);
                        }
                    }
                }
                break;
            case '*':
                p=top (head);
                if (p==NULL) {
                    data.ch=ch;
                    data.li=li;
                    data.co=co;
                    push (&head, &data);
                } else {
                    if (!((p->ch==0x22)||(p->ch==0x2c))) {
                        if ((p->ch=='/')||(p->ch=='*')) {
                            data.ch=ch;
                            data.li=li;
                            data.co=co;
                            push (&head, &data);
                        }
                    }
                }
                break;
            case '\n':
                li++;
                break;
            default:
                ;
        }
        co++;

    }
}
#endif
