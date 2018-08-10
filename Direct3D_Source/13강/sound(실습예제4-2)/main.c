#include <stdio.h>
#include <conio.h>
#include <fmod.h>

FMOD_SYSTEM *g_System;     // FMOD system ��������
FMOD_SOUND  *g_Sound[2];   // �ΰ��� ���� ���ϰ� �����ϱ� ���� FMOD Sound
FMOD_CHANNEL *g_Channel;  

// Note: �ʱ�ȭ 
void Init()
{
	 // FMOD �ʱ�ȭ �� ���� ���� �ε�
	 FMOD_System_Create(&g_System); 
     FMOD_System_Init( g_System, 32, FMOD_INIT_NORMAL,  NULL);  	  
     FMOD_System_CreateSound( g_System, "bgsound.wav", FMOD_LOOP_NORMAL, 0, &g_Sound[0]);
	 FMOD_System_CreateSound( g_System, "safe.wav", FMOD_DEFAULT, 0, &g_Sound[1]);

	 // ����� ���
	 FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[0], 0, &g_Channel);
}

// Note: ����
void Release()
{
	int i;

	for( i =0 ; i < 2 ; i++ )
		FMOD_Sound_Release(g_Sound[i]); // FMOD sound ��ü ����
	
	FMOD_System_Close( g_System ); // FMOD system ��ü clsoe
	FMOD_System_Release( g_System ); // FMOD system ��ü ����
}


int main(void)
{
	int nKey;
	FMOD_CHANNEL *pChannel; 
	
	Init();

	printf( "���� ���\n" );

	while( 1 )
	{
		if( _kbhit() )
		{
			nKey = _getch();

			if( nKey == 's' )
				FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[1], 0, &pChannel); // ȿ���� ���
		}				

		FMOD_System_Update( g_System );
	}

	Release();	
	return 0;
}