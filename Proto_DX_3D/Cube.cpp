#include "Cube.h"
#include "Sprite.h"
#include "MyDirect3D.h"
#include "common.h"
#include "input.h"
#include "MyTex.h"


static const CubeVertex cv[]=
{
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0)},//手前側面１左上
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255), D3DXVECTOR2(0.25f,0.25f) },//手前側面１右下
	{D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0.25f) },//手前側面１左下
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0) },//手前側面１左上２
	{D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0) },//手前側面１右上２
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//手前側面１右下２

	{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f) },//右側面左上
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//右側面右下
{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//右側面左下
{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f) },//右側面2左上
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f) },//右側面2右上
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f) },//右側面2右下

{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.0f) },//左側面右上
{ D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.25f) },//左側面右下
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//左側面左下
{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f) },//左側面2右上
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//左側面2左下
{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f) },//左側面左上

{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f) },//奥側面１左上
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.25f) },//奥側面１左下
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(1,0.25f) },//奥側面１右下
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(1,0.0f) },//奥側面１右上２
{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.0f) },//奥側面１左上２
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(1,0.25f) },//奥側面１右下２

{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f) },//天井奥左上
{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.5f) },//天井手前右下
{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.5f) },//天井手前左下
{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f) },//天井奥左上
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.25f) },//天井奥右上
{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.5f) },//天井手前右下

{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.5f) },//底奥左下
{ D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//底手前左上
{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.5f) },//底手前右下
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//底奥左上
{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f) },//底手前右上
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.5f) },//底奥右下


};



