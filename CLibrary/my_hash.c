
#include "libmy.h"

void freeHashmap(HashMap **m) {
    if (*m) {
        free((*m)->entries);
        free(*m);
    }
}

HashMap *createHashmap(const int initialCapacity, const float maximumLoad, const int(*valueUpdater)(int oldKey, int newKey)) {
    HashMap *m = malloc(sizeof(HashMap));
    m->capacity = initialCapacity;
    m->valueUpdater = valueUpdater;
    m->size = 0;
    m->maximumLoad = maximumLoad;
    m->entries = calloc(initialCapacity, sizeof(Entry));

    return m;
}

int hash(int key, int capacity) {
    return (key % capacity + capacity) % capacity;
}

void resizeHashMap(HashMap *m) {
    int oldCapacity = m->capacity;
    Entry *oldEntries = m->entries;

    m->capacity *= 2;
    m->size = 0;
    m->entries = (Entry*)calloc(m->capacity, sizeof(Entry));

    for (int i = 0; i < oldCapacity; i++) {
        if (oldEntries[i].isOccupied) {
            int index = hash(oldEntries[i].key, m->capacity);

            while (m->entries[index].isOccupied)
                index = (index + 1) % m->capacity;

            m->entries[index] = oldEntries[i];
            m->size++;
        }
    }
    free(oldEntries);
}

void insertHashmap(HashMap *m, int key, int value) {
    if ((float)(m->size + 1) / m->capacity > m->maximumLoad) {
        resizeHashMap(m);
    }

    int index = hash(key, m->capacity);
    while (m->entries[index].isOccupied) {
        if (m->entries[index].key == key) {
            m->entries[index].value = m->valueUpdater(m->entries[index].value, value);
            return;
        }
        index = (index + 1) % m->capacity;
    }

    m->entries[index].key = key;
    m->entries[index].value = value;
    m->entries[index].isOccupied = 1;
    m->size++;
}

int getHashmap(HashMap* map, int key) {
    int index = hash(key, map->capacity);

    while (map->entries[index].isOccupied) {
        if (map->entries[index].key == key) {
            return map->entries[index].value;
        }
        index = (index + 1) % map->capacity;
    }
    return -1;
}

void removeKey(HashMap* map, int key) {
    int index = hash(key, map->capacity);

    while (map->entries[index].isOccupied) {
        if (map->entries[index].key == key) {
            map->entries[index].isOccupied = 0;
            map->size--;
            return;
        }
        index = (index + 1) % map->capacity;
    }
}