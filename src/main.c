#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * */
int main(int argc, char *argv[]){
    // Initialise the Struct
    Parameters p;

    p.parameters = malloc(sizeof(char*) * argc);


    // Decomposing the user selection by sort the parameters for determinate what does the user want tot do
    sortParam(&argc, argv, &p);

    printf("Output file : %s \n", p.outPutPath);
    printf("Path of the Select File : %s \n", p.filePath);
    printf("Param Select : %s \n", p.parameters[0]);

    free(p.parameters);
    return 0;
}

/**
 * Getting the parameters, stock them for interpretation
 * */
void sortParam(int *argc, char *argv[], Parameters *p){
    // Count of parameters added in the struct
    int pcount = 0;

    for(int i=0; i < *argc; i++){
        //
        if (isParameters(argv[i])){

            p->parameters[pcount] = argv[i];

        }else if (strcmp(argv[i], "-o") == 0) {
            p->outPutPath = argv[++i];

        }else{

            p->filePath = argv[i];
        }
    }
}

/**
 * @brief Does a \c char is a valid parameter
 *
 * Determine if the parameters entered by the user is correct
 *
 * @param *arg A potential parameters
 *
 * @return boolean, 1 if param is a Parameters, and 0 if he's not
 * */
bool isParameters(char *arg){
    // -s : Show the result
    // -sd : Show details
    // -m : Metadata
    char *validParameters[] = {"-s", "-sd", "-m"}; // Table of all valids parameters
    int validPcount = sizeof(validParameters) / sizeof(validParameters[0]); // Number of valids parameters

    for(int j=0; j < validPcount; j++){
        if (strcmp(arg, validParameters[j]) == 0){
            return true;
        }
    }
    return false;
}
