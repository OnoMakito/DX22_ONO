#include "Cube.h"
#include "Sprite.h"
#include "MyDirect3D.h"
#include "common.h"
#include "input.h"
#include "MyTex.h"


static const CubeVertex cv[]=
{
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0)},//��O���ʂP����
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255), D3DXVECTOR2(0.25f,0.25f) },//��O���ʂP�E��
	{D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0.25f) },//��O���ʂP����
	{D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0,0) },//��O���ʂP����Q
	{D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0) },//��O���ʂP�E��Q
	{D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,0,-1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//��O���ʂP�E���Q

	{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f) },//�E���ʍ���
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//�E���ʉE��
{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//�E���ʍ���
{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.0f) },//�E����2����
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f) },//�E����2�E��
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f) },//�E����2�E��

{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.0f) },//�����ʉE��
{ D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.25f) },//�����ʉE��
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//�����ʍ���
{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f) },//������2�E��
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.25f) },//������2����
{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(-1,0,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.0f) },//�����ʍ���

{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.0f) },//�����ʂP����
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.75f,0.25f) },//�����ʂP����
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(1,0.25f) },//�����ʂP�E��
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(1,0.0f) },//�����ʂP�E��Q
{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.75f,0.0f) },//�����ʂP����Q
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,0,1),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(1,0.25f) },//�����ʂP�E���Q

{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f) },//�V�䉜����
{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.5f) },//�V���O�E��
{ D3DXVECTOR3(-0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.5f) },//�V���O����
{ D3DXVECTOR3(-0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.0f,0.25f) },//�V�䉜����
{ D3DXVECTOR3(0.5f,0.5f,0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.25f) },//�V�䉜�E��
{ D3DXVECTOR3(0.5f,0.5f,-0.5f),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.5f) },//�V���O�E��

{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.25f,0.5f) },//�ꉜ����
{ D3DXVECTOR3(-0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//���O����
{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.5f) },//���O�E��
{ D3DXVECTOR3(-0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.25f,0.25f) },//�ꉜ����
{ D3DXVECTOR3(0.5f,-0.5f,-0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255),D3DXVECTOR2(0.5f,0.25f) },//���O�E��
{ D3DXVECTOR3(0.5f,-0.5f,0.5f),D3DXVECTOR3(0,-1,0),D3DCOLOR_RGBA(255,255,255,255) ,D3DXVECTOR2(0.5f,0.5f) },//�ꉜ�E��


};



