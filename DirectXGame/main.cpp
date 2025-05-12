#include "Gamescene.h"
#include "KamataEngine.h"
#include <Windows.h>
using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize(L"LE2D_18_ビョウドウ_トモヒロ_AL3");

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	GameScene* gameScene = new GameScene();

	gameScene->Intialize();

	// エンジンの更新
	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		// ゲームシーンの初期化
		gameScene->Update();
		// 描画開始
		dxCommon->PreDraw();
		// ゲームシーンの描画
		gameScene->Draw();
		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの開放
	delete gameScene;
	// nullptrの代入
	gameScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}