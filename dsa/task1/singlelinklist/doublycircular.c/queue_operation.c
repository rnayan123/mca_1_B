#include <stdio.h>

struct student
{
    char *c;
    struct student *point;
};

void main()
{
    struct student s;
    struct student m;

    m.point = s;
    (m.point)->c = "hey";

    printf("%s", s.c);
}