/* OSEMK Hangman Game in C.
   Copyright (C) 2022 Onur Erginer <https://onur.erginer.net/>
   This file is part of an open source license.
  */
   
#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <conio.h>

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif
#define MAXAL 466036


void birinciekran(){
	printf("                                                                      \n");
	printf("########  ########  ######## ###########  #    ##      #      #        ##        ##      #  ########   ##      ##        ##        ##      #          \n");
	printf("#      #  #         #        #    #    #  #   #        #      #       #  #       # #     #  #          # #    # #       #  #       # #     #      \n");
	printf("#      #  #         #        #    #    #  # #          #      #      #    #      #  #    #  #          #  #  #  #      #    #      #  #    #          \n");
	printf("#      #  ########  ######## #    #    #  ##           ########     ########     #   #   #  #   # # #  #   ##   #     ########     #   #   #     \n");
	printf("#      #         #  #        #    #    #  # #          #      #    #        #    #    #  #  #       #  #        #    #        #    #    #  #        \n");
	printf("#      #         #  #        #    #    #  #   #        #      #   #          #   #     # #  #       #  #        #   #          #   #     # #           \n");
	printf("########  ########  ######## #    #    #  #    ##      #      #  #            #  #      ##  #########  #        #  #            #  #      ##         \n");
	printf("                                                                      \n");
	printf("                                                                      \n");
	printf("           New Game  < N >\n");
	printf("           Tutorials < T >\n");
	printf("           Quit Game < Q >\n");
}
char* rasgele_kelime_sec(const char *dosyaadi) {
     FILE *f;
    size_t satirno = 0;
    size_t satirsec;
    char secildi[256]; 
    char secilen[256];
    secildi[0] = '\0';
    rand();
    int random=rand();
	int sayi= random*(MAXAL/RAND_MAX);
    f = fopen(dosyaadi, "r"); 
		//	double say= 1.0/rand();
    while (fgets(secilen, sizeof(secilen), f)) {
        if (sayi < ++satirno && strlen(secilen)>4) {
            strcpy(secildi, secilen);
    printf("%d \n",satirno);
    break;
        }
    }
    fclose(f);
    satirsec = strlen(secildi);
    if (satirsec > 0 && secildi[satirsec-1] == '\n') {
        secildi[satirsec-1] = '\0';
    }
    return strdup(secildi);
}
void tamekran()
{ 
CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo; 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);
    COORD new_screen_buffer_size;
    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - 
    screenBufferInfo.srWindow.Left + 1; 
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - 
    screenBufferInfo.srWindow.Top + 1; 
    SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);
 keybd_event(VK_MENU,
				0x38,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				KEYEVENTF_KEYUP,
				0);
	keybd_event(VK_MENU,
				0x38,
				KEYEVENTF_KEYUP,
				0);
}
void adamiciz(int hatalar) {
	switch(hatalar) {
		case 7: 
			printf("\n\n\t _________\n"
	       "\t|         | \n"
	       "\t|        (_) \n"
	       "\t|        /|\\ \n"
	       "\t|         | \n"
	       "\t|        / \\    \n"
	       "\t|             "
		   "\n  -------------");  break;
		case 6: 	printf("\n\n\t _________\n"
	       "\t|         | \n"
	       "\t|        (_) \n"
	       "\t|        /|\\ \n"
	       "\t|         | \n"
	       "\t|        /     \n"
	       "\t|             "
		   "\n  -------------");  break;
		case 5: 	printf("\n\n\t _________\n"
	       "\t|         | \n"
	       "\t|        (_) \n"
	       "\t|        /|\\ \n"
	       "\t|         | \n"
	       "\t|           \n"
	       "\t|             "
		   "\n  -------------");   break;
		case 4: 	printf("\n\n\t _________\n"
	       "\t|         | \n"
	       "\t|        (_) \n"
	       "\t|        /|\\ \n"
	       "\t|          \n"
	       "\t|           \n"
	       "\t|             "
		   "\n  -------------"); break;
		case 3: 	printf("\n\n\t _________\n"
	       "\t|         | \n"
	       "\t|        (_) \n"
	       "\t|        /| \n"
	       "\t|          \n"
	       "\t|          \n"
	       "\t|             "
		   "\n  -------------"); break;
		case 2: 	printf("\n\n\t _________\n"
	       "\t|         | \n"
	       "\t|        (_) \n"
	       "\t|         | \n"
	       "\t|          \n"
	       "\t|           \n"
	       "\t|             "
		   "\n  -------------");  break;
	       case 1: 	printf("\n\n\t _________\n"
	       "\t|         | \n"
	       "\t|        (_) \n"
	       "\t|          \n"
	       "\t|          \n"
	       "\t|           \n"
	       "\t|             "
		   "\n  -------------");  break;
		default:
	printf("\n\n\t _________\n"
	       "\t|         | \n"
	       "\t|         \n"
	       "\t|       \n"
	       "\t|          \n"
	       "\t|            \n"
	       "\t|             "
		   "\n  -------------"); 
		   break;

	}

}
int main(){
  tamekran();
	int oyunekrani=1;
	char c;  
	char * kelime;
	char  bosluk[200],tahmin[200];
	int hata=0, hak=7,j,bildimi=0,oyunbittimi=0,kazandi=0,bilinen=0,tahminbuf=0,tahminedildimi=0,oyunbasladi=0;
	const char * dosyaadi="words.txt";

	srand ( (unsigned)time(NULL) );
	kelime = rasgele_kelime_sec(dosyaadi);
	if( access( dosyaadi, F_OK ) == 0 ) {
		for(j=0;j<=strlen(kelime);j++){
								bosluk[j*4]=' ';
								if(tolower(kelime[j])==' '|| tolower(kelime[j])=='-'|| tolower(kelime[j])=='.'|| tolower(kelime[j])==','){
								bosluk[(j*4)+1]=kelime[j];
								bilinen++;
								}else{
   								bosluk[(j*4)+1]=' ';
								}
								bosluk[(j*4)+2]=' ';
								bosluk[(j*4)+3]=' ';
								tahmin[j*3]=' ';	tahmin[(j*3)+1]=' ';	tahmin[(j*3)+2]=' ';
								
				}
		while(1){
			system("cls");
			printf("Hangman Game has developed by Onur Erginer. github.com/osemk \t onur.erginer.net");
			switch(oyunekrani){
				
			case 1: 
			birinciekran();
			c=getch();
			if(c=='n' || c=='N'){ 
				oyunekrani=2;
			}
			else if(c=='t' || c=='T'){
				oyunekrani=3;
			}
			else if(c=='q' || c=='Q'){
				exit(0);
			}
			break;
			case 3:
				printf("\n\n\n\t\tTUTORIALS;");
				printf("\n\n\t\t\t\t1) To Start new game, press N key in main screen");
				printf("\n\n\t\t\t\t2) To Quit game, press Q key in main screen, press 5 key to quit when game has started");
				printf("\n\n\t\t\t\t3) When game has started, if you press 1 key, it opens main screen");
				printf("\n\n\t\t\t\t4) When game has started, if you press 2 key, it opens tutorials screen");
				printf("\n\n\t\t\t\t5) When game has started, if you press 3 key, you restart the game with previous word");
				printf("\n\n\t\t\t\t6) When game has started, if you press 4 key, you start new game with new word");
				printf("\n\n\t\t\t\t7) When game has started, if you press 5 key, game will be closed");
				printf("\n\n\t\t\t\t8) On game over, if you press 6 you can see the hidden word without spaces");
				printf("\n\n\n\n\t\t\t\t\tRULES and How to Play:");	
				printf("\n\n\t\t\t\t\tYou can play game by keyboard. When you start a new game, you can use all keys in keyboard except 1-6 keys. ");
				printf("\n\t\t\t\t\tGame pick a word randomly from word pool there are over 400k words in pool. Guess the word using keys.\n\t\t\t\t\t When you press a key it compares, "
				"if the word has letter that you pressed, you don't lose your chance and you can see the letter \n\t\t\t\t\tthat you pressed in pitch." 
				" if the word hasn't letter that you pressed, then you lose 1 chance and your man go to rope. \n\t\t\t\t\tIf you couldn't guess the word in 7 press, you'll be busted");
				printf("\n\n\t\t\t\t\tAbout:");	
				printf("\n\n\t\t\t\t\tThe Osemk Hangman Game has developed by Onur Erginer in 19/03/2022. github.com/osemk\n\t\t\t\t\tonur.erginer.net\n\t\t\t\t\t"
				"developer note: as time goes by i see, the sources of C programmes in internet are running low. i share this project for new developers to inspire C games.");
				
				if(oyunbasladi==1) printf("\n\n < R > Return to Current Game");
				printf("\n\n\n < M > Main Screen     < N > Start New Game   < Q > Quit Game");
				c=getch();
				if(tolower(c)=='m')
					oyunekrani=1;
				else if(tolower(c)=='n')
					oyunekrani=2;
				else if(tolower(c)=='r' && oyunbasladi==1)
					oyunekrani=2;
				else if(tolower(c)=='q')
					exit(0);
					
				break;
			case 2:
				oyunbasladi=1;
				adamiciz(hata);
				printf("\n\t\t\t ");
				for(j=0;j<strlen(kelime)*4;j++)
				printf("%c",bosluk[j]);
				printf("\n\t\t\t ");
				for(j=0;j<strlen(kelime);j++){
					if(kelime[j]==' '|| kelime[j]=='-'|| kelime[j]==','|| kelime[j]=='`')
					printf("    ");
					else
					printf("___ ");
				}
				printf("\n\n Mistakes: %d\n %d chance left",hata,hak);  
				
				printf("    Predictions: ");    
				for(j=0;j<tahminbuf*3;j++)
				printf("%c",tahmin[j]);
				if(oyunbittimi>0 && kazandi==0){
				  printf("\n\n#******#######################****# GAME OVER #***#######################******#   Press < 6 > to show word");
				}else if(oyunbittimi>0 && kazandi>0){
				  printf("\n\n-------------------!!!!!YOU WON!!!!------------------------");
				}

				printf("\n\n\n\n\n\nReturn to Main Screen : < 1 >  Tutorials: < 2 >  Restart Game : < 3 >    Start New Game: < 4 >     Quit Game: < 5 >");
				c= getch();	
				if(c=='1'){
					oyunekrani=1;
					hata=0; hak=7;
					kazandi=0; oyunbittimi=0; bilinen=0; 
					kelime = rasgele_kelime_sec(dosyaadi);
							for(j=0;j<=strlen(kelime);j++){
								bosluk[j*4]=' ';
								if(tolower(kelime[j])==' '|| tolower(kelime[j])=='-'|| tolower(kelime[j])=='.'|| tolower(kelime[j])==','){
								bosluk[(j*4)+1]=kelime[j];
								bilinen++;
								}else{
   								bosluk[(j*4)+1]=' ';
								}
								bosluk[(j*4)+2]=' ';
								bosluk[(j*4)+3]=' ';
				}
				for(j=0;j<150;j++)
				tahmin[j]=' ';
				tahminbuf=0;
				}
				else if(c=='2'){
					oyunekrani=3;
				}
				else if(c=='3'){
					oyunekrani=2;
					hata=0; hak=7;
					kazandi=0; oyunbittimi=0; bilinen=0; 
							for(j=0;j<=strlen(kelime);j++){
								bosluk[j*4]=' ';
								if(tolower(kelime[j])==' '|| tolower(kelime[j])=='-'|| tolower(kelime[j])=='.'|| tolower(kelime[j])==','){
								bosluk[(j*4)+1]=kelime[j];
								bilinen++;
								}else{
   								bosluk[(j*4)+1]=' ';
								}
								bosluk[(j*4)+2]=' ';
								bosluk[(j*4)+3]=' ';
				}
				for(j=0;j<150;j++)
				tahmin[j]=' ';
				tahminbuf=0;
				}
				else if(c=='4'){
					oyunekrani=2;
					hata=0; hak=7;
					kazandi=0; oyunbittimi=0; bilinen=0; 
					kelime = rasgele_kelime_sec(dosyaadi);
							for(j=0;j<=strlen(kelime);j++){
								bosluk[j*4]=' ';
								if(tolower(kelime[j])==' '|| tolower(kelime[j])=='-'|| tolower(kelime[j])=='.'|| tolower(kelime[j])==','){
								bosluk[(j*4)+1]=kelime[j];
								bilinen++;
								}else{
   								bosluk[(j*4)+1]=' ';
								}
								bosluk[(j*4)+2]=' ';
								bosluk[(j*4)+3]=' ';								
				}
				for(j=0;j<150;j++)
				tahmin[j]=' ';
				tahminbuf=0;
				}
				else if(c=='5'){
				exit(0);
				}else if(c=='6' && oyunbittimi==1){
					for(j=0;j<strlen(kelime);j++){
							printf("\n%d",j);
								bosluk[j*4]=' ';
								bosluk[(j*4)+1]=kelime[j];
								bosluk[(j*4)+2]=' ';
								bosluk[(j*4)+3]=' ';
						
					}
				}
				else{
					if(oyunbittimi==0){
						for(j=0;j<strlen(tahmin);j++){
							if(tahmin[j]==c)
							tahminedildimi=1;
						}
						if(tahminedildimi==0){
						
					bildimi=0;
					for(j=0;j<strlen(kelime);j++){
						if(tolower(c)==tolower(kelime[j])){
							bildimi=1;
							bilinen++;
							printf("\n%d",j);
								bosluk[j*4]=' ';
								bosluk[(j*4)+1]=kelime[j];
								bosluk[(j*4)+2]=' ';
								bosluk[(j*4)+3]=' ';
						}
					}
					if(bilinen==strlen(kelime)){
					oyunbittimi=1; kazandi=1;
					}
					
					if(bildimi==0){
						printf("\a");
						hak--; hata++;
					}
					
						tahmin[tahminbuf*3+1]=c;
						tahmin[tahminbuf*3+2]=',';
						tahmin[tahminbuf*3+3]=' ';
						tahminbuf++;
					}
					if(hak==0){
					oyunbittimi=1;kazandi=0;
					}
					tahminedildimi=0;
					}
				}
				break;
			default:
				return 0;
			}
		}
	}
	else{
		printf("         \n");
		printf("         \n");
		printf("words.txt is missing :-( ");
		printf("         \n");
		printf("         \n");
		getch();
		return 0;
	}
	return 0;
}
