#include "global.h"

void main() {
    init();
    parse();
    freeSymbolTable();

    exit(0); // Successful termination
}
