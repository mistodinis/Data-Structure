#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tries are trees but the are used to stock words , each node has only one letter 

// Transform from characters to integer
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
// Calculate an array size
#define ARRAY_SIZE(v) sizeof(v) / sizeof(v[0])

typedef struct trie{
    // Count represents if a word is ending in this node (1 = yes , 0 = no)
    // nrfii represents how many times a word occurs
    int count , nrfii;
    // 26 children for all 26 letter from 'a' to 'z'
    struct trie* child[26];
}Trie;
// Initialize a trie
Trie *initTrie(){

    Trie* newTrie = (struct trie*) malloc(sizeof(struct trie));

    newTrie->count = 0;
    newTrie->nrfii = 0;

    for(int i = 0;i < 26;i++)
        newTrie->child[i] = NULL;       
    
    return newTrie;
}
// Insert a word into a trie
void insert(Trie *root , const char *key){

    int index;
    // A pointer to root
    Trie *tmp = root;
    // Parse through key's letters
    for(int i = 0;i < strlen(key);i++){
        // Index is the difference between key's letter and "a"
        index = CHAR_TO_INDEX(key[i]);
        // If that node is NULL
        if(!tmp->child[index])
            // Initialize it
            tmp->child[index] = initTrie();
        // Move into the tmp->child[index]
        // Just in this way we can still add next letters until we reach end of "key"
        tmp = tmp->child[index];
    }
    // on last letter we mark that a word is ending on this letter
    tmp->count = 1;
    // Increase number of occurence of this word
    tmp->nrfii++;
}
// Search into a trie
int search(Trie *root , const char *key){

    int index;

    Trie *tmp = root;

    for(int i = 0;i < strlen(key);i++){

        index = CHAR_TO_INDEX(key[i]);
        // If the speficific letter is not in the trie 
        // then return 0 ( not found)
        if(!tmp->child[index])
            return 0;
        // Else move on
        tmp = tmp->child[index];
    }
    // If  tmp is not empty and a word is ending in that node 
    // Then return 1 ( Word Found)
    if(tmp != NULL && tmp->count == 1)
        return 1;
}
// Return 1 if root is empty 0 , otherwise
int isEmpty(Trie *root){

    for(int i = 0;i < 26;i++){
        if(root->child[i])
            return 0;
    }

    return 1;
}
// Delete a word
Trie *delete(Trie *root , const char *key , int depth )
{
    // If root is empty return NULL
    if(!root)
        return NULL;
    // If we reach the lenght of the word with depth
    if(depth == strlen(key)){
        // If a word is ending on this node
        if(root->count)
            // Switch it to no word is ending on this node
            root->count = 0;
        // If root is empty(has no children)
        if(isEmpty(root)){
            // Release root
            free(root);
            root = NULL;
        }
        // Return root
        return root;
    }
    // If the depth still didn't reach length of "key"
    // Index takes value of key[depth] - 'a'
    int index = CHAR_TO_INDEX(key[depth]);
    // Move on to next node(letter) from the word       here we increment depth for next letter
    root->child[index] = delete(root->child[index] , key , depth + 1);
    // If root (has no more children) and no word is ending in this node
    if(isEmpty(root) && root->count == 0){
        // Release root 
        free(root);
        root = NULL;
    }
    // Return root
    return root;

}
// Test every function from above
int main(){

    char keys[][8] = {"the", "a", "there", "answer", "any", 
                     "by", "bye", "their"}; 
  
    char output[][32] = {"Not present in trie", "Present in trie"}; 

    Trie *root = initTrie();

    for(int i = 0;i < ARRAY_SIZE(keys);i++){
        insert(root, keys[i]);
    }

    printf("%s --- %s\n", "the", output[search(root, "the")] ); 
    printf("%s --- %s\n", "these", output[search(root, "these")] ); 
    printf("%s --- %s\n", "their", output[search(root, "their")] ); 
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] ); 
    printf("%s --- %s\n", "by", output[search(root, "by")] ); 

    delete(root , "the" , 0);
    printf("%s --- %s\n", "the", output[search(root, "the")] ); 
    delete(root , "by" , 0);
    printf("%s --- %s\n", "by", output[search(root, "by")] ); 
    
    return 0;
}
