#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<string>
/*
	�ɾͣ� 
	1.����é®��  ��ɵ�һ���ƶ�
	2.����������  �ϳ�����512
	3.�ռ�Ŀ�꣺  �ϳ�����2048
	4.����ս��    ��Ϸ��50�غ��ڽ��� 
	5.�����ǣ�    ��������3������4 
	6.�־�ս��    ��Ϸ����300�غ����� 
	7.��Խ���ޣ�  �ϳ�����4096
	8.�Ĵ���Ĺ������Ĵ������� 
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
		ifstream inFile("������.txt");
		inFile>>in_flag>>str>>in_i>>flag_in;
		if(str=="main"&&flag_in){
			ofstream outfile("������.txt");
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
	cout<<"��ӭ����2048 v.2.0.0\n\n\n";
	cout<<"1.��ʼ��Ϸ     2.������¼     3.ʹ����֪\n\n";
	cout<<"4.�ɾ��б�     5.�������     6.������־\n\n";
	do in=in_i(); while(in==' ');
}
void de_1(){
	ifstream inFile("�ƶ����.txt");
	if(inFile.good()){
		inFile>>ma_flag;
	}
	inFile.close();
}
void de_2(){
	ifstream inFile("������.txt");
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
	ifstream inFile("��¼.txt");
	if(!inFile.good()){
		ofstream outfile("��¼.txt");
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
	ifstream inFile("�ƶ����.txt");
	if(inFile.good()){
		ofstream outfile("�ƶ����.txt");
		outfile<<"0\n";
		outfile.close();
	}
	inFile.close();
} 
void ass_co2(){
	ifstream inFile("������.txt");
	if(inFile.good()){
		ofstream outfile("������.txt");
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
		ofstream outfile("��ͼ.txt");
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
	cout<<f<<"\t*"<<s_<<"\t��"<<H<<"�غ�\n\n";
	if(time(0)<time_start+time_au){
		if(flag_au==1) cout<<"�����ɾͣ�����é®"; 
		if(flag_au==2) cout<<"�����ɾͣ���������"; 
		if(flag_au==3) cout<<"�����ɾͣ��ռ�Ŀ��"; 
		if(flag_au==5) cout<<"�����ɾͣ�������"; 
		if(flag_au==6) cout<<"�����ɾͣ��־�ս"; 
		if(flag_au==7) cout<<"�����ɾͣ���Խ����"; 
		if(flag_au==8) cout<<"�����ɾͣ��Ĵ���Ĺ�"; 
	}
	else{
		time_start=0;
	}
	cout<<"\n\n";
	for(int i=1;i<=8*(ab+1)+3;i++){
		cout<<"_";
	}
	for(int i=1;i<=ab;i++){
		cout<<"\n��\t";
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
		cout<<"��\n";
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
	ifstream inFile("��¼.txt");
	if(!inFile.good()){
		ofstream outfile("��¼.txt");
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
			cout<<"��¼��ȡ����\n\n";
			return ;
		}
		last_f[i]=(last_f[i]/3-2)/2; 
		for(int a=1;a<=ab;a++){
			for(int b=1;b<=ab;b++){
				inFile>>last[a][b][i];
				if(last[a][b][i]%3||(last[a][b][i]/3-2)%2){
					cout<<"��¼��ȡ����\n\n";
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
	ifstream inFile("��¼.txt");
	inFile>>n;
	inFile.close();
	if(n==0){
		cout<<"��ǰ���޼�¼���쿪ʼ��Ϸ��\n\n";
	}
	else{
		cout<<"������"<<n<<"����¼\n\n\n";
	}
	for(int i=1;i<=n;i++){
		if(i!=1){
			cout<<"\n\n\n";
		}
		cout<<i<<".";
		cout<<"����"<<last_f[i]<<"��\n\n��ͼ����\n";
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
	cout<<"\n\n�����������������\n\n";
	while(in_i()==' ') continue;
}
void last_out(bool fla){
	int n;
	ifstream inFile("��¼.txt");
	if(!inFile.good()){
		ofstream outfile("��¼.txt");
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
			cout<<"��¼��ȡ����\n\n";
			return ;
		}
		last_f[i]=(last_f[i]/3-2)/2; 
		for(int a=1;a<=ab;a++){
			for(int b=1;b<=ab;b++){
				inFile>>last[a][b][i];
				if(last[a][b][i]%3||(last[a][b][i]/3-2)%2){
					cout<<"��¼��ȡ����\n\n";
					return ;
				}
				last[a][b][i]=(last[a][b][i]/3-2)/2;   //x=(x*2+2)*3
			}
		}
	}
	ofstream outFile("��¼.txt");
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
	cout<<"�ɾ�\n\n\n";
	for(int i=1;i<=m;i++){
		if(flag_ach[i]==1){
			if(i==1) cout<<"1.����é®��  ��ɵ�һ���ƶ�\n\n"; 
			if(i==2) cout<<"2.����������  �ϳ�����512\n\n"; 
			if(i==3) cout<<"3.�ռ�Ŀ�꣺  �ϳ�����2048\n\n"; 
			if(i==4) cout<<"4.����ս��    ��Ϸ��50�غ��ڽ���\n\n"; 
			if(i==5) cout<<"5.�����ǣ�    ��������3������4\n\n"; 
			if(i==6) cout<<"6.�־�ս��    ��Ϸ����300�غ�����\n\n"; 
			if(i==7) cout<<"7.��Խ���ޣ�  �ϳ�����4096\n\n";
			if(i==8) cout<<"8.�Ĵ���Ĺ������Ĵ�������\n\n";
			flag=1; 
		}
	}
	if(flag==0){
		cout<<"��δ�����ɾͣ���ȥ��Ϸ��\n\n";
	}
	cout<<"\n�����ɾ���ʾ ";
	if(time_au>0) cout<<"yes";
	else cout<<"no ";
	cout<<" (��x����)\n";
	cout<<"\n\n������������������\n\n";
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
	cout<<"qihangxing����\n\n\n"; 
	cout<<"2025.3.08  v.1.0.0   ��ɻ������ƶ��ͺϳ�\n\n";
	cout<<"2025.3.10  v.1.1.0   �������棬���Ż�Ч��\n\n";
	cout<<"2025.3.11  v.1.2.0   ��ӱ��٣������漰��־\n\n";
	cout<<"2025.3.11  v.1.2.5   ��ӽ������޸���֪BUG\n\n";
	cout<<"2025.3.12  v.1.4.0   ��Ӽ�¼���޸���֪BUG\n\n";
	cout<<"2025.3.13  v.1.4.5   ��Ӳ�����֪\n\n";
	cout<<"2025.3.13  v.1.5.0   �Ż���¼����\n\n";
	cout<<"2025.3.16  v.1.5.5   ���Ĳ������ƣ��޸���֪BUG\n\n";
	cout<<"2025.3.16  v.1.6.0   ��ӳɾ͹���\n\n";
	cout<<"2025.3.17  v.1.6.5   ��ӳɾ���ʾ���Ż���Ϸ����\n\n";
	cout<<"2025.3.20  v.1.7.0   ���� [2048 �ƶ��������] \n\n";
	cout<<"2025.3.20  v.1.7.5   �滻 [�����ռ�] Ϊ [�������] \n\n";
	cout<<"2025.3.21  v.1.8.0   �޸���֪BUG\n\n";
	cout<<"2025.3.29  v.1.8.5   ���� [2048 ���븨�����] \n\n";
	cout<<"2025.3.30  v.1.9.0   �������棬�Ż���Ϸ����\n\n";
	cout<<"2025.3.31  v.1.9.5   ���3���ɾͺͳɾʹ浵����\n\n";
	cout<<"2025.4.07  v.2.0.0   �޸���֪BUG������������֪\n\n";
	cout<<"\n\n�����������������\n\n";
	while(in_i()==' ') continue;
}
void help(){
	system("cls");
	cout<<"������֪��\n\n";
	cout<<"1.�� w,a,s,d   �ƶ�\n\n";
	cout<<"2.�� x         ��������\n\n";
	cout<<"3.�� e         ������Ϸ\n\n";
	cout<<"\n����ע�⣺\n\n";
	cout<<"1.�浵�ĵ�ͼ��С��ͬ�ᵼ�¶�ȡ����Ŷ!\n\n";
	cout<<"2.�ƶ������ [ e ] �˳��Ż��˳��й�\n\n";
	cout<<"\n\n�����������������\n\n";
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
			ifstream inFile("�ƶ����.txt");
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
			cout<<"\n���ٵ���\n\n";
			cin>>s_;
			if(s_==0){
				s=0;
			}
			else{
				s=1/s_;
			}
		}
		else if(x=='e'){
			cout<<"ȷ���˳�������Ϸ (y/n)\n\n";
			char y;
			cin>>y;
			if(y=='y'){
				out();
				break;
			}
		} 
		else{
			cout<<"��������";
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
	cout<<"������Ϸ��"<<f<<"��\n\n";
	cout<<"\n\n�����������������\n\n";
	while(in_i()==' ') continue;
} 
void co(){
	de();
	bool flag_co=0;
	system("cls");
	if(ma_flag==1){
		if(flag_co==0){
			cout<<"�����Ӳ��:\n\n";
			flag_co=1;
		}
		cout<<"2048 �ƶ��������\n\n";
	}
	if(in_flag==1){
		if(flag_co==0){
			cout<<"�����Ӳ��:\n\n";
			flag_co=1;
		}
		cout<<"2048 ���븨�����\n\n";
	}
	if(flag_co==0){
		cout<<"��δ���ӵ����\n\n";
	} 
	cout<<"\n\n�����������������\n\n";
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
