#include <stdio.h>
#include <stdlib.h>

#define SIZE1 256
#define SIZE2 128
#define SIZE3 32
#define SIZE4 8
#define SIZE5 4

int globalA[SIZE1][SIZE2];
int globalB[SIZE2][SIZE3];

int sum1DArray(int arr[SIZE1])
{
    int sum = 0;
    for (int i = 0; i < SIZE1; i++)
    {
        sum += arr[i];
    }
    globalA[2][15] = sum;
    return sum;
}

int sum2DArray(int arr[SIZE1][SIZE2])
{
    int sum = 0;
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            sum += arr[i][j] + globalB[j][i];
            sum += arr[2 * 3 * sum][i * j];
        }
    }

    double matrix[SIZE1][SIZE2];
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            matrix[i][j] = i * arr[i][j];
            globalA[i][j] = matrix[i][j];
        }
    }

    return sum;
}

int sum3DArray(int arr3d[SIZE1][SIZE2][SIZE3])
{
    int sum = 0;
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            for (int k = 0; k < SIZE3; k++)
            {
                sum += arr3d[i][j][k];
            }
        }
    }
    return sum;
}

unsigned char img[8][10] = {
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
    {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}};

int main()
{
    int arr1D[SIZE1];
    int arr2D[SIZE1][SIZE2];

    int x = img[4][5];
    img[6][2] = 210;

    // Fill the 1D, 2D, 3D, 4D and 5D arrays with random values
    for (int i = 0; i < SIZE1; i++)
    {
        arr1D[i] = rand() % RAND_MAX; // Random number between 0 and 99
        for (int j = 0; j < SIZE2; j++)
        {
            arr2D[i][j] = rand() % 100; // Random number between 0 and 99
        }
    }

    int sum1D = sum1DArray(arr1D);
    int sum2D = sum2DArray(arr2D);

    printf("Sum of 1D array: %d, expected %d (%s)\n", sum1D, 971773852, (sum1D == 971773852) ? "PASSED" : "FAILED");
    printf("Sum of 2D array: %d, expected %d (%s)\n", sum2D, 1617520, (sum2D == 1617520) ? "PASSED" : "FAILED");
    return 0;
}