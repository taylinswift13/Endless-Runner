#pragma once
#include <string>
#include<vector>
using namespace std;
struct Rect
{
	int x;
	int y;
	int w;
	int h;
};
struct SpriteSheet
{
	string ImageFile;
	vector <Rect> Sprites;
};