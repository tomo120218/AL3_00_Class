#pragma once
#include "KamataEngine.h"

// ゲームシーン
class GameScene {

	public:

		// テキスチャハンドル
	    uint32_t textureHandle_ = 0;

		// 3Dモデル
	    KamataEngine::Model* model_ = nullptr;

		// ワールドトランスフォーム
	    KamataEngine::WorldTransform worldTransform_;

		// カメラ
	    KamataEngine::Camera camera_;

		~GameScene();

		// 初期化
	    void Initialize();

		// 更新
	    void Update();

		// 描画
	    void Draw();
};
