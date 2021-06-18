/*
 * main.c
 * 
 * Copyright 2021 jcld14 <jcld14@inf.ufpr.br>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct intArray_s {
	int  s; // size of memory alocation
	int  l; // lenght of the array
	int *a; // pointer to array of integers
} intArray_t;


intArray_t* intArrayAlloc() {
	intArray_t *A = (intArray_t*)malloc(sizeof(intArray_t));
	A->s=0;
	A->l=0;
	A->a=NULL;
	return A;
}

int push_back(intArray_t *A, int itg) {
	if (A->s<=0 && A->l<=0 && A->a==NULL) {
		A->a = (int*)malloc(sizeof(int)*2);
		if (A->a == NULL)
			return 0;
		A->s=2;
		A->l=1;
		A->a[0] = itg;
		return 1;
	}
	
	if (A->s > A->l) {
		A->a[A->l] = itg;
		A->l++;
		return 1;
	}
	
	if (A->s == A->l) {
		A->a = (int*)realloc(A->a, sizeof(int)*(A->s+4));
		if (A->a == NULL)
			return 0;
		A->s = A->s +4;
		A->a[A->l] = itg;
		A->l+=1;
		return 1;
	}
	return 0;
}

int pop_back( intArray_t *A) {
	if (A->l > 0) {
		A->l--;
		return A->a[A->l+1];
	} else {
		return 0;
	}
}

void printintArray( intArray_t *A) {
	if (A==NULL) {
		printf("A{NULL}");
		return;
	}
	printf("{");
	for (int i = 0; i < A->l; i++) {
		if (i != 0)
			printf(" ");
		printf("%d",A->a[i]);
		if (i != A->l - 1)
			printf(", ");
	}
	printf("}\n");	
}

// Function to find all unique combination of
// given elements such that their sum is K
void unique_combination(int l, int sum, int K, intArray_t *local, intArray_t *A, intArray_t **result, int *count) {
    //printf("unique_combination(int l=%d, int sum=%d, int K=%d, intArray_t *local=%p, intArray_t *A=%p)\n", l, sum, K, local, A); fflush(stdout);
	// If a unique combination is found
    if ( (0<l) /*&& (sum<=K)*/ ) {
		*count = *count+1;
        /*printf("count=%d {", *count);
        for (int i = 0; i < local->l; i++) {
            if (i != 0)
                printf(" ");
            printf("%d",local->a[i]);
            if (i != local->l - 1)
                printf(", ");
        }
        printf("}, remainder=%d\n",K-sum);*/
    }
    
    if ( (sum<=K) ) {
		result[*count] = intArrayAlloc();
        for (int i = 0; i < local->l; i++) {
			push_back(result[*count], local->a[i]);
        }
    }
    
    
    
    if (sum > K)
		return;
 
    // For all other combinations
    for (int i = l; i < A->l; i++) {
        // Check if the sum exceeds K
        if (sum + A->a[i] > K)
            continue;
        // Check if it is repeated or not
        if (i > l && A->a[i] == A->a[i - 1])
            continue;
        // Take the element into the combination
        push_back(local, A->a[i]);
        // Recursive call
        unique_combination(i + 1, sum + A->a[i], K, local, A, result, count);
        // Remove element from the combination
        pop_back(local);
    }
}

int ascend(const void *p, const void *q) {
	return *(const int *)p - *(const int *)q;
}

// Function to find all combination
// of the given elements
intArray_t** Combination(intArray_t *A, int K, int *count) {
	//printf("void Combination(intArray_t *A=%p, int K=%d)\n", A, K); fflush(stdout);
	// Sort the given elements
	
	qsort(A->a, A->l, sizeof(int), ascend);
	
	// To store combination
	intArray_t *local = intArrayAlloc();
	
	intArray_t **results = (intArray_t**)calloc(sizeof(intArray_t*),pow(2.0,(A->l+1)/2));
	*count = -1;
	unique_combination(0, 0, K, local, A, results, count);
	
	return results;
}



/* Se e empresa tem 3 máquinas a demanda tem pedidos de 4 tempos 
 * diferentes, com 10 de 200 minutos, 250 de 330 minutos, 10 de 420 
 * minutos e 50 de 500 minutos, o arquivo de entrada seria como abaixo.*/
