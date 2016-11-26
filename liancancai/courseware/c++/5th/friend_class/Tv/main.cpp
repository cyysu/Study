#include "tv.h"

int main(void)
{
	Tv s42;

	cout << "initial setting for s42\" TV\n";
	s42.settings();
	s42.onoff();
	s42.settings();
	s42.chanup();
	s42.settings();
    Remote grey;
	grey.set_chan(s42, 9);
	s42.settings();

/*
 *    s42.onoff();
 *    s42.settings();
 *    s42.chanup();
 *    s42.chanup();
 *    s42.chanup();
 *    s42.chanup();
 *    s42.voldown();
 *    s42.voldown();
 *    s42.settings();
 *    printf("============\n");
 *    Remote grey;
 *    grey.volup(s42);
 *    grey.chandown(s42);
 *    grey.set_chan(s42, 108);
 *    s42.settings();
 *
 *    Tv s60(Tv::On);
 *    s60.settings();
 */








}
