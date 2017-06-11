#include <stdio.h>


struct point {
    int x;
    int y;
};

struct rectangle {
    struct point p1;
    struct point p2;
};


struct point makepoint(int x, int y);
struct rectangle canonrect(struct rectangle r);
int
main(int argc, char *argv[]) {
    struct point pt;
    pt.x = 3;
    pt.y = 4;
    printf("%d, %d\n", pt.x, pt.y);

    struct point maxpt = {320, 200};
    printf("%d, %d\n", maxpt.x, maxpt.y);

    struct rectangle rt;
    rt.p1 = pt;
    rt.p2 = maxpt;
    struct rectangle test = {pt, maxpt};

    printf("%d, %d\n", rt.p1.x, rt.p2.x);

    struct rectangle rt2;
    rt2.p1 = makepoint(0,0);
    rt2.p2 = makepoint(1000, 1000);
    struct point middle = makepoint((rt2.p1.x +  rt2.p2.x) / 2, (rt2.p1.y + rt2.p2.y) / 2);
    printf("middle values %d, %d\n", middle.x, middle.y);
    printf("size of int %lu\n", sizeof(int));
    printf("size of point %lu\n", sizeof(struct point));
    printf("size of rectangle %lu\n", sizeof(struct rectangle));
    return 0;
}

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

/* here we return p1 since point values are pass by value like all others */
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: checks if a point is within a rectangle */
int ptinrect(struct point p, struct rectangle r) {
    return p.x >= r.p1.x && p.x < r.p2.x
        && p.y >= r.p1.y && p.y < r.p2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
struct rectangle canonrect(struct rectangle r) {
    struct rectangle temp;
    temp.p1.x = min(1, 2);
    temp.p1.y = min(r.p1.y, r.p2.y);
    temp.p2.x = max(r.p1.x, r.p2.x);
    temp.p2.y = max(r.p1.y, r.p2.y);
    return temp;
}
