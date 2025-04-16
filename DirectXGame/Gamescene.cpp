#include "Gamescene.h"
using namespace KamataEngine;

GameScene::~GameScene() { 
	delete model_; 
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
}

void GameScene::Update() {


}

void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// 3Dモデル
	model_->Draw(worldTransform_, camera_, textureHandle_);
	

	// eDモデル描画後処理
	Model::PostDraw();
}