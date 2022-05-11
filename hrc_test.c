#include "hrc.h"
#include <stdio.h>

int main(int argc, char ** argv) {

    suffix_basic * suffix_struct = init_suffix_basic(100);
    
    fprintf(stdout, "Testing the suffix structure with the following series: \n");
    for (uint64_t i = 0; i < 100; i++) {
        uint64_t block_request = rand()%25;
        if (i%10 == 0) { printf("\n"); }
        fprintf(stdout, "%ld, ", block_request);
        update_suffix_basic(suffix_struct, block_request, i+1);
    }
    fprintf(stdout, "\n");
    for (uint64_t i=100; i > 0; i -= 10) {
        fprintf(stdout, "Unique requests since time %ld: %ld\n", i-10, unique_accesses_basic(suffix_struct, i-9));
    }

    return 0;
}