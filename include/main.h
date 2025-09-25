#ifndef MAIN_H   // include guard start
#define MAIN_H

#include <stdbool.h>

// A constant
#define APP_NAME "MetaForge"

/**
 * The structure who stock all the informations send by the user
 * */
typedef struct Parameters{
    char *filePath;
    char *outPutPath;
    char *currentPath;
    char **parameters;
}Parameters;

/**
 * Put the parameters send by the user in the
*/
void sortParam(int *argc, char *argv[], Parameters *p);

bool isParameters(char *arg);

#endif // MAIN_H