//{ 200, 330, 420, 500};

// Driver code

void scanfile (	int K,
				int *n,
				int *m,
				intArray_t *amount,
				intArray_t *size,
				intArray_t *comb_size)
{
	
	if (scanf("%d %d",n, m) != 2)
		return;
	
	for (int i = 0; i < *m; i++) {
		int aux1, aux2;
		if (scanf("%d %d", &aux1, &aux2) != 2)
			break;
		push_back(amount,aux1);
		push_back(size,aux2);
		
		for (int j=1; j*aux2 < K; j++)
			push_back(comb_size,aux2);
	}
}


int main() {
	int n;
	int m;
	
	
	int K =  540;
	
	intArray_t *amount   = intArrayAlloc();
	intArray_t *size      = intArrayAlloc();
	intArray_t *comb_size = intArrayAlloc();
	
	scanfile( K, &n, &m, amount, size, comb_size);
    
    // Function call
    int count = 0;
	intArray_t ** result = Combination(comb_size, K, &count);
    
    
    if (count==0)
		return 1; // no results wore found
	else
		count++; // (count+1) results wore found
    
    printf("\n/* Objective function */\n");
    for (int i = 0; i < count; i++){
		if (i==0)
			printf("MIN: X%d",i);
		else
			printf(" + X%d",i);
	}
    printf(";\n");
    
    
    
    
    int offset = 1;
	for(int i = 1; i<9; i++) {
		if (offset<count)
			offset = 10*offset;
		else
			break;
	}
	
	int eq[count+1][size->l+1][2+1]; //printf("offset=%d\n",offset);
    
    for (int i = 0; i < count; i++) {
		for (int k=0; k < result[i]->l; k++) {
			eq[i][k][1] = 0;
			eq[i][k][2] = 0;
		}
	}
	
    
    for (int i = 0; i < count; i++) { // percore cada uma das equações
		for (int j = 0; j < size->l; j++) { // para cada um dos size
			eq[i][j][1] = size->a[j];
			eq[i][j][2] = 0;
			for (int k=0; k <result[i]->l; k++) {// conta quantas vezes o tamanho se repetiu
				if ( eq[i][j][1] == result[i]->a[k])
					eq[i][j][2]++;
			}
		}
	}
	
	printf("\n/* Variable bounds (aka min and max value) */\n");
	for (int i = 0; i < count; i++) {
		int min = K;
		for (int k=0; k < size->l; k++) {
			if (eq[i][k][2]!=0) {
				if (min > (amount->a[k]+eq[i][k][2]-1)/eq[i][k][2])
					min = (amount->a[k]+eq[i][k][2]-1)/eq[i][k][2];
			}
					
		}
		printf("X%d >= 0;\n", i);
		printf("X%d <= %d;\n", i, min+1);
	}
    
    /** Variable Constraints */
    printf("\n/* Variable Constraints */\n");
    for (int k=0; k < size->l; k++) {
		int is_first = 1;
		for (int i = 0; i < count; i++) {
			if (eq[i][k][2]!=0) {
				if (is_first==1) {
					printf("%d*X%d", eq[i][k][2], i);
					is_first=0;
				} else {
					printf(" + %d*X%d", eq[i][k][2], i);
				}
			}
		}
		printf(" >= %d;\n",amount->a[k]);
	}
	
	/** Variable Types **/
	printf("\n/* Variable Types */\n");
    for (int i = 0; i < count; i++){
		printf("int X%d;\n",i);
		
	}
    
    
    /* Linear equations system explained */
    printf("\n/* Linear equations system explained \n");
    for (int i = 0; i < count; i++) {
		int eq_not_null = 0;
		int is_first = 1;
		for (int k=0; k < size->l; k++) {
			if (eq[i][k][2]!=0) {
				if (is_first==1) {
					printf("\teq%2d: %d*%d",i, eq[i][k][2],eq[i][k][1]); fflush(stdout);
					is_first=0;
				} else {
					printf(" + %d*%d", eq[i][k][2], eq[i][k][1]); fflush(stdout);
				}
				eq_not_null = 1;
			}
		}
		if (eq_not_null == 1)
			printf("\n");
	}
    printf("*/\n");
    
    return 0;
}
