#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

point *read_points(size_t count) {
    point *points;
    points = (point*) malloc(count);
    for (int i = 0; i < count; i++) {
        double x;
        double y;
        printf("Enter one point: ");
        scanf("%lf %lf", &x, &y);
        points[i].x = x;
        points[i].y = y;
    }
    return points;
}

double perimeter(const point *points, size_t count) {
    double perimeter = 0;
    for (int i = 0; i < count-1; i++) {
        double side_x = points[i+1].x - points[i].x;
        double side_y = points[i+1].y - points[i].y;
        perimeter += sqrt(side_x*side_x + side_y*side_y);
    }
    double side_x = points[count-1].x - points[0].x;
    double side_y = points[count-1].y - points[0].y;
    perimeter += sqrt(side_x*side_x + side_y*side_y);

    return perimeter;
}

double area(const point *points, size_t count) {
    double area = 0;
    int j = count-1;
    for (int i = 0; i < count; i++) {
        double sum_x = points[j].x + points[i].x;
        double sum_y = points[j].y - points[i].y;
        area += sum_x * sum_y;
        j = i;
    }
    
    return area / 2;
}

int main(int argc, char *argv[]) {
    printf("How many points will you input? ");
    double count;
    scanf("%lf", &count);
    point *points = read_points(count);
    printf("%lf\n", perimeter(points, count));
    printf("%lf\n", area(points, count));
    free(points);
}

//for both this and points2.c all of the test cases work except for the {(1 1), (5 1), (5 3), (1 3)} for some reason I'm not sure
