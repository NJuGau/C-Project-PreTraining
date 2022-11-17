#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*
CProject
T076 - Nathanael Juan Gauthama
*/
struct Data{
	char name[31];
	int score;
}PLv1[101],PLv2[101],PLv3[101];

char map[10][10];
int Pl1=0,Pl2=0,Pl3=0;

void Display_Map(){
	system("cls");
	for(int i=0; i<9; i++){
		printf("%s\n", map[i]);
	}	
}

void Sort_Score1(){
	int temp=Pl1;
	while(PLv1[temp].score<=PLv1[temp-1].score){
		if(PLv1[temp].score<PLv1[temp-1].score){
			struct Data tmp = PLv1[temp];
			PLv1[temp]=PLv1[temp-1];
			PLv1[temp-1]=tmp;
		} else if (PLv1[temp].score==PLv1[temp-1].score){
			if(strcmpi(PLv1[temp].name,PLv1[temp-1].name)<0){
			struct Data tmp=PLv1[temp];
			PLv1[temp]=PLv1[temp-1];
			PLv1[temp-1]=tmp;
		}
	}
	temp--;	
}
}

void Sort_Score2(){
	int temp=Pl2;
	while(PLv2[temp].score<=PLv2[temp-1].score){
		if(PLv2[temp].score<PLv2[temp-1].score){
			struct Data tmp=PLv2[temp];
			PLv2[temp]=PLv2[temp-1];
			PLv2[temp-1]=tmp;
		} else if (PLv2[temp].score==PLv2[temp-1].score){
			if(strcmpi(PLv2[temp].name,PLv2[temp-1].name)<0){
			struct Data tmp=PLv2[temp];
			PLv2[temp]=PLv2[temp-1];
			PLv2[temp-1]=tmp;
		}
	}	
	temp--;
	}
}

void Sort_Score3(){
	int temp=Pl3;
	while(PLv3[temp].score<=PLv3[temp-1].score){
		if(PLv3[temp].score<PLv3[temp-1].score){
			struct Data tmp=PLv3[temp];
			PLv3[temp]=PLv3[temp-1];
			PLv3[temp-1]=tmp;
		} else if (PLv3[temp].score==PLv3[temp-1].score){
			if(strcmpi(PLv3[temp].name,PLv3[temp-1].name)<0){
			struct Data tmp=PLv3[temp];
			PLv3[temp]=PLv3[temp-1];
			PLv3[temp-1]=tmp;
		}
	}
	temp--;
	}
}

void Win_Screen(int Lv, int move){
	char name[50];
	do{
		printf("Input name: ");
		scanf("%[^\n]", name); getchar();
		if (strlen(name)<3||strlen(name)>30)
			printf("Name must be 3-30 char long!\n");
	}while (strlen(name)<3||strlen(name)>30);
	switch(Lv){
		case 1:
			Pl1++;
			strcpy(PLv1[Pl1].name,name);
			PLv1[Pl1].score=move;
			Sort_Score1();
			break;
		case 2:
			Pl2++;
			strcpy(PLv2[Pl2].name,name);
			PLv2[Pl2].score=move;
			Sort_Score2();
			break;
		case 3:
			Pl3++;
			strcpy(PLv3[Pl3].name,name);
			PLv3[Pl3].score=move;
			Sort_Score3();
			break;
	}
}

int Validate_Move(int xnow, int ynow, int xnext, int ynext){
	if(map[ynext][xnext]!='#'){
		if(map[ynext][xnext]==' '||map[ynext][xnext]=='T'){
			return 1;
		} else if (map[ynext][xnext]=='@'){
			if(map[ynext+(ynext-ynow)][xnext+(xnext-xnow)]!='#'&&map[ynext+(ynext-ynow)][xnext+(xnext-xnow)]!='@'){
				return 1;
			}
		}
	}
	return 0;
}

void Check_Target(int Gamount, int xgoal[], int ygoal[], int x, int y){
	for(int i=0; i<Gamount; i++){
		if (x==xgoal[i]&&y==ygoal[i]){
			map[y][x]='T';
			return;
		}
	}
}

