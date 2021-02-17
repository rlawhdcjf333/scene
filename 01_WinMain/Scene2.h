#pragma once
#include "Scene.h"
//final : 
class Scene2 final : public Scene
{
public:
	void Init()override;
	void Release()override;
	void Update()override;
	void Render(HDC hdc)override;
};
