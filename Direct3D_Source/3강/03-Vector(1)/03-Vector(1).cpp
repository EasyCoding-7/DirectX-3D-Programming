// 03-Vector(1).cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <d3dx9math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	D3DXVECTOR3 v1( 0.f, 3.0f, 0.0f );
	D3DXVECTOR3 v2( 3.0f, 0.0f, 0.0f );
	D3DXVECTOR3 v3;
	D3DXVECTOR3 v4( 3.0f, 3.0f, 0.0f );
	float fLength;

	// ������ ��
	/*v3 = v1 + v2;
	printf( "�� : %f %f %f \n",  v3.x, v3.y, v3.z );

	D3DXVec3Add( &v3, &v1, &v2 );
	printf( "�� : %f %f %f \n",  v3.x, v3.y, v3.z );*/

	// ������ ����
	/*v3 = v1 - v2;

	printf( "���� : %f %f %f \n",  v3.x, v3.y, v3.z );

	D3DXVec3Subtract( &v3, &v1, &v2 );
	printf( "���� : %f %f %f \n",  v3.x, v3.y, v3.z );*/

	// ũ�� 
	/*fLength = D3DXVec3Length( &v4 );
	printf( "ũ�� : %f \n", fLength );*/

	// ������ ũ�� ��ȯ 
	/*float fScale = 2.0f;
	D3DXVECTOR3 v5( 2.0f, 1.0f, 0.0f );

	D3DXVec3Scale( &v5, &v5, fScale );
	printf( "���� ������ �� : %f %f %f \n", v5.x, v5.y, v5.z );*/

	//// ������ ��������
	D3DXVECTOR3 v6( 2.0f, 2.0f, 3.0f );
	D3DXVECTOR3 vResult;
	float fNormalize;
	
	D3DXVec3Normalize( &vResult, &v6 );
	printf( "�������� : %f %f %f \n", vResult.x, vResult.y, vResult.z );
	fNormalize = D3DXVec3Length( &vResult );
	printf( "ũ�� : %f \n", fNormalize );

	return 0;
}

