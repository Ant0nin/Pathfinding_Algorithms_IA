#pragma once

#include "ControllerSelector.h"
#include "Scene.h"

class InputListener
{
private:
	Scene *scene;
	ControllerSelector *selector;
public:
	InputListener(Scene *scene, ControllerSelector *selector);
	~InputListener();
	void run();
};

