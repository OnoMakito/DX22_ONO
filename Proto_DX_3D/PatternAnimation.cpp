#include <d3d9.h>
#include <d3dx9.h>
#include "MyDirect3D.h"
#include "MyTex.h"
#include "common.h"
#include "PatternAnimation.h"
#include "Sprite.h"
#include "input.h"
#define COCO_WALK_PATTERN_MAX (13)
#define RUNNINGMAN_PATTERN_MAX (10)


void PatternAnimation_Init()
{
	Texture_Load();

}


void PatternAnimation_Draw(float dx, float dy, int FrameCount)
{
	
	int pattern = FrameCount/3%RUNNINGMAN_PATTERN_MAX;	//フレームカウンタ/待ちフレーム/パターン数
	
	


	//キャラクタ右向き描画

}







