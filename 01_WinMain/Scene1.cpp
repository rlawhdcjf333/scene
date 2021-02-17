#include "pch.h"
#include "Scene1.h"
#include "Image.h"

void Scene1::Init()
{
	for (int i = 0; i < 100; i++)
	mImageList.push_back(IMAGEMANAGER->FindImage(L"Heart" + to_wstring(i)));

	SoundPlayer::GetInstance()->Play(L"Test1", 0.2f);

	time = 0;

	for (int i=0; i<100; i++)
	{
		pt temp = { Random::GetInstance()->RandomInt(WINSIZEX), Random::GetInstance()->RandomInt(WINSIZEY) };
		ptList.push_back(temp);
	}
}

void Scene1::Release()
{
	mImageList.clear();
	mImageList.shrink_to_fit();
	IMAGEMANAGER->Release();
	SoundPlayer::GetInstance()->Release();
}

void Scene1::Update()
{
	if (Input::GetInstance()->GetKeyDown(VK_SPACE)) {

		

		SceneManager::GetInstance()->GetFrom() = L"Scene1";
		SceneManager::GetInstance()->GetTo() = L"Scene2";
		SceneManager::GetInstance()->LoadScene(L"LoadingScene");

		this->Release();
	}
}

void Scene1::Render(HDC hdc)
{
	wstring str = L"³ª Scene1";
	TextOut(hdc, WINSIZEX / 2, WINSIZEY / 2, str.c_str(), str.length());
	
	int w=10;
	int h=10;

	time += Time::GetInstance()->DeltaTime();

	if (time > 1) {
		
		for (int i = 0; i < 100; i++)
		{
			ptList[i] = { Random::GetInstance()->RandomInt(WINSIZEX), Random::GetInstance()->RandomInt(WINSIZEY) };
		}

		time = 0;
	}

	for (int i = 0; i < 100; i++) {

		mImageList[i]->ScaleRender(hdc, ptList[i].x , ptList[i].y, w, h);

		w++;
		h++;
	}



}
