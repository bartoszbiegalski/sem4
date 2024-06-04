/* PRINT TRANSPOSED BST */


#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *left;
  struct node * right;
  int element;
};

struct node*  root=NULL;

void insert( struct node** root, struct node* node_ptr ){
  if( node_ptr==NULL) return;
  if( *root == NULL ) {
    *root= node_ptr;
  } else if( node_ptr->element < (*root)->element ) {
    insert( &(*root)->left, node_ptr);
  } else {
    insert( &(*root)->right, node_ptr);
  }
}


void free_subtree(struct node** root){
  if( *root == NULL ) return;
  if( (*root)->left != NULL ){
    free_subtree( &(*root)->left );
  }
  if( (*root)->right != NULL ){
    free_subtree( &(*root)->right );
  }
  free(*root);
  *root=NULL;  
}

// global variables used in `print_BST`
char* left_trace; // needs to be allocaded with size
char* right_trace; // needs to be allocaded with size


void print_BST( struct node * root, int depth,char prefix){
  if( root == NULL ) return;
  if( root->left != NULL ){
    print_BST(root->left, depth+1, '/');
  }
  if(prefix == '/') left_trace[depth-1]='|';
  if(prefix == '\\') right_trace[depth-1]=' ';
  if( depth==0) printf("-");
  if( depth>0) printf(" ");
  for(int i=0; i<depth-1; i++)
    if( left_trace[i]== '|' || right_trace[i]=='|' ) {
      printf("| ");
    } else {
      printf("  ");
    }
  if( depth>0 ) printf("%c-", prefix);
  printf("[%d]\n", root->element);
  left_trace[depth]=' ';
  if( root->right != NULL ){
    right_trace[depth]='|';
    print_BST(root->right, depth+1, '\\');
  }
}

int main(){
  int seed;
  printf("input seed: ");
  scanf("%d", &seed);
  printf("seed = %d\n", seed);
  srandom( seed );

  int size=10;
  printf("input size: ");
  scanf("%d", &size);
  printf("size = %d\n", size);

  // init traces
  left_trace= malloc( size*sizeof(char) );
  right_trace= malloc( size*sizeof(char) );
  for(int i=0; i<=size; i++){
    left_trace[i]=' ';
    left_trace[i]=' ';
  }
  
  printf("\n");
  
  for(int i=0; i<size; i++){
    struct node * node_ptr = malloc( sizeof(struct node));
    node_ptr->element = random()%1000;
    node_ptr->left=NULL;
    node_ptr->right=NULL;
    printf("INSERT: [%d]\n\n", node_ptr->element);
    insert(&root, node_ptr );
    printf("TREE:\n");
    print_BST(root, 0, '-');
    printf("\n\n");
  }

  free(left_trace);
  free(right_trace);
  free_subtree(&root);
}
