tyedef struct Node {
		int val;
		Node *leftprev, *rightnext;
} Node;

Node* tree_to_doublyll(Node* root) {
		Stack s;
		Node *curr = root, *head = NULL, *tail = NULL;

		// push all left
		while(curr) {
				push(s, curr);
				curr = curr->leftprev;
		}

		while(!isEmpty(s)) {
				curr = pop(s);
				if (head == NULL) {
						curr->leftprev = NULL;
						head = tail = curr;
				} else {
						tail->rightnext = curr;
						curr->leftprev = tail;
						tail = curr;
				}

				curr = curr->rightnext;
				while(curr) {
						push(s, curr);
				}				
		}

		// if circular linked list
		tail->rightnext = head;
		head->leftprev = tail;

		return head;
}

// -----------------------------------------------------------------------------

//Better

// This is a modified in-order traversal adapted to this problem.
// prev (init to NULL) is used to keep track of previously traversed node.
// head pointer is updated with the list's head as recursion ends.
void treeToDoublyList(Node *p, Node *& prev, Node *& head) {
  if (!p) return;
  treeToDoublyList(p->left, prev, head);
  // current node's left points to previous node
  p->left = prev;
  if (prev)
    prev->right = p;  // previous node's right points to current node
  else
    head = p; // current node (smallest element) is head of
              // the list if previous node is not available
  // as soon as the recursion ends, the head's left pointer 
  // points to the last node, and the last node's right pointer
  // points to the head pointer.
  Node *right = p->right;
  head->left = p;
  p->right = head;
  // updates previous node
  prev = p;
  treeToDoublyList(right, prev, head);
}
 
// Given an ordered binary tree, returns a sorted circular
// doubly-linked list. The conversion is done in-place.
Node* treeToDoublyList(Node *root) {
  Node *prev = NULL;
  Node *head = NULL;
  treeToDoublyList(root, prev, head);
  return head;
}


// -----------------------------------------------------------------------------


typedef struct node {
		int data;
		node *left, *right, *next, *prev;
} node;


node * convertBSTToDoublyLinkedList (node *root, node *succ) {
		if (root == NULL)
				return NULL;
		node * r = root->right;
		if (r == NULL) {
				root->next = succ;
				if (succ != NULL)
						succ->prev = root;
		}
		else {
				while(r->left != NULL)
						r = r->left;
				root->next = r;
				r->prev = root;
		}
		convertBSTToDoublyLinkedList(root->left, root);
		convertBSTToDoublyLinkedList(root->right, NULL);
		return root;
}

void main () {
		node *root;
		root = create(root);
		root = convertBSTToDoublyLinkedList(root, NULL);
}
