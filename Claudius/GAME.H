#pragma once

#include<iostream>
#include <string>
#include <vector>
#include<fstream>
#include<sstream>
#include "KeyCode.h"
#include"Lives.h"
#include"RunningAnimation.h"
#include"JumpingAnimation.h"
#include"EagleAnimation.h"
#include"HurtAnimation.h"
#include"Eagle.h"
#include "Font.h"
#include "Text.h"
#include "Sound.h"
#include "Music.h"
#include "Image.h"
#include "TEST_STRUCT_DELETE_BEFORE_HANDIN.h"
#include"Background.h"
#include"Fox.h"
#include"Screen.h"
struct RenderManager;
struct ResourceManager;
struct SoundManager;
using namespace std;

class Game
{
	Background die;
	Background win;
	Background timerImage;
	Background background;
	Background background_ground;
	Background background_grass;
	Background background_grass_2;
	Background background_hill;
	Background background_hill_2;
	Background background_cloud;
	Background background_cloud_2;
	Background Menu;
	Background Tutorial;
	Background Option_1;
	Background Option_2;
	Background Option_3;
	Background Settings;
	Background MusicOption;
	Background SoundOption;
	Background MusicVolume;
	Background SoundVolume;

	Fox fox;
	Eagle eagle;
	Font font;
	Lives life[3];
	Text timer;
	RunningAnimation running[6];
	JumpingAnimation jumping[2];
	EagleAnimation eagles[4];
	HurtAnimation hurt[2];
	Sound HurtSound;
	Sound JumpSound;
	Sound SelectSound;
	Music music;
	bool Pause=false;
	bool VolumeOptions = false;
	int PlayState=1;
	int MenuOptions=1;
	int HurtingPlayingIndex=0;
	int Countdown = 2700;
	int lives = 3;	
	int AnimationPlaySpeed=10;
	int Runningcounter = 0;
	int RunningIndex=0;
	int EagleCounter=0;
	int EagleIndex=0;
	int HurtAnimationCounter = 0;	
	float musicVolume = 100;
	float soundVolume = 100;
	vector<int> words;
	ResourceManager& resourceManager;
	SoundManager& soundManager;
public:
	
	// references to a resource and sound manager sent in the constructor
	Game(ResourceManager& resourceManager, SoundManager& soundManager);
	~Game();

	// References sent to the game from the base to set the window size and name
	bool Enter(int& width, int& height, std::string& title); 

	// If Games update returns false the program will exit, dt is milliseconds passed since last frame
	bool Update(float dt);


	// reference to the rendermanager sent in the function call, make sure to separate update logic from render logic
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
	void OnKeyUp(KeyCode key);
	void LoadConfiguration(string ConfigueFile);
	void Shake(Transform trans);
};