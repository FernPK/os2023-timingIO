#include <stdio.h>
#include <time.h>

clock_t start, end;

void readInputFromFile(char filename[]){
    char str[100000];
    start = clock();
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File not found!\n");
        return;
    }
    fgets(str, 100000, fp);
    end = clock();
    fclose(fp);
    printf("Time taken to read from file: %f s\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

void printOutput(){
    start = clock();
    for(int i = 0; i < 100000; i++){
        printf("");
    }
    end = clock();
    printf("Time taken to print to console: %f s\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

void notPrintOutput(){
    start = clock();
    for(int i = 0; i < 100000; i++){
        ;
    }
    end = clock();
    printf("Time taken if didn't print to console: %f s\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

int main(){
    readInputFromFile("sampleInput.txt");
    printOutput();
    notPrintOutput();
    return 0;
}