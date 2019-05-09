//
// Created by Felix Häner on 3.05.2019.
//

#include <iostream>
#include "pqueue.h"
#include <ctime>
using namespace std;

char* randomString(int size){
    int i;
    char* str = (char*) malloc((size+1)*sizeof(char));
    for(i = 0 ; i < size ; ++i) {
        str[i] = (rand() % 26) + 'A';
    }
    str[size] = '\0';
    return str;
}

int main(void){
    int i;
    clock_t tic, toc;
    srand(time(NULL));
    char* strings[60000];

    PriorityQueue * pq = new PriorityQueue;

    for(i = 0 ; i < 60000; ++i) {//MAX
        strings[i] = randomString(8);
    }

    tic = clock();
    for(i = 0 ; i < 60000; ++i) {
        std::string b(strings[i]);
        pq->insert(b, rand() % 100);
    }
    toc = clock();

    printf("insertion time: %.2f\n", (float)(toc-tic) / CLOCKS_PER_SEC);

    tic = clock();
    for(i = 0 ; i < 60000 ; ++i) {
        pq->extractMin();
    }
    toc = clock();
    printf("extract time: %.10f\n", (float)(toc-tic) / CLOCKS_PER_SEC);

    return 0;
}




