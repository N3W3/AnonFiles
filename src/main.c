#include "main.h"
#include <linux/limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Start function
 *
 *
 *
 * @param argc
 * @parm *argv[]
 * */
int main(int argc, char *argv[]){
    // Initialise the Struct
    Parameters p;

    p.parameters = malloc(sizeof(char*) * argc);


    // Decomposing the user selection by sort the parameters for determinate what does the user want tot do
    sortParam(&argc, argv, &p);

    // Invalid File path
    if(p.filePath==NULL){
        printf("Invalid filePath : %s \n", p.filePath);
        return 1;
    }

    printf("Output file : %s \n", p.outPutPath);
    printf("Path of the Select File : %s \n", p.filePath);
    printf("Param Select : %s \n", p.parameters[0]);
    printf("Current Directory : %s \n", p.currentPath);

    free(p.parameters);
    free(p.currentPath);
    return 0;
}

/**
 * @brief Getting the parameters, stock them in the struct for interpretation
 *
 *
 *
 * @param *argc  Number of elements in the table of argv
 * @param *argv[] Table of elements sent by the user
 * @param *p Struct where elements will by stock & sort
 *
 * */
void sortParam(int *argc, char *argv[], Parameters *p){
    // Count of parameters added in the struct
    int pcount = 0;

    // Initialising the current directory where the tool is executed
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL){
        p->currentPath = strdup(cwd);

        // Initialising the defaults values
        p->parameters[0] = NULL;
        p->outPutPath = ".";

        for(int i=1; i < *argc; i++){
            //
            if (isParameters(argv[i])){

                p->parameters[pcount] = argv[i];

            }else if (strcmp(argv[i], "-o") == 0) {
                p->outPutPath = argv[++i];

            }else{

                p->filePath = argv[i];
            }
        }

    }else{
        printf("Error : Impossible to find the current directory");
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
    // -w : WaterMark
    char *validParameters[] = {"-s", "-sd", "-m", "-w"}; // Table of all valids parameters
    int validPcount = sizeof(validParameters) / sizeof(validParameters[0]); // Number of valids parameters

    for(int j=0; j < validPcount; j++){
        if (strcmp(arg, validParameters[j]) == 0){
            return true;
        }
    }
    return false;
}
