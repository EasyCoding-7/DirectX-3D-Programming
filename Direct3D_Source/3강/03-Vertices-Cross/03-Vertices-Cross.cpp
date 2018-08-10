// 03-Vertices-Cross.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <d3dx9math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	D3DXVECTOR3 v1( 3.0f, 0.0f, 0.0f );
	D3DXVECTOR3 v2( 0.0f, 0.0f, 3.0f );
	D3DXVECTOR3 vResult;

	D3DXVec3Cross( &vResult, &v1, &v2 );
	D3DXVec3Normalize( &vResult, &vResult );
	printf( "%f %f %f \n", vResult.x, vResult.y, vResult.z );
	return 0;
}

