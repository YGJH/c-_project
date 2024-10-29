#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
#define MAX_COL 20
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 \
                                                       : 1)

typedef struct
{
    int row;
    int col;
    int value;
} term;

void read_matrix(term mat[]);
void print_matrix(term mat[]);
int search(term mat[], int value);
void fast_transpose(term a[], term b[]);
void multiply(term mat1[], term mat2[], term mat3[]);
void print_terms(term a[]);

int main()
{
    term mat1[MAX_TERMS], mat2[MAX_TERMS];
    read_matrix(mat1);
    // print_matrix(mat1);
    read_matrix(mat2);
    // print_matrix(mat2);
    term result[MAX_TERMS];
    // fast_transpose(mat2, result);
    // print_matrix(result);
    //  term result[MAX_TERMS];
    multiply(mat1, mat2, result);
    // print_matrix(result);
    print_terms(result);
}

void print_terms(term a[])
{
    for (int i = 0; i <= a[0].value; i++)
    {
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
    }
}

void fast_transpose(term a[], term b[])
{ // b is set to the transpose of a
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i, j, num_cols = a[0].col, num_terms = a[0].value;
    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_terms;
    if (num_terms > 0)
    { // nonzero matrix
        for (i = 0; i < num_cols; i++)
            row_terms[i] = 0; // initialization for the counting
        for (i = 1; i <= num_terms; i++)
            row_terms[a[i].col]++; // counting the row items
        starting_pos[0] = 1;
        for (i = 1; i < num_cols; i++) // calculate the starting positions
            starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
        for (i = 1; i <= num_terms; i++)
        {
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

void storeSum(term d[], int* totalD, int row, int column, int* sum)
{
    if (*sum)
    {
        if (*totalD < MAX_TERMS)
        {
            d[++*totalD].row = row;
            d[*totalD].col = column;
            d[*totalD].value = *sum;
            *sum = 0;
        }
        else
        {
            fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
            exit(1);
        }
    }
}

void multiply(term a[], term b[], term d[])
{
    int i, j, column, totalA = a[0].value, totalB = b[0].value, totalD = 0;
    int rowsA = a[0].row, colsA = a[0].col, colsB = b[0].col;
    int rowBegin = 1, sum = 0;
    term newB[MAX_TERMS];
    if (colsA != b[0].row)
    {
        fprintf(stderr, "Incompatible matrices\n");
        exit(0);
    }
    fast_transpose(b, newB);
    a[totalA + 1].row = rowsA;
    newB[totalB + 1].row = colsB;
    newB[totalB + 1].col = -1;
    int row = a[1].row;
    for (i = 1; i <= totalA;)
    {
        column = newB[1].row;
        for (j = 1; j <= totalB + 1;)
        {
            if (a[i].row != row)
            {
                storeSum(d, &totalD, row, column, &sum);
                i = rowBegin; // reset i
                for (; newB[j].row == column; j++)
                    ; // move j to next column
                column = newB[j].row;
            }
            else if (newB[j].row != column)
            {
                storeSum(d, &totalD, row, column, &sum);
                i = rowBegin;
                column = newB[j].row;
            }
            else
            {
                switch (COMPARE(a[i].col, newB[j].col))
                {
                case -1: // a[i].col < newB[j].col, go to next term of a
                    i++;
                    break;
                case 0: // match, multiply
                    sum += (a[i++].value * newB[j++].value);
                    break;
                case 1: // a[i].col > newB[j].col, go to next term of b
                    j++;
                }
            }
        }
        for (; a[i].row == row; i++)
            ; // go to next row of a
        rowBegin = i;   // rowBegin is the start of the next row
        row = a[i].row; // set current row
    }
    d[0].row = rowsA;
    d[0].col = colsB;
    d[0].value = totalD;
}

void read_matrix(term mat[])
{
    int entries, rows, cols;
    scanf("%d %d %d", &rows, &cols, &entries);
    mat[0].row = rows;
    mat[0].col = cols;
    mat[0].value = entries;
    for (int i = 1; i <= entries; i++)
    {
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
        // printf("%d %d %d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}

void print_matrix(term mat[])
{
    int k = 1;
    // printf("Rows: %d, Cols: %d, Entries: %d\n", mat[0].row, mat[0].col, mat[0].value);
    for (int i = 0; i < mat[0].row; i++)
    {
        for (int j = 0; j < mat[0].col; j++)
        {
            if (mat[k].row == i && mat[k].col == j)
            {
                printf("%d ", mat[k++].value);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int search(term mat[], int value)
{
    for (int i = 1; i <= mat[0].value; i++)
    {
        if (mat[i].value == value)
        {
            return 1;
        }
    }
    return 0;
}