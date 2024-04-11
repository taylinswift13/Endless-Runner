#include "Game.h"
#include <assert.h>
#include "ResourceManager.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"

Game::Game(ResourceManager& resourceManager, SoundManager& soundManager) : resourceManager(resourceManager), soundManager(soundManager)
{
	LoadConfiguration("Configuration.txt");
	eagle.Initialize(resourceManager);
	die.Initialize(resourceManager, "../Assets/Die.png", 0, Vector2(0, 0));
	win.Initialize(resourceManager, "../Assets/Win.png", 0, Vector2(0, 0));
	timerImage.Initialize(resourceManager, "../Assets/Timer.png", 0, Vector2(800, 40));
	background.Initialize(resourceManager, "../Assets/Background.png", 0, Vector2(0, 0));
	background_ground.Initialize(resourceManager, "../Assets/Ground.png", 0, Vector2(0, 0));
	background_hill.Initialize(resourceManager, "../Assets/Background_Hill.png", 15, Vector2(0, 0));
	background_hill_2.Initialize(resourceManager, "../Assets/Background_Hill.png", 15, Vector2(900, 0));
	background_cloud.Initialize(resourceManager, "../Assets/Background_Cloud.png", 5, Vector2(0, 0));
	background_cloud_2.Initialize(resourceManager, "../Assets/Background_Cloud.png", 5, Vector2(900, 0));
	background_grass.Initialize(resourceManager, "../Assets/Background_Grass.png", words[3], Vector2(0, 0));
	background_grass_2.Initialize(resourceManager, "../Assets/Background_Grass.png", words[3], Vector2(900, 0));
	Menu.Initialize(resourceManager, "../Assets/Menu.png", 0, Vector2(0, 0));
	Tutorial.Initialize(resourceManager, "../Assets/Tutorial.png", 0, Vector2(0, 0));
	Option_1.Initialize(resourceManager, "../Assets/Option_1.png", 0, Vector2(0, 0));
	Option_2.Initialize(resourceManager, "../Assets/Option_2.png", 0, Vector2(0, 0));
	Option_3.Initialize(resourceManager, "../Assets/Option_3.png", 0, Vector2(0, 0));
	Settings.Initialize(resourceManager, "../Assets/Settings.png", 0, Vector2(0, 0));
	MusicOption.Initialize(resourceManager, "../Assets/MusicOption.png", 0, Vector2(0, 0));
	MusicVolume.Initialize(resourceManager, "../Assets/SoundVolume.png", 0, Vector2(399, 342));
	SoundOption.Initialize(resourceManager, "../Assets/SoundOption.png", 0, Vector2(0, 0));
	SoundVolume.Initialize(resourceManager, "../Assets/SoundVolume.png", 0, Vector2(399, 189));
	fox.Initialize(resourceManager);
	for (int i = 0; i < 3; i++) {
		life[i].Initialize(resourceManager, Vector2(800 + i * 33, 0));
	}
	if (!resourceManager.LoadSoundFromFile(JumpSound, "../Assets/test.ogg"))
		return;
	if (!resourceManager.LoadSoundFromFile(SelectSound, "../Assets/SelectSound.ogg"))
		return;
	if (!resourceManager.LoadSoundFromFile(HurtSound, "../Assets/HurtSound.ogg"))
		return;
	if (!resourceManager.LoadMusicFromFile(music, "../Assets/Music.ogg"))
		return;
	if (!resourceManager.LoadFontFromFile(font, "../Assets/test.ttf", 16))
		return;

	/*test[0].sprite.SetImage(image[0]);
	test[0].sprite.SetSource(64, 64, 128, 128);
	test[0].transform.SetPosition(100, 100);
	test[0].collider.SetSize(64, 64);
	test[1].sprite.SetImage(image[1]);
	test[1].sprite.SetSource(0, 0, 256, 256);
	test[1].transform.SetPosition(300, 100);
	test[1].transform.SetScale(0.5f, 0.5f);
	test[1].collider.SetSize(64, 64);*/


	// The test structs movement logic is INSIDE test struct
	/*text[0].text = "WASD examples of moving box, color change on collision,TIMER";
	text[1].text = "YUIO to play/stop/raise/lower music/volume";
	text[2].text = "HJK to play/raise/lower sound/volume";
	text[3].text = "QE ZC non uniform scaling";*/

	timer.text = "Timer: ";
	timer.transform.SetPosition(750, 40);
	timer.transform.SetScale(2, 2);
	timer.color.SetColor(0, 0, 0, 0);


	/*	for (int i = 0; i < 4; i++)
		{
			text[i].transform.SetPosition(10, static_cast<float>(10 + 20*i));
			text[i].color.SetColor(255, 255, 255, 0);
		}*/
		//Animation
	for (int i = 0; i < 6; i++) {
		running[i].Initialize(resourceManager, Vector2(i * 33, 32));
	}
	jumping[0].Initialize(resourceManager, Vector2(0, 32));
	jumping[1].Initialize(resourceManager, Vector2(33, 32));
	for (int i = 0; i < 4; i++) {
		eagles[i].Initialize(resourceManager, Vector2(i * 40, 41));
	}
	hurt[0].Initialize(resourceManager, Vector2(0, 32));
	hurt[1].Initialize(resourceManager, Vector2(33, 32));
}

