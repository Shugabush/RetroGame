#include "SoundPool.h"

Music song;

Sound fastInvaderSounds[4];

Sound invaderKilledSound;
Sound playerKilledSound;

Sound ufoSounds[2];

Sound shootSound;

void LoadSounds()
{
	song = LoadMusicStream("Sounds/spaceinvaders.mp3");

	fastInvaderSounds[0] = LoadSound("Sounds/fastinvader1.wav");
	fastInvaderSounds[1] = LoadSound("Sounds/fastinvader2.wav");
	fastInvaderSounds[2] = LoadSound("Sounds/fastinvader3.wav");
	fastInvaderSounds[3] = LoadSound("Sounds/fastinvader4.wav");

	invaderKilledSound = LoadSound("Sounds/invaderkilled.wav");
	playerKilledSound = LoadSound("Sounds/playerkilled.wav");

	ufoSounds[0] = LoadSound("Sounds/ufo_lowpitch.wav");
	ufoSounds[1] = LoadSound("Sounds/ufo_highpitch.wav");

	shootSound = LoadSound("Sounds/shoot.wav");
}