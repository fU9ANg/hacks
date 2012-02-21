#include <stdio.h>

struct treenode {
    char   data;
    struct treenode *firstchild;
    struct treenode *nextbro;
};

struct treenode *
create(void)
{
    char          data;
    int           m, n;
    struct treenode *p;

    fprintf(stdout, "input data for nodeoftree: \n");
    fprintf(stdout, "m=");
    scanf("%d,", &m);
    fprintf(stdout, "data=");
    scanf("%c,", &data);
    fprintf(stdout, "n=");
    scanf("%d,", &n);
    if(data == 0)
        p = NULL;
    else {
        p = (struct treenode *)malloc(sizeof(struct treenode));
        p->data = data;
        p->firstchild = NULL;
        p->nextbro    = NULL;
    }
    
    if(m != 0)
        p->firstchild = create();
    if(n != 0)
        p->nextbro    = create();

    return(p);
}

print(tree, n)
struct treenode *tree;
int n;
{
    if(tree)
    {
        print(tree->firstchild, n+1);
        printf("%d\t%c\n", n, tree->data);
        print(tree->nextbro, n+1);
    }
}

print2(tree, n)
struct treenode *tree;
int     n;
{
    for(; tree && (!n); tree=tree->firstchild, n--);
    while(tree) {
        printf("%c, ", tree->data);
        tree = tree->nextbro;
    }
}

main()
{
    struct treenode *tree;
    
    tree=create();
    printf("print:\n");
    print(tree, 0);

    if(tree) free(tree);
}
