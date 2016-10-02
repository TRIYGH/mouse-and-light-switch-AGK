//T.Robert Ward
//June 26, 2013
//
// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

const int SCR_WIDTH = 640;
const int SCR_HEIGHT = 480;
const int ROOM = 1;
const int LIGHTSWITCH = 2;
const int ON = 1;
const int OFF = 2;
bool OnOrOff = true;

// Begin app, called once at the start
void app::Begin( void )
{
	agk::SetVirtualResolution(SCR_WIDTH, SCR_HEIGHT);
	
	agk::SetWindowTitle("Virtual LightSwitch");

	agk::LoadImage(ON, "light_switch_on.png");
	agk::LoadImage(OFF, "light_switch_off.png");

	agk::CreateSprite(ROOM,"room.png");
	agk::CreateSprite(LIGHTSWITCH,ON);

	agk::SetSpriteScale(LIGHTSWITCH,0.2, 0.2);
	
	agk::SetSpritePosition(LIGHTSWITCH, 60,60);

}

// Main loop, called every frame
void app::Loop ( void )
{
	if(agk::GetRawMouseLeftPressed())
	{
		float mouseX = agk::GetRawMouseX();
		float mouseY = agk::GetRawMouseY();

		if ( agk::GetSpriteHit(mouseX, mouseY) == LIGHTSWITCH)
		{
			if( OnOrOff )
			{
				agk::SetSpriteColor(ROOM,60,60,60,255);
				agk::SetSpriteImage(LIGHTSWITCH,OFF);
				agk::SetSpriteColor(LIGHTSWITCH,60,60,60,255);

				OnOrOff = false;
			}
			else
			{
				agk::SetSpriteColor(ROOM,255,255,255,255);
				agk::SetSpriteImage(LIGHTSWITCH,ON);
				agk::SetSpriteColor(LIGHTSWITCH,255,255,255,255);

				OnOrOff = true;
			}
		}
	}

	agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
