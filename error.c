#include "global.h"

void error(char *msg)
{
    fprintf(stderr, "line %d: %s\n", lineno, msg);
    exit(1);
}
