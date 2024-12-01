#ifndef MYHASH
    #define MYHASH

    typedef struct Entry_s {
        int key;
        int value;
        int isOccupied;
    } Entry;

    typedef struct HashMap_s {
        struct Entry_s* entries;
        int capacity;
        int size;
        float maximumLoad;
        int (*valueUpdater)(int oldKey, int newKey);
    } HashMap;

    void resizeHashMap(HashMap *m);
    int hash(int key, int capacity);
    void insertHashmap(HashMap *m, int key, int value);
    int getHashmap(HashMap* map, int key);
    void removeKey(HashMap* map, int key);
    HashMap *createHashmap(const int initialCapacity, const float maximumLoad, const int(*valueUpdater)(int oldKey, int newKey));
#endif