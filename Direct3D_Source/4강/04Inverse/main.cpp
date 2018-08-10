// 03-Vertices-Cos.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <d3dx9math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	D3DXMATRIX matMatrix, matResult;	
	D3DXMatrixRotationX( &matMatrix, 0.3f );

	printf( "------------ ȸ�� ��� --------------\n");
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			printf( "%7.1f" , matMatrix(i, j)  );
		}

		printf( "\n" );
	}

	printf( "------------Inverse------------------\n");

	D3DXMatrixInverse( &matResult, NULL, &matMatrix );	
	
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			printf( "%7.1f" , matResult(i, j)  );
		}

		printf( "\n" );
	}

	printf( "--------------Inverse-----------------\n");

	D3DXMatrixInverse( &matResult, NULL, &matResult );	
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			printf( "%7.1f" , matResult(i, j) );
		}

		printf( "\n" );
	}	

	return 0;
}

