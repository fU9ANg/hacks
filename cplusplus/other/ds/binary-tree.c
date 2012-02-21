/*
 *      Tree of datastructure
 *      H. F. G. fU9ANg (bb.newlife@gmail.com)
 *      Copyleft(c)2010 HackerFellowShip. All lefts reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  NSIZE  	20
#define  STRCMP(s1, s2) !strcmp(s1, s2)

/*
 *      def struct type for Tree
 */
typedef struct tree {
	char 		sdata[NSIZE];
	struct tree	*parent;
	struct tree	*left;
	struct tree	*right;
} tree;


/*
 *	prototypes
 */
void lefttraversal (tree *);
void midtraversal  (tree *);
void righttraversal(tree *);


tree *
create(void) {

	tree *node;
	char string[NSIZE];
	fprintf(stdout, "(If value of string is \"NULL\", then program quit.) Input string data: ? ");
	scanf("%s", &string);
	if(STRCMP(string, "NULL"))
		node = NULL;
	else {
		node = (tree *)malloc(sizeof(tree));
		if(!node)
			goto memerr;
		strcpy(node->sdata, string);
		node->parent = NULL;

		node->left   = create();
		if(node->left)
			node->parent = node;

		node->right  = create();
		if(node->right)
			node->parent = node;
	}
	return(node);

memerr:
	fprintf(stderr, "out of memory.\n");
	return(NULL);
}

void
lefttraversal(root)
	tree *root; {

	if(root) {
		lefttraversal(root->left);
		fprintf(stdout, "%s ", root->sdata);
		lefttraversal(root->right);
	}
}

void
midtraversal(root)
	tree *root; {

	if(root) {
		fprintf(stdout, "%s ", root->sdata);
		midtraversal(root->left);
		midtraversal(root->right);
	}
}

void
righttraversal(root)
	tree *root; {
	
	if(root) {
		righttraversal(root->right);
		fprintf(stdout, "%s ", root->sdata);
		righttraversal(root->left);
	}
}
	
/* we got running */
main() {

	tree *root;

	root=create();
	printf("\nmidtraversal   :");
	midtraversal(root);
	printf("\nlefttraversal  :");
	lefttraversal(root);
	printf("\nrighttraversal :");
	righttraversal(root);
	printf("\n");
}
