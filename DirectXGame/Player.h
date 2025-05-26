#pragma once
#include "KamataEngine.h"
#include <vector>

using namespace KamataEngine;

// 自キャラ
class Player {
private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	Camera* camera_ = nullptr;
	uint32_t textureHandle_ = 0u;

	std::vector<std::vector<WorldTransform*>> worldTransformPlayer_;

	Vector3 velocity_ = {};

	static inline const float kAcceleration = 0.1f;
	static inline const float kAttenuation = 0.1f;
	static inline const float kLimitRunSpeed = 0.5f;
	static inline const float kTimerTurn = 0.3f;

	enum class LRDirection {
		kRight,
		kLeft,
	};
	LRDirection lrDirection_ = LRDirection::kRight;

	// 旋回開始時の角度
	float turnFirstRotationY_ = 0.8f;

	// 旋回タイマー
	float turnTimer_ = 0.0f;

	// 接地状態フラグ
	bool onGround_ = true;

	// 重力加速度(下方向)
	static inline const float kDravityAccleratyion = 0.1f;

	// 最大落下速度(下方向)
	static inline const float kLimitFallSpeed = 0.5f;

	// ジャンプ初速(上方向)
	static inline const float kJumpAccleration = 0.5f;

public:
	// 初期化
	void Initialize(Model* model, Camera* camera, const Vector3& position);
	// 更新
	void Update();
	// 描画
	void Draw();
};