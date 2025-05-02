#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point2D
{
    float x;
    float y;
};

typedef struct
{
    float x;
    float y;
    float z;
} Point3D;

typedef struct
{
    int id;      // Scalar member: integer
    float value; // Scalar member: float
    char *name;  // Pointer member: char*
} Data;

typedef float pixel_t;

typedef struct
{
    pixel_t x;
    pixel_t y;
    pixel_t z;
} gradient_t;

Point3D globalPoint3D;

void usePoint2D(struct Point2D point)
{
    printf("Point2D: (%.2f, %.2f)\n", point.x, point.y);
    float x1 = point.x + 1.0;
    float y1 = point.y + 1.0;
    printf("Point2D + 1: (%.2f, %.2f)\n", x1, y1);
}

void usePoint2DRef(struct Point2D *point)
{
    printf("Point2D: (%.2f, %.2f)\n", point->x, point->y);
    float x1 = point->x + 1.0;
    float y1 = point->y + 1.0;
    printf("Point2D + 1: (%.2f, %.2f)\n", x1, y1);
}

void usePoint3D(Point3D point)
{
    printf("Point3D: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
    int x1 = point.x + 1;
    int y1 = point.y + 1;
    int z1 = point.z + 1;
    globalPoint3D.x = 3123.0;
    globalPoint3D.y = 3123.0;
    globalPoint3D.z = 3123.0;
    printf("Point3D + 1: (%d, %d, %d)\n", x1, y1, z1);
}

void usePoint3DRef(Point3D *point)
{
    printf("Point3D: (%.2f, %.2f, %.2f)\n", point->x, point->y, point->z);
    int x1 = point->x + 1;
    int y1 = point->y + 1;
    int z1 = point->z + 1;
    printf("Point3D + 1: (%d, %d, %d)\n", x1, y1, z1);
}

void useData(Data data)
{
    printf("Data: ID=%d, Value=%.2f, Name=%s\n", data.id, data.value, data.name);
    int id1 = data.id + 1;
    float value1 = data.value + 1.0;
    printf("Data + 1: ID=%d, Value=%.2f\n", id1, value1);
}

void useDataRef(Data *data)
{
    printf("Data: ID=%d, Value=%.2f, Name=%s\n", data->id, data->value, data->name);
    int id1 = data->id + 1;
    float value1 = data->value + 1.0;
    printf("Data + 1: ID=%d, Value=%.2f\n", id1, value1);
}

void structToStructAssignment()
{
    Data d1 = {1, 2.0, "Data 1"};
    Data d2;
    d2 = d1;
}

void testCopyStruct(Data s)
{
    printf("Data: ID=%d, Value=%.2f, Name=%s\n", s.id, s.value, s.name);
}

void testPointerStruct(Data *s)
{
    printf("Data: ID=%d, Value=%.2f, Name=%s\n", s->id, s->value, s->name);
}

void testArrays(int x)
{
    int a[3];
    a[0] = 1;
    Data a1[3];
    Data a2[3] = {{1, 2.0, "Data 1"}, {2, 3.0, "Data 2"}, {3, 4.0, "Data 3"}};
    Data a3[3] = {1, 2.0, "Data 1", 2, 3.0, "Data 2", 3, 4.0, "Data 3"};
    Data *a4 = (Data *)malloc(3 * sizeof(Data));

    a1[0].id = 1;
    a1[0].value = a2[0].value;
    int y = a2[2].id;
    a1[0] = a2[0];
}

void testEverything(Data s1, Data *s2)
{
    Data s3 = {102, 98.9, "fooooooooooooo"};
    s3.id = 999;
    s2->id = s3.id;
    Data *s4 = (Data *)malloc(sizeof(Data));
    s4->id = 106;
    s4->value = 95.9;
    s4->name = "baaaaaar";
    s2->name = s4->name;
    testCopyStruct(s3);
    testCopyStruct(*s4);
    testPointerStruct(s4);
    testPointerStruct(&s3);

    Data s5 = s3;
    Data s6 = *s4;
    Data *s7 = s4;
    Data *s8 = &s3;

    s3 = s5;
    s6 = *s4;
    s7 = s4;
    s8 = &s3;
}

void createData(int id, float value, const char *name, Data *data)
{
    data = (Data *)malloc(sizeof(Data));
    data->id = id;
    data->value = value;
    data->name = (char *)malloc(strlen(name) + 1);
    strcpy(data->name, name);
}

void declsWithInit()
{
    Data dataInit1 = {102, 98.9, "Sample Data 1"};
    Data dataInit2 = {.id = 103, .value = 97.9, .name = "Sample Data 2"};
    Data dataInit3 = {.value = 96.9, .id = 104, .name = "Sample Data 3"};
    Data dataInit4 = {5};
    Data dataInit5 = {.id = 105};

    Data *dataInit12 = malloc(sizeof(Data));
    Data *dataInit13 = (Data *)malloc(sizeof(Data));
    Data *dataInit14 = (Data *)malloc(16);
    Data *dataInit15 = (Data *)calloc(1, sizeof(Data));
}

int main()
{
    struct Point2D myPoint2D;
    myPoint2D.x = 1.0;
    myPoint2D.y = 2.0;
    usePoint2D(myPoint2D);
    usePoint2DRef(&myPoint2D);

    struct Point2D *myPoint2DPtr = (struct Point2D *)malloc(sizeof(struct Point2D));
    myPoint2DPtr->x = 3.0;
    myPoint2DPtr->y = 4.0;
    usePoint2D(*myPoint2DPtr);
    usePoint2DRef(myPoint2DPtr);

    Point3D myPoint3D;
    myPoint3D.x = 1.0;
    myPoint3D.y = 2.0;
    myPoint3D.z = 3.0;
    usePoint3D(myPoint3D);
    usePoint3DRef(&myPoint3D);

    Point3D *myPoint3DPtr = (Point3D *)malloc(sizeof(Point3D));
    myPoint3DPtr->x = 4.0;
    myPoint3DPtr->y = 5.0;
    myPoint3DPtr->z = 6.0;
    usePoint3D(*myPoint3DPtr);

    globalPoint3D.x = 7.0;
    globalPoint3D.y = 8.0;
    globalPoint3D.z = 9.0;

    Data myData;
    myData.id = 101;
    myData.value = 99.9;
    const char *inputName = "Sample Data";
    myData.name = (char *)malloc(strlen(inputName) + 1);
    strcpy(myData.name, inputName);

    useData(myData);
    useDataRef(&myData);

    free(myData.name);

    Data *funData1;
    createData(1, 2.0, "Data 1", funData1);

    myData.id = 102;

    return 0;
}