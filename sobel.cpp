#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

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

unsigned char* convert_to_grayscale(unsigned char* image, int width, int height, int channels) {
    unsigned char* gray = (unsigned char*)malloc(width * height);
    if (gray == NULL) {
        printf("Unable to allocate memory for grayscale image\n");
        exit(1);
    }

    #pragma omp parallel for
    for(int i = 0; i < width * height; i++) {
        gray[i] = 0.299 * image[i * channels] + 
                  0.587 * image[i * channels + 1] + 
                  0.114 * image[i * channels + 2];
    }

    return gray;
}



int main() {

    int width, height, channels;
    unsigned char *image = stbi_load("../image.png", &width, &height, &channels, 0);

    if (image == NULL) {
        printf("Error loading image\n");
        return 1;
    }

    printf("Loaded image with width: %d, height: %d, channels: %d\n", width, height, channels);
    unsigned char* gray_image = convert_to_grayscale(image, width, height, channels);


    
    
    // stbi_write_png("gray_image.png", width, height, 1, gray_image, width);
   
   

   
    free(gray_image);
    stbi_image_free(image);
    return 0;
}
