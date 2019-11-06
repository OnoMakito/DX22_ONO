#pragma once

#ifndef CUBE_H
#define CUBE_H

#include <d3d9.h>
#include <d3dx9.h>
#include "MyTex.h"
#include "Sprite.h"

typedef struct CubeVertex_tag
{
	D3DXVECTOR3 position;
	D3DXVECTOR3 normal;	//法線(DirectXの都合上、position,normal,colorの順に定義する)	法線は単位ベクトルで入れる(XYZどれか一つが1か-1、それ以外は0)
	D3DCOLOR color;
	D3DXVECTOR2 uv;
}CubeVertex;


#define CUBE_FVF (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_NORMAL|D3DFVF_TEX1)


void CubeInit(void);

void CubeUpdate(void);

void CubeDraw(/*const D3DXMATRIX *pMatrix*/);
/*行列は外側から入れる方が綺麗に書けるかも*/

void CubeUnInit(void);

#endif