void Input_Move(int x, int y, int Gamount, int xgoal[], int ygoal[], int *move){
	Display_Map();
	printf("Your move: %d\n", *move);
	int count_goal=0;
	for(int i=0; i<Gamount; i++){
		if(map[ygoal[i]][xgoal[i]]=='@')
			count_goal++;
	}
	if(count_goal==Gamount){
		printf("You Win!\n Your move(s): %d\n", *move);
		return;
	}else{
		printf("x: %d y: %d\n", x,y);
		printf("Press [W A S D] to move.\n");
		printf("Press [ESC] to exit.\n");
		printf("Press [SPACE] to reset.\n");
		char opt = getch();
		int check=0;
		if(opt==27){
			char exit;
			do{
				printf("Are you sure you want to exit [y|n]?\n>> ");
				scanf("%c", &exit); getchar();
				if(exit>=97)
					exit-=32;
			}while(exit!='Y'&&exit!='N');
			if(exit=='Y'){
				*move=-1;
				return;
			} else{
				Input_Move(x,y,Gamount,xgoal,ygoal,move);
			}
		} else if (opt==32){
			printf("Resetting...\n");
			*move=-2;
			return;
		} else {
			if (opt=='W'||opt=='w'){
			check = Validate_Move(x,y,x,y-1);
			if(check==1){
				if(map[y-1][x]=='@'){
					map[y-2][x]='@';
				}
				map[y-1][x]='P';
				map[y][x]=' ';
				Check_Target(Gamount,xgoal,ygoal,x,y);
				*move+=1;
				Input_Move(x,y-1,Gamount,xgoal,ygoal,move);
			}else{
				Input_Move(x,y,Gamount,xgoal,ygoal,move);
			}		
		} else if (opt=='S'||opt=='s'){
			check = Validate_Move(x,y,x,y+1);
			if(check==1){
				if(map[y+1][x]=='@'){
					map[y+2][x]='@';
				}
				map[y+1][x]='P';
				map[y][x]=' ';
				Check_Target(Gamount,xgoal,ygoal,x,y);
				*move+=1;
				Input_Move(x,y+1,Gamount,xgoal,ygoal,move);
			}else{
				Input_Move(x,y,Gamount,xgoal,ygoal,move);
			}
				
		} else if (opt=='A'||opt=='a'){
			check = Validate_Move(x,y,x-1,y);
			if(check==1){
				if(map[y][x-1]=='@'){
					map[y][x-2]='@';
				}
				map[y][x-1]='P';
				map[y][x]=' ';
				Check_Target(Gamount,xgoal,ygoal,x,y);
				*move+=1;
				Input_Move(x-1,y,Gamount,xgoal,ygoal,move);
			}else{
				Input_Move(x,y,Gamount,xgoal,ygoal,move);
			}
			
				
		} else if (opt=='D'||opt=='d'){
			check = Validate_Move(x,y,x+1,y);
			if(check==1){
				if(map[y][x+1]=='@'){
					map[y][x+2]='@';
				}
				map[y][x+1]='P';
				map[y][x]=' ';
				Check_Target(Gamount,xgoal,ygoal,x,y);
				*move+=1;
				Input_Move(x+1,y,Gamount,xgoal,ygoal,move);
			} else{
				Input_Move(x,y,Gamount,xgoal,ygoal,move);
			}	
		}else{
			Input_Move(x,y,Gamount,xgoal,ygoal,move);
		}
		} 
	}
}

int Play_Lv(int Lv){
	int move;
	if(Lv!=0){
		do{
		move=0;
		system("cls");
		int x,y,goal;
		int xgoal[21],ygoal[21];
		FILE* LvSelect;
		switch(Lv){
			case 1:
				LvSelect=fopen("./Map1.txt","r");
				break;
			case 2:
				LvSelect=fopen("./Map2.txt","r");
				break;
			case 3:
				LvSelect=fopen("./Map3.txt","r");
				break;
		}
		fscanf(LvSelect, "%d %d\n", &x,&y);
		fscanf(LvSelect, "%d\n", &goal);
		for(int i=0; i<goal; i++)
			fscanf(LvSelect, "%d %d\n", &xgoal[i],&ygoal[i]);
		for(int i=0; i<9; i++)
			fscanf(LvSelect, "%[^\n]\n", &map[i]);
		for(int i=0; i<goal; i++)
			map[ygoal[i]][xgoal[i]]='T';
		map[y][x]='P';
		fclose(LvSelect);
		Input_Move(x,y,goal,xgoal,ygoal,&move);
		if(move==-1)
			return 0;
		}while(move==-2);
		Win_Screen(Lv,move);
	}
	return 1;
}

void Display_Lv(){
	system("cls");
	printf("1. Level 1\n");
	printf("2. Level 2\n");
	printf("3. Level 3\n");
	printf("0. Exit\n");
}

int Choose_Lv(){
	Display_Lv();
	int Opt;
	do{
		printf(">> ");
		scanf("%d", &Opt); getchar();
  		if(Opt<0||Opt>3)
  			Display_Lv();
	}while(Opt<0||Opt>3);
	return Opt;
}

void Write_Score(){
	FILE *scr;

	scr=fopen("./score1.txt", "w");
	fprintf(scr,"\n");
	for(int i=1; i<=Pl1; i++){
		fprintf(scr, "%s#%d\n", PLv1[i].name, PLv1[i].score);
	}
	fclose(scr);
	scr=fopen("./score2.txt", "w");
	fprintf(scr,"\n");
	for(int i=1; i<=Pl2; i++){
		fprintf(scr, "%s#%d\n", PLv2[i].name, PLv2[i].score);
	}
	fclose(scr);
	scr=fopen("./score3.txt", "w");
	fprintf(scr,"\n");
	for(int i=1; i<=Pl3; i++){
		fprintf(scr, "%s#%d\n", PLv3[i].name, PLv3[i].score);
	}
	fclose(scr);
}

