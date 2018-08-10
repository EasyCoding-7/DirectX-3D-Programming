// FmodSound00.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <conio.h>
#include <string>
#include "FmodSound.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string strBGFileName[] = { "war.mp3", "wave.mp3" };
	string strEffectFileName = "play_fire.wav";
	int nKey;

	CFmodSound FmodSound;	
	FmodSound.CreateBGSound( 2, strBGFileName );
	FmodSound.CreateEffectSound( 1, &strEffectFileName );

	printf( "���� �ý��� �غ� �Ϸ�\n" );
	printf( "Ű 1: ���1 ���    Ű 2: ȿ���� ���  Ű 3: ����� ����   Ű q: ����\n" );

	while( 1 )
	{
		nKey = _getch();
		if( nKey == '1' )
			FmodSound.PlaySoundBG( 1 );
		if( nKey == '2' )
			FmodSound.PlaySoundEffect(0);

		if( nKey == '3' )
			FmodSound.StopSoundBG( 1 );

		if( nKey == 'q' )
			break;

		FmodSound.Update();
	}

	FmodSound.ReleaseSound();

	return 0;
}

