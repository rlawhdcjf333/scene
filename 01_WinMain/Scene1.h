#pragma once
#include "Scene.h"
class Image;
class Scene1 : public Scene
{
	struct pt {
		int x;
		int y;
	};
	
	vector <pt> ptList;
	
	float time;

public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};

