#pragma once
#include "KamataEngine.h"

// <summary>
// 自キャラ
// </summary>
class Player {

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
	// テキスチャハンドル
	uint32_t textureHandle_ = 0u;

public:
	void Initialize();
	void Update();
	void Draw();
};
