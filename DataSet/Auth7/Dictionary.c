/*
 * You are writing a basic spell checker component.
 *
 * When your component is being initialized, it is given a list of words
 * that should make up the dictionary.  Your task is to implement two functions:
 * 1. setup()    -- given a list of words (the dictionary), preprocess and save them
 * 2. isMember() -- given a word to check, returns True if the word exists in
 *                  the dictionary
 */

/*
'mat', 'map', 'mats'

'0'
 |
'm'
 |
'a'
 |    \
't'(1) 'p'(1)
 |
's'(1)
*/

typedef struct node {
    //char c;
    node *n[26];
    int isLast;
} node;

node *root = NULL;

void add(char * word) {
    int i;
    node *curr = root;
    for(i=0 ; i<strlen(word) ; i++) {
        if(curr->n[word[i]-'a'] == NULL) {
            curr->n[word[i]-'a'] = getNode(word[i]);            
        }
        curr = curr->n[word[i]-'a'];
    }
    curr->isLast = 1;
}

void setup(char* words[MAX], int n) {
    int i, j;
    root = getNode('0');
    
    for(i=0; i<n ; i++) {
        add(words[i]);        
    }
}


int isMember(char *word) {
    int i;
    node* curr = root;
    for (i=0 ; i<strlen(word); i++) {
        if(curr->n[word[i]-'a'] == NULL) {
            return 0;
        }
        curr = curr->n[word[i]-'a'];
    }
    
    if (curr->isLast)
        return 1;
    return 0;
}
