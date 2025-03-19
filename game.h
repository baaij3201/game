#ifndef geme
#define game
//#include"stdc++.h"
#include<windows.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<tchar.h>
//#include<easyx.h>
#include<time.h>
//#define randmax() (rand()<<15|rand())
//#define randpro(a,b) ((rand()%(b-a+1))+a)
namespace randtools {
	int randmax() { return (rand() << 15) | rand(); }
	int randpro(int a, int b) { return (rand() % (b - a + 1)) + a; }
};
#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
#define dn(VK_NONAME) keybd_event(VK_NONAME,0,0,0)
#define up(VK_NONAME) keybd_event(VK_NONAME,0,0,0)
#define ps(VK_NONAME) up(VK_NONAME),dn(VK_NONAME)
int mgb(const char* a, const char* b, unsigned int c) {
	return MessageBox(NULL, _T(a), _T(b), c);
}
namespace SBtools {
	bool SB;
	void editsb(bool t) {
		SB = t;
	}
};
#endif
