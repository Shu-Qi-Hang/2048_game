#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<string>
/*
	成就： 
	1.初出茅庐：  完成第一次移动
	2.如日中升：  合成数字512
	3.终极目标：  合成数字2048
	4.闪电战：    游戏在50回合内结束 
	5.幸运星：    连续生成3次数字4 
	6.持久战：    游戏持续300回合以上 
	7.超越极限：  合成数字4096
	8.改代码的狗：更改代码数据 
*/
using namespace std;
const int ab=4,m=8;
double s,s_;
bool flag_ach[m+1],ove,ma_flag=0,in_flag=0,game_f=1;
char in;
long long mp[ab+1][ab+1],last[ab+1][ab+1][25];
int last_f[25],f,num4=0,H,time_start,flag_au=0,time_au=3;
char in_i(){
	if(in_flag==1){
		bool flag_in;
		string str;
		char in_i;
		ifstream inFile("输入插件.txt");
		inFile>>in_flag>>str>>in_i>>flag_in;
		if(str=="main"&&flag_in){
			ofstream outfile("输入插件.txt");
			outfile<<in_flag<<" "<<"main "<<in_i<<" 0";
			outfile.close();
			return in_i;
		}
		else
			return ' ';
		inFile.close();
	}
	else{
		return getch();
	}
} 
void home(){
	cout<<"欢迎来到2048 v.2.0.0\n\n\n";
	cout<<"1.开始游戏     2.检索记录     3.使用需知\n\n";
	cout<<"4.成就列表     5.插件管理     6.更新日志\n\n";
	do in=in_i(); while(in==' ');
}
void de_1(){
	ifstream inFile("移动插件.txt");
	if(inFile.good()){
		inFile>>ma_flag;
	}
	inFile.close();
}
void de_2(){
	ifstream inFile("输入插件.txt");
	if(inFile.good()){
		inFile>>in_flag;
	}
	inFile.close();
} 
void de(){
	de_1();
	de_2();
}
void ass(){
	ifstream inFile("记录.txt");
	if(!inFile.good()){
		ofstream outfile("记录.txt");
		outfile<<"0\n";
		for(int i=1;i<=m;i++){
			outfile<<"0 ";
		}
		outfile.close();
	}
	inFile.close();
	for(int i=1;i<=ab;i++){
		for(int j=1;j<=ab;j++){
			mp[i][j]=0;
		}
	}
	system("title 2048 v.2.0.0");
	srand(time(0));
}
void ass_co1(){
	ifstream inFile("移动插件.txt");
	if(inFile.good()){
		ofstream outfile("移动插件.txt");
		outfile<<"0\n";
		outfile.close();
	}
	inFile.close();
} 
void ass_co2(){
	ifstream inFile("输入插件.txt");
	if(inFile.good()){
		ofstream outfile("输入插件.txt");
		outfile<<"0\n";
		outfile.close();
	}
	inFile.close();
}
void ass_co(){
	ass_co1();
	ass_co2();
}
void ma(){
	if(ma_flag){
		ofstream outfile("地图.txt");
		outfile<<ove<<"\n";
		for(int i=1;i<=ab;i++){
			for(int j=1;j<=ab;j++){
				outfile<<mp[i][j]<<" ";
			}
			outfile<<"\n";
		}
		outfile.close();
	}
}
void out(){
	system("cls");
	cout<<f<<"\t*"<<s_<<"\t第"<<H<<"回合\n\n";
	if(time(0)<time_start+time_au){
		if(flag_au==1) cout<<"解锁成就：初出茅庐"; 
		if(flag_au==2) cout<<"解锁成就：如日中升"; 
		if(flag_au==3) cout<<"解锁成就：终极目标"; 
		if(flag_au==5) cout<<"解锁成就：幸运星"; 
		if(flag_au==6) cout<<"解锁成就：持久战"; 
		if(flag_au==7) cout<<"解锁成就：超越极限"; 
		if(flag_au==8) cout<<"解锁成就：改代码的狗"; 
	}
	else{
		time_start=0;
	}
	cout<<"\n\n";
	for(int i=1;i<=8*(ab+1)+3;i++){
		cout<<"_";
	}
	for(int i=1;i<=ab;i++){
		cout<<"\n│\t";
		for(int j=1;j<=ab;j++){
			if(mp[i][j]==0){
				cout<<"  ";
			}
			else if(mp[i][j]<10000){
				cout<<mp[i][j];
			}
			else if(mp[i][j]<1000000){
				cout<<mp[i][j]/1000<<"K";
			}
			else{
				cout<<mp[i][j]/1000000<<"B";
			}
			cout<<"\t ";
		}
		cout<<"│\n";
	}
	for(int i=1;i<=8*(ab+1)+3;i++){
		cout<<"_";
	}
	cout<<"\n";
}
bool over(){
	bool flag=0;
	for(int i=1;i<=ab;i++){
		for(int j=1;j<=ab;j++){
			if(mp[i][j]==0){
				flag=1;
				break;
			}
			else if(i>1&&mp[i-1][j]==mp[i][j]){
				flag=1;
				break;
			}
			else if(j>1&&mp[i][j-1]==mp[i][j]){
				flag=1;
				break;
			}
			else if(i<ab&&mp[i+1][j]==mp[i][j]){
				flag=1;
				break;
			}
			else if(j<ab&&mp[i][j+1]==mp[i][j]){
				flag=1;
				break;
			}
		}
	}
	return flag;
}
void last_in(){
	system("cls");
	int n;
	ifstream inFile("记录.txt");
	if(!inFile.good()){
		ofstream outfile("记录.txt");
		outfile<<"0\n";
		for(int i=1;i<=m;i++){
			outfile<<"0 ";
		}
		outfile.close();
	}
	inFile>>n;
	for(int i=1;i<=n;i++){
		inFile>>last_f[i];
		if(last_f[i]%3||(last_f[i]/3-2)%2){
			cout<<"记录读取错误\n\n";
			return ;
		}
		last_f[i]=(last_f[i]/3-2)/2; 
		for(int a=1;a<=ab;a++){
			for(int b=1;b<=ab;b++){
				inFile>>last[a][b][i];
				if(last[a][b][i]%3||(last[a][b][i]/3-2)%2){
					cout<<"记录读取错误\n\n";
					return ;
				}
				last[a][b][i]=(last[a][b][i]/3-2)/2;
			}
		}
	}
	for(int i=1;i<=m;i++){
		inFile>>flag_ach[i];
	}
	inFile.close();
}
void last_in_out(){
	int n;
	ifstream inFile("记录.txt");
	inFile>>n;
	inFile.close();
	if(n==0){
		cout<<"当前暂无记录，快开始游戏吧\n\n";
	}
	else{
		cout<<"检索到"<<n<<"个记录\n\n\n";
	}
	for(int i=1;i<=n;i++){
		if(i!=1){
			cout<<"\n\n\n";
		}
		cout<<i<<".";
		cout<<"共计"<<last_f[i]<<"分\n\n地图如下\n";
		for(int a=1;a<=ab;a++){
			for(int b=1;b<=ab;b++){
				if(last[a][b][i]<10000){
					cout<<last[a][b][i];
				}
				else if(last[a][b][i]<1000000){
					cout<<last[a][b][i]/1000<<"K";
				}
				else{
					cout<<last[a][b][i]/1000000<<"B";	
				}
				cout<<"\t";
			}
			cout<<"\n";
		}
	}
	cout<<"\n\n按任意键返回主界面\n\n";
	while(in_i()==' ') continue;
}
void last_out(bool fla){
	int n;
	ifstream inFile("记录.txt");
	if(!inFile.good()){
		ofstream outfile("记录.txt");
		outfile<<"0\n";
		for(int i=1;i<=m;i++){
			outfile<<"0 ";
		}
		outfile.close();
	}
	inFile>>n;
	for(int i=1;i<=n;i++){
		inFile>>last_f[i];
		if(last_f[i]%3||(last_f[i]/3-2)%2){
			cout<<"记录读取错误\n\n";
			return ;
		}
		last_f[i]=(last_f[i]/3-2)/2; 
		for(int a=1;a<=ab;a++){
			for(int b=1;b<=ab;b++){
				inFile>>last[a][b][i];
				if(last[a][b][i]%3||(last[a][b][i]/3-2)%2){
					cout<<"记录读取错误\n\n";
					return ;
				}
				last[a][b][i]=(last[a][b][i]/3-2)/2;   //x=(x*2+2)*3
			}
		}
	}
	ofstream outFile("记录.txt");
	if(fla){
		outFile<<min(20,n+1)<<"\n\n";
		outFile<<(f*2+2)*3<<"\n";
		for(int a=1;a<=ab;a++){
			for(int b=1;b<=ab;b++){
				outFile<<(mp[a][b]*2+2)*3<<" ";
			}
			outFile<<"\n";
		}
		outFile<<"\n";
	}
	else{
		outFile<<n<<"\n\n";
	}
	for(int i=1;i<=n&&i<=20;i++){
		outFile<<(last_f[i]*2+2)*3<<"\n";
		for(int a=1;a<=ab;a++){
			for(int b=1;b<=ab;b++){
				outFile<<(last[a][b][i]*2+2)*3<<" ";
			}
			outFile<<"\n";
		}
		outFile<<"\n";
	}
	outFile<<"\n";
	for(int i=1;i<=m;i++){
		outFile<<flag_ach[i]<<" ";
	}
	outFile<<"\n";
	outFile.close();
}
void ach(){
	start:
	last_in();
	bool flag=0;
	system("cls");
	cout<<"成就\n\n\n";
	for(int i=1;i<=m;i++){
		if(flag_ach[i]==1){
			if(i==1) cout<<"1.初出茅庐：  完成第一次移动\n\n"; 
			if(i==2) cout<<"2.如日中升：  合成数字512\n\n"; 
			if(i==3) cout<<"3.终极目标：  合成数字2048\n\n"; 
			if(i==4) cout<<"4.闪电战：    游戏在50回合内结束\n\n"; 
			if(i==5) cout<<"5.幸运星：    连续生成3次数字4\n\n"; 
			if(i==6) cout<<"6.持久战：    游戏持续300回合以上\n\n"; 
			if(i==7) cout<<"7.超越极限：  合成数字4096\n\n";
			if(i==8) cout<<"8.改代码的狗：更改代码数据\n\n";
			flag=1; 
		}
	}
	if(flag==0){
		cout<<"暂未解锁成就，快去游戏吧\n\n";
	}
	cout<<"\n解锁成就提示 ";
	if(time_au>0) cout<<"yes";
	else cout<<"no ";
	cout<<" (按x更改)\n";
	cout<<"\n\n按其他键返回主界面\n\n";
	last_out(0);
	if(in_flag==1){
		char x;
		do x=in_i(); while(x==' ');
		if(x=='x'){
			if(time_au>0) time_au=-1;
			else time_au=3;
			goto start;
		}	
	}
	else
		while(in_i()==' ') continue;
}
void unl(){
	bool fl=0;
	for(int i=1;i<=ab;i++){
		for(int j=1;j<=ab;j++){
			if(mp[i][j]>=512&&flag_ach[2]==0){
				flag_ach[2]=1;
				flag_au=2;
				fl=1;
			}
			if(mp[i][j]>=2048&&flag_ach[3]==0){
				flag_ach[3]=1;
				flag_au=3;
				fl=1;
			}
			if(mp[i][j]>=4096&&flag_ach[7]==0){
				flag_ach[7]=1;
				flag_au=7;
				fl=1;
			}
		}
	}
	if(num4>=3&&flag_ach[5]==0){
		flag_ach[5]=1;
		flag_au=5;
		fl=1;
	}
	if(H<=50&&ove==0&&flag_ach[4]==0){
		flag_ach[4]=1;
	}
	if(H>=300&&ove==1&&flag_ach[6]==0){
		flag_ach[6]=1;
		flag_au=6;
		fl=1;
	}
	if(ab!=4&&flag_ach[8]==0){
		flag_ach[8]=1;
		flag_au=8;
		fl=1;
	} 
	if(fl==1){
		time_start=time(0);
	}
} 
void day(){
	system("cls");
	cout<<"qihangxing制作\n\n\n"; 
	cout<<"2025.3.08  v.1.0.0   完成基本的移动和合成\n\n";
	cout<<"2025.3.10  v.1.1.0   美化界面，并优化效率\n\n";
	cout<<"2025.3.11  v.1.2.0   添加倍速，主界面及日志\n\n";
	cout<<"2025.3.11  v.1.2.5   添加结束，修复已知BUG\n\n";
	cout<<"2025.3.12  v.1.4.0   添加记录，修复已知BUG\n\n";
	cout<<"2025.3.13  v.1.4.5   添加操作需知\n\n";
	cout<<"2025.3.13  v.1.5.0   优化记录功能\n\n";
	cout<<"2025.3.16  v.1.5.5   更改部分名称，修复已知BUG\n\n";
	cout<<"2025.3.16  v.1.6.0   添加成就功能\n\n";
	cout<<"2025.3.17  v.1.6.5   添加成就提示，优化游戏机制\n\n";
	cout<<"2025.3.20  v.1.7.0   适配 [2048 移动辅助插件] \n\n";
	cout<<"2025.3.20  v.1.7.5   替换 [建议收集] 为 [插件管理] \n\n";
	cout<<"2025.3.21  v.1.8.0   修复已知BUG\n\n";
	cout<<"2025.3.29  v.1.8.5   适配 [2048 输入辅助插件] \n\n";
	cout<<"2025.3.30  v.1.9.0   美化界面，优化游戏机制\n\n";
	cout<<"2025.3.31  v.1.9.5   添加3个成就和成就存档功能\n\n";
	cout<<"2025.4.07  v.2.0.0   修复已知BUG，调整操作需知\n\n";
	cout<<"\n\n按任意键返回主界面\n\n";
	while(in_i()==' ') continue;
}
void help(){
	system("cls");
	cout<<"操作需知：\n\n";
	cout<<"1.按 w,a,s,d   移动\n\n";
	cout<<"2.按 x         调整倍速\n\n";
	cout<<"3.按 e         结束游戏\n\n";
	cout<<"\n功能注意：\n\n";
	cout<<"1.存档的地图大小不同会导致读取错误哦!\n\n";
	cout<<"2.移动插件按 [ e ] 退出才会退出托管\n\n";
	cout<<"\n\n按任意键返回主界面\n\n";
	while(in_i()==' ') continue;
}
void game(){
	H=0;ove=1;f=0;s=1;s_=1;num4=0;
	unl();
	while(1){
		ma();
		de();
		char x;	
		int i=1;
		if(x!='e'&&x!='x'){
			while(i<=ab*ab){
				int a=rand()%ab+1,b=rand()%ab+1;
				if(mp[a][b]==0){
					mp[a][b]=4-2*bool(rand()%4);
					if(mp[a][b]==4) num4+=1;
					else num4=0;
					break;
				}
				else i++;
			}
		}
		out();
		Sleep(750);
		a:
		if(ma_flag){
			ifstream inFile("移动插件.txt");
			inFile>>ma_flag>>game_f;
			if(game_f==0){
				s=0; s_=0;
				inFile>>x;
			}
			inFile.close();
		}
		else if(in_flag){
			do x=in_i(); while(x==' ');
		}
		else{
			x=in_i();
		}
		if(x=='w'){
			if(flag_ach[1]==0){
				flag_ach[1]=1;
				flag_au=1;
				time_start=time(0);
			}
			for(int i=1;i<=ab;i++){
				for(int j=1;j<=ab;j++){
					int X=i;
					while(mp[X][j]!=0&&X>1&&(mp[X-1][j]==0||mp[X-1][j]==mp[X][j])){
						if(mp[X-1][j]==0){
							mp[X-1][j]=mp[X][j];
							mp[X][j]=0;
						}
						else{
							f+=mp[X][j]*2;
							mp[X-1][j]=mp[X][j]*2;
							mp[X][j]=0;
						}
						X--;
						out();
						Sleep(int(100*s)); 
					}
				}
			}
			H++;
		}
		else if(x=='a'){
			if(flag_ach[1]==0){
				flag_ach[1]=1;
				flag_au=1;
				time_start=time(0);
			}
			for(int j=1;j<=ab;j++){
				for(int i=1;i<=ab;i++){
					int Y=j;
					while(mp[i][Y]!=0&&Y>1&&(mp[i][Y-1]==0||mp[i][Y-1]==mp[i][Y])){
						if(mp[i][Y-1]==0){
							mp[i][Y-1]=mp[i][Y];
							mp[i][Y]=0;
						}
						else{
							f+=mp[i][Y]*2;
							mp[i][Y-1]=mp[i][Y]*2;
							mp[i][Y]=0;
						}
						Y--;
						out();
						Sleep(int(100*s)); 
					}
				}
			}
			H++;
		}
		else if(x=='s'){
			if(flag_ach[1]==0){
				flag_ach[1]=1;
				flag_au=1;
				time_start=time(0);
			}
			for(int i=ab;i>=1;i--){
				for(int j=1;j<=ab;j++){
					int X=i;
					while(mp[X][j]!=0&&X<ab&&(mp[X+1][j]==0||mp[X+1][j]==mp[X][j])){
						if(mp[X+1][j]==0){
							mp[X+1][j]=mp[X][j];
							mp[X][j]=0;
						}
						else{
							f+=mp[X][j]*2;
							mp[X+1][j]=mp[X][j]*2;
							mp[X][j]=0;
						}
						X++;
						out();
						Sleep(int(100*s)); 
					}
				}
			}
			H++;
		}
		else if(x=='d'){
			if(flag_ach[1]==0){
				flag_ach[1]=1;
				flag_au=1;
				time_start=time(0);
			}
			for(int j=ab;j>=1;j--){
				for(int i=1;i<=ab;i++){
					int Y=j;
					while(mp[i][Y]!=0&&Y<ab&&(mp[i][Y+1]==0||mp[i][Y+1]==mp[i][Y])){
						if(mp[i][Y+1]==0){
							mp[i][Y+1]=mp[i][Y];
							mp[i][Y]=0;
						}
						else{
							f+=mp[i][Y]*2;
							mp[i][Y+1]=mp[i][Y]*2;
							mp[i][Y]=0;
						}
						Y++;
						out();
						Sleep(int(100*s)); 
					}
					
				}
			}
			H++;
		}
		else if(x=='x'){
			cout<<"\n倍速调节\n\n";
			cin>>s_;
			if(s_==0){
				s=0;
			}
			else{
				s=1/s_;
			}
		}
		else if(x=='e'){
			cout<<"确定退出本局游戏 (y/n)\n\n";
			char y;
			cin>>y;
			if(y=='y'){
				out();
				break;
			}
		} 
		else{
			cout<<"重新输入";
			Sleep(500); 
			out();
			goto a;
		}
		if(over()==0){
			ove=0;
			out();
			unl();
			break;
		}
		unl();
	}
	unl();
	ma();
	last_out(1);
	cout<<"本局游戏共"<<f<<"分\n\n";
	cout<<"\n\n按任意键返回主界面\n\n";
	while(in_i()==' ') continue;
} 
void co(){
	de();
	bool flag_co=0;
	system("cls");
	if(ma_flag==1){
		if(flag_co==0){
			cout<<"已连接插件:\n\n";
			flag_co=1;
		}
		cout<<"2048 移动辅助插件\n\n";
	}
	if(in_flag==1){
		if(flag_co==0){
			cout<<"已连接插件:\n\n";
			flag_co=1;
		}
		cout<<"2048 输入辅助插件\n\n";
	}
	if(flag_co==0){
		cout<<"暂未连接到插件\n\n";
	} 
	cout<<"\n\n按任意键返回主界面\n\n";
	while(in_i()==' ') continue;
}
int main(){
	ass_co();
	while(1){
		system("cls"); 
		de();
		ass();
		home();
		if(in=='1'){
			game();
		}
		else if(in=='2'){
			last_in();
			last_in_out();
		}
		else if(in=='3'){
			help();
		}
		else if(in=='4'){
			ach(); 
		}
		else if(in=='5'){
			co();
		}
		else if(in=='6'){
			day();
		}
	}
	return 0;
}
