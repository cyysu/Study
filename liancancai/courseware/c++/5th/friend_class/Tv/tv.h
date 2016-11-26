#ifndef __TV_H__
#define __TV_H__

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

//声明类 遥控器
class Remote;

//电视机
class Tv{
	private:
		int state;//on or off
		int volume;//音量
		int maxchannel;//表示频道最大数
		int channel;//表示当前频道
		int mode;//有线  无线
		int input;//TV DVD 
	public:
		friend class Remote;
		enum{Off, On};
		enum{MinVal, MaxVal = 20};
		enum{antenna, cable};
		enum{TV, DVD};

		Tv(int s = Off, int mc = 200) : state(s), volume(8), maxchannel(mc), channel(1), mode(cable),input(TV){}
		void onoff(void){state = !state;}
		bool ison(void) const {return state == On;}
		bool volup(void);
		bool voldown(void);
		void chanup(void);
		void chandown(void);
		void set_mode(void) {mode = (mode == antenna) ? cable : antenna;}
		void set_input(void) {input = !input;}
		void settings(void) const;//显式all settings
};
class Remote{
	private:
		int mode;//TV or DVD
	public:
		Remote(int m = Tv::TV) : mode(m){}
		bool volup(Tv & t){return t.volup();}
		bool voldown(Tv & t){return t.voldown();}
		void chanup(Tv & t){t.chanup();}
		void chandown(Tv & t){t.chandown();}
		void set_chan(Tv & t, int c){t.channel = c;}
		void set_mode(Tv & t){t.set_mode();}
		void set_input(Tv & t){t.set_input();}



};
#endif /*TV_H*/
