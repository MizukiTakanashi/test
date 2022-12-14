//=======================================
// リザルト画面関係(ヘッダファイル)
// 作成日：2022/09/22
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _RESULT_H_
#define _RESULT_H_

#include "texture_useful.h"
#include "DrawObject.h"
#include "UI.h"
#include "number.h"
#include "main.h"

class Result
{
//定数
private:
	//ここで初期化
	static const int NUMBER_DIGIT = 3;

	//cppで初期化
	static const D3DXVECTOR2 NUMBER_POS;
	static const D3DXVECTOR2 NUMBER_SIZE;


//メンバ変数
private:
	int m_BGM = 0;

	TextureUseful* m_pTexUse = nullptr;
	DrawObject* m_pDrawOb = nullptr;
	UI* m_pBG = nullptr;
	Number* m_pNumber = nullptr;

public:
	Result();	//デフォルトコンストラクタ

	Result(Number* pNumber);

	~Result();	//デストラクタ

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const;
};

#endif // !_RESULT_H_