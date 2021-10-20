
#include <stdio.h>
//#include <curses.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
		 float ratio, a[SIZE][SIZE];
		 int i,j,k,n;
         n=3;
		 
         a[1][1] = 1;
         a[1][2] = 1;
         a[1][3] = 3;
         a[2][1] = 1;
         a[2][2] = 3;
         a[2][3] = -3;
         a[3][1] = -2;
         a[3][2] = -4;
         a[3][3] = -4;
		 
		 for(i=1;i<=n;i++)
		 {
			  for(j=1;j<=n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
		 }
		 /* Applying Gauss Jordan Elimination */
		 for(i=1;i<=n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("Mathematical Error!");
				   exit(0);
			  }
			  for(j=1;j<=n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++)
					    {
                            printf("m=%.2f, ajk[%i][%i]=%.2f, aik[%i][%i]=%.2f, ajk1[%i][%i]=%.2f\n",ratio,j,k,a[j][k],i,k,a[i][k],j,k,a[j][k] - ratio*a[i][k]);
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 /* Row Operation to Make Principal Diagonal to 1 */
         
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			  }
		 }
         
		 /* Displaying Inverse Matrix */
		 printf("\nInverse Matrix is:\n");
		 for(i=1;i<=n;i++)
		 {
			  for(j=n+1;j<=2*n;j++)
			  {
			   	printf("%0.3f\t",a[i][j]);
			  }
			  printf("\n");
		 }
		 return(0);
}
