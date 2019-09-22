#include "Audio.h"

bool AudioSystem::AudioInit()
{

	Console_OutputLog(L"Initalizing Audio...", LOGINFO);

	FMOD_RESULT result;
	result = FMOD::System_Create(&audioSystem);
	if (result != FMOD_OK) {
		Console_OutputLog(L"Cannot Initalise Audio FMOD_OK Check Failed!", LOGWARN);
		return false;
	}
	result = audioSystem->init(100, FMOD_INIT_NORMAL | FMOD_INIT_3D_RIGHTHANDED, 0);
	if (result != FMOD_OK) {
		Console_OutputLog(L"Cannot Initalise Audio FMOD_OK Check Failed!", LOGWARN);
		return false;
	}

	/* CREATE SOUNDS */

	result = audioSystem->createSound("Resources/Sounds/VeryGoodThemeMusic.mp3", FMOD_LOOP_NORMAL, 0, &backMusic);
	if (result != FMOD_OK) {
		Console_OutputLog(L"Cannot Initalise Audio Track VeryGoodThemeMusic.mp3", LOGWARN);
	}

	Console_OutputLog(L"Initalized Audio...", LOGINFO);

	return true;
}

void AudioSystem::Play(int track) {
	bool foundtrack = true;
	bool result = false;
	switch (track)
	{
	case BACK: {
		result = audioSystem->playSound(backMusic, 0, false, 0);
		break;
	}
	default: {
		foundtrack = false;
		Console_OutputLog(to_wstring("Audio Track: " + std::to_string(track) + " was called but it doesn't exist"), LOGWARN);
		break;
	}
	}

	if (foundtrack) {
		if (result != FMOD_OK) {
			Console_OutputLog(to_wstring("Audio Track: " + std::to_string(track) + " was called but cannot be played"), LOGWARN);
			return;
		}
	}
}

void AudioSystem::Tick()
{
	audioSystem->update();
}

