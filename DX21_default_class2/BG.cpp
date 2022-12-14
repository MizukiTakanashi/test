/*==============================================================================

   頂点管理 [polygon.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include	"BG.h"

//==========================
// 定数の初期化
//==========================
const float BG::UV_SPEED = 0.005f;

//=========================
// 背景描画
//=========================
void BG::DrawBG()const
{
	int hoge = 255;
	//テクスチャの設定
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), m_start_uv_x, 0.0f, 1.0f, 1.0f);

	int tekitou = 0;
}