Game::~Game()
{
}

bool Game::Enter(int& width, int& height, std::string& title)
{
	width = words[0];
	height = words[1];
	title = "Endless Runner";
	return true;
}


bool Game::Update(float dt)
{
	//State Ckecking
	if (MenuOptions > 3) {
		MenuOptions = 1;
	}
	if (MenuOptions < 1) {
		MenuOptions = 3;
	}
	if (Pause == false && PlayState == 2)
	{
		if (fox.Hurting == false)
		{
			Countdown--;
			hurt[0].trans.SetPosition(fox.trans.position.x, fox.trans.position.y);
			hurt[1].trans.SetPosition(fox.trans.position.x, fox.trans.position.y);
			fox.Update(dt);
			Runningcounter++;
			if (Runningcounter % AnimationPlaySpeed == 0)
			{
				Runningcounter = 0;
				if (RunningIndex <= 5)
				{
					RunningIndex++;
				}
			}
			if (RunningIndex == 6) {
				RunningIndex = 0;
			}
			std::cout << RunningIndex << std::endl;
			eagle.Update(dt);
			if (eagle.trans.position.x <= -100) {
				eagle.trans.SetPosition(1300, 460);
			}
			for (int i = 0; i < 6; i++) {
				running[i].trans.SetPosition(fox.trans.position.x, fox.trans.position.y);
			}
			for (int i = 0; i < 4; i++) {
				eagles[i].trans.SetPosition(eagle.trans.position.x, eagle.trans.position.y);
			}
			jumping[0].trans.SetPosition(fox.trans.position.x, fox.trans.position.y);
			jumping[1].trans.SetPosition(fox.trans.position.x, fox.trans.position.y);

			timerImage.sprite.SetSource(0, 0, 33 * Countdown / 2700, 6);
			//scolling

			if (background_grass.trans.position.x <= -900) {
				background_grass.trans.position.x = background_grass_2.trans.position.x + 900;
			}
			if (background_grass_2.trans.position.x <= -900) {
				background_grass_2.trans.position.x = background_grass.trans.position.x + 900;
			}
			if (background_hill.trans.position.x <= -900) {
				background_hill.trans.position.x = background_hill_2.trans.position.x + 900;
			}
			if (background_hill_2.trans.position.x <= -900) {
				background_hill_2.trans.position.x = background_hill.trans.position.x + 900;
			}
			if (background_cloud.trans.position.x <= -900) {
				background_cloud.trans.position.x = background_cloud_2.trans.position.x + 900;
			}
			if (background_cloud_2.trans.position.x <= -900) {
				background_cloud_2.trans.position.x = background_cloud.trans.position.x + 900;
			}
			background_cloud.Update(dt);
			background_cloud_2.Update(dt);
			background_grass.Update(dt);
			background_grass_2.Update(dt);
			background_hill.Update(dt);
			background_hill_2.Update(dt);

			//eagle animation
			EagleCounter++;
			//	std::cout << Mouse.type << std::endl;
			if (EagleCounter % AnimationPlaySpeed == 0)
			{
				EagleCounter = 0;
				if (EagleIndex <= 3)
				{
					EagleIndex++;
				}
			}
			if (EagleIndex == 4) {
				EagleIndex = 0;
			}
			if (CollisionManager::CheckCollision(fox.collider, eagle.collider)) {
				fox.Hurting = true;
				lives--;
				eagle.trans.SetPosition(1500, 460);
				soundManager.PlaySound(HurtSound, 0);

			}
		}
		else
		{
			int extent = words[2];

			background_cloud.Shake(extent);
			background_cloud_2.Shake(extent);
			background_hill.Shake(extent);
			background_hill_2.Shake(extent);
			background_grass.Shake(extent);
			background_grass_2.Shake(extent);
			background_ground.Shake(extent);
			HurtAnimationCounter++;
			if (HurtAnimationCounter >= 100) {
				HurtingPlayingIndex = 1;
				if (HurtAnimationCounter >= 200) {
					HurtAnimationCounter = 0;
					fox.Hurting = false;
					HurtingPlayingIndex = 0;
					background_cloud.trans.position.x = 895;
					background_grass.trans.position.x = 895;
					background_hill.trans.position.x = 895;
				}
			}
		}
		if (HurtingPlayingIndex > 1) {
			HurtingPlayingIndex = 0;
		}
	}

	if (PlayState == 3) {
		SoundVolume.sprite.SetSource(0, 0, soundVolume / 100 * 114, 8);
		MusicVolume.sprite.SetSource(0, 0, musicVolume / 100 * 114, 8);
	}
	return true;
}

