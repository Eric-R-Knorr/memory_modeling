#include <stdlib.h>
#include <stdint.h>

// A basic suffic structure for retrieving the number of unique blocks 
// accessed over any suffix of our request series.
typedef struct {
    uint64_t series_length;
    uint64_t time;    // Stores the time of the last update
    uint32_t * A;     // An array storing the block number accessed at each time stamp
} suffix_basic;

suffix_basic * init_suffix_basic(uint64_t series_length);
void delete_suffix_basic(suffix_basic * X);
void update_suffix_basic(suffix_basic * X, uint64_t block_request, uint64_t time);
uint64_t unique_accesses_basic(suffix_basic * X, uint64_t t);