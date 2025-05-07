#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include <vector>

// ゲームシーン
class GameScene {

	public:

		// テキスチャハンドル
	    uint32_t textureHandle_ = 0;

		// 3Dモデル
	    KamataEngine::Model* model_ = nullptr;
	    KamataEngine::Model* modelBlock_ = nullptr;

		// ワールドトランスフォーム
	    KamataEngine::WorldTransform worldTransform_;

		// カメラ
	    KamataEngine::Camera camera_;

		// デバックカメラ有効
	    bool isDebugCameraActive_ = false;

	    // デバックカメラ
	    KamataEngine::DebugCamera* debugCamera_ = nullptr;

		~GameScene();

		// 自キャラ
	    Player* player_ = nullptr;

		// 初期化
	    void Initialize();

		// 更新
	    void Update();

		// 描画
	    void Draw();

	    std::vector<std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;
};
