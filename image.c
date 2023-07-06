#include <stdio.h>
#include <stdlib.h>
#include "image.h"

#define frand() ((double) rand() / (RAND_MAX+1.0))

void printImageAsPPM(struct ImageHandle img) {
  printf("P3\n");
  printf("%d %d\n", img.width, img.height);
  printf("%d\n", 255); // max color

  struct RGB* p = img.pixels;
  struct RGB* end_p = img.pixels + (img.width * img.height);
  while (p < end_p) {
    printf("%d %d %d\n", p->r, p->g, p->b);
    p++;
  }
}

struct RGB makeRandomColor() {
  return (struct RGB) {
    (unsigned short)(frand() * 255.0),
      (unsigned short)(frand() * 255.0),
      (unsigned short)(frand() * 255.0),
  };
}

struct ImageHandle makeRandomNoiseImage(int width, int height) {
  int pixel_count = width * height;
  struct RGB* pixels = malloc(pixel_count * sizeof(struct RGB));

  struct RGB* p = pixels;
  struct RGB* end_p = pixels + pixel_count;
  while (p < end_p) {
    *p = makeRandomColor();
    p++;
  }

  return (struct ImageHandle) { width, height, pixels };
}