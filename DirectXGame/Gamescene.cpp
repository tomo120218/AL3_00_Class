#include "Gamescene.h"
using namespace KamataEngine;

GameScene::~GameScene() {
	delete model_;

	// 自キャラの解放
	delete player_;
}

void GameScene::Initialize() {

	// ファイル名を指定してテキスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources/mario.jpg");

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
}

void GameScene::Update() {
	// 自キャラの更新
	player_->Update();
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

	// eDモデル描画後処理
	Model::PostDraw();
}