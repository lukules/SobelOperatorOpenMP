#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>

const int SOBEL_X[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}}
;



int main(int argc, char** argv){

    printf("Hello from process: %d\n", omp_get_thread_num());

    return 0;
}