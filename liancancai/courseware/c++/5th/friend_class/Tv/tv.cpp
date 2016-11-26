#include "tv.h"

bool Tv::volup(void)
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
	{
		return false;
	}
}
bool Tv::voldown(void)
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
	{
		return false;
	}
}

void Tv::chanup(void)
{
	if (channel < maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 0;
	}
}
void Tv::chandown(void)
{
	if (channel > 0)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;
	}
}
void Tv::settings(void) const
{
	cout << "TV is : " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "volume = " << volume << endl;
		cout << "channel = " << channel << endl;
		cout << "mode = " << (mode == antenna ? "antenna" : "cable") << endl;
		cout << "input = " << (input == TV ? "TV" : "DVD") << endl;
	}
}