void Read_Score(){
	FILE *Rd;
	Rd=fopen("./score1.txt", "r");
	if(Rd!=NULL){
	fscanf(Rd,"\n");
	while(!feof(Rd)){
		Pl1++;
		fscanf(Rd, "%[^#]#%d\n", PLv1[Pl1].name, &PLv1[Pl1].score);
	}
	}
	fclose(Rd);
	Rd=fopen("./score2.txt", "r");
	if(Rd!=NULL){
	fscanf(Rd,"\n");
	while(!feof(Rd)){
		Pl2++;
		fscanf(Rd, "%[^#]#%d\n", PLv2[Pl2].name, &PLv2[Pl2].score);
	}
	}
	fclose(Rd);
	Rd=fopen("./score3.txt", "r");
	if(Rd!=NULL){
	fscanf(Rd,"\n");
	while(!feof(Rd)){
		Pl3++;
		fscanf(Rd, "%[^#]#%d\n", PLv3[Pl3].name, &PLv3[Pl3].score);
	}
	}
	fclose(Rd);
}

void View_Score(){
	printf("Scoreboard\n");
	printf("=======================================================\n");
	printf("Level 1:\n");
	if(Pl1>0){
		printf("####################################################################\n");
		printf("| No. | Name                                               | Score |\n");
		printf("####################################################################\n");
		for(int i=1; i<=Pl1; i++){
			printf("| %3d | %-50s | %5d |\n", i, PLv1[i].name, PLv1[i].score);
		}
		printf("####################################################################\n");	
	}else{
		printf("There is no data...\n");
	}
	printf("=======================================================\n");
	printf("Level 2:\n");
	if(Pl2>0){
		printf("####################################################################\n");
		printf("| No. | Name                                               | Score |\n");
		printf("####################################################################\n");
		for(int i=1; i<=Pl2; i++){
			printf("| %3d | %-50s | %5d |\n", i, PLv2[i].name, PLv2[i].score);
		}
		printf("####################################################################\n");	
	}else{
		printf("There is no data...\n");
	}
	
	printf("=======================================================\n");
	printf("Level 3:\n");
	if(Pl3>0){
		printf("####################################################################\n");
		printf("| No. | Name                                               | Score |\n");
		printf("####################################################################\n");
		for(int i=1; i<=Pl3; i++){
			printf("| %3d | %-50s | %5d |\n", i, PLv3[i].name, PLv3[i].score);
		}
		printf("####################################################################\n");	
	}else{
		printf("There is no data...\n");
	}
	getchar();
}

void Display_Menu(){
	system("cls");
	printf(" _ªªªªªªªª  _ªªªªªª_     _ª   _ª_  _ªªªªªª_  »ªªªªªªªªª_     _ªªªªªªªª ªªª____\n");
 	printf(" ªªª    ªªª ªªª    ªªª   ªªª _ªªª» ªªª    ªªª   ªªª    ªªª   ªªª    ªªª ªªª»»»ªª_\n");
  	printf(" ªªª    ª»  ªªª    ªªª   ªªªªªª»   ªªª    ªªª   ªªª    ªªª   ªªª    ªªª ªªª   ªªª\n");
  	printf(" ªªª        ªªª    ªªª  _ªªªªª»    ªªª    ªªª  _ªªª___ªª»    ªªª    ªªª ªªª   ªªª\n");
  	printf("ªªªªªªªªªªª ªªª    ªªª »»ªªªªª_    ªªª    ªªª »»ªªª»»»ªª_  »ªªªªªªªªªªª ªªª   ªªª\n");
  	printf("        ªªª ªªª    ªªª   ªªªªªª_   ªªª    ªªª   ªªª    ªª_   ªªª    ªªª ªªª   ªªª\n");
  	printf("  _ª    ªªª ªªª    ªªª   ªªª »ªªª_ ªªª    ªªª   ªªª    ªªª   ªªª    ªªª ªªª   ªªª\n");
  	printf(" _ªªªªªªªª»  »ªªªªªª»    ªªª   »ª»  »ªªªªªª»  _ªªªªªªªªª»    ªªª    ª»   »ª   ª»\n");
  	printf("1. Game\n");
  	printf("2. View score\n");
  	printf("0. Exit\n");
}
int MainMenu(){
  	Display_Menu();
  	int Opt;
  	do{
  		printf(">> ");
  		scanf("%d", &Opt); getchar();
  		if(Opt<0||Opt>2)
  			Display_Menu();
	}while(Opt<0||Opt>2);
	return Opt;	
}

int main(){
	int Mopt=0;
	Read_Score();
	do{
		system("cls");
		Mopt=MainMenu();
		switch(Mopt){
			case 1:
				{
					int check;
					do{
						check = Play_Lv(Choose_Lv());	
					} while (check==0);
					break;
				}
			case 2:
				{
					View_Score();
					break;
				}
		}
	}while(Mopt!=0);
	Write_Score();
	printf("Thank you for playing!\n");
	return 0;
}
