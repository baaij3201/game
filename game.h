#ifndef geme
#define game
#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
#define dn(VK_NONAME) keybd_event(VK_NONAME,0,0,0)
#define up(VK_NONAME) keybd_event(VK_NONAME,0,0,0)
#define ps(VK_NONAME) up(VK_NONAME),dn(VK_NONAME)
#define mgb(a,b,c) MessageBox(NULL,a,b,c)
//#include"stdc++.h"
#include<windows.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<fstream>
//#include<easyx.h>
#include<time.h>
#endif
