#include "pch.h"
#include "LoadingScene.h"

void LoadingScene::AddLoadFunc(const function<void(void)>& func)
{
	mLoadList.push_back(func);
}

void LoadingScene::Init()
{
	if (SceneManager::GetInstance()->GetFrom() == L"Scene2") {
		for (int i = 0; i < 100; ++i) {

			AddLoadFunc([i]() {IMAGEMANAGER->LoadFromFile(L"Heart" + to_wstring(i), Resources(L"Heart.bmp"), 48, 44, true); });
		}

		AddLoadFunc([]() {SOUNDPLAYER->LoadFromFile(L"Test1", Resources(L"Test1.mp3"), true); });
	}

	if (SceneManager::GetInstance()->GetFrom() == L"Scene1") {
		for (int i = 0; i < 100; ++i) {

			AddLoadFunc([i]() {IMAGEMANAGER->LoadFromFile(L"Ball" + to_wstring(i), Resources(L"ball.bmp"), 60, 60, true); });
		}

		AddLoadFunc([]() {SOUNDPLAYER->LoadFromFile(L"Test2", Resources(L"Test2.mp3"), true); });
	}


	mLoadIndex = 0;
	mIsEndLoading = false;
}



void LoadingScene::Release()
{
}

void LoadingScene::Update()
{
	if (mLoadIndex >= mLoadList.size())
	{
		mIsEndLoading = true;

		if (Input::GetInstance()->GetKeyDown(VK_SPACE))
		{
			if (SceneManager::GetInstance()->GetFrom() == L"Scene1") {
				SceneManager::GetInstance()->LoadScene(L"Scene2");
				mLoadList.clear();
				mLoadList.shrink_to_fit();
			}

			if (SceneManager::GetInstance()->GetFrom() == L"Scene2") {

				SceneManager::GetInstance()->LoadScene(L"Scene1");
				mLoadList.clear();
				mLoadList.shrink_to_fit();
			}
		}
		return;
	}

	


	function<void(void)> func = mLoadList[mLoadIndex];
	func();
	mLoadIndex++;
}

void LoadingScene::Render(HDC hdc)
{
	RECT backGround = { 0,0, 1280, 720 };

	HBRUSH newb = (HBRUSH)GetStockObject(4);
	HBRUSH oldb = (HBRUSH)SelectObject(hdc, newb);
	RenderRect(hdc, backGround);
	SelectObject(hdc, oldb);
	DeleteObject(newb);

	wstring onLoading = L"·ÎµùÁß";
	if (mIsEndLoading) {
		onLoading = L"Press Space Key";
	}

	RECT rc = { 550, WINSIZEY/2 - 60, 730, WINSIZEY/2 - 30 };
	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc,RGB(255,255,255));
	DrawTextW(hdc, onLoading.c_str(), onLoading.size(), &rc, DT_CENTER && DT_VCENTER);


	float dd = Math::Lerp(0,1000, (float)mLoadIndex / mLoadList.size());
	progress = RectMake(140, WINSIZEY/2-25, dd ,50 );
	RenderRect(hdc, progress);
	




}
