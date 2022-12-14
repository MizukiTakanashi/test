//=======================================
// プレイヤーHP関係(cppファイル)
// 作成日：2022/09/17
// 作成者：高梨水希
//=======================================
#include "PlayerHP.h"

//==========================
// 定数初期化
//==========================
const float PlayerHP::HP_MAX = 5.0f;
const float PlayerHP::SIZE_X = 200.0f;
const float PlayerHP::SIZE_Y = 25.0f;
const float PlayerHP::FLAME_SIZE_X = 205.0f;
const float PlayerHP::FLAME_SIZE_Y = 30.0f;
const float PlayerHP::POS_SPACE_X = 20.0f;
const float PlayerHP::POS_SPACE_Y = 20.0f;
const float PlayerHP::POS_X = (PlayerHP::SIZE_X / 2 + PlayerHP::POS_SPACE_X);
const float PlayerHP::POS_Y = (PlayerHP::SIZE_Y / 2 + PlayerHP::POS_SPACE_Y);

//==========================
// HPを減らす
//==========================
void PlayerHP::ReduceHP(float reduce_num)
{
	m_hp -= reduce_num;

	//もしもHPが0であれば
	if (m_hp <= 0) {
		m_hp = 0;
		m_HP0 = true;
		return;
	}

	//HPバーのサイズ、位置の変更
	float tempXsize = SIZE_X * (m_hp / HP_MAX);
	UI::SetSize(D3DXVECTOR2(tempXsize, SIZE_Y));
	UI::SetPos(D3DXVECTOR2(tempXsize / 2 + POS_SPACE_X, POS_Y));
}

//==========================
// 描画処理
//==========================
void PlayerHP::DrawHP(void)const
{
	if (!m_HP0) {
		//HPバーを描画
		UI::Draw();
	}

	//フレームを描画
	m_frame_DrawObject.Draw(D3DXVECTOR2(POS_X, POS_Y), D3DXVECTOR2(FLAME_SIZE_X, FLAME_SIZE_Y));
}