#include "common.h"
#include "MyDirect3D.h"
#include "Light.h"
#include "d3d9.h"
#include "d3dx9.h"



static D3DLIGHT9 Light = {};//初期化



void LightInit()
{
	LPDIRECT3DDEVICE9 p_Device;
	p_Device = GetDevice();


	Light.Type = D3DLIGHT_DIRECTIONAL;

	D3DXVECTOR3 vecDirLight(-1.0f, -1.0f, 1.0f);	//単位ベクトルにする(光の方向)


//D3DXVec3Normalize(&vecDirLight,&vecDirLight);//正規化を行う (出力,入力)
//Light.Direction = vecDirLight;
	D3DXVec3Normalize((D3DXVECTOR3*)&Light.Direction, &vecDirLight);//上２行を一行に集約


	/*ライトカラー*/
	Light.Diffuse.r = 1.0f;
	Light.Diffuse.g = 1.0f;
	Light.Diffuse.b = 1.0f;
	Light.Diffuse.a = 0.0f;//aは無視される?


	p_Device->SetLight(0, &Light);	//ライトのスロット番号,ライトの設定情報	(光を動的に操作する場合毎フレームセットする必要がある)

	p_Device->LightEnable(0, TRUE);	//ライトのスロット番号,ライトのON/OFF

	p_Device->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);	//強制的に正規化するのかどうか
	
	/*アンビエントの設定*/
	p_Device->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(100, 100, 70));	//アンビエントカラー
	p_Device->SetRenderState(D3DRS_AMBIENTMATERIALSOURCE, D3DMCS_COLOR1);	
	
	//色＝アンビエントマテリアル*アンビエントライト+ディレクショナルライト*ディヒューズマテリアル
	//光の色彩はこのように設定される。(光を当てすぎると白に近づいてしまうため注意)
	/*カメラとは真逆の方向に光を当てることでオブジェクトに輪郭が発生する*/



	p_Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);//(DIFFUSEMATERIAL)マテリアルは頂点カラーで指定する
}


void LightUpdate()
{

}


void LightDraw()
{

}

void LightUnInit()
{

}