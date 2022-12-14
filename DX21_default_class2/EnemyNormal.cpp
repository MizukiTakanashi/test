//=======================================
// 普通の敵関係(cppファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#include "EnemyNormal.h"

//==========================
// 定数初期化
//==========================
const float EnemyNormal::SIZE_X = 50.0f;
const float EnemyNormal::SIZE_Y = 50.0f;
const float EnemyNormal::STOP_POS_X = 800.0f;

const float EnemyNormal::SPEED = 1.5f;

//======================
// 更新処理
//======================
void EnemyNormal::Update(void)
{
	//止まる場所まで移動する
	if (GameObject::GetPos().x > STOP_POS_X) {
		GameObject::MovePos(D3DXVECTOR2(-SPEED, 0.0f));
	}

	//時間が来たら弾を作る
	if (m_bullet_count++ > BULLET_TIME) {
		m_bullet_make = true;
		m_bullet_count = 0;
	}
}
