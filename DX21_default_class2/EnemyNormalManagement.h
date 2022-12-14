//=======================================
// 普通の敵の管理関係(ヘッダファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MANAGEMENT_H_
#define _ENEMY_NORMAL_MANAGEMENT_H_

#include "main.h"
#include "EnemyNormal.h"
#include "bullet.h"
#include "DrawObject.h"
#include "EnemySetPos.h"
#include "player.h"

class EnemyNormalManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int MAX_NUM = 10;			//敵の最大数
	static const int APPEARANCE_TIME = 200;	//敵の出現スピード

	//cppで初期化
	//弾
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 1;			//攻撃値
	//弾
	static const int BULLET_ATTACK = 1;		//攻撃値


private:
	//メンバ変数
	EnemyNormal* m_pEnemyNormal = nullptr;
	Bullet* m_pBullet = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;
	EnemySetPos m_pEnemySetPos;

	int m_enemy_num = 0;	//敵の数
	int m_bullet_num = 0;	//弾の数

	int m_count = 0;		//敵の出現速度

public:
	//デフォルトコンストラクタ
	EnemyNormalManagement(){
		m_pEnemyNormal = new EnemyNormal[MAX_NUM];
		m_pBullet = new Bullet[MAX_NUM];
	}	

	//引数付きコンストラクタ
	EnemyNormalManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, 
		EnemySetPos& pEnemySetPos);

	//更新処理
	void Update(const D3DXVECTOR2& PlayerPos);

	//描画処理
	void Draw(void)const;			


	//指定した敵を消す
	void DeleteEnemy(int index_num);

	//現在の敵の数を返す
	int GetEnemyNum(void)const { return m_enemy_num; }

	//指定した敵の座標を返す
	const D3DXVECTOR2& GetEnemyPos(int index_num)const { return m_pEnemyNormal[index_num].GetPos(); }

	//敵のサイズを返す
	const D3DXVECTOR2& GetEnemySize(void)const { return m_pEnemyNormal[0].GetSize(); }


	//指定した弾を消す
	void DeleteBullet(int index_num);

	//現在の弾の数を返す
	int GetBulletNum(void)const { return m_bullet_num; }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const { return m_pBullet[index_num].GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(void)const { return m_pBullet[0].GetSize(); }
};

#endif // !_ENEMY_NORMAL_MANAGEMENT_H_