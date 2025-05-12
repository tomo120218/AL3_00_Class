#pragma once
#include "MyMath.h"
#include "Player.h"
#include "SkyDome.h"
#include <KamataEngine.h>
#include <vector>

class GameScene {
public:
	~GameScene();
	// 初期化
	void Intialize();
	// 更新
	void Update();
	// 描画
	void Draw();

private:
	uint32_t textureHandle_ = 0;

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Model* modelBlock_ = nullptr;

	KamataEngine::Camera camera_;

	Player* player_ = nullptr;

	SkyDome* skydome_ = nullptr;

	KamataEngine::Model* modelSkydome_ = nullptr;

	std::vector<std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;

	// デバックカメラ有効
	bool isDebugCameraActive_ = false;

	// デバックカメラ
	KamataEngine::DebugCamera* debugCamera_ = nullptr;
};