#include "common.h"
#include "grid.h"
#include "Cube.h"
#include "MyDirect3D.h"


static GridVertex gridvertex[44];






void GridInit()
{
#if defined(_DEBUG) || defined(DEBUG)
	int Line_Count=0;	//引いた辺の数を計測する

	for (int i = 0; i <21;)	//横の辺のラインの座標を設定
	{
		gridvertex[i].position = D3DXVECTOR3(-5, 0, -5+Line_Count);
		gridvertex[i].color = D3DCOLOR_RGBA(0, 255, 255, 255);
		i++;

		gridvertex[i].position = D3DXVECTOR3(5, 0, -5+Line_Count);
		gridvertex[i].color = D3DCOLOR_RGBA(0, 255, 255, 255);
		i++;

		Line_Count++;
		
	}

	Line_Count = 0;

	for (int i =22; i <44;)	//縦のラインを座標を設定する
	{
		gridvertex[i].position = D3DXVECTOR3(-5 + Line_Count, 0, -5 );
		gridvertex[i].color = D3DCOLOR_RGBA(0, 255, 255, 255);
		i++;

		gridvertex[i].position = D3DXVECTOR3(-5 + Line_Count, 0, 5 );
		gridvertex[i].color = D3DCOLOR_RGBA(0, 255, 255, 255);
		i++;

		Line_Count++;

	}
#endif
}

void GridUpdate()
{


}

void GridDraw()
{
#if defined(_DEBUG) || defined(DEBUG)
	LPDIRECT3DDEVICE9 p_Device=GetDevice();

	/*ワールド変換*/
	D3DXMATRIX mtxWorld;//ワールド変換行列

	D3DXMatrixIdentity(&mtxWorld);	//行列の単位化	(*1)



	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映



	p_Device->SetTexture(0, NULL);
	p_Device->SetFVF(CUBE_FVF);
	p_Device->SetRenderState(D3DRS_LIGHTING, FALSE);


	p_Device->DrawPrimitiveUP(D3DPT_LINELIST, 22, gridvertex, sizeof(GridVertex));

#endif
}
