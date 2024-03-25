#include "global.h"

// void main() {
//     init();
//     parse();
//     freeSymbolTable();

//     exit(0); // Successful termination
// }
int main(int argc, char *argv[])
{ // Modified to take command-line arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input)
    {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (!output)
    {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    parse(input, output);
    freeSymbolTable();

    fclose(input);
    fclose(output);

    return 0;
}