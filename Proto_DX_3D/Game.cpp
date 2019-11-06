#include "input.h"
#include "Cube.h"
#include "grid.h"
#include "camera.h"
#include "Light.h"

void GameInit()
{
	GridInit();
	CubeInit();
	LightInit();

}


void GameUpdate()
{
	CameraUpdate();

	GridUpdate();

	Keyboard_Update();

	CubeUpdate();
}

void GameDraw()
{
	GridDraw();
	CameraDraw();

	
	CubeDraw();
}


void GameUninit()
{
	CubeUnInit();
}




