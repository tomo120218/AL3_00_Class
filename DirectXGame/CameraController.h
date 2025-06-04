#pragma once
#include <KamataEngine.h>

class Player;

class CameraController {
public:
	void Initialize();

	void Update();

	void SetTarget(Player* target) { target_ = target; }

	void Reset();

	const KamataEngine::Camera& GetViewProjection() const { return camera_; }

private:
	KamataEngine::Camera camera_;

	Player* target_ = nullptr;

	KamataEngine::Vector3 targetOffset_ = {0, 0, -15.0f};
};