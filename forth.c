#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a[50][50], b[50][50], c[50][50];	
	int r1,c1,r2,c2,k,l,i,j;

	while(1){

		while(1){
			printf("Enter the number of rows for FIRST matrix\n");
			scanf("%d",&r1);

			if(r1<=0)
				printf("Enter a positive non zero number\n");
			else
				break;
		}

		while(1){
			printf("Enter the number of columns for the FIRST matrix\n");
			scanf("%d",&c1);

			if(c1<=0)
				printf("Enter a positive non zero number\n");
			else
				break;
		}

		while(1){
			printf("Enter the number of rows for SECOND matrix\n");
			scanf("%d",&r2);

			if(r2<=0)
				printf("Enter a positive non zero number\n");
			else
				break;
		}

		while(1){
			printf("Enter the number of columns for the SECOND matrix\n");
			scanf("%d",&c2);

			if(c2<=0)
				printf("Enter a positive non zero number\n");
			else
				break;
		}

		if(c1==r2)
			break;
		else
			printf("Matrix Multiplication cannot be performed.\nThe Number of columns of first matrix should be equal to Number of rows of second matrix\nEnter the number of rows and columns again.\n");	
	}
	

	printf("Enter the Elements : Matrix FIRST\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}

	printf("Enter the Elements : Matrix SECOND\n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}	

	printf("Entered Matrix is : Matrix FIRST\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}	

	printf("Entered Matrix is : Matrix SECOND\n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}	


	for(i=0;i<r2;i++){
		for(j=0;j<c1;j++){
			for(k=0;k<c1;k++){
				c[i][j] += (a[i][k]*b[k][j]);
			}
		}
	}


	printf("Multiplication Matrix is : THIRD\n");
	for(i=0;i<r2;i++){
		for(j=0;j<c1;j++){
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}	

	return 0;
}

