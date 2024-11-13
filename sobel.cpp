#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

const int SOBEL_X[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};

const int SOBEL_Y[3][3] = {
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1}
};


int main() {
    
    int width, height, channels;
    unsigned char *image = stbi_load("../image.png", &width, &height, &channels, 0);

    if (image == NULL) {
        printf("Error loading image\n");
        return 1;
    }

    printf("Loaded image with width: %d, height: %d, channels: %d\n", width, height, channels);

 

    stbi_image_free(image);
    return 0;
}