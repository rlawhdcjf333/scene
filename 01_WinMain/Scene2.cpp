#include "pch.h"
#include "Scene2.h"
#include "Image.h"

void Scene2::Init()
{
	for (int i = 0; i < 100; i++)
		mImageList.push_back(IMAGEMANAGER->FindImage(L"Ball" + to_wstring(i)));
	SoundPlayer::GetInstance()->Play(L"Test2", 0.2f);

}

void Scene2::Release()
{
	mImageList.clear();
}

void Scene2::Update()
{
	if (Input::GetInstance()->GetKeyDown(VK_SPACE)) {

		this->Release();

		SceneManager::GetInstance()->LoadScene(L"Scene1");
	}
}

void Scene2::Render(HDC hdc)
{
	wstring str = L"³ª Scene2";
	TextOut(hdc, WINSIZEX / 2, WINSIZEY / 2, str.c_str(), str.length());

	int w = 10;
	int h = 10;
	for (Image* elem : mImageList) {

		elem->ScaleRender(hdc, Random::GetInstance()->RandomInt(WINSIZEX), Random::GetInstance()->RandomInt(WINSIZEY), w, h);

		w++;
		h++;
	}




}
