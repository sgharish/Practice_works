#include<stdio.h>
#include<math.h>
#define MAX 30

int array[MAX];

int sqr_finder( int k )
{
	int i, j, expted_value, count = 0;
	for ( i=0; i<k; i++ )
	{
		expted_value = array[i]*array[i];
		for( j=0; j<k; j++ )
		{
			if( array[j] == expted_value )
			{
				printf( "\n true" );
				printf( "\n sqrt %d = %d; elements are %d and %d (value %d)", array[i], expted_value, i, j, array[j]);
				return 0;
			} 
		}
	}
	printf( "\n false" );
	return 0;
}

int main()
{
	int k;
	scanf( "%d", &k );
	if( k>=30 )
	{
		return 0;
	}
	else
	{
		int i;
		for( i=0; i<k; i++)
		{
			printf( "\n%d. ", i);
			scanf( "%d", &array[i]);
		}
		sqr_finder( k );
	}
	return 0;
}
	
