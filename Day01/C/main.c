#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libmy.h"

int counter(int a, int b) {
    return a + b;
}

int main(int ac, char **av) {
    char *filename = av[1];
    FILE *file = fopen(av[1], "r");
    
    char *line = NULL;
    size_t len = 0;
    size_t nread;
    size_t nbLine = 0;
    while ((nread = getline(&line, &len, file)) != -1) {
        nbLine++;
    }
    rewind(file);

    int *leftCol = malloc(sizeof(int) * nbLine);
    int *rightCol = malloc(sizeof(int) * nbLine);
    size_t cLine = 0;
    int leftMaxValue = 0;
    int rightMaxValue = 0;

    HashMap *m = createHashmap(nbLine, 0.80, counter);
    
    while ((nread = getline(&line, &len, file)) != -1) {
        leftCol[cLine] = atoi(line);
        int nextIndex = 2;
        if (leftCol[cLine] != 1) {
            nextIndex += (int)ceil(log10(leftCol[cLine]));
        } else {
            nextIndex++;
        }
        rightCol[cLine] = atoi(line + nextIndex);

        insertHashmap(m, rightCol[cLine], 1);

        leftMaxValue = MAX(leftMaxValue, leftCol[cLine]);
        rightMaxValue = MAX(rightMaxValue, rightCol[cLine]);
        cLine++;
    }

    radix(leftCol, nbLine, leftMaxValue);
    radix(rightCol, nbLine, rightMaxValue);

    size_t totalDistanceSum = 0;
    for (int i = 0; i < nbLine; i++) {
        totalDistanceSum += abs(leftCol[i] - rightCol[i]);
    }
    printf("Total distance summed: %ld\n", totalDistanceSum);

    size_t similarityScore = 0;
    for (int i = 0; i < nbLine; i++) {
        int count = getHashmap(m, leftCol[i]);
        if (count != -1) {
            similarityScore += leftCol[i] * count;
        }
    }

    printf("Similarity: %ld\n", similarityScore);

    free(leftCol);
    free(rightCol);
}