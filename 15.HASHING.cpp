#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
struct HashEntry {
    int key;
    int value;
};
struct HashEntry* createHashEntry(int key, int value) {
    struct HashEntry* newEntry = (struct HashEntry*)malloc(sizeof(struct HashEntry));
    newEntry->key = key;
    newEntry->value = value;
    return newEntry;
}
int hashFunction(int key) {
    return key % SIZE;
}
void insertLinearProbing(struct HashEntry* hashTable[], int key, int value) {
    int index = hashFunction(key);
    
    while (hashTable[index] != NULL) {
        index = (index + 1) % SIZE; 
    }
    
    hashTable[index] = createHashEntry(key, value);
}
int searchLinearProbing(struct HashEntry* hashTable[], int key) {
    int index = hashFunction(key);
    
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }
        index = (index + 1) % SIZE; 
    }
    
    return -1; 
}

int main() {
    struct HashEntry* hashTable[SIZE] = { NULL };
    
    insertLinearProbing(hashTable, 10, 42);
    insertLinearProbing(hashTable, 20, 18);
    insertLinearProbing(hashTable, 30, 99);
    insertLinearProbing(hashTable, 10, 55); 

    printf("Value for key 20: %d\n", searchLinearProbing(hashTable, 20));
    printf("Value for key 10: %d\n", searchLinearProbing(hashTable, 10));

    return 0;
}

