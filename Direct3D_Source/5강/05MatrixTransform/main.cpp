// 03-Vertices-Cos.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <d3dx9math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	D3DXMATRIX matMatrix;	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%7.1f", matMatrix(i, j));
		}

		printf("\n");
	}
	
	printf( "----------�̵� ���-------------------\n");
	D3DXMatrixTranslation(&matMatrix, 10.0f, 9.0f, 8.0f);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%7.1f", matMatrix(i, j));
		}

		printf("\n");
	}

	printf( "-------------ũ�� ���---------------------\n");
	D3DXMatrixScaling(&matMatrix, 5.0f, 2.0f, 3.0f);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%7.1f", matMatrix(i, j));
		}

		printf("\n");
	}
	
	printf( "------------- X �� ȸ�� ���---------------\n");
	D3DXMatrixRotationX(&matMatrix, D3DXToRadian(90));
	for( int i = 0 ; i < 4 ; i++ )
	{ 
		for( int j = 0 ; j < 4 ; j++ )
		{
			printf( "%7.1f" , matMatrix(i, j) );
		}

		printf( "\n" );
	}

	printf( "------------- Y �� ȸ�� ���---------------\n");
	D3DXMatrixRotationY(&matMatrix, D3DXToRadian(30));
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			printf( "%7.1f" , matMatrix(i, j) );
		}

		printf( "\n" );
	}
/*
	printf( "------------- Z �� ȸ�� ���---------------\n");
	D3DXMatrixRotationZ( &matMatrix, D3DXToRadian( 30 ) );
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			printf( "%7.1f" , matMatrix(i, j) );
		}

		printf( "\n" );
	}*/

	return 0;
}

