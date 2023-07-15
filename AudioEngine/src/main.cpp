#include <iostream>
#include "Components/AudioObject.h"
#include "Components/Mixer.h"
#include "Common/Position.h"
#include "portaudio.h"
#include "Engine/AudioEngine.h"
#include "AudioFile.h"
#include <Windows.h>

void TryPlayAudioObject(bool &keyPressed, char key, AudioObject &audioObject)
{

}

int main()
{
    //TODO: Test initialization to be moved to script or game engine
     
    AudioEngine audioEngine;
    
    Mixer mainOutput {};
    //Mixer channel1 {};
    //Mixer channel2 {};

  /*  mainOutput.AddChildMixer(&channel1);
    mainOutput.AddChildMixer(&channel2);*/

    Position audioObjectPosition{ 0, 0 };
    AudioObject audioObject{ audioObjectPosition, "resources/test.wav" };

    //Position audioObject2Position{ 0, 0 };
    //AudioObject audioObject2 { audioObject2Position, "resources/test2.wav", &channel2 };

    //Audio Engine Setup

    audioEngine.Initialize();
    audioEngine.OpenStream(&audioObject);

    std::cout << "_________________________" << std::endl;
    std::cout << "AUDIO RUNNING" << std::endl;
    std::cout << "press A for testing sound" << std::endl;
    std::cout << "_________________________" << std::endl;


    bool keyPressed = false;
    while (true)
    {
        if (GetKeyState('A') < 0)/*Check if high-order bit is set (1 << 15)*/
        {
            if (!keyPressed)
            {
                audioObject.Play();
                keyPressed = true;
            }
        }
        else
            keyPressed = false;

        //if (GetKeyState('B') < 0)/*Check if high-order bit is set (1 << 15)*/
        //{
        //    if (!keyPressed)
        //    {
        //        audioObject2.Play();
        //        keyPressed = true;
        //    }
        //}
        //else
        //    keyPressed = false;
    }

    audioEngine.Terminate();

	return 0;
}