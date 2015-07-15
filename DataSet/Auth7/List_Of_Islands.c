Given: 2D array of cells indicating land or water piece

land piece if value in (0, 1], representing the gradient %
water piece if value = 0

Want: Sorted list of islands by score, where score(island) = sum(score(island pieces))

0 0.1 0
0 0 0.3

|- (1, 0)-> (1, 1)-> (2,1)
|- ()->....

struct pair {
    int row, col;
}pair;

struct node {
    pair p;
    node* next;
    node* down;
}node; 

struct stack {
    pair p;
    int top;
}

void addToList(float arr[N][M], int i, int j, node* islands) {
    node *p=islands, *temp;
    stack s;
    pair p
    init(s);
    if(islands == NULL) {
        islands = getNode(getPair(i,j));
        p = islands;
    } else {
        while(p->down != NULL) {
            p = p->down;
        }
        temp = getNode(getPair(i,j));
        p->down = temp;
        p = temp;
    }
    push(s,getPair(i,j));
    while(!isEmpty(s)) {
        p = pop(s);
        arr[p.row][p.col] = 0;
        if (isValid(p.row+1) && arr[p.row+1][p.col] > 0) {
            temp = getNode(getPair(p.row+1, p.col));
            p->next = temp;
            p = temp;
            push(getPair(p.row+1,p.col));
        }
        // all 4 dir
    }
    
    return islands;
}

parseMatrix(float arr[N][M], node* islands) {
    int i, j;
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            if(arr[i][j] != 0)
                islands = addToList(arr, i,j,islands);
        }
    }
    return islands;
}
