#pragma once
#include "d3dapp.h"
#include <d3dx9math.h>
#include <D3dx9shape.h>

enum GAME_STATE { INIT, LOADING, READY, RUN, STOP, SUCCESS, FAILED, END };

struct PLAYER
{
	int nLife;
	D3DXVECTOR3 vPos;
	float fScale;
	float fRotationY;

	float fVelocity;
	
	// �Ѿ˿� ���� �Ӽ�	
	DWORD dwBulletFireTime;
	DWORD dwOldBulletFireTime;

	D3DXMATRIX matWorld;
	D3DXMATRIX matScale;
	D3DXMATRIX matRotationY;
	D3DXMATRIX matTranslation;	

	// ���ΰ� �浹 �ڽ�
	D3DXVECTOR3 vMin, vMax;
};

class CGameEdu01 : public CD3DApp
{
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

	D3DXMATRIX m_matView;
	D3DXMATRIX m_matProj;
	D3DXVECTOR3 m_Eye, m_At, m_Up;

	LPD3DXMESH m_pTeapotMesh; // ���ΰ�	
	LPD3DXMESH m_pPlayerBulletMesh; // ���ΰ� �Ѿ� (�����)
	LPD3DXMESH m_pEnemyBoxMesh;
	LPD3DXMESH m_pEnemyBulletMesh;

	PLAYER m_sPlayer;

	// ��Ʈ
	LPD3DXFONT m_pFont, m_pFont2, m_pFont3;

	
	DWORD m_dwElapsedTime;

	// �������� ����
	DWORD m_dwGameStartTime;
	DWORD m_dwGameElapsedTime;	

	int m_nStage;
	GAME_STATE m_nGameState;
	int m_nLoadingCount;
	int m_nGrade;
	int m_nTotalGrade;

public:
	CGameEdu01(void);
	~CGameEdu01(void);
};

