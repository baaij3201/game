#include "game.h"
#pragma message("game version is 6.0.1")
using namespace std;
void updj(){
	system("cls");
	cout<<"1.0版本：2023年出版\n";
	getch();
	cout<<"1.1:修复bug\n";
	getch();
	cout<<"2.0:增加资源设定\n";
	getch();
	cout<<"2.9.6:出现第一个公开版\n";
	getch();
	cout<<"2.0后续版本:增加了贪心提示\n以及完善逃跑功能\n和作者的杀手\n";
	getch();
	cout<<"3.0:界面的优化\n";
	getch();
	cout<<"3.1:新增快速加载\n";
	getch();
	cout<<"3.2:配备老板键\n";
	getch();
	cout<<"4.0版本:大规模界面优化\n";
	getch();
	cout<<"4.1:增加快捷源码查看\n以及更新日志\n";
	getch();
	cout<<"4.2:增加装逼提取\n";
	getch();
	cout<<"4.3:修复打怪闪退的bug\n";
	getch();
	cout<<"4.4.0:修复按多余按键的Bug\n";
	getch();
	cout<<"4.4.1:在主界面显示更多信息\n";
	getch();
	cout<<"4.5.0:界面优化（无闪清屏）\n";
	getch();
	cout<<"4.5.1:优化代码结构\n";
	getch();
	cout<<"4.5.2:改进老板键\n";
	getch();
	cout<<"4.5.3:修复一些场景显示主界面的bug\n";
	getch();
	cout<<"5.0.1:将在某些场景禁用软件\n";
	getch();
	cout<<"5.0.2:修复bug\n";
	getch();
	cout<<"5.0.3:修复逃跑加钱的bug\n";
	getch();
	cout<<"5.1.0:增加了铁门和钥匙,这下难多了(qwq)\n";
	getch();
	cout<<"5.1.1:修复bug\n";
	getch();
	cout<<"5.2.0:优化一系列算法\n";
	getch();
	cout << "6.0.0:增加了叨\n";
	getch();
	cout << "6.0.1增加了是否出口成章\n";
	getch();
	system("cls");
}
string getpas(){
	bool t=true;
	string k;
	while(1){
		char c=getch();
		if(c==' ') t=!t;
		else if(c==8){
			if(k.size()>0){
				k.erase(k.size()-1, 1);
				system("cls");
			}
		}
		else if(c=='\r'){
			break;
		}
		else if(0<=c&&c<=127)k+=c;
		if(t){
			system("cls");
			for(int i=0;i<k.size();i++){
				cout<<"*";
			}
		}
		else{
			system("cls");
			cout<<k;
		}
	}
	return k;
}
void gotoxy(int x,int y){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
struct pel{
	bool dw;
	int gj,fy,xl,x,y;
};
int sj=5;
void bosskey(){
	system("cls");
	system("title G锁定状态");
	cout<<"如果不是误触，请按L否则按其他键退出锁定";
	char c=getch();
	if(c=='L'||c=='l'){
		system("cls");
		exit(0);
	}
	system("title 学校大乱斗v6.0.1");
	system("cls");
	return;
}
char Map[100][100]={
	"###################################################",
	"#I@@@@$$$@@@@@@......S@@@@@@@#........TC#Z#@@@@@@@#",
	"################T#####@@@@@@@#........TT#BS@@@@@@@#",
	"#$@$#CT.........T....#$$$$$$$#..........#J#$@$@$@$#",
	"#TTT#TTB#######S##############..........#T#@$@$@$@#",
	"#...#....#..#$$S$$###.....................#$@$@$@$#",
	"#...#.......#$$$$$#.#.....................#@@@@@@@#",
	"#...........SB$$$BS.J.....................#@@@@@@@#",
	"#...........#$$$$$#.#.....................#......U#",
	"#S#######...#$B$$#############S####################",
	"#[T..BBB#...##S####.......................S.......#",
	"#####]@B#........#........................#.......#",
	"#JJJJJ###........#.....................#B##.......#",
	"#JJJJJ#..........#.....................#JJ#.......#",
	"#PZJJJ#..........S.....................#JL#......A#",
	"###################################################",
	"T:老师，B：校霸，#：墙，$：钱，Z:作者",
	"I：我，L：五金店，C：黑市，@：免费的血",
	"P：校长，J：教导主任，K：作者的杀手，",
	"S：保安 U&A:金钥匙 []:上锁的门",
	"输入q开启/关闭快速加载",
	"输入r查看快速加载状态"
},c,*cz,k;
string Set="";                   
string password="123456",jdt=">>>>>>>>>>>>>>>>>>>>>>>>>";
bool win,sl=false,rn=false,fast=false,keyu=false,keya=false; 
int i=1,j=1,t=0,money=100,dy=1,n1=0,n2=0,cs=0,kfz=-1,lai=5,dcs=0,ycs=0,ksm=0,x1=-1,x2=-1,fsm=0,ddy=2,xdao=0,xdaom=3;
double gj=110,fy=75,xl=1350;
void color(int x,int y){
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	switch(x){
	    case 1:SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED  );break;	//红
	  	case 2:SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_BLUE );break;	//蓝
	    case 3:SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_GREEN);break;	//绿
		case 4:SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED  |FOREGROUND_BLUE );break;	//红+蓝=紫
		case 5:SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED  |FOREGROUND_GREEN);break;	//红+绿=黄
		case 6:SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_BLUE |FOREGROUND_GREEN);break;	//蓝+绿=青
	    case 7:SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_GREEN|FOREGROUND_BLUE |FOREGROUND_RED);break;	//红+蓝+绿=白
	    case 8:SetConsoleTextAttribute(handle, FOREGROUND_RED  );break;	//红
		case 9:SetConsoleTextAttribute(handle, FOREGROUND_BLUE );break;	//蓝
	    case 10:SetConsoleTextAttribute(handle, FOREGROUND_GREEN);break;	//绿
		case 11:SetConsoleTextAttribute(handle, FOREGROUND_RED  |FOREGROUND_BLUE );break;	//红+蓝=紫
		case 12:SetConsoleTextAttribute(handle, FOREGROUND_RED  |FOREGROUND_GREEN);break;	//红+绿=黄
		case 13:SetConsoleTextAttribute(handle, FOREGROUND_BLUE |FOREGROUND_GREEN);break;	//蓝+绿=青
	    case 14:SetConsoleTextAttribute(handle, FOREGROUND_GREEN|FOREGROUND_BLUE |FOREGROUND_RED);break;	//红+蓝+绿=白
	    case 15:SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY );//灰色
	    default:return;
	}
	switch(y){
	    case 1:SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |BACKGROUND_RED  );break;	//红
	  	case 2:SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |BACKGROUND_BLUE );break;	//蓝
	    case 3:SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |BACKGROUND_GREEN);break;	//绿
		case 4:SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |BACKGROUND_RED  |BACKGROUND_BLUE );break;	//红+蓝=紫
		case 5:SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |BACKGROUND_RED  |BACKGROUND_GREEN);break;	//红+绿=黄
		case 6:SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |BACKGROUND_BLUE |BACKGROUND_GREEN);break;	//蓝+绿=青
	    case 7:SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY |BACKGROUND_GREEN|BACKGROUND_BLUE |BACKGROUND_RED);break;	//红+蓝+绿=白
	    case 8:SetConsoleTextAttribute(handle, BACKGROUND_RED  );break;	//红
	  	case 9:SetConsoleTextAttribute(handle, BACKGROUND_BLUE );break;	//蓝
	    case 10:SetConsoleTextAttribute(handle, BACKGROUND_GREEN);break;	//绿
		case 11:SetConsoleTextAttribute(handle, BACKGROUND_RED  |BACKGROUND_BLUE );break;	//红+蓝=紫
		case 12:SetConsoleTextAttribute(handle, BACKGROUND_RED  |BACKGROUND_GREEN);break;	//红+绿=黄
		case 13:SetConsoleTextAttribute(handle, BACKGROUND_BLUE |BACKGROUND_GREEN);break;	//蓝+绿=青
	    case 14:SetConsoleTextAttribute(handle, BACKGROUND_GREEN|BACKGROUND_BLUE |BACKGROUND_RED);break;	//红+蓝+绿=白
	    default:return;
	}
	
}
void xhxcolor(int x){
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	switch(x){
	    case 1:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_INTENSITY |FOREGROUND_RED  );break;	//红
	  	case 2:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_INTENSITY |FOREGROUND_BLUE );break;	//蓝
	    case 3:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_INTENSITY |FOREGROUND_GREEN);break;	//绿
		case 4:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_INTENSITY |FOREGROUND_RED  |FOREGROUND_BLUE );break;	//红+蓝=紫
		case 5:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_INTENSITY |FOREGROUND_RED  |FOREGROUND_GREEN);break;	//红+绿=黄
		case 6:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_INTENSITY |FOREGROUND_BLUE |FOREGROUND_GREEN);break;	//蓝+绿=青
	    case 7:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_INTENSITY |FOREGROUND_GREEN|FOREGROUND_BLUE |FOREGROUND_RED);break;	//红+蓝+绿=白
	    case 8:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_RED  );break;	//红
		case 9:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_BLUE );break;	//蓝
	    case 10:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_GREEN);break;	//绿
		case 11:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_RED  |FOREGROUND_BLUE );break;	//红+蓝=紫
		case 12:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_RED  |FOREGROUND_GREEN);break;	//红+绿=黄
		case 13:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_BLUE |FOREGROUND_GREEN);break;	//蓝+绿=青
	    case 14:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_GREEN|FOREGROUND_BLUE |FOREGROUND_RED);break;	//红+蓝+绿=白
	    case 15:SetConsoleTextAttribute(handle, COMMON_LVB_UNDERSCORE|FOREGROUND_INTENSITY );//灰色
	    default:return;
	}
}
void zz(){
	puts("老板：你来找我打什么？");
	getch();
	puts("武器，盔甲，还是钥匙？");
	getch();
	int a=114514;
	while(a){
		
	}	
}
void sabi() {
	while (1) {
		if (SBtools::SB) {
			mgb("你个傻逼", "傻逼", MB_OK | MB_ICONWARNING);
		}
		else {
			mgb("我真不想出口成章啊", "哎呀", MB_OK | MB_ICONWARNING);
		}
	}
}
void xg(){
	gj/=30;
	fy/=15;
	xl/=3;
	money=0;
	dy=0;
	for(int i=0;i<16;i++){
		for(int j=0;j<48;j++){
			if(Map[i][j]=='@'||Map[i][j]=='$'){
				Map[i][j]='K';
			}
		}
	}
	rn=true;
}
void ar(int t){
	system("cls");
	char a;
	int RAND=rand()%15;
	string s1="作者：小伙汁，挺厉害嘛\n竟然能杀到这里！\n",s2="作者：小伙汁挺勇的嘛\n作者使用了修改器！\n",s3="作者：呵呵，骗你的啦！\n作者为了补偿你，给了你50滴血！",s4="作者：（终于没人让我滚了吗？！）\n呃……呃……\n好吧，我答应你！\n",s5="作者：我让你全方位翻倍！！！！！\n",s6="作者：我刚做完一把死光枪，给你！\n",s7="作者：我刚做完一个无敌装甲，给你！\n",s8="作者：还想占便宜？\n想得美！\n作者使用了修改器！\n",s9="作者：想搞事？我陪你！\n作者使用了修改器！\n";    
	if(lai==0){
		color(1,0);
		for(int i=0;i<s8.size();i++){cout<<s8[i];Sleep(50);}
		xg();
		color(7,0);
		return;
	} 
	if(lai==1){
		MessageBox(NULL,"不要贪心哦","作者提示",MB_OK|MB_ICONWARNING);
	}                                             
	color(5,0);
	for(int i=0;i<s1.size();i++){cout<<s1[i];Sleep(50*(!fast));}
	color(1,0);
	cout<<"所以我决定奖励你，开始吧！\n输入1.好，2.滚";
	a=getch();
	color(7,0);
	if(a=='1'){
		lai--;
		if(RAND==0||RAND==1||RAND==2||RAND==3||RAND==4||RAND==5||RAND==6){
			color(1,0);
			for(int i=0;i<s3.size();i++){cout<<s3[i];Sleep(50*(!fast));}
			xl+=50;
			color(7,0);
		}
		if(RAND==7||RAND==8||RAND==9||RAND==10){
			color(1,0);
			for(int i=0;i<s4.size();i++){cout<<s4[i];Sleep(50*(!fast));}
			gj+=5;
			fy+=5;
			xl+=30;
			money+=50;
			dy++;
			color(7,0);
		}
		if(RAND==11||RAND==12){
			color(1,0);
			for(int i=0;i<s5.size();i++){cout<<s5[i];Sleep(50*(!fast));}
			gj*=1.5;
			fy*=1.5;
			xl*=1.5;
			money*=2;
			dy=dy*2+1;
			color(7,0);
		}
		if(RAND==13){
			color(1,0);
			for(int i=0;i<s6.size();i++){cout<<s6[i];Sleep(50*(!fast));}
			gj+=350;
			color(7,0);
		}
		if(RAND==14){
			color(1,0);
			for(int i=0;i<s7.size();i++){cout<<s7[i];Sleep(50*(!fast));}
			fy+=200;
			color(7,0);
		}
	}
	else if(a=='2'){
		color(1,0);
		system("cls");
		for(int i=0;i<s2.size();i++){cout<<s2[i];Sleep(50*(!fast));}
		color(7,0);
		xg();
	}
	else{
		cout<<"\n作者：输入错误！";
		Sleep(1000);system("cls");
		if(t<2) ar(t+1);
		else{
			color(1,0);
			for(int i=0;i<s9.size();i++){cout<<s9[i];Sleep(50*(!fast));}
			color(7,0);
			xg();
		}
	}
}
void gm(){
	char a='A';
	while(a!='0'&&money>0){
		system("cls");
		cout<<fixed<<setprecision(3)<<"血量："<<xl<<"   攻击："<<gj<<"   防御："<<fy<<"   钱："<<money<<"元   "<<'\n';
		puts("--------------------黑市--------------------");
		puts("|                你要买什么？              |");
		puts("|0.停止购买                                |------------");
		puts("|1.创可贴（回30点血）                      |价格：10元 |");
		puts("|2.急救包（回60点血）                      |价格：20元 |");
		puts("|3.毒药（让敌人的属性削弱+这一轮不会攻击） |价格：100元|");
		puts("|4.铁剑（攻击力+10）                       |价格：50元 |");
		puts("|5.圣剑（攻击力+40）                       |价格：180元|");
		puts("|6.铁铠（防御力+15）                       |价格：40元 |");
		puts("|7.防弹衣（防御力+35）                     |价格：120元|");
		puts("|8.小叨（一次性用品，神助攻）              |价格：160元|");
		puts("--------------------------------------------------------");
		a=getch();
		if(a==-32){
			getch();
		}
		else if(a=='1'){
			if(money>=10){
				puts("购买完成！");
				xl+=20+rand()%20;
				money-=10;
			}
			else puts("钱不够！");
		}
		else if(a=='2'){
			if(money>=20){
				puts("购买完成！");
				xl+=50+rand()%25;
				money-=20;
			}
			else puts("钱不够！");
		}
		else if(a=='3'){
			if(money>=100){
				puts("购买完成！");
				dy++;
				dcs++;
				money-=100;
			}
			else puts("钱不够！");
		}
		else if(a=='4'){
			if(money>=50){
				puts("购买完成！");
				gj+=9+rand()%3;
				money-=50;
			}
			else puts("钱不够！");
		}
		else if(a=='5'){
			if(money>=180&&sj){
				puts("购买完成！");
				gj+=37+rand()%5;
				money-=180;
				sj--;
			}
			else if(sj) puts("钱不够！");
			else puts("卖光了。。。");
		}
		else if(a=='6'){
			if(money>=40&&ksm<=2){
				puts("购买完成！");
				money-=40;
				ksm=6;
			}
			else if(ksm>2) cout<<"装备良好无需购买";
			else puts("钱不够！");
		}
		else if(a=='7'){
			if(money>=120&&fsm<=1){
				puts("购买完成！");
				money-=120;
				ycs++;
				fsm=4;
			}
			else if(fsm>1) cout<<"装备良好无需购买";
			else puts("钱不够！");
		}
		else if (a == '8') {
			if (money >= 180 && xdaom) {
				puts("购买完成！");
				xdao++;
				money -= 160;
				xdaom--;
			}
			else if (sj) puts("钱不够！");
			else puts("卖光了。。。");
		}
		else if(a=='g'||a=='G'){
			bosskey();
		}
		else{continue;}
		if(ycs==5){
			ycs=0;
			color(1,0);
			puts("商家：恭喜你触发买五送一活动，另外还有……（系统提示：以自动屏蔽广告）");
			color(7,0);
			fy+=33+rand()%5;
		}
		if(dcs==5){
			dcs=0;
			color(1,0);
			puts("商家：恭喜你触发买五送一活动，另外还有……（系统提示：以自动屏蔽广告）");
			color(7,0);
			fy+=33+rand()%5;
		}
		Sleep(2000*(!fast));
		if(fast){
			getch();
		}
	}
}
void dajia(char lx){
	if(lx=='K'&&kfz!=-1){
		win=true;
		return;
	}
	if(lx=='K'){
		system("cls");
		color(15,1);
		FILE* fp=fopen("set.ini","w");
		fprintf(fp,"killban");
		fclose(fp);
		string killer="体验死亡的快乐吧！\n";
		for(int i=0;i<killer.size();i++){
			cout<<killer[i];
			Sleep(900*(!fast));
		}
		while(xl>0){
			puts("投降吧！1：投降2：拒不投降");
			char c;
			c=getch();
			if(c=='1'){
				while(1){
					int rand1=rand()%7+1,rand2=rand()%7+1;
					color(rand1,rand2);
					cout<<"赶紧滚！";
				}
			}
			else{
				xl-=10;
				cout<<"赶紧投降！";
				Sleep(1000*(!fast));
				system("cls");
			}
		}
		system("SB.vbs");
	}
	int ksm2,fsm2;
	if(ksm>0){
		tiejia:
		system("cls");
		puts("是否使用铁甲？ yesorno");
		string s;
		cin>>s;
		if(s=="yes"||s=="YES"){
			ksm2=1;
		}
		else if(s=="no"||s=="NO"){
			ksm2=0;
		}
		else{goto tiejia;}
		system("cls");
	}
	if(fsm>0){
		fangdanyi:
		system("cls");
		puts("是否使用防弹衣？ yesorno");
		string s;
		cin>>s;
		if(s=="yes"||s=="YES"){
			fsm2=1;
		}
		else if(s=="no"||s=="NO"){
			fsm2=0;
		}
		else{goto fangdanyi;}
		system("cls");
	}
	if(ksm2){
		ksm--;
		fy+=13+rand()%5;
	} 
	if(fsm2){
		fsm--;
		fy+=33+rand()%5;
	}
	win=true;
	bool xz=false;
	system("cls");
	double jxl=t/5,jgj=t/6,jfy=t/7,dxl,dgj,dfy;
	int kez=rand()%5;
	string s="敌人被你毒的不轻，损失了35%的血！\n敌人正在恢复，这一轮他没有攻击！\n",dr[5]={"老师","校霸","教导主任","校长","保安"},s2="校长来了，成败在此一举！\n",s3="校长被你干掉了，你统治了学校！\n",s4="你被你毒的不轻，损失了35%的血！\n你正在恢复，这一轮他没有攻击！\n",s5="叨很好使，敌人鲜血直流\n",s6="敌人有亿点点傻，竟然把叨拔了出来，狗带了\n";
	int mr[5]={55,65,130,-1,280};
	int k,ren;
	if(lx=='T'){
		xz=false;
		dxl=170+jxl;
		dgj=95+jgj;
		dfy=40+jfy;
		ren=0;
	}
	if(lx=='B'){
		xz=false;
		dxl=220+jxl;
		dgj=90+jgj;
		dfy=65+jfy;
		ren=1;
	}
	if(lx=='J'){
		xz=false;
		dxl=260+jxl;
		dgj=90+jgj;
		dfy=70+jfy;
		ren=2;
	}
	if(lx=='P'){
		xz=true;
		dxl=500+jxl+xl*0.6;
		dgj=150+jgj+gj*0.6;
		dfy=100+jfy+fy*0.6;
		ren=3;
	}
	if(lx=='S'){
		xz=false;
		dxl=300+jxl/2;
		dgj=135+jgj*3+jfy+jxl+gj*0.2;
		dfy=90+fy*0.1;
		ren=4;
	}
	if(kez==1){
		xl+=10;
		gj+=20;
		fy+=15;
	}
	else if(kez==2){
		dxl+=10;
		dgj+=20;
		dfy+=15;
	}
	else if(kez==3){
		xl-=10;
		gj-=20;
		fy-=15;
	}
	else if(kez==4){
		dxl-=10;
		dgj-=20;
		dfy-=15;
	}
	if(xz){
		color(1,0);
		for(int i=0;i<s2.size();i++){
			cout<<s2[i];
			Sleep(100);
		}
		color(7,0);
	}
	while(dxl>0){
		shuru:
		system("cls");
		color(1,0);cout<<fixed<<setprecision(3)<<dr[ren]<<"剩余血量：";color(0,7);cout<<dxl;color(1,0);cout<<"\n我剩于血量（战时）：";color(7,0);cout<<xl<<'\n';
		cout<<"1：普通攻击，2：毒药攻击，3：逃跑";
		if (xdao) cout << "4：拔叨相助";
		cout << '\n';
		k=getch();
		if(k=='1'){
			if(rand()%8==0&&ddy){
				ddy--;
				color(3,0);
				for(int i=0;i<s.size();i++){
					cout<<s4[i];
					Sleep(200*(!fast));
				}
				color(7,0);
				system("cls");
				xl*=0.8;
				gj*=0.9;
				fy*=0.9;
			}
			else{
				dxl-=max(2,gj*1.53-dfy*1.32)+rand()%3;
				xl-=max(4,dgj*1.52-fy*1.35+ren-((xl>1600)?(xl/300):(6))) + rand() % 3;
			}
			
		}
		else if(k=='2'){
			if(dy){
				color(3,0);
				for(int i=0;i<s.size();i++){
					cout<<s[i];
					Sleep(200*(!fast));
				}
				color(7,0);
				dxl*=0.65;
				dgj*=0.9;
				dfy*=0.85;
				dy--;
			}
			else{
				cout<<"没有了！\n";
				Sleep(1500*(!fast));
				if(fast){
					getch();
				}
				system("cls");
				goto shuru;
			}
		}
		else if(k=='3'){
			if(rand()%3<2){
				if(kez==1){
					xl-=15;
					gj-=25;
					fy-=20;
				}
				win=false;
				return;
			}
			else{
				cout<<"逃跑失败！\n";
				dxl+=10;
				xl-=dgj/3;
			}
		}
		else if (k == '4') {
			if (xdao) {
				xdao--;
				if (rand() % 5 == 0) {
					cout << "可惜你的叨被夺过去了\n";
					xl -= dgj * 1.5 + 60;
				}
				else{
					for (int i = 0; i < s5.size(); i++) {
						cout << s5[i];
						Sleep(300 * (!fast));
					}
					dxl -= gj * 1.5 + 60;
					if (rand() % 8 == 0) {
						for (int i = 0; i < s6.size(); i++) {
							cout << s6[i];
							Sleep(300 * (!fast));
						}
						dxl = 0;
						xl += 10;
					}
				}
			}
			else {
				cout << "可惜你没叨\n";
				xl -= dgj - 1.5;
			}
		}
		else if(k=='g'||k=='G'){
			bosskey();
		}
		else{
			if(k==-32){
				k=getch();
			}
			else{
				cout<<"输入错误！";
				Sleep(1500*(!fast));
				if(fast){
					getch();
				}
				system("cls");
			}
			
			goto shuru;
		}
		if(xl<=0){
			system("cls");
			cout<<"你死了！";
			Sleep(2000);
			if(kfz!=-1) return;
			else exit(0);
		}
	}
	if(xz){
		color(6,0);
		for(int i=0;i<s3.size();i++){
			cout<<s3[i];
			Sleep(200*(!fast));
		}
		if(fast){
			getch();
		}
		sl=true;
		color(7,0);
		if(kfz!=-1) return;
		else exit(0);
	}
	color(6,0);
	cout<<"他被你干掉了，你赢了！";
	money+=mr[ren];
	color(7,0);
	Sleep(3000*(!fast));
	if(ksm2==1){
		fy-=13+rand()%5;
	}
	if(fsm2==1){
		fy-=33+rand()%5;
	}
	if(kez==1){
		xl-=10;
		gj-=20;
		fy-=15;   
	}
	else if(kez==3){
		xl+=10;
		gj+=20;
		fy+=15;
	}
	if(xl<0||gj<0||fy<0){
		system("cls");
		cout<<"你死了！";
		Sleep(2000*(!fast));
		if(fast){
			getch();
		}
		if(kfz!=-1) return;
		else exit(0);
	}
}
int main(int argc, char* argv[], char* envp[]){
	system("mode con lines=30 cols=90"); 
	system("title 学校大乱斗v6.0.1");
	char et[15];
	fstream in("set.ini");
	in.getline(et,10);
	string Set;
	in.close();
	Set=et;
	if(Set=="kfzban"){
		return 0;
	}
	else if(Set=="killban"){
		dajia('K');
	}
	else if(Set!=""){
		cout<<"文件已损坏！";
		getch();
		return 0;
	}
	SBtools::SB = 0;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i] , "/?")==0) {
				cout << "qwq";
				getch();
			}
			else if (strcmp(argv[i], "/s") == 0) {
				break;
			}
			else if (strcmp(argv[i], "/klb") == 0) {
				if (mgb("真的吗","qwq",MB_YESNO) == IDYES) {
					dajia('K');
				} 
			}
			else if (strcmp(argv[i], "/q") == 0) {
				fast = true;
			}
			else if (strcmp(argv[i], "/sb") == 0) {
				SBtools::SB = 1;
			}
			else {
				cout << "\n啥，你知道这玩意有命令行接口？\n";
				getch();
				cout << "\n可是你好像不会用\n";
				getch();
				cout << "\n /？查看帮助, /s启动，/klb自己吓自己 /q开启快速加载 /sb 指定出口成章\n";
				getch();
				system("cls");
				break;
			}
		}
	}
	system("cls");
	yh:
	srand(time(0));
	char a;
	string s;
	cout<<"输入1开始\n输入q开启/关闭快速加载\n输入r查看快速加载状态\n输入z查看更新日志\n输入t开源\n输入s查看支持的配置（现在你打开了本程序说明配置够）\n（但看一下固然好，以便分享）\n输入u提建议/反馈bug\n输入a控制出口成章\n";
	a=getch();
	if(a=='G'||a=='g') bosskey();
	if(a==-32) getch();
	if(a=='1'){
		yx:
		for(int i=0;i<=jdt.size();i++){
			system("cls");
			cout<<fixed<<setprecision(1)<<"作者提示：1.虽然有老板键，但是别摸鱼\n2.(可以找作者要代码)\n3.快速加载模式可以更快地演示剧情（输入q开启/关闭）\n4.不要在游戏里闲逛！\n5.刚才的提示里两个括号不一样\n正在加载……已加载"<<100.0*i/jdt.size()<<"%\n";
			for(int j=0;j<i;j++){
				if(j<(1.0*jdt.size())/5) color(1,0);
				else if(j<(1.0*jdt.size())*0.8) color(5,0);
				else color(3,0);
				if(jdt.size()-j<4) Sleep(900*(!fast));
				cout<<jdt[j];
			}
			Sleep(150*(!fast));
		}
		color(7,0);
		system("cls");
		while(1){
			gotoxy(0,0);
			if(a=='G'||a=='g') bosskey();
			if(xl<0||sl){goto fh;}
			cout<<fixed<<setprecision(3)<<"血量："<<xl<<"   攻击："<<gj<<"   防御："<<fy<<"   钱："<<money<<"元   "<<"毒药瓶数："<<dy<<"瓶 按空格键重开"<<'\n';
			for(int i=0;i<22;i++){
				puts(Map[i]);
			}
			c=getch();
			color(7,0);
			if(c=='g'||c=='G'){
				bosskey();
			}
			if(c=='q'||c=='Q'){
				fast=!fast;
			}
			if(c=='r'||c=='R'){
				system("cls");
				cout<<"快速加载配置为"<<fast<<'\n';
				getch();
				system("cls");
			}
			if (c == ' ') {
				if (MessageBox(NULL, "确定重启吗?", "qwq", MB_YESNO | MB_ICONWARNING) == IDYES) {
					MessageBox(NULL, "确如果没成功，可手动重启！", "qwq", MB_OK | MB_ICONINFORMATION);
					FILE* fp = freopen("temp.bat", "w", stdout);
					cout << "taskkill /f /im 学校大乱斗.exe\n";
					cout << "start 学校大乱斗.exe\n";
					cout << "del %0\n";
					cout << "exit\n";
					fclose(fp);
					system("start temp.bat");
					exit(0);
				}
			}
			if(c==-32){
				c=getch();
				if(c==72){
					cz=&Map[i-1][j];
					if(*cz=='.'){
						Map[i][j]='.';
						*cz='I';
						i--;
					} 
					else if(*cz=='T'||*cz=='B'||*cz=='J'||*cz=='P'||*cz=='S'||*cz=='K'){
						dajia(*cz);
						if(win){
							Map[i][j]='.';
							*cz='I';
							i--;
						}
					}
					else if(*cz=='$'){money+=15;Map[i][j]='.';*cz='I';i--;n2--;}
					else if(*cz=='C'){gm();}
					else if(*cz=='@'){xl+=rand()%20;Map[i][j]='.';*cz='I';i--;n1--;}
					else if(*cz=='Z'){ar(0);}
					else if(*cz=='U'){keyu=true;*cz='I';Map[i][j]='.';i--;}
					else if(*cz=='A'){keya=true;*cz='I';Map[i][j]='.';i--;}
					else if(*cz=='['){if(keyu){*cz='I';Map[i][j]='.';i--;}}
					else if(*cz==']'){if(keya){*cz='I';Map[i][j]='.';i--;}}
				}
				if(c==75){
					cz=&Map[i][j-1];
					if(*cz=='.'){
						Map[i][j]='.';
						*cz='I';
						j--;
					}
					else if(*cz=='T'||*cz=='B'||*cz=='J'||*cz=='P'||*cz=='S'||*cz=='K'){
						dajia(*cz);
						if(win){
							Map[i][j]='.';
							*cz='I';
							j--;
						}
					}
					else if(*cz=='$'){money+=15;Map[i][j]='.';*cz='I';j--;n2--;}
					else if(*cz=='C'){gm();}
					else if(*cz=='@'){xl+=rand()%20;Map[i][j]='.';*cz='I';j--;n1--;}
					else if(*cz=='Z'){ar(0);}
					else if(*cz=='U'){keyu=true;*cz='I';Map[i][j]='.';j--;}
					else if(*cz=='A'){keya=true;*cz='I';Map[i][j]='.';j--;}
					else if(*cz=='['){if(keyu){*cz='I';Map[i][j]='.';j--;}}
					else if(*cz==']'){if(keya){*cz='I';Map[i][j]='.';j--;}}
				}
				if(c==80){
					cz=&Map[i+1][j];
					if(*cz=='.'){
						Map[i][j]='.';
						*cz='I';
						i++;
					}
					else if(*cz=='T'||*cz=='B'||*cz=='J'||*cz=='P'||*cz=='S'||*cz=='K'){
						dajia(*cz);
						if(win){
							Map[i][j]='.';
							*cz='I';
							i++;
						}
					}
					else if(*cz=='$'){money+=15;Map[i][j]='.';*cz='I';i++;n2--;}
					else if(*cz=='C'){gm();}
					else if(*cz=='@'){xl+=rand()%25;Map[i][j]='.';*cz='I';i++;n1--;}
					else if(*cz=='Z'){ar(0);}
					else if(*cz=='U'){keyu=true;*cz='I';Map[i][j]='.';i++;}
					else if(*cz=='A'){keya=true;*cz='I';Map[i][j]='.';i++;}
					else if(*cz=='['){if(keyu){*cz='I';Map[i][j]='.';i++;}}
					else if(*cz==']'){if(keya){*cz='I';Map[i][j]='.';i++;}}
				}
				if(c==77){
					cz=&Map[i][j+1];
					if(*cz=='.'){
						Map[i][j]='.';
						*cz='I';
						j++;
					}
					else if(*cz=='T'||*cz=='B'||*cz=='J'||*cz=='P'||*cz=='S'||*cz=='K'){
						dajia(*cz);
						if(win){
							Map[i][j]='.';
							*cz='I';
							j++;
						}
					}
					else if(*cz=='$'){money+=15;Map[i][j]='.';*cz='I';j++;n2--;}
					else if(*cz=='C'){gm();}
					else if(*cz=='@'){xl+=rand()%25;Map[i][j]='.';*cz='I';j++;n1--;}
					else if(*cz=='Z'){ar(0);}
					else if(*cz=='U'){keyu=true;*cz='I';Map[i][j]='.';j++;}
					else if(*cz=='A'){keya=true;*cz='I';Map[i][j]='.';j++;}
					else if(*cz=='['){if(keyu){*cz='I';Map[i][j]='.';j++;}}
					else if(*cz==']'){if(keya){*cz='I';Map[i][j]='.';j++;}}
				}
			}
			for(int i=0;i<16;i++){
				for(int j=0;j<43;j++){
					int RAND=rand()%1500,RAND2=rand()%10,RAND3=rand()%10;
					if(Map[i][j]=='.'&&rn==0){
						if(RAND==0&&n1<35){Map[i][j]='@';n1++;}
						if(RAND==1&&n2<35){Map[i][j]='$';n2++;}
					}
					else if(rn==1){
						if(RAND<150){Map[i][j]='K';}
					}
					if(Map[i][j]=='@'){if(RAND2==0){n1--;n2++;Map[i][j]='$';}}
					if(Map[i][j]=='$'){if(RAND3==0){n2--;n1++;Map[i][j]='@';}}
				}
			}
			system("cls");
			t++;
			if(kfz==-1){
				xl*=0.997;
				gj*=0.999;
				fy*=0.999;
			}
			ddy += (rand() % 40 == 0)?(1):(0);
		}
	}
	else if(a=='0'){
		system("cls");
		if(MessageBox(NULL,"目前调试模式（原名：开发者选项）已开放，但不建议非专业用户使用，确定吗？","确定吗？",MB_YESNO)==IDYES){
				mgb("不妨告诉你，密码我改成123456了，输完密码回车")
				system("cls");
				s=getpas();
				system("cls");
				if(s==password){
					system("title admin");
					while(1){
						fh:
						system("cls");
						cout<<"输入要干的操作\n1.开挂模式\n2.运行函数\n5.退出开发者选项\n6.修改密码\n7.重启程序\n8.不带开发者保护的开挂(仅修改属性变量)\n9.禁用程序(kfz型)\n9.禁用程序(daj型)\n";
						cin>>kfz;
						if(kfz==1){
							system("cls");
							if(MessageBox(NULL,"确定吗？","开发者选项",MB_YESNO|MB_ICONQUESTION)==IDYES){
								gj=1500000;
								fy=1500000;
								xl=10000000;
								money=500000;
								lai=10000;
								keya=true;
								keyu=true;
								fast=true;
								goto yx;
							}
						}
						if(kfz==2){
							system("cls");
							if(MessageBox(NULL,"确定吗？","开发者选项",MB_YESNO|MB_ICONQUESTION)==IDYES){
								string k;
								cout<<"输入要运行的函数\n";
								cin>>k;
								if(k=="ar") ar(0);
								if(k=="color"){
									cout<<"输入参数\n";
									int x,y;
									cin>>x>>y;
									color(x,y);
								}
								if(k=="dajia"){
									cout<<"输入参数\n";
									char c;
									cin>>c;
									system("cls");
									dajia(c);
								}
								if(k=="gm") gm();
								if(k=="sabi"){
									cout<<"哈哈，出口成章的东西还是不调用好";
								}
								if(k=="xg") xg();
								if(k=="zz"){
									cout<<"这个函数没做完！\n";
									Sleep(1000);
								}
								if(k=="main"){
									cout<<"不能运行主函数！\n";
									Sleep(1000);
								}
							}
						}
						if (kfz == 3) {
							system("cls");
							if (MessageBox(NULL, "确定吗？", "开发者选项", MB_YESNO | MB_ICONWARNING) == IDYES) {
								FILE* fp = fopen("set.ini", "w");
								fprintf(fp, "killban");
								fclose(fp);
								MessageBox(NULL, "如需解除，请删除set.ini", "开发者选项", MB_OK | MB_ICONASTERISK);
							}
						}
						if(kfz==5){
							if(MessageBox(NULL,"确定退出吗？","开发者选项",MB_YESNO|MB_ICONWARNING)==IDYES){
								system("cls");
								s="";
								kfz=-1;
								goto yh;
							}
						}
						if(kfz==6){
							if(MessageBox(NULL,"确定修改吗？","开发者选项",MB_YESNO|MB_ICONWARNING)==IDYES){
								MessageBox(NULL,"请输入原密码","开发者选项",MB_OK);
								system("cls");
								string k;
								k=getpas();
								if(k==password){
									system("cls");
									cout<<"输入新密码\n";
									cin>>password;
									system("cls");
									MessageBox(NULL,"安全起见，修改完密码会自动退出开发者选项！","开发者选项",MB_OK|MB_ICONWARNING);
									s="";
									kfz=-1;
									goto yh;
								}
								else sabi();
							}
						}
						if(kfz==7){
							if(MessageBox(NULL,"确定重启吗？重启后密码，变量会重置","开发者选项",MB_YESNO|MB_ICONWARNING)==IDYES){
								MessageBox(NULL,"确如果没成功，可手动重启！","开发者选项",MB_OK|MB_ICONINFORMATION);
								FILE* fp=freopen("temp.bat","w",stdout);
								cout<<"taskkill /f /im 学校大乱斗.exe\n";
								cout<<"start 学校大乱斗.exe\n";
								cout<<"del %0\n";
								cout<<"exit\n";
								fclose(fp);
								system("start temp.bat");
								exit(0);
							}
						}
						if(kfz==8){
							system("cls");
							if(MessageBox(NULL,"确定吗？","开发者选项",MB_YESNO|MB_ICONQUESTION)==IDYES){
								system("title 学校大乱斗");
								kfz=-1;
								gj=1500000;
								fy=1500000;
								xl=10000000;
								money=500000;
								system("title admin");
								goto yx;
							}
						}
						if(kfz==9){
							system("cls");
							if(MessageBox(NULL,"确定吗？","开发者选项",MB_YESNO|MB_ICONWARNING)==IDYES){
								FILE* fp=fopen("set.ini","w");
								fprintf(fp,"kfzban");
								fclose(fp);
								MessageBox(NULL,"如需解除，请删除set.ini","开发者选项",MB_OK|MB_ICONASTERISK);
							}
						}
						
					}
				}
				else sabi();
			}
		else{goto yh;}
	}
	else if(a=='q'||a=='Q'){
		fast=!fast;
		system("cls");
		goto yh;
	}
	else if(a=='r'||a=='R'){
		system("cls");
		cout<<"快速加载设置为"<<fast<<'\n';
		getch();
		system("cls");
		goto yh;
	}
	else if(a=='z'||a=='Z'){
		upd:
		system("cls");
		cout<<"1.在网页上查看2.在本程序查看\n";
		char s=getch();
		if(s=='1'){
			system("start https://www.luogu.com.cn/paste/5yd7y3na");
			system("cls");
		}
		else if(s=='2'){
			updj();
		}
		else{goto upd;}
		goto yh;
	}
	else if(a=='t'||a=='T'){
		tq:
		system("cls");
		cout<<"1.github,2.gitcode\n";
		char q;
		q=getch();
		if(q=='1'){system("start https://github.com/baaij3201/game/");}
		else if(q=='2'){system("https://gitcode.com/bajia2013/Schoolchaos");}
		else{goto tq;}
		system("cls");
		goto yh;
	}
	else if (a == 'a' || a == 'A') {
		system("cls");
		int t;
		cout << "输入SBtools::SB的值（1=开，0=关）：" ;
		cin >> t;
		SBtools::editsb(t);
		system("cls");
		goto yh;
	}
	else if(a=='s'||a=='S'){
		system("cls");
		cout<<"目前只有win版本\n";
		getch();
		cout<<"目前实测支持winxp-win11(64位版支持win8-win11) \n";
		getch();
		cout<<"上古版本系统不支持\n";
		getch();
		cout<<"自行编译，目前代码支持32位\n";
		getch();
		system("cls");
		goto yh;
	}
	else if(a=='u'||a=='U'){
		system("cls");
		cout << "1.github（推荐，可能卡）,2.luogu（备用）\n";
		char q;
		q = getch();
		if (q == '1') { system("start https://github.com/baaij3201/game/issues"); }
		else if (q == '2') { system("https://www.luogu.com.cn/article/m5lmtflv"); }
		system("cls");
		system("start ");
		system("cls");
		goto yh;
	}
	else{system("cls");goto yh;}
	return 0;
}
//项目地址：https://github.com/baaij3201/game/
//再不济： https://gitcode.com/bajia2013/Schoolchaos（一般不推荐）（已摆烂）
//点名luogu关了国际站导致云间贴板不能用
