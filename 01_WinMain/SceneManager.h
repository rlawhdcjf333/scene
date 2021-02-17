#pragma once
/*
Scene�� �����ϴ� �༮
*/

/*
�ε� �����ؿ���!!
- �������ϸ� �ε����� ����
- ���ҽ� �ε���(�����, �̹���)
- ���α׷��� �� �־����� ������
- �ε��� ������ �����̽��� �������� ��� ���� ����
- �����̽� ������ ���������� �Ѿ
*/

class Scene;
class SceneManager
{
	Singleton(SceneManager)
private:
	/*
	key ������ value�� ã���� �ſ� ������
	*/
	map<wstring, Scene*> mSceneList;
	Scene* mCurrentScene;						//���� ��
	typedef map<wstring, Scene*>::iterator SceneIter;
public:
	SceneManager();
	~SceneManager();

	void Init();
	void Update();
	void Render(HDC hdc);

	void AddScene(const wstring& sceneName,Scene* scene);
	void LoadScene(const wstring& sceneName);
};

