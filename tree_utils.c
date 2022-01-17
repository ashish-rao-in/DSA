/*
 * BST Utilities
 *
 * Insert, Walk (in order), Walk (BFS)
 * Queue - init, push, pop
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Global definitions
 */

/* Tree Node */
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *root;         //root of the binary tree

#define MAX 100     //Max queue depth
int counter;        //current queue depth

node *queue[MAX];   //array of pointers to the tree node 
node **q_head;      //pointer to the head of the queue
node **q_tail;      //pointer to the tail of the queue


/*
 * API definitions
 */
 
 
/* API to initialize the queue */
void
init_q()
{
    counter = 0;
    memset(queue, 0, sizeof(queue));
    q_head = q_tail = queue;
}


/* API to push elements into the queue */
void
queue_push (node *n) 
{
    counter++;
    if(counter == MAX-1) {
        printf("\nQueue Full\n");
        exit(0);
    }
    *q_tail = n;
    (q_tail)++;
}

/* API to pop elements from the queue */
void
queue_pop ()
{
    (*q_head) = '\0';
    (q_head)++;
    
}

/* API to walk the tree - BFS (level order traversal) */
void
bfs(node *root) 
{
    if(root == NULL) {
        return;
    }
    init_q();
    queue_push(root);
    
    while (q_head != q_tail) {                                                   
        printf("%d ",(*q_head)->data);                                           
        if((*q_head)->left) {                                                    
            queue_push((*q_head)->left);
        }                                                                        
        if ((*q_head)->right) {                                                  
            queue_push((*q_head)->right);
        }                                                                        
        queue_pop();                                                             
    }
    
    init_q();
    return;
}


/* API to walk the tree - DFS (Depth first traversal - In Order) */
void
walk (node *root)
{
    if (root == NULL) {
        return;
    }
    
    walk(root->left);
    printf("%d ", root->data);
    walk(root->right);
    return;
    
}

/* API to insert nodes into the tree - BST */
node *
insert (node *root, int val) 
{
    if (root == NULL) {
        node *new_node = calloc(1, sizeof(node));
        new_node->data = val;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    
    if (root->data > val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}


int main()
{
    root = insert (root, 10);
    root = insert (root, 2);
    root = insert (root, 35);
    root = insert (root, 4);
    root = insert (root, 55);
    root = insert (root, 6);
    root = insert (root, 7);
    root = insert (root, 85);

    
    walk(root);
    

    printf("\n");
    bfs(root);
    printf("\n");
    

    return 0;
}