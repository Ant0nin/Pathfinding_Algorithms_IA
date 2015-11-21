#pragma once

#include "ControlPanel.h"
#include "Scene.h"

class InputListener
{
private:
	Scene *scene;
	ControlPanel *controlPanel;
public:
	InputListener(Scene *scene, ControlPanel *panel);
	~InputListener();
	void run();
};

