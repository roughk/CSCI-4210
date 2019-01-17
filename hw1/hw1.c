/*****************************************************************************/
/* Assignment 1: 2-D/ Matrix Multiplication **********************************/
/* Name: YOUR NAME GOES HERE *************************************************/
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int **mm_alloc( int rows, int columns )
{	
	/*
		* hints: allocate an array of pointers to ints, then allocate
		* an row/array of ints and assign each int pointer that row
		* see slide 62
	*/
	int i;
	int **temp;
	temp= (int **)malloc(rows * sizeof(int *));
	for(i=0; i<rows; i++){
		temp[i] = (int *)malloc(columns * sizeof(int));
	}
    
    return temp;
}

void mm_free( int **matrix, int rows, int columns )
{
	int i;
	for(i=0; i<rows; i++){
		free(&matrix[i]);
	}
	free(&matrix[i]);
}

void mm_read( int **matrix, int rows, int columns )
{
	int i,j,temp;
	printf("Please enter the values for the %d x %d matrix:\n", rows, columns);
	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++){
			scanf("%d", &temp);
			matrix[i][j]=temp;
		}
	}
	
	
}

void mm_print( int **matrix, int rows, int columns )
{
	int i,j;
	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void mm_mult( int **m1, int m1_rows, int m1_cols,
              int **m2, int m2_rows, int m2_cols,
              int **results)
{
	
	int i,j,k, total;
	for(i=0; i < m1_rows; i++){
		for(j=0; j < m2_cols; j++){
			total=0;
			for(k=0; k< m1_cols; k++){
				total+= (m1[i][k])*(m2[k][j]);
			}
			results[i][j]=total;
		}
	}
		
}

int main()
{
    /*
     * You must keep this function AS IS.
     * You are not allowed to modify it!
     */
    int **matrix1 = NULL;
    int **matrix2 = NULL;
    int **results_matrix = NULL;

    int m1_rows, m1_columns;
    int m2_rows, m2_columns;

    printf("How many rows are in the first matrix? ");
    scanf("%d", &m1_rows);
	printf("\n");
    printf("How many columns are in the first matrix? ");
    scanf("%d\n", &m1_columns);
	printf("\n");
	
    printf("How many rows are in the second matrix? ");
    scanf("%d\n", &m2_rows);
    printf("\n");
	printf("How many columns are in the second matrix? ");
    scanf("%d\n", &m2_columns);
	printf("\n");
	
    printf("\n");

    if (m1_columns != m2_rows) {
        printf("Invalid matrix multiplication!\n");
        exit(-1);
    }
	
    matrix1 = mm_alloc(m1_rows, m1_columns);
	matrix2 = mm_alloc(m2_rows, m2_columns);
	
    results_matrix = mm_alloc(m1_rows, m2_columns);

    mm_read( matrix1, m1_rows, m1_columns );
    mm_read( matrix2, m2_rows, m2_columns );

    printf("\n");

    mm_mult(matrix1, m1_rows, m1_columns, matrix2, m2_rows, m2_columns, results_matrix);

    mm_print( matrix1, m1_rows, m1_columns );
    printf("\n");
    printf("multiplied by\n\n");
    mm_print( matrix2, m2_rows, m2_columns );
    printf("\n");
    printf("is: \n\n");
    mm_print( results_matrix, m1_rows, m2_columns );
    mm_free( matrix1, m1_rows, m1_columns );
    mm_free( matrix2, m2_rows, m2_columns );
    mm_free( results_matrix, m1_rows, m2_columns );
	
    return 0;
}
