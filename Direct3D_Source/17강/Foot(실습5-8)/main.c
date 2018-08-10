#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "Screen.h"

typedef enum _GAME_STATE { INIT, READY, RUNNING, STOP, SUCCESS, FAILED, RESULT } GAME_STATE;
                                
GAME_STATE g_GameState = INIT;
int g_nGoal, g_nStage, g_GameStartTime;

char g_strMessage[100]; // ���� ���¸� �����ϴ� ���ڿ�
clock_t g_OldTime; // ���� ���� ���̸� ���� ���� �ð� ����

void Init()
{       
	g_OldTime = clock();
}

void Update()
{
	clock_t CurTime = clock();	

	switch( g_GameState )
	{
	case INIT :
				if( g_nStage == 0 )
				{
					sprintf( g_strMessage, "%s", "���� �� ���� �ʱ�ȭ" );
					if( CurTime - g_OldTime > 3000 )
					{
						g_OldTime = CurTime;
						g_nStage = 1;
					}
				}else{
					sprintf( g_strMessage, "[INIT] ���� %d �������� �ʱ�ȭ", g_nStage );
					if( CurTime - g_OldTime > 3000 )
					{
						g_OldTime = CurTime;
						g_GameState = READY;
					}
				}
				break;
	case READY :	
				sprintf( g_strMessage, "[READY] %d ��������", g_nStage );
				if( CurTime - g_OldTime > 3000 )
				{
					g_OldTime = CurTime;
					g_GameState = RUNNING;
					g_GameStartTime = CurTime;
				}
				break;
	case RUNNING :				
				if( CurTime - g_GameStartTime > 10000 ) // Note: ���� �ð�
				{
					g_GameState = STOP;					
				}else{			
					sprintf( g_strMessage, "[RUNNING] ���� �ð� : 10��  ����ð� : %d", 
														 ( CurTime - g_GameStartTime ) / 1000 );				
				}		
				break;
	case STOP :				
				if( g_nGoal == 1 )
					g_GameState = SUCCESS;
				else
				    g_GameState = FAILED;	
				break;
	case SUCCESS :
				sprintf( g_strMessage, "%s", "�̼� ����" );
				if( CurTime - g_OldTime > 3000 )
				{
					g_OldTime = CurTime;
					g_GameState = INIT;
					++g_nStage;					
				}
				break;
	case FAILED :
				sprintf( g_strMessage, "%s", "�̼� ����! ��� �Ͻðڽ��ϱ�? <y/n> " );
				break;

	case RESULT: 
				sprintf( g_strMessage, "%s", "���� ��� ȭ��" );
				if( CurTime - g_OldTime > 3000 )
				{
					g_OldTime = CurTime;								
				}				
				break;
	}
}

void Render()
{	
	 clock_t CurTime = clock();
	 
     ScreenClear();

     // Note: ������ ����	
	 ScreenPrint( 20, 10, g_strMessage );
			 
	 // Note: ������ �� 
	 ScreenFlipping();
}

void Release()
{
}

int main(void)
{
	int nKey;

    ScreenInit();
    Init();        // �ʱ�ȭ
         
    while( 1 )
    { 
		if( g_GameState == RESULT )
			return ;

		if( _kbhit() )
		{
			nKey = _getch();

			if( nKey == 'q' )
			   break;

			switch( nKey )
            {
             case 's' : 
                        g_nGoal = 1;
                        break;
             case 'f' :
   	                    g_nGoal = 0;
                        break;
			 case 'y' :
			 case 'Y' :
						if( g_GameState == FAILED ) 
						{
							g_GameState = INIT;
							g_OldTime = clock();
						}
						break;
			 case 'n' :
			 case 'N' :
						if( g_GameState == FAILED )
						{
							g_GameState = RESULT;
							g_OldTime = clock();
						}
						break;
            } 
		}

        Update();    // ������ ����
        Render();    // ȭ�� ���		
    }
     
    Release();   // ����
    ScreenRelease();
    return 0;
}
