#include "hrc.h"
#include <assert.h>

suffix_basic * init_suffix_basic(uint64_t series_length) {
    suffix_basic * X = malloc(sizeof(suffix_basic));
    X->series_length = series_length;
    X->time = 0;
    X->A = calloc(series_length, sizeof(uint64_t));
}

void delete_suffix_basic(suffix_basic * X) {
    free(X->A);
    free(X);
}

void update_suffix_basic(suffix_basic * X, uint64_t block_request, uint64_t time) {
    assert(time == X->time + 1 && time <= X->series_length);
    X->A[time-1] = block_request;
    X->time = time;
}

uint64_t unique_accesses_basic(suffix_basic * X, uint64_t start_time) {
    assert(start_time <= X->time);
    uint64_t unique_requests = 0;
    uint64_t requested_blocks[X->time - start_time];
    for (uint64_t i=0; i < X->time - start_time; i++) {
        requested_blocks[i] = 0; 
    }
    for (uint64_t i=start_time-1; i < X->time; i++) {
        uint64_t j;
        for (j = 0; j < unique_requests; j++) {
            if (X->A[i] == requested_blocks[j]) { break; } 
        }
        if (j == unique_requests) {
            requested_blocks[j] = X->A[i]; 
            unique_requests++; 
        }
    }
    return unique_requests;
}