void Game::Render(RenderManager& renderManager)
{
	//Game
	if (PlayState == 2)
	{
		background.Render(renderManager);
		background_hill.Render(renderManager);
		background_hill_2.Render(renderManager);
		background_cloud.Render(renderManager);
		background_cloud_2.Render(renderManager);
		background_grass.Render(renderManager);
		background_grass_2.Render(renderManager);
		fox.Render(renderManager);
		background_ground.Render(renderManager);
		eagle.Render(renderManager);
		timerImage.Render(renderManager);
		renderManager.Render(font, timer);

		if (fox.JumpingDown == false && fox.JumpingUp == false)
		{
			running[RunningIndex].Render(renderManager);
		}
		eagles[EagleIndex].Render(renderManager);
		if (fox.JumpingUp == true) {
			jumping[0].Render(renderManager);
		}
		if (fox.JumpingDown == true) {
			jumping[1].Render(renderManager);
		}
		if (lives == 3) {
			life[0].Render(renderManager);
			life[1].Render(renderManager);
			life[2].Render(renderManager);
		}
		if (lives == 2) {

			life[1].Render(renderManager);
			life[2].Render(renderManager);
		}
		if (lives == 1) {
			life[2].Render(renderManager);
		}
		if (lives <= 0 && fox.Hurting == false) {
			PlayState = 4;
		}
		if (Countdown <= 0)
		{
			PlayState = 5;
		}
		if (fox.Hurting == true) {
			hurt[HurtingPlayingIndex].Render(renderManager);
		}
	}
	//Menu
	if (PlayState == 1) {
		Menu.Render(renderManager);
		if (MenuOptions == 1)
		{
			Option_1.Render(renderManager);
		}
		else if (MenuOptions == 2)
		{
			Option_2.Render(renderManager);
		}
		else if (MenuOptions == 3)
		{
			Option_3.Render(renderManager);
		}

	}
	//Settings
	if (PlayState == 3) {
		Settings.Render(renderManager);
		MusicVolume.Render(renderManager);
		SoundVolume.Render(renderManager);
		if (VolumeOptions) {
			SoundOption.Render(renderManager);
		}
		else
		{
			MusicOption.Render(renderManager);
		}
	}
	//GameOver
	if (PlayState == 4)
	{
		die.Render(renderManager);
	}
	//Game Complete
	if (PlayState == 5)
	{
		win.Render(renderManager);
	}
	//
	if (PlayState == 6)
	{
		Tutorial.Render(renderManager);
	}
}