static const CubeVertex gv[] = {
	{D3DXVECTOR3(-10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//����
	{D3DXVECTOR3(10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//�E��O
	{D3DXVECTOR3(-10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255)},//����O

{ D3DXVECTOR3(-10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//����
{ D3DXVECTOR3(10,-2.0,10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//�E��
{ D3DXVECTOR3(10,-2.0,-10),D3DXVECTOR3(0,1,0),D3DCOLOR_RGBA(100,100,0,255) },//�E��O

};

/*��]�p*/
static float angleY;
static float angleX;


/*�O�����[�v�p*/
static D3DXVECTOR3 RunPosition;
static int RunVector;//0��O�@1���@2���@3�E


/*�g��p*/
static D3DXVECTOR3 ScalingPosition;
static D3DXVECTOR3 Scaling;
static bool bScaling;

/*�ςݏd�Ȃ���*/
static int CubeCount;
static D3DXVECTOR3 FallCubePosition1;
static D3DXVECTOR3 FallCubePosition2;
static D3DXVECTOR3 FallCubePosition3;
static D3DXVECTOR3 FallCubePosition4;
static D3DXVECTOR3 FallCubePosition5;

/*��������*/
static bool Movement;
static int DiceVector;	//1:�O�i 2�F�E�ց@3�F���ց@4�F���
static D3DXVECTOR3 DicePosition;
static float DiceAngleX;
static float DiceAngleZ;


static int CubeTexture;


void CubeInit()
{
	CubeTexture=Texture_SetLoadFile("Asset\\�Ί_.jpg",1024,1024);
	Texture_Load();


	/*��]*/
	angleY = 0.0f;
	angleX = 0.0f;

	/*�O�����[�v*/
	RunPosition = { 4.5f, 0.5f, -4.5f };
	RunVector = 0;

	/*�g��*/
	ScalingPosition = { 4.5f,0.5f,4.5f };
	bScaling = false;/*false�F�g��@true:�k��*/

	/*�ςݏd�Ȃ���*/
	CubeCount = 0;
	FallCubePosition1 = { -4.5f,10,4.5f };
	FallCubePosition2 = { -4.5f,10,4.5f };
	FallCubePosition3 = { -4.5f,10,4.5f };
	FallCubePosition4 = { -4.5f,10,4.5f };
	FallCubePosition5 = { -4.5f,10,4.5f };


	/*��������*/
	Movement = true;	//false:�ړ��� true:�ړ��ς�
	DicePosition.x = 0;
	DicePosition.y = 0.5f;
	DicePosition.z = 0;
	DiceAngleX=0;
}

void CubeUpdate()
{
	/*��]������*/
		angleY += 0.01f;
	

	/*�O��������*/
	if (RunVector==0)	//��O�ړ�
	{
		RunPosition.x -= 0.1;
		if (RunPosition.x <= -4.5)
		{
			RunVector = 1;
		}
	}
	else if (RunVector == 1)	//���ӈړ�
	{
		RunPosition.z += 0.1;
		if (RunPosition.z >= 4.5)
		{
			RunVector = 2;
		}
	}
	else if (RunVector == 2)	//�E��
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



	/*�g�傷����*/
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


	/*�ςݏd�Ȃ���*/
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



	/*��������*/
	if (Keyboard_IsPress(DIK_W)&&Movement)
	{
		DiceVector = 1;	//�O�i
		Movement = false;
	}
	if (Keyboard_IsPress(DIK_S) && Movement)
	{
		DiceVector = 4;	//���
		Movement = false;
	}
	if (Keyboard_IsPress(DIK_A) && Movement)
	{
		DiceVector = 3;	//��
		Movement = false;
	}
	if (Keyboard_IsPress(DIK_D) && Movement)
	{
		DiceVector = 2;	//�E
		Movement = false;
	}

}

void CubeDraw(/*const D3DXMATRIX *pMatrix*/)
{
	LPDIRECT3DDEVICE9	p_Device = GetDevice();	//�f�o�C�X�擾
	
	
	/*���[���h�ϊ�*/
	D3DXMATRIX mtxWorld,mtxRotationX,mtxRotationY,mtxTranslation,mtxScaling,mtxScalingPosition,mtxScalingPosition2,mtxDiceRotation;//���[���h�ϊ��s��E��]�s��E���s�ړ��s��
	

	D3DXMatrixIdentity(&mtxWorld);	//�s��̒P�ʉ�	(*1)


	D3DXMatrixRotationY(&mtxRotationY, angleY);	//��]������
	D3DXMatrixRotationX(&mtxRotationX, angleX);	//��]������
	D3DXMatrixTranslation(&mtxTranslation, 0, 0.5f, 0);//���[���h���W���X�V

	
	mtxWorld = mtxTranslation * mtxRotationX*mtxRotationY;	//�����̏��Ԃɒ���

	
	
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f




	ReSetSamplerState();
	p_Device->SetFVF(CUBE_FVF);
	p_Device->SetTexture(0, Texture_GetTexture(CubeTexture));	//�e�N�X�`��
	p_Device->SetRenderState(D3DRS_LIGHTING,TRUE);	//Value�l��true�ɂ��邱�ƂŃ��C�e�B���O���s��
	


	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));	//�L���[�u�o��


	/*�O������L���[�u*/
	D3DXMatrixTranslation(&mtxTranslation, RunPosition.x,RunPosition.y,RunPosition.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation ;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	

	
	/*�����ŉ�]����L���[�u*/
	D3DXMatrixTranslation(&mtxTranslation, -4.5f, 0.5f,-4.5f);//���[���h���W���X�V
	mtxWorld = mtxRotationY*mtxTranslation ;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));


	/*�E���3�{�܂Ŋg��k������*/
	D3DXMatrixTranslation(&mtxScalingPosition, -0.5f, 0.5, -0.5f);//���[���h���W���X�V
	D3DXMatrixTranslation(&mtxScalingPosition2, 0.5f, -0.5, 0.5f);//���[���h���W���X�V
	D3DXMatrixScaling(&mtxScaling, Scaling.x, Scaling.x, Scaling.z);
	D3DXMatrixTranslation(&mtxTranslation, ScalingPosition.x, ScalingPosition.y, ScalingPosition.z);//���[���h���W��
	mtxWorld = mtxScalingPosition*mtxScaling*mtxScalingPosition2*mtxTranslation ;	//�����̏��Ԃɒ���

	//mtxWorld *= mtxTranslation;	//�����̏��Ԃɒ���
	
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));


	/*�ςݏd�Ȃ���*/
	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition1.x, FallCubePosition1.y, FallCubePosition1.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation ;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition2.x, FallCubePosition2.y, FallCubePosition2.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition3.x, FallCubePosition3.y, FallCubePosition3.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));

	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition4.x, FallCubePosition4.y, FallCubePosition4.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	
	D3DXMatrixTranslation(&mtxTranslation, FallCubePosition5.x, FallCubePosition5.y, FallCubePosition5.z);//���[���h���W���X�V
	mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
	p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
	p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));





	/*��������*/
	D3DXMatrixTranslation(&mtxTranslation, -DicePosition.x, DicePosition.y, DicePosition.z);//��������̍��W

	if (DiceVector == 1&&!Movement)	//�O�i
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition, 0, 0.5, -0.5f);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition2, 0, -0.5, 0.5f);//���[���h���W���X�V
		D3DXMatrixRotationX(&mtxDiceRotation, D3DXToRadian(DiceAngleX));	//��]������
		DicePosition.z += 0.015f;
		DiceAngleX++;
		DicePosition.z += 0.01f;
		if (DiceAngleX >= 90)
		{
			DiceAngleX = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 2&&!Movement)	//�E
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, -0.5f, 0.5, 0);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition2, -0.5f, -0.5, 0);//���[���h���W���X�V
		D3DXMatrixRotationX(&mtxDiceRotation, D3DXToRadian(DiceAngleZ));	//��]������
		DicePosition.x += 0.015f;
		DiceAngleZ++;
		if (DiceAngleZ >= 90)
		{
			DiceAngleZ = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 3 && !Movement)	//��
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, 0.5f, 0.5, 0);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition2, 0.5f, -0.5, 0);//���[���h���W���X�V
		D3DXMatrixRotationX(&mtxDiceRotation, -D3DXToRadian (DiceAngleZ));	//��]������
		DicePosition.x -= 0.015f;
		DiceAngleZ++;
		if (DiceAngleZ >= 90)
		{
			DiceAngleZ = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	if (DiceVector == 4 && !Movement)	//���
	{
		D3DXMatrixTranslation(&mtxTranslation, DicePosition.x, DicePosition.y, DicePosition.z);
		D3DXMatrixTranslation(&mtxScalingPosition, 0, 0.5, 0.5f);//���[���h���W���X�V
		D3DXMatrixTranslation(&mtxScalingPosition2, 0, -0.5, 0.5f);//���[���h���W���X�V
		D3DXMatrixRotationX(&mtxDiceRotation, -D3DXToRadian(DiceAngleX));	//��]������
		DicePosition.z -= 0.015f;
		DiceAngleX++;
		if (DiceAngleX >= 90)
		{
			DiceAngleX = 0;
			Movement = true;
		}
		mtxWorld = mtxScalingPosition * mtxDiceRotation*mtxScalingPosition2*mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));

	}
	else
	{
		mtxWorld = mtxTranslation;	//�����̏��Ԃɒ���
		p_Device->SetTransform(D3DTS_WORLD, &mtxWorld);//�P�ʉ������s��𔽉f
		p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, cv, sizeof(CubeVertex));
	}
	





	

	//p_Device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, gv, sizeof(CubeVertex));


}

void CubeUnInit()
{

}