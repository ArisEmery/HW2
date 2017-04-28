#include "Comparer.h"

// Note that the two parameters give you an array of program arguments and the count of things in that array.

int main(int argc, char* argv[])
{
    // Declare (and create) a comparer object
    Comparer comparer;

    // Have the comparer load all the input files and then do the comparison,
    // which creates the output file
    if (comparer.load(argc, argv)==0)
        comparer.compare();
}