


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

	/*�r���[�ϊ��s��*/
	D3DXMATRIX mtxView;
	D3DXVECTOR3 eye(2.0, 7.0f, -20.0f);	//�J�����̍��W
	D3DXVECTOR3 eye_at(0, 0.0f, 0.0f);	//�J���������Ă����(�����_)
	D3DXVECTOR3 eye_up(0.0f, 1.0f, 0.0f);	//�J�����̏�����x�N�g����ݒ�

	D3DXMatrixLookAtLH(&mtxView, &eye, &eye_at, &eye_up);	//�J�����Ɉڂ�悤�ɐ��E�𓮂����s��

	p_Device->SetTransform(D3DTS_VIEW, &mtxView);	//�r���[�ϊ��s��𔽉f


													/*�v���W�F�N�V�����ϊ�(�p�[�X�y�N�e�B��)*/
	D3DXMATRIX mtxProjection;
	D3DXMatrixPerspectiveFovLH(&mtxProjection, D3DXToRadian(30),//��p�̔���
		(float)SCREEN_WIDTH / SCREEN_HEIGHT,//�A�X�� �����ɂȂ邽��Float�ŃL���X�g����
		0.1f,	//near	//0�����傫��
		100.0f//far
	);


	p_Device->SetTransform(D3DTS_PROJECTION, &mtxProjection);//�p�[�X�y�N�e�B�u�ϊ��s��𔽉f

}
void CameraUnInit()
{

}


