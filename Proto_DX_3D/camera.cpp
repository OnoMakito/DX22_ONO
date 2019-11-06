


#include "MyDirect3D.h"
#include "camera.h"
#include "Cube.h"


void CameraInit()
{
	
}
void CameraUpdate()
{
	

}
void CameraDraw()
{
	LPDIRECT3DDEVICE9 p_Device = GetDevice();

	/*ビュー変換行列*/
	D3DXMATRIX mtxView;
	D3DXVECTOR3 eye(2.0, 7.0f, -20.0f);	//カメラの座標
	D3DXVECTOR3 eye_at(0, 0.0f, 0.0f);	//カメラが見ている先(注視点)
	D3DXVECTOR3 eye_up(0.0f, 1.0f, 0.0f);	//カメラの上方向ベクトルを設定

	D3DXMatrixLookAtLH(&mtxView, &eye, &eye_at, &eye_up);	//カメラに移るように世界を動かす行列

	p_Device->SetTransform(D3DTS_VIEW, &mtxView);	//ビュー変換行列を反映


													/*プロジェクション変換(パースペクティヴ)*/
	D3DXMATRIX mtxProjection;
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(30),//画角の半分
		(float)SCREEN_WIDTH / SCREEN_HEIGHT,//アス比 小数になるためFloatでキャストする
		0.1f,	//near	//0よりも大きく
		100.0f//far
	);


	p_Device->SetTransform(D3DTS_PROJECTION, &mtxProjection);//パースペクティブ変換行列を反映

}
void CameraUnInit()
{

}