static const CubeVertex gv[] = {
	{D3DXVECTOR3(-10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//左奥
	{D3DXVECTOR3(10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//右手前
	{D3DXVECTOR3(-10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//左手前

{ D3DXVECTOR3(-10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//左奥
{ D3DXVECTOR3(10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//右奥
{ D3DXVECTOR3(10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//右手前

};

/*回転用*/
static float angleY;
static float angleX;


/*外周ループ用*/
static D3DXVECTOR3 RunPosition;
static int RunVector;//0手前　1左　2奥　3右


/*拡大用*/
static D3DXVECTOR3 ScalingPosition;
static D3DXVECTOR3 Scaling;
static bool bScaling;

/*積み重なるやつ*/
static int CubeCount;
static D3DXVECTOR3 FallCubePosition1;
static D3DXVECTOR3 FallCubePosition2;
static D3DXVECTOR3 FallCubePosition3;
static D3DXVECTOR3 FallCubePosition4;
static D3DXVECTOR3 FallCubePosition5;

/*さいころ*/
static bool Movement;
static int DiceVector;	//1:前進 2：右へ　3：左へ　4：後退
static D3DXVECTOR3 DicePosition;
static float DiceAngleX;
static float DiceAngleZ;


static int CubeTexture;


void CubeInit()
{
	CubeTexture=Texture_SetLoadFile("Asset\\石垣.jpg",1024,1024);
	Texture_Load();


	/*回転*/
	angleY = 0.0f;
	angleX = 0.0f;

	/*外周ループ*/
	RunPosition = { 4.5f, 0.5f, -4.5f };
	RunVector = 0;

	/*拡大*/
	ScalingPosition = { 4.5f,0.5f,4.5f };
	bScaling = false;/*false：拡大　true:縮小*/

	/*積み重なるやつ*/
	CubeCount = 0;
	FallCubePosition1 = { -4.5f,10,4.5f };
	FallCubePosition2 = { -4.5f,10,4.5f };
	FallCubePosition3 = { -4.5f,10,4.5f };
	FallCubePosition4 = { -4.5f,10,4.5f };
	FallCubePosition5 = { -4.5f,10,4.5f };


	/*さいころ*/
	Movement = true;	//false:移動中 true:移動済み
	DicePosition.x = 0;
	DicePosition.y = 0.5f;
	DicePosition.z = 0;
	DiceAngleX=0;
}

void CubeUpdate()
{
	/*回転するやつ*/
		angleY += 0.01f;
	

	/*外周走るやつ*/
	if (RunVector==0)	//手前移動
	{
		RunPosition.x -= 0.1;
		if (RunPosition.x <= -4.5)
		{
			RunVector = 1;
		}
	}
	else if (RunVector == 1)	//左辺移動
	{
		RunPosition.z += 0.1;
		if (RunPosition.z >= 4.5)
		{
			RunVector = 2;
		}
	}
	else if (RunVector == 2)	//右辺
	{
		RunPosition.x += 0.1;
		if (RunPosition.x >= 4.5)
		{
			RunVector = 3;
		}
	}
	else if (RunVector == 3)
	{
		RunPosition.z -= 0.1;
		if (RunPosition.z <= -4.5)
		{
			RunVector = 0;
		}
	}



	/*拡大するやつ*/
	if (!bScaling)
	{
		Scaling.x += 0.05;
		Scaling.z += 0.05;
		
		if (Scaling.x >= 3 && Scaling.z >= 3)
		{
			bScaling = true;
		}
	}
	else
	{
		Scaling.x -= 0.05;
		Scaling.z -= 0.05;
		if (Scaling.x <= 1 && Scaling.z <= 1)
		{
			bScaling = false;
		}
	}


	/*積み重なるやつ*/
	if (CubeCount == 0)
	{
		if (FallCubePosition1.y > 0.5)
		{
			FallCubePosition1.y -= 0.5f;
		}
		else
		{
			CubeCount = 1;
		}
	}
	else if (CubeCount == 1)
	{
		if (FallCubePosition2.y > 1.5)
		{
			FallCubePosition2.y -= 0.5f;
		}
		else
		{
			CubeCount =2;
		}
	}
	else if (CubeCount == 2)
	{
		if (FallCubePosition3.y > 2.5)
		{
			FallCubePosition3.y -= 0.5f;
		}
		else
		{
			CubeCount =3;
		}
	}
	else if (CubeCount == 3)
	{
		if (FallCubePosition4.y > 3.5)
		{
			FallCubePosition4.y -= 0.5f;
		}
		else
		{
			CubeCount =4;
		}
	}
	else if (CubeCount == 4)
	{
		if (FallCubePosition5.y > 4.5)
		{
			FallCubePosition5.y -= 0.5f;
		}
		else
		{
			CubeCount = 0;
			FallCubePosition1 = { -4.5f,10,4.5f };
			FallCubePosition2 = { -4.5f,10,4.5f };
			FallCubePosition3 = { -4.5f,10,4.5f };
			FallCubePosition4 = { -4.5f,10,4.5f };
			FallCubePosition5 = { -4.5f,10,4.5f };
		}
	}



	/*さいころ*/
	if (Keyboard_IsPress(DIK_W)&&Movement)
	{
		DiceVector = 1;	//前進
		Movement = false;
	}
	if (Keyboard_IsPress(DIK_S) && Movement)
	{
		DiceVector = 4;	//後退
		Movement = false;
	}
	if (Keyboard_IsPress(DIK_A) && Movement)
	{
		DiceVector = 3;	//左
		Movement = false;
	}
	if (Keyboard_IsPress(DIK_D) && Movement)
	{
		DiceVector = 2;	//右
		Movement = false;
	}

}

void CubeDraw(/*const D3DXMATRIX *pMatrix*/)
{
	LPDIRECT3DDEVICE9	p_Device = GetDevice();	//デバイス取得
	
	
	/*ワールド変換*/
	D3DXMATRIX mtxWorld,mtxRotationX,mtxRotationY,mtxTranslation,mtxScaling,mtxScalingPosition,mtxScalingPosition2,mtxDiceRotation;//ワールド変換行列・回転行列・平行移動行列
	

	D3DXMatrixIdentity(&mtxWorld);	//行列の単位化	(*1)


	D3DXMatrixRotationY(&mtxRotationY, angleY);	//回転させる
	D3DXMatrixRotationX(&mtxRotationX, angleX);	//回転させる
	D3DXMatrixTranslation(&mtxTranslation, 0, 0.5f, 0);//ワールド座標を更新

	
	mtxWorld = mtxTranslation * mtxRotationX*mtxRotationY;	//合成の順番に注意

	
	
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映




	ReSetSamplerState();
	p_Device->SetFVF(CUBE_FVF);
	p_Device->SetTexture(0, Texture_GetTexture(CubeTexture));	//テクスチャ
	p_Device->SetRenderState(D3DRS_LIGHTING,TRUE);	//Value値をtrueにすることでライティングを行う
	


	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));	//キューブ出力


	/*外周走るキューブ*/
	D3DXMatrixTranslation(&mtxTranslation, RunPosition.x,RunPosition.y,RunPosition.z);//ワールド座標を更新
	mtxWorld = mtxTranslation ;	//合成の順番に注意
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	

	
	/*左下で回転するキューブ*/
	D3DXMatrixTranslation(&mtxTranslation, -4.5f, 0.5f,-4.5f);//ワールド座標を更新
	mtxWorld = mtxRotationY*mtxTranslation ;	//合成の順番に注意
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));


	/*右上で3倍まで拡大縮小する*/
	D3DXMatrixTranslation(&mtxScalingPosition, -0.5f, 0.5, -0.5f);//ワールド座標を更新
	D3DXMatrixTranslation(&mtxScalingPosition2, 0.5f, -0.5, 0.5f);//ワールド座標を更新
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);
	D3DXMatrixTranslation(&mtxTranslation, ScalingPosition.x, ScalingPosition.y, ScalingPosition.z);//ワールド座標を
	mtxWorld = mtxScalingPosition*mtxScaling*mtxScalingPosition2*mtxTranslation ;	//合成の順番に注意

	//mtxWorld *= mtxTranslation;	//合成の順番に注意
	
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));


	/*積み重なるやつ*/
	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition1.x, FallCubePosition1.y, FallCubePosition1.z);//ワールド座標を更新
	mtxWorld = mtxTranslation ;	//合成の順番に注意
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition2.x, FallCubePosition2.y, FallCubePosition2.z);//ワールド座標を更新
	mtxWorld = mtxTranslation;	//合成の順番に注意
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition3.x, FallCubePosition3.y, FallCubePosition3.z);//ワールド座標を更新
	mtxWorld = mtxTranslation;	//合成の順番に注意
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition4.x, FallCubePosition4.y, FallCubePosition4.z);//ワールド座標を更新
	mtxWorld = mtxTranslation;	//合成の順番に注意
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	
	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition5.x, FallCubePosition5.y, FallCubePosition5.z);//ワールド座標を更新
	mtxWorld = mtxTranslation;	//合成の順番に注意
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));





	/*さいころ*/
	D3DXMatrixTranslation(&mtxTranslation, -DicePosition.x, DicePosition.y, DicePosition.z);//さいころの座標

	if (DiceVector == 1&&!Movement)	//前進
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);//ワールド座標を更新
		D3DXMatrixTranslation(&mtxScalingPosition, 0, 0.5, -0.5f);//ワールド座標を更新
		D3DXMatrixTranslation(&mtxScalingPosition2, 0, -0.5, 0.5f);//ワールド座標を更新
		D3DXMatrixRotationX(&mtxDiceRotation, D3DXToRadian(DiceAngleX));	//回転させる
		DicePosition.z += 0.015f;
		DiceAngleX++;
		DicePosition.z += 0.01f;
		if (DiceAngleX >= 90)
		{
			DiceAngleX = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//合成の順番に注意
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 2&&!Movement)	//右
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, -0.5f, 0.5, 0);//ワールド座標を更新
		D3DXMatrixTranslation(&mtxScalingPosition2, -0.5f, -0.5, 0);//ワールド座標を更新
		D3DXMatrixRotationX(&mtxDiceRotation, D3DXToRadian(DiceAngleZ));	//回転させる
		DicePosition.x += 0.015f;
		DiceAngleZ++;
		if (DiceAngleZ >= 90)
		{
			DiceAngleZ = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//合成の順番に注意
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 3 && !Movement)	//左
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, 0.5f, 0.5, 0);//ワールド座標を更新
		D3DXMatrixTranslation(&mtxScalingPosition2, 0.5f, -0.5, 0);//ワールド座標を更新
		D3DXMatrixRotationX(&mtxDiceRotation, -D3DXToRadian (DiceAngleZ));	//回転させる
		DicePosition.x -= 0.015f;
		DiceAngleZ++;
		if (DiceAngleZ >= 90)
		{
			DiceAngleZ = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//合成の順番に注意
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 4 && !Movement)	//後退
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, 0, 0.5, 0.5f);//ワールド座標を更新
		D3DXMatrixTranslation(&mtxScalingPosition2, 0, -0.5, 0.5f);//ワールド座標を更新
		D3DXMatrixRotationX(&mtxDiceRotation, -D3DXToRadian(DiceAngleX));	//回転させる
		DicePosition.z -= 0.015f;
		DiceAngleX++;
		if (DiceAngleX >= 90)
		{
			DiceAngleX = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//合成の順番に注意
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));

	}
	else
	{
		mtxWorld = mtxTranslation;	//合成の順番に注意
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//単位化した行列を反映
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	





	

	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, gv, sizeof(CubeVertex));


}

void CubeUnInit()
{

}