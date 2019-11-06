#pragma once

#ifdef PLAYER_H
#define PALYER_H

#endif
void Player_Init(void);	//初期座標・テクスチャの準備

void Player_Update(void);	//キー入力で移動・

void Player_Draw(void);	//プレイヤーの状態を監視して描画(生存・死亡・爆発など)

void Player_Uninit(void);	//テクスチャ解放(シーン終了時に開放するなら、ここに書く必要はない。)


