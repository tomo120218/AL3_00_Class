#include "Skydome.h"

void SkyDome::Initialize(KamataEngine::Model* model, uint32_t textureHandle, KamataEngine::Camera* camera) {

	textureHandle_ = textureHandle;

	model_ = model;

	worldTransform_.Initialize();

	camera_ = camera;
}

void SkyDome::Update() { worldTransform_.TransferMatrix(); }

void SkyDome::Draw() { model_->Draw(worldTransform_, *camera_); }