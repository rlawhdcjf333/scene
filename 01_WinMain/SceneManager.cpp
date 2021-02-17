#include "pch.h"
#include "SceneManager.h"

#include "Scenes.h"
#include "LoadingScene.h"

SceneManager::SceneManager()
	:mCurrentScene(nullptr) {}

SceneManager::~SceneManager()
{
	SceneIter iter = mSceneList.begin();
	for (; iter != mSceneList.end(); ++iter)
	{
		iter->second->Release();
		SafeDelete(iter->second);
	}
}

void SceneManager::Init()
{

	AddScene(L"Scene1", new Scene1);
	AddScene(L"Scene2", new Scene2);
	AddScene(L"LoadingScene", new LoadingScene);
	GetFrom() = L"Scene2";

}

void SceneManager::Update()
{
	if (mCurrentScene != nullptr)
		mCurrentScene->Update();


}

void SceneManager::Render(HDC hdc)
{
	if (mCurrentScene != nullptr)
		mCurrentScene->Render(hdc);
}

void SceneManager::AddScene(const wstring& sceneName,Scene * scene)
{
	SceneIter iter = mSceneList.find(sceneName);
	//�̹� �ش��̸��� �����Ͱ� �ʾȿ� �ִ�
	if (iter != mSceneList.end())
		return;

	mSceneList.insert(make_pair(sceneName, scene));
}

void SceneManager::LoadScene(const wstring & sceneName)
{
	SceneIter iter = mSceneList.find(sceneName);
	//��ã������ return (���ư���)
	if (iter == mSceneList.end())
		return;

	if (mCurrentScene == iter->second)
		return;
	
	Scene* targetScene = iter->second;

	if (mCurrentScene)
		mCurrentScene->Release();

	targetScene->Init();

	mCurrentScene = targetScene;
}
