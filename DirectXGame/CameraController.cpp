#include "CameraController.h"
#include "Player.h"

using namespace KamataEngine;
using namespace MathUtility;

void CameraController::Initialize() { camera_; }

void CameraController::Update() {}

void CameraController::Reset() {

	// 追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	// 追従対象とオフセットからからカメラの座標計算
	camera_.translation_ = targetWorldTransform.translation_ + targetOffset_;
	// 行列を更新
	camera_.UpdateMatrix();
}