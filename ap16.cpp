#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct student
{
    string name;
    int code;
    int score;
};


typedef int (*compare)(const void* s1, const void* s2);

int compare_codes(const student* s1, const student* s2)
{
    return s1->code - s2->code;
}


int main()
{
    student arman;
    arman.name = "arman";
    arman.code = 3;
    arman.score = 19;

    student safayi;
    safayi.name = "safayi";
    safayi.code = 1;
    safayi.score = 15;

    student gorgali;
    gorgali.name = "gorgali";
    gorgali.code = 7;
    gorgali.score = 10;

    student shayan;
    shayan.name = "shayan";
    shayan.code = 3;
    shayan.score = 12;

    student* students[4] = {&arman, &safayi, &gorgali, &shayan};

    compare mycompare = compare_codes;

    qsort(students, 4, sizeof(student), mycompare);

}


struct student
{
    string name;
    int code;
    int score;
};


typedef int (*compare)(const void* s1, const void* s2);

int compare_codes(const student* s1, const student* s2)
{
    return s1->code - s2->code;
}

compare mycompare = compare_codes;