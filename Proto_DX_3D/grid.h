#pragma once

#ifndef GRID_H
#define GRID_H

#include <d3d9.h>
#include <d3dx9.h>

typedef struct GridVertex_tag
{
	D3DXVECTOR3 position;
	D3DCOLOR color;
}GridVertex;
/*
44頂点をLINELISTで描画
1マス1*1
10*10マス
中央をx,y,z=0.0.0に合わせる

DrawPrimitiveUp一回で描画

ワールド変換行列は単位行列

ビュー行列と往路じぇくしょん行列は今後キューブやグリッドなどで共通になるからCamera.hを作成する・


*/



void GridInit(void);

void GridUpdate(void);

void GridDraw(void);




#endif