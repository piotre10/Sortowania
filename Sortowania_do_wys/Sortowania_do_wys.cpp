
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>
#include"sort.h"


#define DEBUG
#define NAME_SIZE 50
#define HOW_MANY 50
#define MAX_ELEMENT (int)1e+5

typedef void( *sort_f_pointer )( int*, int );
typedef const char f_name[NAME_SIZE];
int* create_array( int size );
void delete_array( int** array );
void print_n_elements( int* array, int n );
void RandomizeArray( int* array, int size, int max_elem );
int main( int argc, char* argv[] )
{
	if( argc!=2 )
	{
		printf( "Usage: %s int number - size of arrays to sort",argv[0] );
		return -1;
	}

	const int size = atoi( argv[1] );

	sort_f_pointer f_pointers[] = { bubble_sort, modified_bubble_sort, insertion_sort, modified_insertion_sort, selection_sort, heap_sort };
	void ( *quicksort_pointer )( int*, int, int ) = quick_sort;
	f_name f_names[] = { "Bubble sort","Modified bubble sort","Insertion sort","Modified insertion sort","Selection sort","Heap sort", "Quick sort" };

	int* original_array = create_array( size );
	if( !original_array )
	{
		printf( "Error1: Stack overflow, array cannot be created" );
		return -1;
	}
	int* array_to_sort = create_array( size );
	if( !array_to_sort )
	{
		printf( "Error2: Stack overflow, array cannot be created" );
		return -1;
	}

	RandomizeArray( original_array, size,MAX_ELEMENT );

	int n = sizeof( f_pointers )/sizeof( sort_f_pointer );

	for( int i = 0; i<n; i++ )
	{
		memcpy( array_to_sort, original_array, size*sizeof( int ) );
		clock_t start_time = clock( );
		f_pointers[i]( array_to_sort, size );
		clock_t end_time = clock( );
		printf( "%s rozmiar tablicy: %d\n Czas w sekundach: %f s\n Czas w milisekundach: %d ms \n", f_names[i], size, double( end_time-start_time )/CLOCKS_PER_SEC, int( 1000*double( end_time-start_time )/CLOCKS_PER_SEC ) );
#ifdef DEBUG
		printf( "Pierwsze elementy tablicy:" );
		print_n_elements( array_to_sort, ( HOW_MANY<size ) ? HOW_MANY : size );
#endif
	}
	memcpy( array_to_sort, original_array, size*sizeof( int ) );
	clock_t start_time = clock( );
	quicksort_pointer( array_to_sort, 0, size-1 );
	clock_t end_time = clock( );
	printf( "%s rozmiar tablicy: %d\n Czas w sekundach: %f s\n Czas w milisekundach: %d ms\n", f_names[n], size, double( end_time-start_time )/CLOCKS_PER_SEC, int( 1000*double( end_time-start_time )/CLOCKS_PER_SEC ) );
#ifdef DEBUG
	printf( "Pierwsze elementy tablicy:" );
	print_n_elements( array_to_sort, ( HOW_MANY<size ) ? HOW_MANY : size );
#endif

	delete_array( &original_array );
	delete_array( &array_to_sort );
	return 0;
}

int* create_array( int size )
{
	int* tab = (int*)malloc( size*sizeof( int ) );
	if( !tab ) return NULL;
	memset( tab, 0, size*sizeof( int ) );
	return tab;
}
void delete_array( int** array )
{
	free( *array );
	*array = NULL;
}
void print_n_elements( int* tab, int n )
{
	for( int i = 0; i<n; i++ )
	{
		if( i%10==0 ) printf( "\n" );
		printf( "%d\t", *tab++ );
	}
	printf( "\n" );
}
void RandomizeArray( int* array, int size, int max_elem )
{
	srand( (unsigned)time( NULL ) );
	for( int i = 0; i<size; i++ )
	{
		*array++ = rand( )%max_elem;
	}
}
