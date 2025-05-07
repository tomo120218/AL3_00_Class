#include "Gamescene.h"
#include "MyMath.h"
using namespace KamataEngine;

GameScene::~GameScene() {
	delete model_;
	delete modelBlock_;

	// 自キャラの解放
	delete player_;

	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			delete worldTransformBlock;
		}
	}
	worldTransformBlocks_.clear();

	delete debugCamera_;

}

void GameScene::Initialize() {

	// ファイル名を指定してテキスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources/mario.jpg");

	// モデル読み込み
	modelBlock_ = Model::CreateFromOBJ("cube");

	// 3Dモデルの生成
	model_ = Model::Create();

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	// カメラの初期化
	camera_.Initialize();

	// 自キャラの生成
	player_ = new Player();

	// 自キャラの初期化
	player_->Initialize(model_, textureHandle_, &camera_);

	// 要素数
	const uint32_t kNumBlockHorizontal = 20;
	const uint32_t kNumBlockVirtcal = 10;

	// 要素数を変更する
	worldTransformBlocks_.resize(kNumBlockHorizontal);

	// ブロック１個分の横幅
	const float kBlockWidth = 2.0f;
	const float kBlockHeight = 2.0f;

	// 要素数を変更する
	// 列数を設定(縦方向のブロック数)
	worldTransformBlocks_.resize(kNumBlockVirtcal);
	for (uint32_t i = 0; i < kNumBlockVirtcal; ++i) {
		// 1列の要素数を設定(横方向のブロック数)
		worldTransformBlocks_[i].resize(kNumBlockHorizontal);
	}

	for (uint32_t i = 0; i < kNumBlockVirtcal; ++i) {
		for (uint32_t j = 0; j < kNumBlockHorizontal; ++j) {
			if (j % 2 == 0)
				continue;
			worldTransformBlocks_[i][j] = new WorldTransform();
			worldTransformBlocks_[i][j]->Initialize();
			worldTransformBlocks_[i][j]->translation_.x = kBlockWidth* j;
			worldTransformBlocks_[i][j]->translation_.y = kBlockHeight* i;
		}
	}

	// デバックカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);
}

void GameScene::Update() {
	// 自キャラの更新
	player_->Update();

	// ブロックの更新
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			if (!worldTransformBlock)
				continue;

			// アフィン変換行列の作成
			worldTransformBlock->matWorld_ = MakeAffineMatrix(worldTransformBlock->scale_, worldTransformBlock->rotation_, worldTransformBlock->translation_); // アフィン変換行列

			// 定数バッファに転送する
			worldTransformBlock->TransferMatrix();
		}
	}

	// デバックカメラの更新
	debugCamera_->Update();

	#ifdef _DEBUG
	// aaaaaaaa
	if (Input::GetInstance()->TriggerKey(DIK_0)) {
		isDebugCameraActive_ = !isDebugCameraActive_;
	}
	#endif

	// カメラの処理
	if (isDebugCameraActive_) {
		// デバックカメラの更新
		debugCamera_->Update();

		// デバックカメラのビュー行列
		camera_.matView = debugCamera_->GetCamera().matView;

		// デバックカメラのプロジェクション行列
		camera_.matProjection = debugCamera_->GetCamera().matProjection;

		// ビュープロジェクション行列の転送
		camera_.TransferMatrix();
	} else {
		// ビュープロジェクション行列の更新と転送
		camera_.UpdateMatrix();
	}
}

void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// 3Dモデル
	model_->Draw(worldTransform_, camera_, textureHandle_);

	// 自キャラの描画
	player_->Draw();

	// ブロックの描画
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			if (!worldTransformBlock)
				continue;

			modelBlock_->Draw(*worldTransformBlock, camera_);
		}
	}

	// eDモデル描画後処理
	Model::PostDraw();
}