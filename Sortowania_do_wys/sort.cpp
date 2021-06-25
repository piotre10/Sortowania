
#include "sort.h"
#include <stdlib.h>

void Update( int* tab, int l, int p );

void bubble_sort( int* tab, int size )
{
	for( int i = 1; i<size; i++ )
		for( int j = size-1; j>i-1; j-- )
		{
			if( tab[j-1]>tab[j] )
			{
				int x = tab[j-1];
				tab[j-1] = tab[j];
				tab[j] = x;
			}
		}
}
void modified_bubble_sort( int* tab, int size )
{
	int k = size-1;
	int l = 1;
	int p = size-1;
	while( l<=p )
	{
		for( int j = p; j>=l; j-- )
		{
			if( tab[j-1]>tab[j] )
			{
				int x = tab[j-1];
				tab[j-1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		l = k+1;
		for( int j = l; j<=p; j++ )
		{
			if( tab[j-1]>tab[j] )
			{
				int x = tab[j-1];
				tab[j-1] = tab[j];
				tab[j] = x;
				k = j;
			}
		}
		p = k-1;
	}
}
void heap_sort( int* tab, int size )
{
	int p = size-1;
	for( int l = size/2; l>=0; l-- ) Update( tab, l, p );
	for(;p>0;p-- )
	{

		int x = tab[0];
		tab[0] = tab[p];
		tab[p] = x;
		Update( tab, 0, p-1 );
	}
}
void Update( int* tab, int l, int p )
{
	if( l==p ) return;
	int x = tab[l];
	int i = l;
	int j = 2*i+1;
	while( j<=p )
	{
		if( ( j<p )&&( tab[j]<tab[j+1] ) ) j++;
		if( x>=tab[j] ) break;
		tab[i] = tab[j];
		i = j;
		j = 2*i+1;
	}
	tab[i] = x;
}
void insertion_sort( int* tab, int size )
{
	int temp = 0;
	for( int i = 1; i<size; i++ )
	{
		int x = tab[i];
		int j = i-1;
		while( j>=0 && x<tab[j] )
		{
			tab[j+1] = tab[j--];
		}
		tab[j+1] = x;
	}
}
void modified_insertion_sort( int* tab, int size )
{
	{
		int temp = 0;
		for( int i = 1; i<size; i++ )
		{
			int x = tab[i];
			int l = 0;
			int p = i;
			while( l<p )
			{
				int m = ( l+p )/2;
				if( x<tab[m] ) p = m;
				else l = m+1;
			}
			for( int j = i-1; j>=l; j-- )
			{
				tab[j+1] = tab[j];
			}
			tab[l] = x;
		}
	}
}
void quick_sort( int* tab, int l, int p )
{
	int i = l;
	int j = p;

	int x = tab[( l+p )/2];
	while( i<j )
	{
		while( tab[i]<x ) i++;
		while( tab[j]>x ) j--;
		if( i<=j )
		{
			int w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++; j--;
		}
	}

	if( l<j ) quick_sort( tab, l, j );
	if( i<p ) quick_sort( tab, i, p );

}
void selection_sort( int* tab, int size )
{
	for( int i = 0; i<size-2; i++ )
	{
		int k = i;
		int x = tab[i];
		for( int j = i; j<size; j++ )
		{
			if( tab[j]<x )
			{
				k = j;
				x = tab[j];
			}
		}
		tab[k] = tab[i];
		tab[i] = x;
	}
}
