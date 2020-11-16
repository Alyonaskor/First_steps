#include <stdio.h>
#include <math.h>
int main() {
    double x = 1;
    double y = 1;
    double x1 = 0;
    double y1 = 0;
    double x2 = 4;
    double y2 = 0;
    double x3 = 0;
    double y3 = 4;
    // (y1-y2)*x + (x2-x1)*y + (x1*y2 - x2*y1) = 0
    if(x < (-(x2-x1)*y - (x1*y2 - x2*y1) / (y1-y2)) && (y <  -(y1-y2)*x - (x1*y2 - x2*y1) / (x2-x1)))
    {
        if(x < (-(x3-x2)*y - (x2*y3 - x3*y2) / (y2-y3)) && (y <  -(y2-y3)*x - (x2*y3 - x3*y2) / (x3-x2)))
        {
            if(x < (-(x1-x3)*y - (x3*y1 - x1*y3) / (y3-y1)) && (y <  -(y3-y1)*x - (x3*y1 - x1*y3) / (x1-x3)))
            printf("Point in triangle \n");
        }
    }
    else
    printf("Point isn't in triangle. ");
    return 0;
}