void Game::OnKeyDown(KeyCode key)
{
	fox.OnKeyDown(key);
	//Music Volume Setting
	if (PlayState == 3 && VolumeOptions == false)
	{
		if (key == KeyCode::RIGHT_ARROW)
		{
			musicVolume = (musicVolume >= 100 ? 100 : musicVolume + 10);
			soundManager.SetMusicVolume(music, musicVolume);
		}
		else if (key == KeyCode::LEFT_ARROW) {
			musicVolume = (musicVolume <= 0 ? 0 : musicVolume - 10);
			soundManager.SetMusicVolume(music, musicVolume);
		}
	}
	//Sound Volume Setting
	if (PlayState == 3 && VolumeOptions)
	{
		if (key == KeyCode::RIGHT_ARROW)
		{
			soundVolume = (soundVolume >= 100 ? 100 : soundVolume + 10);
			soundManager.SetSoundVolume(HurtSound, soundVolume);
			soundManager.SetSoundVolume(JumpSound, soundVolume);
			soundManager.SetSoundVolume(SelectSound, soundVolume);
		}
		else if (key == KeyCode::LEFT_ARROW) {
			soundVolume = (soundVolume <= 0 ? 0 : soundVolume - 10);
			soundManager.SetSoundVolume(HurtSound, soundVolume);
			soundManager.SetSoundVolume(JumpSound, soundVolume);
			soundManager.SetSoundVolume(SelectSound, soundVolume);
		}
	}
	//Menu Option Select
	if (PlayState == 1)
	{
		if (key == KeyCode::S || key == KeyCode::DOWN_ARROW) {
			MenuOptions++;
			soundManager.PlaySound(SelectSound, 0);
		}
		if (key == KeyCode::W || key == KeyCode::UP_ARROW) {
			MenuOptions--;
			soundManager.PlaySound(SelectSound, 0);
		}
		if (key == KeyCode::ENTER && MenuOptions == 1) {
			PlayState = 2;//GAME
			soundManager.PlayMusic(music, -1);
		}
		if (key == KeyCode::ENTER && MenuOptions == 2) {
			PlayState = 3;//SETTINGS
		}
		if (key == KeyCode::ENTER && MenuOptions == 3) {
			PlayState = 6;//TURORIAL
		}
	}
	//Game
	if (PlayState == 2)
	{
		//Jumping Sound Play
		if (key == KeyCode::SPACE || Pause == false)
		{
			soundManager.PlaySound(JumpSound, 0);
		}
	}
	//Volome Option Select
	if (PlayState == 3) {
		if (key == KeyCode::UP_ARROW || key == KeyCode::DOWN_ARROW) {
			VolumeOptions = !VolumeOptions;
			soundManager.PlaySound(SelectSound, 0);
		}
		if (key == KeyCode::ESCAPE) {
			PlayState = 1;
		}
	}
	//GameOver
	if (PlayState == 4) {
		if (key == KeyCode::ENTER) {
			PlayState = 2;
			lives = 3;
			Countdown = 2700;
		}
	}
	//Game Complete
	if (PlayState == 5) {
		if (key == KeyCode::ENTER) {
			PlayState = 1;
			lives = 3;
			Countdown = 2700;
		}
	}
	if (PlayState == 6) {
		if (key == KeyCode::ESCAPE) {
			PlayState = 1;
		}
	}

}

void Game::OnKeyUp(KeyCode key)
{
	if (key == KeyCode::Q) {
		if (Pause == true)
		{
			Pause = false;
		}
		else {
			Pause = true;
		}
	}
}

void Game::LoadConfiguration(string ConfigueFile)
{
	ifstream File;
	File.open(ConfigueFile);
	if (!File.is_open())return;


	string Line;
	int number;
	for (int i = 0; i < 4; i++) {
		getline(File, Line);
		stringstream transferer;
		transferer << Line;
		transferer >> number;
		words.push_back(number);
		cout << words[i] << endl;
		transferer.clear();
	}
	File.close();
}

