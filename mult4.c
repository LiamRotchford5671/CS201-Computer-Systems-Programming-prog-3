/*Liam & Brita*/
/*Loop unrolling by 4*/

void ByteMult(unsigned long* a, unsigned long* b, unsigned long*c, long n)
{	
	long i=0, j=0, k=0, l=0;
	long leftover = n % 4;			
	long iteration = n - leftover; 
	unsigned long sum;

	for (i = 0; i < n; i++)
	{
		long in = i*n;

		for (j = 0; j < n; j++)
		{
			sum = 0;

			for (k = 0; k < iteration; k+=4)
			{
				sum = sum + a[in+k] * b[k*n+j];
				
				sum = sum + a[in+(k+1)] * b[(k+1)*n+j];
				sum = sum + a[in+(k+2)] * b[(k+2)*n+j];
				sum = sum + a[in+(k+3)] * b[(k+3)*n+j];
			}
			
			for(l = k; l < n; l++)
			{
				sum = sum + a[in+l] * b[l*n+j];
			} 

			c[in+j] = sum;
		}
	}
}
