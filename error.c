#include "global.h"

   void error(m)
        char *m;
    {
        fprintf(stderr, "line %d: %s\n", lineno, m);
        exit(1);
    }
