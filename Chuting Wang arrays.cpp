// Chuting Wang arrays.cpp : Defines the entry point for the console application.
//
/*------------------------------Chuting Wang Arrays----------------------------*/
/*     This program uses funtions. It will prompt user to log in by entering   */
/*     a username and password. users can determine to play either             */
/*     singer vs computer or multiplayers with their friends.                  */
/*                                                                             */
/*     After going through the instructions, users would notice that they      */
/*     would be promted to determine their cars' initial velocity, final       */
/*     velocity and acceleration and then their cars would compete             */
/*     according to the data the users imput. When versus computer,            */
/*     the car that finishes 2 km with the least time before gas is run        */
/*     out would be the winner. When versus other users, the car that          */
/*     runs the farthest distance in the limited time would be the winner      */
/*     																		   */
/*     It is recommended that users go through all the menus (except main)     */
/*     starting from choice 'a' and going down one by one as some of choices   */
/*     might not be opened if the previous ones hace none imput yet.           */
/*   																		   */
/*     tips: users can win the game by entering all velocity and acceleration  */
/*     as big as possible. And when competing with computer, use car-3 in      */
/*     all three trails.                                                       */
/*                                                                             */
/*                        PROGRAM ID:Chuting Wang Arrays                       */ 
/*                        PROGRAMMER:Chuting Wang                              */
/*                        DATE:May 8th, 2018                                   */ 
/*                                                   						   */
/*-----------------------------------------------------------------------------*/
/*----------------------------PREPORCESSING DIRECTIVES-------------------------*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
/*-------------------------------MAINLINE CONTROL------------------------------*/
int main(void)
{
/*------------------------------------TITLE------------------------------------*/

	system("TITLE Chuting Wang Arrays");
	
/*----------------------------declare local variables--------------------------*/
	/*-----------log in------------*/
	int intLetter=0, keyNum=0;	                    //password letter as integer
	char letter;			                        //input letter key (password)
	char password[20], maskPassword[20];	        //password and mask
	char userName[30];                              //username  
	
	/*-----------Menu-------------*/
	char mainMenu;                                  //main menu
	char carMenu;                                   //single player car menu
	char car2Menu;                                  //multi player car menu
	char settingMenu;                               //single player setting
	char setting2Menu;                              //multi player setting
	
	/*-------Single player---------*/	
	//user setting
	char carName[3][30];                            //user three cars' names
	int initialVelocity1;                           //user car-1's initial velocity
	int initialVelocity2;                           //user car-2's initial velocity
	int initialVelocity3;                           //user car-3's initial velocity
	int finalVelocity1;                             //user car-1's final velocity
	int finalVelocity2;                             //user car-2's final velocity
	int finalVelocity3;                             //user car-3's final velocity
	int acceleration1;                              //user car-1's acceleration
	int acceleration2;                              //user car-2's acceleration
	int acceleration3;                              //user car-3's acceleration
	int userCompetingOrder[3];                      //competing order of user's cars 
	
	//computer setting
	int randNum;                                    //hold the random number, determining which competing order is used	
	int computerAcceleration[3] = {5,10,15};        //computer three cars' acceleration
	int computerInitialVelocity[3] = {5,10,15};     //computer three cars' initial velocity
	int computerFinalVelocity[3] = {90,110,130};    //computer three cars' final velocity 	                    
	int computerGasCar1[3] = {4,5,6};               //computer Car-1's gas used under different range of velocity
	int computerGasCar2[4] = {3,4,5,6};             //computer Car-2's gas used under different range of velocity
	int computerGasCar3[5] = {2,3,4,5,6};	        //computer Car-3's gas used under different range of velocity
	int computerCompetingOrder1[3] = {1,2,3};       //computer three cars' competing order1, selected if randNum=1
	int computerCompetingOrder2[3] = {2,1,3};       //computer three cars' competing order2, selected if randNum=2
	int computerCompetingOrder3[3] = {1,3,2};       //computer three cars' competing order3, selected if randNum=3
	int computerTime1 = 30;                         //time computer Car-1 takes to complete 2km
	int computerTime2 = 23;							//time computer Car-2 takes to complete 2km
	int computerTime3 = 19;                         //time computer Car-3 takes to complete 2km
	
	//both setting
	char carNum[3][20] = {"Car-1","Car-2","Car-3"}; 		//Car number for both user and computer
	int velocityRangea=0;                           		//determine gas used under a certain range of velocity(in front of '-')
	int velocityRangeb=0;                           		//determine gas used under a certain range of velocity(behind '-')
	int singlePlayerMaxVelocity[3] = {100,120,140};  	    //Maximum velocity of three cars for both computer and user
	int singlePlayerMaxAcceleration[3] = {10,15,20};        //Maximum acceleration of three cars for both computer and user
	int singlePlayerGasCapacity[3] = {15000,20000,25000};   //Gas Capacity of three cars for both computer and user
	int result1;											//competing result of first trail
	int result2;											//competing result of second trail
	int result3;											//competing result of third trail
	int totalResult;
	
	//calculations
	//car 1
	int time1;                    //time car-1 takes when accelerating
	int time1a;                   //time car-1 takes at constant speed
	int totalTime1;               //car-1 total time
	int distance1;                //distance car-1 travels when accelerating 
	int distance1a;               //distance car-1 travels at constant speed
	int realFinalVelocity1;       //actual velocity for car-1 if it cannot accelerate to the expected velocity after 2km
	int gas1;                     //car-1 gas used at velocity below 20m/s
	int gas1a;					  //car-1 gas used at velocity 20-40 m/s
	int gas1b;					  //car-1 gas used at velocity 40-60 m/s
	int gas1c;					  //car-1 gas used at velocity 60-80 m/s
	int gas1d;					  //car-1 gas used at velocity 80-100 m/s
	int totalGas1;			      //car-1 total gas used
	//car 2
	int time2;			          //time car-2 takes when accelerating
	int time2a;                   //time car-2 takes at constant speed
	int totalTime2;				  //car-2 total time 
	int distance2;                //distance car-2 travels when accelerating 
	int distance2a;               //distance car-2 travels at constant speed
	int realFinalVelocity2;       //actual velocity for car-2 if it cannot accelerate to the expected velocity after 2km
	int gas2;                     //car-2 gas used at velocity below 20m/s
	int gas2a;                    //car-2 gas used at velocity 20-40 m/s
	int gas2b;                    //car-2 gas used at velocity 40-60 m/s
	int gas2c;					  //car-2 gas used at velocity 60-80 m/s
	int gas2d;                    //car-2 gas used at velocity 80-100 m/s
	int gas2e;                    //car-2 gas used at velocity 100-120 m/s
	int totalGas2;                //car-2 total gas used

	//car 3
	int time3;                    //time car-3 takes when accelerating
	int time3a;                   //time car-3 takes at constant speed
	int totalTime3;               //car-2 total time 
	int distance3;                //distance car-3 travels when accelerating 
	int distance3a;               //distance car-3 travels at constant speed
	int realFinalVelocity3;       //actual velocity for car-2 if it cannot accelerate to the expected velocity after 2km
	int gas3;                     //car-3 gas used at velocity below 20m/s
	int gas3a;                    //car-3 gas used at velocity 20-40 m/s
	int gas3b;                    //car-3 gas used at velocity 40-60 m/s
	int gas3c;                    //car-3 gas used at velocity 60-80 m/s
	int gas3d;                    //car-3 gas used at velocity 80-100 m/s
	int gas3e;                    //car-3 gas used at velocity 100-120 m/s
	int gas3f;                    //car-3 gas used at velocity 120-140 m/s
	int totalGas3;                //car-3 total gas used
	
	/*----------Multi player-------*/
	char userCarName[100][30];                      //cars' names
	int userNumber=0;                               //number of users/cars playing games 
	int userInitialVelocity[100];                   //cars' initial velocity
	int userFinalVelocity[100];                     //cars' final velocity
	int userAcceleration[100];                      //cars' acceleration
	int userTime=0;                                 //time limit when competing
	int winner;                                     //the one with the farthest distance is winner
	int userTime1[100];                             //calculation of time when accelerating
	int userRealFinalVelocity[100];                 //actual velocity if the cars cannot accelerate to the expected velocity in the limited time
	int userDistance1[100];                         //distance when accelerating
	int userDistance2[100];                         //distance at constant speed
	int userTotalDistance[100];	                    //total distance                   

	/*------Condition and loop-----*/	
	char choice;                                    //users determine continue or return
	int row=0;                                      //determine number order in arrays
	int column=0;                                   //determine number order in arrays
	int flag=0;                                     //decide stay in or return do-while
	int z=0,z1=0,z2=0,z3=0,z4=0,k=0;                //decide if users select choice of imput before viewing it

/*set screen size*/ 
	HWND foregroundWindow = GetForegroundWindow();
	
/*set color*/
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);  
	WORD wOldColorAttrs;                                                                                               
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                                                               
	GetConsoleScreenBufferInfo(h1, &csbiInfo);                                                                                       
	wOldColorAttrs = csbiInfo.wAttributes;

/*Greeting*/	
	system ("color F0"); //background and foreground colour
	printf("\n\n\t\t\t==============================================================");
	printf("\n\t\t\t|                                                              |");											
	printf("\n\t\t\t|                       THE SIMS CAR RACE                      |");		
	printf("\n\t\t\t|                       By: CHUTING WANG                       |");		
	printf("\n\t\t\t|                                                              |");		
	printf("\n\t\t\t================================================================\n\n"); 
	printf("\n\t\t                        Welcome to THE SIMS CAR RACE!\n\n");
	printf("\n\t\t           You can play car race with either computer or your friends!");
	printf("\n\t\t  You will design your own car by using some knowledge from physics.Try to win!!!\n\n");
	printf("\n\t\t                           Press <ENTER> and START!");
	getch();   //hold the screen
	system("cls");  //clear screen
    
	system ("color D"); //foreground colour
	ShowWindow(foregroundWindow, SW_MAXIMIZE); //full screen
	
/*Log in*/	
	printf("PASSWORD: password");   
	printf("\n");        
	printf("\nTTTTTTTTTTTTTTTTTTTTTTThhhhhhh                                         SSSSSSSSSSSSSSS   iiii                                               ");
	printf("\nT:::::::::::::::::::::Th:::::h                                       SS:::::::::::::::S i::::i                                               ");
	printf("\nT:::::::::::::::::::::Th:::::h                                      S:::::SSSSSS::::::S  iiii                                                ");
	printf("\nT:::::TT:::::::TT:::::Th:::::h                                      S:::::S     SSSSSSS                                                  ");
	printf("\nTTTTTT  T:::::T  TTTTTT h::::h hhhhh           eeeeeeeeeeee         S:::::S            iiiiiii    mmmmmmm    mmmmmmm       ssssssssss    ");
	printf("\n        T:::::T         h::::hh:::::hhh      ee::::::::::::ee       S:::::S            i:::::i  mm:::::::m  m:::::::mm   ss::::::::::s   ");
	printf("\n        T:::::T         h::::::::::::::hh   e::::::eeeee:::::ee      S::::SSSS          i::::i m::::::::::mm::::::::::mss:::::::::::::s  ");
	printf("\n        T:::::T         h:::::::hhh::::::h e::::::e     e:::::e       SS::::::SSSSS     i::::i m::::::::::::::::::::::ms::::::ssss:::::s ");
	printf("\n        T:::::T         h::::::h   h::::::he:::::::eeeee::::::e         SSS::::::::SS   i::::i m:::::mmm::::::mmm:::::m s:::::s  ssssss  ");
	printf("\n        T:::::T         h:::::h     h:::::he:::::::::::::::::e             SSSSSS::::S  i::::i m::::m   m::::m   m::::m   s::::::s       ");
	printf("\n        T:::::T         h:::::h     h:::::he::::::eeeeeeeeeee                   S:::::S i::::i m::::m   m::::m   m::::m      s::::::s    ");
	printf("\n        T:::::T         h:::::h     h:::::he:::::::e                            S:::::S i::::i m::::m   m::::m   m::::mssssss   s:::::s  ");
	printf("\n      TT:::::::TT       h:::::h     h:::::he::::::::e               SSSSSSS     S:::::Si::::::im::::m   m::::m   m::::ms:::::ssss::::::s     ");
	printf("\n      T:::::::::T       h:::::h     h:::::h e::::::::eeeeeeee       S::::::SSSSSS:::::Si::::::im::::m   m::::m   m::::ms::::::::::::::s      ");                                                                                          
	printf("\n      T:::::::::T       h:::::h     h:::::h  ee:::::::::::::e       S:::::::::::::::SS i::::::im::::m   m::::m   m::::m s:::::::::::ss        ");                                     
	printf("\n      TTTTTTTTTTT       hhhhhhh     hhhhhhh    eeeeeeeeeeeeee        SSSSSSSSSSSSSSS   iiiiiiiimmmmmm   mmmmmm   mmmmmm  sssssssssss       ");     
	printf("\n");  
	printf("\n                                                                                                                                                           ");
	printf("\n        CCCCCCCCCCCCC                                                         RRRRRRRRRRRRRRRRR                                                            ");
	printf("\n     CCC::::::::::::C                                                         R::::::::::::::::R                                                           ");
	printf("\n   CC:::::::::::::::C                                                         R::::::RRRRRR:::::R                                                          ");
	printf("\n  C:::::CCCCCCCC::::C                                                         RR:::::R     R:::::R                                                         ");
	printf("\n C:::::C       CCCCCC  aaaaaaaaaaaaa  rrrrr   rrrrrrrrr       ssssssssss        R::::R     R:::::R  aaaaaaaaaaaaa      cccccccccccccccc    eeeeeeeeeeee    ");
	printf("\nC:::::C                a::::::::::::a r::::rrr:::::::::r    ss::::::::::s       R::::R     R:::::R  a::::::::::::a   cc:::::::::::::::c  ee::::::::::::ee  ");
	printf("\nC:::::C                aaaaaaaaa:::::ar:::::::::::::::::r ss:::::::::::::s      R::::RRRRRR:::::R   aaaaaaaaa:::::a c:::::::::::::::::c e::::::eeeee:::::ee");
	printf("\nC:::::C                         a::::arr::::::rrrrr::::::rs::::::ssss:::::s     R:::::::::::::RR             a::::ac:::::::cccccc:::::ce::::::e     e:::::e");
	printf("\nC:::::C                  aaaaaaa:::::a r:::::r     r:::::r s:::::s  ssssss      R::::RRRRRR:::::R     aaaaaaa:::::ac::::::c     ccccccce:::::::eeeee::::::e");
	printf("\nC:::::C                aa::::::::::::a r:::::r     rrrrrrr   s::::::s           R::::R     R:::::R  aa::::::::::::ac:::::c             e:::::::::::::::::e ");
	printf("\nC:::::C               a::::aaaa::::::a r:::::r                  s::::::s        R::::R     R:::::R a::::aaaa::::::ac:::::c             e::::::eeeeeeeeeee  ");
	printf("\nC:::::C       CCCCCCa::::a    a:::::a r:::::r            ssssss   s:::::s      R::::R     R:::::Ra::::a    a:::::ac::::::c     ccccccce:::::::e           ");
	printf("\n C:::::CCCCCCCC::::Ca::::a    a:::::a r:::::r            s:::::ssss::::::s   RR:::::R     R:::::Ra::::a    a:::::ac:::::::cccccc:::::ce::::::::e          ");
	printf("\n   CC:::::::::::::::Ca:::::aaaa::::::a r:::::r            s::::::::::::::s    R::::::R     R:::::Ra:::::aaaa::::::a c:::::::::::::::::c e::::::::eeeeeeee  ");                                                                                                                                    
	printf("\n     CCC::::::::::::C a::::::::::aa:::ar:::::r             s:::::::::::ss     R::::::R     R:::::R a::::::::::aa:::a cc:::::::::::::::c  ee:::::::::::::e  ");
	printf("\n        CCCCCCCCCCCCC  aaaaaaaaaa  aaaarrrrrrr              sssssssssss       RRRRRRRR     RRRRRRR  aaaaaaaaaa  aaaa   cccccccccccccccc    eeeeeeeeeeeeee  ");
	printf("\n");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\n\n\n\n\t\t\t\t\t\t\tUSERNAME:");  //input username
	scanf("%[^\n]",userName);
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\tPASSWORD:");  

	do
	{
		keyNum=0;
		maskPassword[0]=0;			//set to not length
		do
		{	
			SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
			system("cls");			//clear screen for password typing
			printf("PASSWORD: password");
			printf("\n");        
			printf("\nTTTTTTTTTTTTTTTTTTTTTTThhhhhhh                                         SSSSSSSSSSSSSSS   iiii                                               ");
			printf("\nT:::::::::::::::::::::Th:::::h                                       SS:::::::::::::::S i::::i                                               ");
			printf("\nT:::::::::::::::::::::Th:::::h                                      S:::::SSSSSS::::::S  iiii                                                ");
			printf("\nT:::::TT:::::::TT:::::Th:::::h                                      S:::::S     SSSSSSS                                                  ");
			printf("\nTTTTTT  T:::::T  TTTTTT h::::h hhhhh           eeeeeeeeeeee         S:::::S            iiiiiii    mmmmmmm    mmmmmmm       ssssssssss    ");
			printf("\n        T:::::T         h::::hh:::::hhh      ee::::::::::::ee       S:::::S            i:::::i  mm:::::::m  m:::::::mm   ss::::::::::s   ");
			printf("\n        T:::::T         h::::::::::::::hh   e::::::eeeee:::::ee      S::::SSSS          i::::i m::::::::::mm::::::::::mss:::::::::::::s  ");
			printf("\n        T:::::T         h:::::::hhh::::::h e::::::e     e:::::e       SS::::::SSSSS     i::::i m::::::::::::::::::::::ms::::::ssss:::::s ");
			printf("\n        T:::::T         h::::::h   h::::::he:::::::eeeee::::::e         SSS::::::::SS   i::::i m:::::mmm::::::mmm:::::m s:::::s  ssssss  ");
			printf("\n        T:::::T         h:::::h     h:::::he:::::::::::::::::e             SSSSSS::::S  i::::i m::::m   m::::m   m::::m   s::::::s       ");
			printf("\n        T:::::T         h:::::h     h:::::he::::::eeeeeeeeeee                   S:::::S i::::i m::::m   m::::m   m::::m      s::::::s    ");
			printf("\n        T:::::T         h:::::h     h:::::he:::::::e                            S:::::S i::::i m::::m   m::::m   m::::mssssss   s:::::s  ");
			printf("\n      TT:::::::TT       h:::::h     h:::::he::::::::e               SSSSSSS     S:::::Si::::::im::::m   m::::m   m::::ms:::::ssss::::::s     ");
			printf("\n      T:::::::::T       h:::::h     h:::::h e::::::::eeeeeeee       S::::::SSSSSS:::::Si::::::im::::m   m::::m   m::::ms::::::::::::::s      ");                                                                                          
			printf("\n      T:::::::::T       h:::::h     h:::::h  ee:::::::::::::e       S:::::::::::::::SS i::::::im::::m   m::::m   m::::m s:::::::::::ss        ");                                     
			printf("\n      TTTTTTTTTTT       hhhhhhh     hhhhhhh    eeeeeeeeeeeeee        SSSSSSSSSSSSSSS   iiiiiiiimmmmmm   mmmmmm   mmmmmm  sssssssssss       ");     
			printf("\n");  
			printf("\n                                                                                                                                                           ");
			printf("\n        CCCCCCCCCCCCC                                                         RRRRRRRRRRRRRRRRR                                                            ");
			printf("\n     CCC::::::::::::C                                                         R::::::::::::::::R                                                           ");
			printf("\n   CC:::::::::::::::C                                                         R::::::RRRRRR:::::R                                                          ");
			printf("\n  C:::::CCCCCCCC::::C                                                         RR:::::R     R:::::R                                                         ");
			printf("\n C:::::C       CCCCCC  aaaaaaaaaaaaa  rrrrr   rrrrrrrrr       ssssssssss        R::::R     R:::::R  aaaaaaaaaaaaa      cccccccccccccccc    eeeeeeeeeeee    ");
			printf("\nC:::::C                a::::::::::::a r::::rrr:::::::::r    ss::::::::::s       R::::R     R:::::R  a::::::::::::a   cc:::::::::::::::c  ee::::::::::::ee  ");
			printf("\nC:::::C                aaaaaaaaa:::::ar:::::::::::::::::r ss:::::::::::::s      R::::RRRRRR:::::R   aaaaaaaaa:::::a c:::::::::::::::::c e::::::eeeee:::::ee");
			printf("\nC:::::C                         a::::arr::::::rrrrr::::::rs::::::ssss:::::s     R:::::::::::::RR             a::::ac:::::::cccccc:::::ce::::::e     e:::::e");
			printf("\nC:::::C                  aaaaaaa:::::a r:::::r     r:::::r s:::::s  ssssss      R::::RRRRRR:::::R     aaaaaaa:::::ac::::::c     ccccccce:::::::eeeee::::::e");
			printf("\nC:::::C                aa::::::::::::a r:::::r     rrrrrrr   s::::::s           R::::R     R:::::R  aa::::::::::::ac:::::c             e:::::::::::::::::e ");
			printf("\nC:::::C               a::::aaaa::::::a r:::::r                  s::::::s        R::::R     R:::::R a::::aaaa::::::ac:::::c             e::::::eeeeeeeeeee  ");
			printf("\nC:::::C       CCCCCCa::::a    a:::::a r:::::r            ssssss   s:::::s      R::::R     R:::::Ra::::a    a:::::ac::::::c     ccccccce:::::::e           ");
			printf("\n C:::::CCCCCCCC::::Ca::::a    a:::::a r:::::r            s:::::ssss::::::s   RR:::::R     R:::::Ra::::a    a:::::ac:::::::cccccc:::::ce::::::::e          ");
			printf("\n   CC:::::::::::::::Ca:::::aaaa::::::a r:::::r            s::::::::::::::s    R::::::R     R:::::Ra:::::aaaa::::::a c:::::::::::::::::c e::::::::eeeeeeee  ");                                                                                                                                    
			printf("\n     CCC::::::::::::C a::::::::::aa:::ar:::::r             s:::::::::::ss     R::::::R     R:::::R a::::::::::aa:::a cc:::::::::::::::c  ee:::::::::::::e  ");
			printf("\n        CCCCCCCCCCCCC  aaaaaaaaaa  aaaarrrrrrr              sssssssssss       RRRRRRRR     RRRRRRR  aaaaaaaaaa  aaaa   cccccccccccccccc    eeeeeeeeeeeeee  ");
			printf("\n");
			SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
			printf("\n\n\n\n\n\t\t\t\t\t\t\tUSERNAME:%s",userName); 
			printf("\n\n\t\t\t\t\t\t\tPASSWORD:"); //input password
			printf("%s",maskPassword);							
			fflush(stdin);
			letter=getch();		//get individual letters
			intLetter=letter;	//convert to integer for key handling
			if(keyNum<20)
			{
				if((intLetter!=13)&&(intLetter!=8))
				{//if not enter or backspace
					password[keyNum]=letter;		//add to password
					maskPassword[keyNum]='*';		//create mask of password
					maskPassword[keyNum+1]=0;		//create end of string null for mask
					keyNum++;						//go to next input letter
				}
			}
			if(intLetter==8)
			{								//if backspace
				if(keyNum>0) keyNum--;		//erase a letter from password
				maskPassword[keyNum]=0;		//end mask of password
			}

		}while(intLetter!=13);		//wait until enter
		password[keyNum]=0;			//create end of password string	

		/*test password*/
		if(strcmp(password,"password")==0)  //string compare testing if password is 'password'
			flag = 2;		
		else
		{
			printf("\n\n\t\t\tPress <ENTER> to try again!");
			flag = 1;
			getch();
			system("cls"); //clear screen
		}
	}while(flag < 2);   //if flag < 2, retry password, others go next
	printf("\n\n\n\t\t\t\t\t\t\tPress <ENTER> to Start!!!!");
	getch();       // hold screen
	system("cls"); //clear screen

/*Loading..*/
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t  ______       ");
	printf("\n\t\t\t\t\t /|_||_|`.__  ");
	printf("\n\t\t\t\t\t(   _    _ _| ");
	printf("\n\t\t\t\t\t=`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there.");
	Sleep(150);     // stay on screen for 150 milliseconds
	system("cls");  //clear screen

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground color
	printf("\n\t\t\t\t\t                     ______       ");
	printf("\n\t\t\t\t\t                    /|_||_|`.__  ");
	printf("\n\t\t\t\t\t                   (   _    _ _| ");
	printf("\n\t\t\t\t\t                 ===`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there..");
	Sleep(150);
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\n\t\t\t\t\t                     ______       ");
	printf("\n\t\t\t\t\t                    /|_||_|`.__  ");
	printf("\n\t\t\t\t\t                   (   _    _ _| ");
	printf("\n\t\t\t\t\t                 ===`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there...");
	Sleep(150);
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\n\t\t\t\t\t                     ______       ");
	printf("\n\t\t\t\t\t                    /|_||_|`.__  ");
	printf("\n\t\t\t\t\t                   (   _    _ _| ");
	printf("\n\t\t\t\t\t                 ===`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there.");
	Sleep(150);
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	SetConsoleTextAttribute ( h1,FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\n\t\t\t\t\t                                             ______       ");
	printf("\n\t\t\t\t\t                                            /|_||_|`.__  ");
	printf("\n\t\t\t\t\t                                           (   _    _ _| ");
	printf("\n\t\t\t\t\t                                           =`-(_)--(_)-' "); 
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\t=========================================================");
	SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
	printf("\n\t\t\t\t\tWe are almost there...");
	Sleep(150);
	system("cls");

/*Main Menu*/
	do
	{
		system("color 0F");   //background and foreground color 
		printf("[MAIN MENU]");
		printf("\n\n\t\t\t\t\t\t\t\tWelcome!!! %s!",userName);
		SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour
		printf("\n\n\n\n");
		printf("\n\t\t\t\t\t                                                        ___________                              ");
		printf("\n\t\t\t\t\t                                              __..--''''           ''''--..__              ");
		printf("\n\t\t\t\t\t                                          _.-''''''''''-----...      ______ `.            ");
		printf("\n\t\t\t\t\t                                      .-'                      l ,-''     | '-.`.          ");
		printf("\n\t\t\t\t\t                                    .-'                         ; ;        ;   | ''--.._   ");
		printf("\n\t\t\t\t\t                                  .'                           : :         |    ;      .l  ");
		printf("\n\t\t\t\t\t                            _.._.'                             ; ;  ___    |    ;    .' :  ");
		printf("\n\t\t\t\t\t                           (  .'                              : :  :   '.  :..-'   .'    ; ");
		printf("\n\t\t\t\t\t                            )'                                | ;  ; __.'-'(     .'  .--.: ");
		printf("\n\t\t\t\t\t                    ___...-'''''----....____          ______.-' :-/.'       |_.-'  .' .-.|l");
		printf("\n\t\t\t\t\t            __..--''                        ''''''''''          /|'          ;    / .gs./|;");
		printf("\n\t\t\t\t\t        _.-'                                                   /  ;          |   . d$P'Tb  ");
		printf("\n\t\t\t\t\t     .-''-,                       ____                        /   |          :   ;:$$   $; ");
		printf("\n\t\t\t\t\t   .'     ;                    ,''    ''--..__               /    :          |   $$$;   :$ ");
		printf("\n\t\t\t\t\t  /'-._  /                     ;       ____..-'    .-'''-.  /     :          ;  _$$$;   :$ ");
		printf("\n\t\t\t\t\t :     ''--.._          ___....+---''''          .'  _._  |/      |         _:-' $$$;   :$ ");
		printf("\n\t\t\t\t\t ;                                              /  .d$$$b./       ;      .-'.'   :$$$   $P ");
		printf("\n\t\t\t\t\t:            .----...____                      :  dP' `T$P        |   .-' .' _.gd$$$$b_d$' ");
		printf("\n\t\t\t\t\t;    __...---|  Chuting  |----....____         | :$     $b        : .'   (.-'  `T$$$$$$P'  ");
		printf("\n\t\t\t\t\t;  .';       '----...____;       /    '-.      ; $;     :$;_____..-'  .-'                  ");
		printf("\n\t\t\t\t\t: /  :                          /        |__..-':$       $$ ;-.    .-'                     ");
		printf("\n\t\t\t\t\t Y    ;                        /          ;     $;       :$;|  `.-'                        ");
		printf("\n\t\t\t\t\t :    :                       /           |     $$       $$;:.-'                           ");
		printf("\n\t\t\t\t\t'$$$ggggp...____             /            :     :$;     :$$                                ");
		printf("\n\t\t\t\t\t  $$$$$$$$$$$$   ''''----...:________....gggg$$$$$$     $$;                                ");
		printf("\n\t\t\t\t\t  'T$$$$$$$$P'                           T$$$$$$$$$b._.d$P                                 ");
		printf("\n\t\t\t\t\t    `T$$$$P'                              T$$$$$$$$$$$$$P                                  ");
		printf("\n\t\t\t\t\t                                           `T$$$$$$$$$P'                                      ");
		

		printf("\n\n\n\n");
		SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
		printf("\n\n\t\t\t\t\t\t\t\t a]  Single Player");
		printf("\n\n\t\t\t\t\t\t\t\t b]  Multi Player");
		printf("\n\n\t\t\t\t\t\t\t\t c]  How to play");
		printf("\n\n\t\t\t\t\t\t\t\t d]  Exit");
		printf("\n\n\n\n\t\t\t\t\t\t\t\t     your choice:");  //prompt user select
		mainMenu = _getch();  //restrict user to enter one character only
		fflush(stdin);
		system("cls");  //clear screen
		switch(mainMenu)
		{
	/*single player*/
		case'A':
		case'a':
			/*randum number*/
			srand(time(NULL));
			randNum = (1 + (rand( )%3));   //number generated will be between 1 and 3

         /*car menu*/
			do
			{   

				system("color 80");
				printf("\n\n\n\n\n");
				printf("\n\t\t\t [CAR MENU]\n\n");
				printf("\n\t\t\t\t||");
				printf("\n\t\t\t\t||  a] Enter/Edit Car Name");
				printf("\n\t\t\t\t||");
				printf("\n\t\t\t\t =====");
				printf("\n\t\t\t\t      ||");
				printf("\n\t\t\t\t      ||  b] View Car Name");
				printf("\n\t\t\t\t      ||");
				printf("\n\t\t\t\t       =====");
				printf("\n\t\t\t\t            ||");
				printf("\n\t\t\t\t            ||  c] Car Setting Menu");
				printf("\n\t\t\t\t            ||");
				printf("\n\t\t\t\t             =====");
				printf("\n\t\t\t\t                  ||");
				printf("\n\t\t\t\t                  ||  d] View Your Cars' Setting");
				printf("\n\t\t\t\t                  ||");
				printf("\n\t\t\t\t                   =====");
				printf("\n\t\t\t\t                        ||");
				printf("\n\t\t\t\t                        ||  e] View computer cars' Setting");
				printf("\n\t\t\t\t                        ||");
				printf("\n\t\t\t\t                         =====");
				printf("\n\t\t\t\t                              ||");
				printf("\n\t\t\t\t                              ||  f] Start Competing!!!!!");
				printf("\n\t\t\t\t                              ||");
				printf("\n\t\t\t\t                               =====");
				printf("\n\t\t\t\t                                    ||");
				printf("\n\t\t\t\t                                    ||  g] See results");
				printf("\n\t\t\t\t                                    ||");
				printf("\n\t\t\t\t                                     =====");
				printf("\n\t\t\t\t                                          ||");
				printf("\n\t\t\t\t                                          ||  h] Return to Main Menu");
				printf("\n\t\t\t\t                                          ||");
				printf("\n\t\t\t\t                                           =====");
				printf("\n\t\t\t\t                                                ||");
				printf("\n\t\t\t\t                                                ||  i] Exit");
				printf("\n\t\t\t\t                                                ||");
				printf("\n\t\t\t\t                                                 =====");
				printf("\n\t\t\t\t                                                      ||");
				printf("\n\t\t\t\t                                                      ||");
				printf("\n\t\t\t\t                                                      ||  Your choice:");
				carMenu = _getch(); //restrict user to enter one character only
				fflush(stdin);
				system("cls"); //clear screen
        
				switch(carMenu)
				{
			/*Enter/Edit car names*/
				case'a':
				case'A':
					system("color 81"); //foreground and background color
					for(row=0;row<3;row++)
					{
						printf("\n\n\t\t\t\tPlease enter name of %s and press <ENTER>:",carNum[row]);
						scanf("%[^\n]",carName[row]);
						fflush(stdin);
					}
					do
					{
						printf("\n\n\n\t\t\t\tPress 'a' to go back to main menu and press 'b' to exit.");
						choice = _getch();  //restrict user to enter one character only
						fflush(stdin);
						if(choice == 'a')
						{
							flag = 2;
							system("cls"); //clear screen
						}
						else if(choice == 'b')
						flag = 7;
						else 
						{
							system("cls");  //clear screen
							printf("\n\t\t\t\tYou have entered an invalid letter!");
							printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
							flag = 1;
						}
					}while(flag < 2);
					z=1;
					break;

			/*View Cars' names*/
				case'b':
				case'B':
					system("color 85");//foreground and background color
					if(z!=1)
					{
						printf("\n\n\t\t\t\t            SORRY! You cannot veiw this page yet!");
						printf("\n\n\t\t\t\t      We have noticed that you have not named your cars!!");
						printf("\n\n\t\t\t\tPress <ENTER> to go back to car menu and set your car's name first!!");
						flag=3;
						getch();
						system("cls");
					}
					else
					{
						printf("\n\n\t\t\t\tFollowing are your cars' names.");
						for(row=0;row<3;row++)
							printf("\n\n\t\t\t%s:    %s",carNum[row],carName[row]);

						do
						{
							printf("\n\n\n\t\t\t\tPress 'a' to go back to car menu and press 'b' to exit.");
							choice = _getch();  //restrict user to enter one character only
							fflush(stdin);
							if(choice == 'a')
							{
								flag = 2;
								system("cls"); //clear screen
							}
							else if(choice == 'b')
							flag = 7;
							else 
							{
								system("cls");  //clear screen
								printf("\n\t\t\t\tYou have entered an invalid letter!");
								printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
								flag = 1;
							}
						}while(flag < 2);
					}
					break;

			/*Setting Menu*/
				case'c':
				case'C':
					system("color 30");//foreground and background color
					if(z!=1)
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						printf("\n\t\t\t\t\tWe have noticed that you have not named your car yet!");
						printf("\n\t\t\t\t\tIt might lead you cannot set your car's information!\n");
						printf("\n\t\t\t\t\t         Do you still want to continue?");
						do
						{
							printf("\n\n\t\t\t\tPress 'a' to continue to Setting Menu, press 'b' to return to car menu");
							choice = _getch();  //restrict user to enter one character only
							fflush(stdin);
							if(choice == 'a')
							{
								flag = 2;
								system("cls"); //clear screen
								z=2;
							}
							else if(choice == 'b')
							{
								flag = 5;
								system("cls");
							}
							else 
							{
								system("cls");  //clear screen
								printf("\n\t\t\t\tYou have entered an invalid letter!");
								printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
								flag = 1;
							}
						}while(flag < 2);
					}

					if((z==1) || (z==2))
					{
						do
						{
							printf("\n\n\n\n\n\n");
							printf("\n\t\t\t\t\t\t\t                [SETTING]");
							printf("\n\n\n");
							printf("\n\t\t\t\t\t\t\t   ||");
							printf("\n\t\t\t\t\t\t\t   || a]  View Three Cars' info");
							printf("\n\t\t\t\t\t\t\t   ||\n\n\n");
							printf("\n\t\t\t\t\t\t\t                                   ||");
							printf("\n\t\t\t\t\t\t\t              Car 1 setting    b]  ||");
							printf("\n\t\t\t\t\t\t\t                                   ||\n\n\n");
							printf("\n\t\t\t\t\t\t\t   ||");
							printf("\n\t\t\t\t\t\t\t   || c]      Car 2 setting");
							printf("\n\t\t\t\t\t\t\t   ||\n\n\n");
							printf("\n\t\t\t\t\t\t\t                                   ||");
							printf("\n\t\t\t\t\t\t\t              Car 3 setting    d]  ||");
							printf("\n\t\t\t\t\t\t\t                                   ||\n\n\n");
							printf("\n\t\t\t\t\t\t\t   ||");
							printf("\n\t\t\t\t\t\t\t   || e]    Return to Car Menu");
							printf("\n\t\t\t\t\t\t\t   ||\n\n\n");
							printf("\n\t\t\t\t\t\t\t                                   ||");
							printf("\n\t\t\t\t\t\t\t                 Exit          f]  ||");
							printf("\n\t\t\t\t\t\t\t                                   ||\n\n\n");
							printf("\n\t\t\t\t\t\t\t   ||");
							printf("\n\t\t\t\t\t\t\t   ||");
							printf("\n\t\t\t\t\t\t\t   ||        Your Choice:");
							
							settingMenu = _getch(); //restrict user to enter one character only
							fflush(stdin);
							system("cls");
							switch(settingMenu)
							{

							/*View three Cars characteristics*/
								case'a':
								case'A':
									system("color 30"); //foreground and background color
									system("cls");
									printf("\n\t\t\t\tFollowing is both your and computer's three cars' characteristics:");
									for(row=0;row<3;row++)
									{										
										printf("\n\n\n\n\t\t\t\t%s:",carNum[row]);										
										printf("\n\n\t\t\t\tCar's information: Max Velocity: %d km/h  Max Acceleration: %d km/h",singlePlayerMaxVelocity[row],singlePlayerMaxAcceleration[row]);
										if(row == 0)
										{
											printf("\n\n\t\t\t\tGas:");
											printf("\n\n\t\t\t\tBelow 20 m/s: 2 ml/km");
											velocityRangeb=20;
											for(column=0;column<3;column++)
											{
												velocityRangeb = velocityRangeb + 20;
												velocityRangea = velocityRangea + 20;
												printf("\n\t\t\t\t%d km/h - %d m/s: %d ml/km",velocityRangea,velocityRangeb,computerGasCar1[column]);
											}
											printf("\n\t\t\t\tAbove 80 m/s: 6 ml/km");																			
										} 
										if(row == 1)
										{
											printf("\n\n\t\t\t\tGas:");
											printf("\n\n\t\t\t\tBelow 20 m/s: 1 ml/km");
											velocityRangeb=20;
											for(column=0;column<4;column++)
											{
												velocityRangeb = velocityRangeb + 20;
												velocityRangea = velocityRangea + 20;
												printf("\n\t\t\t\t%d m/s - %d m/s: %d ml/km",velocityRangea,velocityRangeb,computerGasCar2[column]);
											}
											printf("\n\t\t\t\tAbove 100 m/s: 6 ml/km");																			
										}
										if(row == 2)
										{
											printf("\n\n\t\t\t\tGas:");
											printf("\n\n\t\t\t\tBelow 20 m/s: 0.5 ml/km");
											velocityRangeb=20;
											for(column=0;column<5;column++)
											{
												velocityRangeb = velocityRangeb + 20;
												velocityRangea = velocityRangea + 20;
												printf("\n\t\t\t\t%d m/s - %d m/s: %d ml/km",velocityRangea,velocityRangeb,computerGasCar3[column]);
											}
											printf("\n\t\t\t\tAbove 120 m/s: 5.5 ml/km");																			
										}																				
									}

									do
									{
										printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
										choice = _getch();  //restrict user to enter one character only
										fflush(stdin);
										if(choice == 'a')
										{
											flag = 2;
											system("cls"); //clear screen
										}
										else if(choice == 'b')
										flag = 7;
										else 
										{
											system("cls");  //clear screen
											printf("\n\t\t\t\tYou have entered an invalid letter!");
											printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
											flag = 1;
										}
									}while(flag < 2);
									break;

								/*Car-1 Setting*/
								case'b':
								case'B':
									system("color 31"); //foreground and background color
									if(z != 1)
									{
										printf("\n\n\n\n\n\n\n\n\n\n");
										printf("\n\n\n\t\t\t\t            SORRY! You cannot veiw this page yet!");
										printf("\n\n\n\t\t\t\t      We have noticed that you have not named your cars!!");
										printf("\n\n\n\t\t\t\tPress <ENTER> to go back to car menu and set your car's name first!!");
										flag=3;
										getch();
										system("cls");
									}
									else
									{
										z1=2;										
										printf("\n\n\t\t\tFollowing please set your initial velocity, final velocity and acceleration");
										printf("\n\n\t\t\t\tCar-1: Maximum Velocity: 100 m/s Maximum Acceleration: 10 m/s/s");
										for(row=0;row<1;row++)
										{										
											do
											{	
											
												printf("\n\n\t\t\t\t\t\t\t%s: %s",carNum[row],carName[row]);
											 
												printf("\n\n\t\t\t\tInitial Velocity(0-20 m/s):");
												scanf("%d",&initialVelocity1);
												fflush(stdin);
												if(initialVelocity1 > 20)
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Please enter a number between 0 and 20!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else
												flag=2;	
											}while(flag<2);
											do
											{					
												printf("\n\n\t\t\t\tFinal Velocity(m/s):");
												scanf("%d",&finalVelocity1);
												fflush(stdin);
												if((finalVelocity1>100)||(finalVelocity1 < initialVelocity1))
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice the Maximum Velocity for Car-1 is 100 m/s!");
													printf("\n\n\t\t\tAnd final velocity of the car has to be bigger than the initial velocity!!!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else
												flag=2;
											}while(flag<2);
											do
											{
											
												printf("\n\n\t\t\t\tAcceleration(m/s/s):");
												scanf("%d",&acceleration1);
												fflush(stdin);
												if(acceleration1 > 10)
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice the Maximum Acceleration for Car-1 is 10 m/s/s!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else 
												flag=2;
											}while(flag<2);
											
										}
										
										do
										{
											printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
											choice = _getch();  //restrict user to enter one character only
											fflush(stdin);
											if(choice == 'a')
											{
												flag = 2;
												system("cls"); //clear screen
											}
											else if(choice == 'b')
											flag = 7;
											else 
											{
												system("cls");  //clear screen
												printf("\n\t\t\t\tYou have entered an invalid letter!");
												printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
												flag = 1;
											}
											
										}while(flag < 2);
									}
									break;

							/*Car-2 setting*/
								case'c':
								case'C':
									system("color 31");
									if(z != 1)
									{
										printf("\n\n\n\n\n\n\n\n\n\n");
										printf("\n\n\n\t\t\t\t            SORRY! You cannot veiw this page yet!");
										printf("\n\n\n\t\t\t\t      We have noticed that you have not named your cars!!");
										printf("\n\n\n\t\t\t\tPress <ENTER> to go back to car menu and set your car's name first!!");
										flag=3;
										getch();
										system("cls");
									}
									else
									{
										z2=2;
										printf("\n\n\t\t\tFollowing please set your initial velocity, final velocity and acceleration");
										printf("\n\n\t\t\t\tCar-2: Maximum Velocity: 120 m/s Maximum Acceleration: 15 m/s/s");
										for(row=1;row<2;row++)
										{										
											do
											{	
												
												printf("\n\n\t\t\t\t\t\t\t%s: %s",carNum[row],carName[row]);
												
												printf("\n\n\t\t\t\tInitial Velocity(0-20 m/s):");
												scanf("%d",&initialVelocity2);
												fflush(stdin);
												if(initialVelocity2 > 20)
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Please enter a number between 0 and 20!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else
												flag=2;
											}while(flag<2);
															
											do
											{
																	
												printf("\n\n\t\t\t\tFinal Velocity(m/s):");
												scanf("%d",&finalVelocity2);
												fflush(stdin);
												if((finalVelocity2>120)||(finalVelocity2 < initialVelocity2))
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice the Maximum Velocity for Car-2 is 120 m/s!");
													printf("\n\n\t\t\tAnd final velocity of the car has to be bigger than the initial velocity!!!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else
												flag=2;
											}while(flag<2);
											do
											{
											
												printf("\n\n\t\t\t\tAcceleration(m/s/s):");
												scanf("%d",&acceleration2);
												fflush(stdin);
												if(acceleration2 > 15)
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice the Maximum Acceleration for Car-2 is 20 m/s/s!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else 
												flag=2;
											}while(flag < 2);
										}
										
										do
										{
											printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
											choice = _getch();  //restrict user to enter one character only
											fflush(stdin);
											if(choice == 'a')
											{
												flag = 2;
												system("cls"); //clear screen
											}
											else if(choice == 'b')
											flag = 7;
											else 
											{
												system("cls");  //clear screen
												printf("\n\t\t\t\tYou have entered an invalid letter!");
												printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
												flag = 1;
											}
										}while(flag < 2);
										
									}
									break;

							/*Car-3 setting*/
								case'd':
								case'D':
									system("color 31");
									if(z != 1)
									{
										printf("\n\n\t\t\t\t            SORRY! You cannot veiw this page yet!");
										printf("\n\n\t\t\t\t      We have noticed that you have not named your cars!!");
										printf("\n\n\t\t\t\tPress <ENTER> to go back to car menu and set your car's name first!!");
										flag=3;
										getch();
										system("cls");
									}
									else
									{
										z3=2;
										printf("\n\n\t\t\tFollowing please set your initial velocity, final velocity and acceleration");
										printf("\n\n\t\t\t\tCar-3: Maximum Velocity: 140 m/s Maximum Acceleration: 20 m/s/s");
										for(row=2;row<3;row++)
										{										
											do
											{													
												printf("\n\n\t\t\t\t\t\t\t%s: %s",carNum[row],carName[row]);												
												printf("\n\n\t\t\t\tInitial Velocity(0-20 m/s):");
												scanf("%d",&initialVelocity3);
												fflush(stdin);
												if(initialVelocity3 > 20)
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Please enter a number between 0 and 20!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else
												flag=2;
											}while(flag<2);
											do
											{																								
												printf("\n\n\t\t\t\tFinal Velocity(m/s):");
												scanf("%d",&finalVelocity3);
												fflush(stdin);
												if((finalVelocity3>140)||(finalVelocity3 < initialVelocity3))
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice the Maximum Velocity for Car-3 is 140 m/s!");
													printf("\n\n\t\t\tAnd final velocity of the car has to be bigger than the initial velocity!!!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else
												flag=2;
											}while(flag<2);
											do
											{
											
												printf("\n\n\t\t\t\tAcceleration(m/s/s):");
												scanf("%d",&acceleration3);
												fflush(stdin);
												if(acceleration3 > 20)
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice the Maximum Acceleration for Car-3 is 20 m/s/s!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
												else 
												flag=2;
											}while(flag < 2);
										}
										
										do
										{
											printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
											choice = _getch();  //restrict user to enter one character only
											fflush(stdin);
											if(choice == 'a')
											{
												flag = 2;
												system("cls"); //clear screen
											}
											else if(choice == 'b')
											flag = 7;
											else 
											{
												system("cls");  //clear screen
												printf("\n\t\t\t\tYou have entered an invalid letter!");
												printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
												flag = 1;
											}
										}while(flag < 2);
										
									}
									break;

							   /*Return to Car Menu*/
								case'e':
								case'E':
									flag = 5;
									break;

							   /*Exit*/
								case'f':
								case'F':
									flag = 7;
									break;

								default:
									system("color 30");
									printf("\n\n\n\t\t\t\t\tSORRY!You have entered an invalid letter!");
									printf("\n\n\n\t\t\t\t\tPress <ENTER> to return the SETTING MENU!!");
									getch();
									system("cls");
									flag=2;
									break;						
							} //end of setting menu
						}while(flag<5);
					}
					break;

				/*View users Cars setting*/
				case'd':
				case'D':
					if((z==1) && (z1==2) && (z2==2) && (z3==2))
					{
						printf("\t\t\t\t\tFollowing is your three cars information");
						for(row=0;row<3;row++)
						{
							
							printf("\n\n\t\t\t\t%s: %s",carNum[row],carName[row]);
							
							printf("\n\t\t\t\tCar's characteristics:");
							printf("\n\n\t\t\t\tCar's information: Max Velocity: %d m/s  Max Acceleration: %d m/s/s",singlePlayerMaxVelocity[row],singlePlayerMaxAcceleration[row]);
							printf("\n\t\t\t\t                   Gas Capacity: %d ml",singlePlayerGasCapacity[row]);
							if(row == 0)
							{
								printf("\n\t\t\t\tGas:");
								printf("\n\n\t\t\t\tBelow 20 m/s: 3 ml/km");
								velocityRangeb=20;
								for(column=0;column<3;column++)
								{
									velocityRangeb = velocityRangeb + 20;
									velocityRangea = velocityRangea + 20;
									printf("\n\t\t\t\t%d m/s - %d m/s: %d ml/km",velocityRangea,velocityRangeb,computerGasCar1[column]);
								}
								printf("\n\t\t\t\tAbove 80 m/s: 7 ml/km");	
								printf("\n\n\t\t\t\tInitial Velocity: %d",initialVelocity1);	
								printf("\n\t\t\t\t  Final Velocity: %d",finalVelocity1);
								printf("\n\t\t\t\t    Acceleration: %d",acceleration1);																	
							} 
							if(row == 1)
							{
								printf("\n\t\t\t\tGas:");
								printf("\n\n\t\t\t\tBelow 20 m/s: 2 ml/km");
								velocityRangeb=20;
								for(column=0;column<4;column++)
								{
									velocityRangeb = velocityRangeb + 20;
									velocityRangea = velocityRangea + 20;
									printf("\n\t\t\t\t%d m/s - %d m/s: %d ml/km",velocityRangea,velocityRangeb,computerGasCar2[column]);
								}
								printf("\n\t\t\t\tAbove 100 m/s: 7 ml/km");
								printf("\n\n\t\t\t\tInitial Velocity: %d",initialVelocity2);	
								printf("\n\t\t\t\t  Final Velocity: %d",finalVelocity2);
								printf("\n\t\t\t\t    Acceleration: %d",acceleration2);																			
							}
							if(row == 2)
							{
								printf("\n\t\t\t\tGas:");
								printf("\n\n\t\t\t\tBelow 20 m/s: 1 ml/km");
								velocityRangeb=20;
								for(column=0;column<5;column++)
								{
									velocityRangeb = velocityRangeb + 20;
									velocityRangea = velocityRangea + 20;
									printf("\n\t\t\t\t%d m/s - %d m/s: %d ml/km",velocityRangea,velocityRangeb,computerGasCar3[column]);
								}							
								printf("\n\t\t\t\tAbove 120 m/s: 7 ml/km");
								printf("\n\n\t\t\t\tInitial Velocity: %d",initialVelocity3);	
								printf("\n\t\t\t\t  Final Velocity: %d",finalVelocity3);
								printf("\n\t\t\t\t    Acceleration: %d",acceleration3);
							}													
						}
						do
						{
							printf("\n\n\n\t\t\t\tPress 'a' to go back to car menu and press 'b' to exit.");
							choice = _getch();  //restrict user to enter one character only
							fflush(stdin);
							if(choice == 'a')
							{
								flag = 2;
								system("cls"); //clear screen
							}
							else if(choice == 'b')
							flag = 7;
							else 
							{
								system("cls");  //clear screen
								printf("\n\t\t\t\tYou have entered an invalid letter!");
								printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
								flag = 1;
							}
						}while(flag < 2);
					}
					else if (z!=1)
					{
						printf("\n\n\n\n\n\n\n\n\n\n");
						printf("\n\n\n\t\t\t\t            SORRY! You cannot veiw this page yet!");
						printf("\n\n\n\t\t\t\t      We have noticed that you have not set the names for your car!!");
						printf("\n\n\n\t\t\t\t   Press <ENTER> to go back to car menu and set your car's name first!!");
						flag=3;
						getch();
						system("cls");		
					}
					else
					{
						printf("\n\n\n\n\n\n\n\n\n\n");
						printf("\n\n\n\t\t\t\t            SORRY! You cannot veiw this page yet!");
						printf("\n\n\n\t\t\t\t      We have noticed that you have not set your three cars' characteristics yet!!");
						printf("\n\n\n\t\t\t\t Press <ENTER> to go back to car menu and go to SETTING MENU to set your thre cars!!!");
						flag=3;
						getch();
						system("cls");
					}					
					break;

			  /*View Computer Cars Setting*/
				case'e':
				case'E':
					printf("Following is Computer's three Cars setting");
					for(row=0;row<3;row++)
					{

						printf("\n\n\t\t\t\t%s:",carNum[row]);				
						
						printf("\n\n\t\t\t\tAcceleration: %d m/s/s",computerAcceleration[row]);
						printf("\n\t\t\t\tInitial Velocity: %d m/s",computerInitialVelocity[row]);
						printf("\n\t\t\t\tFinal Velocity: %d m/s",computerFinalVelocity[row]);										
					}
					do
					{
						printf("\n\n\n\t\t\t\tPress 'a' to go back to car menu and press 'b' to exit.");
						choice = _getch();  //restrict user to enter one character only
						fflush(stdin);
						if(choice == 'a')
						{
							flag = 2;
							system("cls"); //clear screen
						}
						else if(choice == 'b')
						flag = 7;
						else 
						{
							system("cls");  //clear screen
							printf("\n\t\t\t\tYou have entered an invalid letter!");
							printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
							flag = 1;
						}
					}while(flag < 2);
					break;

			/*Start Competing*/
				case'f':
				case'F':
					system("color 0D");					
					if((z==1) && (z1==2) && (z2==2) && (z3==2))
					{
						/*do calculation*/
						time1 = (finalVelocity1 - initialVelocity1)/acceleration1;
						distance1 = (finalVelocity1*finalVelocity1 - initialVelocity1*initialVelocity1)/(2*acceleration1);
						if(distance1<= 2000)
						{
							distance1a = 2000 - distance1;
							time1a = distance1a/finalVelocity1;
							totalTime1 = time1+time1a;
						}
						else
						{
							realFinalVelocity1 = sqrt(2*2000*acceleration1+initialVelocity1*initialVelocity1);
							totalTime1 = (realFinalVelocity1 - initialVelocity1)/acceleration1;
						}
						
						if(finalVelocity1<=20)
							totalGas1 = distance1*3;
						else if((finalVelocity1 > 20) && (finalVelocity1 <= 40))
						{
							gas1 = (20*20-initialVelocity1*initialVelocity1)/(2*acceleration1)*3;
							gas1a = (finalVelocity1*finalVelocity1 - 20*20)/(2*acceleration1)*4;
							totalGas1 = gas1+gas1a;
						}
						else if((finalVelocity1 > 40) && (finalVelocity1 <= 60))
						{                                                                   
							gas1 = (20*20-initialVelocity1*initialVelocity1)/(2*acceleration1)*3;
							gas1a = (40*40-20*20)/(2*acceleration1)*4;
							gas1b = (finalVelocity1*finalVelocity1 - 40*40)/(2*acceleration1)*5;
							totalGas1 = gas1+gas1a+gas1b;
						}
						else if((finalVelocity1 > 60) && (finalVelocity1 <= 80))
						{
							gas1 = (20*20-initialVelocity1*initialVelocity1)/(2*acceleration1)*3;
							gas1a = (40*40-20*20)/(2*acceleration1)*4;
							gas1b = (60*60-40*40)/(2*acceleration1)*5;
							gas1c = (finalVelocity1*finalVelocity1 - 60*60)/(2*acceleration1)*6;
							totalGas1 = gas1+gas1a+gas1b+gas1c;
						}
						else
						{
							gas1 = (20*20-initialVelocity1*initialVelocity1)/(2*acceleration1)*3;
							gas1a = (40*40-20*20)/(2*acceleration1)*4;
							gas1b = (60*60-40*40)/(2*acceleration1)*5;
							gas1c = (80*80-60*60)/(2*acceleration1)*6;
							gas1d = (finalVelocity1*finalVelocity1 - 80*80)/(2*acceleration1)*7;
							totalGas1 = gas1+gas1a+gas1b+gas1c+gas1d;
						}	
						
						time2 = (finalVelocity2 - initialVelocity2)/acceleration2;
						distance2 = (finalVelocity2*finalVelocity2 - initialVelocity2*initialVelocity2)/(2*acceleration2);
						if(distance2 <= 2000)
						{
							distance2a = 2000 - distance2;
							time2a = distance2a/finalVelocity2;
							totalTime2 = time2+time2a;
						}
						else
						{
							realFinalVelocity2 = sqrt(2*2000*acceleration2+initialVelocity2*initialVelocity2);
							totalTime2 = (realFinalVelocity2 - initialVelocity2)/acceleration2;
						}
						
						if(finalVelocity2<=20)
							totalGas2 = distance2*2;
						else if((finalVelocity2 > 20) && (finalVelocity2 <= 40))
						{
							gas2 = (20*20-initialVelocity2*initialVelocity2)/(2*acceleration2)*2;
							gas2a = (finalVelocity2*finalVelocity2 - 20*20)/(2*acceleration2)*3;
							totalGas2 = gas2+gas2a;
						}
						else if((finalVelocity2 > 40) && (finalVelocity2 <= 60))
						{
							gas2 = (20*20-initialVelocity2*initialVelocity2)/(2*acceleration2)*2;
							gas2a = (40*40-20*20)/(2*acceleration2)*3;
							gas2b = (finalVelocity2*finalVelocity2 - 40*40)/(2*acceleration2)*4;
							totalGas2 = gas2+gas2a+gas2b;
						}
						else if((finalVelocity2 > 60) && (finalVelocity2 <= 80))
						{
							gas2 = (20*20-initialVelocity2*initialVelocity2)/(2*acceleration2)*2;
							gas2a = (40*40-20*20)/(2*acceleration2)*3;
							gas2b = (60*60-40*40)/(2*acceleration2)*4;
							gas2c = (finalVelocity2*finalVelocity2 - 60*60)/(2*acceleration2)*5;
							totalGas2 = gas2+gas2a+gas2b+gas2c;
						}
						else if((finalVelocity2 > 80) && (finalVelocity2 <= 100))
						{
							gas2 = (20*20-initialVelocity2*initialVelocity2)/(2*acceleration2)*2;
							gas2a = (40*40-20*20)/(2*acceleration2)*3;
							gas2b = (60*60-40*40)/(2*acceleration2)*4;
							gas2c = (80*80-60*60)/(2*acceleration2)*5;
							gas2d = (finalVelocity2*finalVelocity2 - 80*80)/(2*acceleration2)*6;
							totalGas2 = gas2+gas2a+gas2b+gas2c+gas2d;
						}	
						else 
						{
							gas2 = (20*20-initialVelocity2*initialVelocity2)/(2*acceleration2)*2;
							gas2a = (40*40-20*20)/(2*acceleration2)*3;
							gas2b = (60*60-40*40)/(2*acceleration2)*4;
							gas2c = (80*80-60*60)/(2*acceleration2)*5;
							gas2d = (100*100-80*80)/(2*acceleration2)*6;
							gas2e = (finalVelocity2*finalVelocity2 - 100*100)/(2*acceleration2)*7;
							totalGas2 = gas2+gas2a+gas2b+gas2c+gas2d+gas2e;
						}
						time3 = (finalVelocity3 - initialVelocity3)/acceleration3;
						distance3 = (finalVelocity3*finalVelocity3 - initialVelocity3*initialVelocity3)/(2*acceleration3);
						if(distance3 <= 2000)
						{
							distance3a = 2000 - distance3;
							time3a = distance3a/finalVelocity3;
							totalTime3 = time3+time3a;
						}
						else
						{
							realFinalVelocity3 = sqrt(2*2000*acceleration3+initialVelocity3*initialVelocity3);
							totalTime3 = (realFinalVelocity3 - initialVelocity3)/acceleration3;
						}
						
						if(finalVelocity3<=20)
							totalGas3 = distance3*1;
						else if((finalVelocity3 > 20) && (finalVelocity3 <= 40))
						{
							gas3 = (20*20-initialVelocity3*initialVelocity3)/(2*acceleration3)*1;
							gas3a = (finalVelocity3*finalVelocity3 - 20*20)/(2*acceleration3)*2;
							totalGas3 = gas3+gas3a;
						}
						else if((finalVelocity3 > 40) && (finalVelocity3 <= 60))
						{
							gas3 = (20*20-initialVelocity3*initialVelocity3)/(2*acceleration3)*1;
							gas3a = (40*40-20*20)/(2*acceleration3)*2;
							gas3b = (finalVelocity3*finalVelocity3 - 40*40)/(2*acceleration3)*3;
							totalGas3 = gas3+gas3a+gas3b;
						}
						else if((finalVelocity3 > 60) && (finalVelocity3 <= 80))
						{
							gas3 = (20*20-initialVelocity3*initialVelocity3)/(2*acceleration3)*1;
							gas3a = (40*40-20*20)/(2*acceleration3)*2;
							gas3b = (60*60-40*40)/(2*acceleration3)*3;
							gas3c = (finalVelocity3*finalVelocity3 - 60*60)/(2*acceleration3)*4;
							totalGas3 = gas3+gas3a+gas3b+gas3c;
						}
						else if((finalVelocity3 > 80) && (finalVelocity3 <= 100))
						{
							gas3 = (20*20-initialVelocity3*initialVelocity3)/(2*acceleration2)*1;
							gas3a = (40*40-20*20)/(2*acceleration3)*2;
							gas3b = (60*60-40*40)/(2*acceleration3)*3;
							gas3c = (80*80-60*60)/(2*acceleration3)*4;
							gas3d = (finalVelocity3*finalVelocity3 - 80*80)/(2*acceleration3)*5;
							totalGas3 = gas3+gas3a+gas3b+gas3c+gas3d;
						}	
						else if((finalVelocity3 > 100) && (finalVelocity3 <= 120))
						{
							gas3 = (20*20-initialVelocity3*initialVelocity3)/(2*acceleration3)*1;
							gas3a = (40*40-20*20)/(2*acceleration3)*2;
							gas3b = (60*60-40*40)/(2*acceleration3)*3;
							gas3c = (80*80-60*60)/(2*acceleration3)*4;
							gas3d = (100*100-80*80)/(2*acceleration3)*5;
							gas3e = (finalVelocity3*finalVelocity3 - 100*100)/(2*acceleration3)*6;
							totalGas3 = gas3+gas3a+gas3b+gas3c+gas3d+gas3e;
						}
						else
						{
							gas3 = (20*20-initialVelocity3*initialVelocity3)/(2*acceleration3)*1;
							gas3a = (40*40-20*20)/(2*acceleration3)*2;
							gas3b = (60*60-40*40)/(2*acceleration3)*3;
							gas3c = (80*80-60*60)/(2*acceleration3)*4;
							gas3d = (100*100-80*80)/(2*acceleration3)*5;
							gas3e = (120*120-100*100)/(2*acceleration3)*6;
							gas3e = (finalVelocity3*finalVelocity3 - 120*120)/(2*acceleration3)*7;
							totalGas3 = gas3+gas3a+gas3b+gas3c+gas3d+gas3e+gas3f;
						}																																			
						
						//computer competing order 1
						if(randNum==1)
						for(row=0;row<3;row++)
						{  
							//users determine order of competing cars
							printf("\n\n\t\t\t\tFollowing you determine which car you want to compete in the first competition");  							
							printf("\n\n\t\t\t\tCompetition %d",computerCompetingOrder1[row]);
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour							
							printf("\n\n\t\t\t\tcomputer: Car-%d",computerCompetingOrder1[row]);
							SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour							
							printf("\n\n\t\t\t\t    User: Car-");
							scanf("%d",&userCompetingOrder[row]);
							fflush(stdin);
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							printf("\n\n\n\t\t\t\tPress <ENTER> to start!!!");
							getch();
							system("cls");
							//animation - competing
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t                    ");
							printf("\n\t   _/|______||__     ");
							printf("\n\t  / ,-. -|-  ,-.`-.  ");
							printf("\n\t  `( o )----( o )-'  ");
							printf("\n\t    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour	
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t_                     ");
							printf("\n\t_-  _/|______||__     ");
							printf("\n\t_  / ,-. -|-  ,-.`-.  ");
							printf("\n\t_- `( o )----( o )-'  ");
							printf("\n\t     `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t___                     ");
							printf("\n\t_-_-  _/|______||__     ");
							printf("\n\t-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t_-_- `( o )----( o )-'  ");
							printf("\n\t       `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  ___                      ");
							printf("\n\t  _-_-   _/|______||__     ");
							printf("\n\t-_-__   / ,-. -|-  ,-.`-.  ");
							printf("\n\t  _-_-  `( o )----( o )-'  ");
							printf("\n\t          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t	___                     ");
							printf("\n\t    _-_-  _/|______||__     ");
							printf("\n\t _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t    _-_- `( o )----( o )-'  ");
							printf("\n\t           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	  ___                     ");
							printf("\n\t      _-_-  _/|______||__     ");
							printf("\n\t   _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t      _-_- `( o )----( o )-'  ");
							printf("\n\t             `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	    ___                     ");
							printf("\n\t        _-_-  _/|______||__     ");
							printf("\n\t     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t        _-_- `( o )----( o )-'  ");
							printf("\n\t               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	      ___                     ");
							printf("\n\t          _-_-  _/|______||__     ");
							printf("\n\t       _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t          _-_- `( o )----( o )-'  ");
							printf("\n\t                 `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	        ___                     ");
							printf("\n\t            _-_-  _/|______||__     ");
							printf("\n\t         _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t            _-_- `( o )----( o )-'  ");
							printf("\n\t                   `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t             ___                     ");
							printf("\n\t             _-_-  _/|______||__     ");
							printf("\n\t          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t             _-_- `( o )----( o )-'  ");
							printf("\n\t                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	            ___                     ");
							printf("\n\t                _-_-  _/|______||__     ");
							printf("\n\t             _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                _-_- `( o )----( o )-'  ");
							printf("\n\t                       `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	              ___                     ");
							printf("\n\t                  _-_-  _/|______||__     ");
							printf("\n\t              _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                  _-_- `( o )----( o )-'  ");
							printf("\n\t                         `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                ___                     ");
							printf("\n\t                    _-_-  _/|______||__     ");
							printf("\n\t                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                    _-_- `( o )----( o )-'  ");
							printf("\n\t                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t==================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                 ___                     ");
							printf("\n\t                     _-_-  _/|______||__     ");
							printf("\n\t                  _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                     _-_- `( o )----( o )-'  ");
							printf("\n\t                            `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                    ___                     ");
							printf("\n\t                        _-_-  _/|______||__     ");
							printf("\n\t                     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                        _-_- `( o )----( o )-'  ");
							printf("\n\t                               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                       ___                     ");
							printf("\n\t                           _-_-  _/|______||__     ");
							printf("\n\t                        _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                           _-_- `( o )----( o )-'  ");
							printf("\n\t                                  `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                          ___                     ");
							printf("\n\t                              _-_-  _/|______||__     ");
							printf("\n\t                           _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                              _-_- `( o )----( o )-'  ");
							printf("\n\t                                     `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                             ___                     ");
							printf("\n\t                                 _-_-  _/|______||__     ");
							printf("\n\t                              _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                 _-_- `( o )----( o )-'  ");
							printf("\n\t                                        `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                ___                     ");
							printf("\n\t                                    _-_-  _/|______||__     ");
							printf("\n\t                                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                    _-_- `( o )----( o )-'  ");
							printf("\n\t                                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                   ___                     ");
							printf("\n\t                                       _-_-  _/|______||__     ");
							printf("\n\t                                    _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                       _-_- `( o )----( o )-'  ");
							printf("\n\t                                              `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                       ___                     ");
							printf("\n\t                                           _-_-  _/|______||__     ");
							printf("\n\t                                        _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                           _-_- `( o )----( o )-'  ");
							printf("\n\t                                                  `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	                                           ___                     ");
							printf("\n\t                                               _-_-  _/|______||__     ");
							printf("\n\t                                            _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                               _-_- `( o )----( o )-'  ");
							printf("\n\t                                                      `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                               ___                     ");
							printf("\n\t                                                   _-_-  _/|______||__     ");
							printf("\n\t                                                _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                   _-_- `( o )----( o )-'  ");
							printf("\n\t                                                          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                    ___                     ");
							printf("\n\t                                                        _-_-  _/|______||__     ");
							printf("\n\t                                                     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                        _-_- `( o )----( o )-'  ");
							printf("\n\t                                                               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                         ___                     ");
							printf("\n\t                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\tt   	                                                              ___                     ");
							printf("\n\tt                                                                  _-_-  _/|______||__     ");
							printf("\n\tt                                                               _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\tt                                                                  _-_- `( o )----( o )-'  ");
							printf("\n\tt                                                                         `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\tt===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                   ___                     ");
							printf("\n\t                                                                       _-_-  _/|______||__     ");
							printf("\n\t                                                                   _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                       _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                              `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                         ___                   ");
							printf("\n\t                                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                    `-'      `-'      ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                               ___                   ");
							printf("\n\t                                                                                   _-_-  _/|______||__     ");
							printf("\n\t                                                                                _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                   _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                     ___                   ");
							printf("\n\t                                                                                         _-_-  _/|______||__     ");
							printf("\n\t                                                                                      _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                         _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
							
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                           ___                   ");
							printf("\n\t                                                                                               _-_-  _/|______||__     ");
							printf("\n\t                                                                                            _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                               _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                      `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                ___                   ");
							printf("\n\t                                                                                                    _-_-  _/|______||__     ");
							printf("\n\t                                                                                                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                    _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                     ___                   ");
							printf("\n\t                                                                                                         _-_-  _/|______||__     ");
							printf("\n\t                                                                                                      _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                         _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                                `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                         ___                   ");
							printf("\n\t                                                                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							if(row==0) 
							{
								if(userCompetingOrder[0] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 30))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=0;
									}
									if((totalGas1<15000) && (totalTime1 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result1=1;
									}
								}
								else if(userCompetingOrder[0] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 30))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=0;
									}
									if((totalGas2<20000) && (totalTime2 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result1=1;
									}
								}
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 30))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=0;
									}
									if((totalGas3<25000) && (totalTime3 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result1=1;
									}
								}
								printf("\n\n\t\t\tPress <ENTER> to move to the next competition!!");
							}
							else if(row == 1)
							{									
								if(userCompetingOrder[1] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 23))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas1<15000) && (totalTime1 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								else if(userCompetingOrder[1] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 23))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas2<20000) && (totalTime2 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 23))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas3<25000) && (totalTime3 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								printf("\n\n\t\t\tPress <ENTER> to move to the next competition!!");
							}
							else
							{									
								if(userCompetingOrder[2] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 19))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas1<15000) && (totalTime1 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}
								else if(userCompetingOrder[2] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 19))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas2<20000) && (totalTime2 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 19))
									{
										SetConsoleTextAttribute ( h1,FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas3<25000) && (totalTime3 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}
								printf("\n\n\t\t\tThree competitions are finished!!");
								printf("\n\n\t\t\tPress <ENTER> to continue!!");
							}								
							getch();
							system("cls");							
						}
						//computer competing order 2
						else if(randNum==2)						
						for(row=0;row<3;row++)
						{   
							//users determine order of competing cars
							printf("\n\n\t\t\t\tFollowing you determine which car you want to compete in the first competition");  
							printf("\n\n\t\t\t\tCompetition %d",computerCompetingOrder1[row]);
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour						
							printf("\n\n\t\t\t\tcomputer: Car-%d",computerCompetingOrder2[row]);
							SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour								
							printf("\n\n\t\t\t\t    User: Car-");
							scanf("%d",&userCompetingOrder[row]);
							fflush(stdin);
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							printf("\n\n\n\t\t\t\tPress <ENTER> to start!!!");
							getch();
							system("cls");
							//animation - competing
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t                    ");
							printf("\n\t   _/|______||__     ");
							printf("\n\t  / ,-. -|-  ,-.`-.  ");
							printf("\n\t  `( o )----( o )-'  ");
							printf("\n\t    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour	
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t_                     ");
							printf("\n\t_-  _/|______||__     ");
							printf("\n\t_  / ,-. -|-  ,-.`-.  ");
							printf("\n\t_- `( o )----( o )-'  ");
							printf("\n\t     `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t___                     ");
							printf("\n\t_-_-  _/|______||__     ");
							printf("\n\t-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t_-_- `( o )----( o )-'  ");
							printf("\n\t       `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  ___                      ");
							printf("\n\t  _-_-   _/|______||__     ");
							printf("\n\t-_-__   / ,-. -|-  ,-.`-.  ");
							printf("\n\t  _-_-  `( o )----( o )-'  ");
							printf("\n\t          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t	___                     ");
							printf("\n\t    _-_-  _/|______||__     ");
							printf("\n\t _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t    _-_- `( o )----( o )-'  ");
							printf("\n\t           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	  ___                     ");
							printf("\n\t      _-_-  _/|______||__     ");
							printf("\n\t   _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t      _-_- `( o )----( o )-'  ");
							printf("\n\t             `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	    ___                     ");
							printf("\n\t        _-_-  _/|______||__     ");
							printf("\n\t     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t        _-_- `( o )----( o )-'  ");
							printf("\n\t               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	      ___                     ");
							printf("\n\t          _-_-  _/|______||__     ");
							printf("\n\t       _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t          _-_- `( o )----( o )-'  ");
							printf("\n\t                 `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	        ___                     ");
							printf("\n\t            _-_-  _/|______||__     ");
							printf("\n\t         _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t            _-_- `( o )----( o )-'  ");
							printf("\n\t                   `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t             ___                     ");
							printf("\n\t             _-_-  _/|______||__     ");
							printf("\n\t          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t             _-_- `( o )----( o )-'  ");
							printf("\n\t                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	            ___                     ");
							printf("\n\t                _-_-  _/|______||__     ");
							printf("\n\t             _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                _-_- `( o )----( o )-'  ");
							printf("\n\t                       `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	              ___                     ");
							printf("\n\t                  _-_-  _/|______||__     ");
							printf("\n\t              _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                  _-_- `( o )----( o )-'  ");
							printf("\n\t                         `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                ___                     ");
							printf("\n\t                    _-_-  _/|______||__     ");
							printf("\n\t                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                    _-_- `( o )----( o )-'  ");
							printf("\n\t                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t==================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                 ___                     ");
							printf("\n\t                     _-_-  _/|______||__     ");
							printf("\n\t                  _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                     _-_- `( o )----( o )-'  ");
							printf("\n\t                            `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                    ___                     ");
							printf("\n\t                        _-_-  _/|______||__     ");
							printf("\n\t                     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                        _-_- `( o )----( o )-'  ");
							printf("\n\t                               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                       ___                     ");
							printf("\n\t                           _-_-  _/|______||__     ");
							printf("\n\t                        _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                           _-_- `( o )----( o )-'  ");
							printf("\n\t                                  `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                          ___                     ");
							printf("\n\t                              _-_-  _/|______||__     ");
							printf("\n\t                           _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                              _-_- `( o )----( o )-'  ");
							printf("\n\t                                     `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                             ___                     ");
							printf("\n\t                                 _-_-  _/|______||__     ");
							printf("\n\t                              _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                 _-_- `( o )----( o )-'  ");
							printf("\n\t                                        `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                ___                     ");
							printf("\n\t                                    _-_-  _/|______||__     ");
							printf("\n\t                                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                    _-_- `( o )----( o )-'  ");
							printf("\n\t                                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                   ___                     ");
							printf("\n\t                                       _-_-  _/|______||__     ");
							printf("\n\t                                    _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                       _-_- `( o )----( o )-'  ");
							printf("\n\t                                              `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                       ___                     ");
							printf("\n\t                                           _-_-  _/|______||__     ");
							printf("\n\t                                        _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                           _-_- `( o )----( o )-'  ");
							printf("\n\t                                                  `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	                                           ___                     ");
							printf("\n\t                                               _-_-  _/|______||__     ");
							printf("\n\t                                            _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                               _-_- `( o )----( o )-'  ");
							printf("\n\t                                                      `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                               ___                     ");
							printf("\n\t                                                   _-_-  _/|______||__     ");
							printf("\n\t                                                _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                   _-_- `( o )----( o )-'  ");
							printf("\n\t                                                          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                    ___                     ");
							printf("\n\t                                                        _-_-  _/|______||__     ");
							printf("\n\t                                                     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                        _-_- `( o )----( o )-'  ");
							printf("\n\t                                                               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                         ___                     ");
							printf("\n\t                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\tt   	                                                              ___                     ");
							printf("\n\tt                                                                  _-_-  _/|______||__     ");
							printf("\n\tt                                                               _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\tt                                                                  _-_- `( o )----( o )-'  ");
							printf("\n\tt                                                                         `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\tt===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                   ___                     ");
							printf("\n\t                                                                       _-_-  _/|______||__     ");
							printf("\n\t                                                                   _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                       _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                              `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                         ___                   ");
							printf("\n\t                                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                    `-'      `-'      ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                               ___                   ");
							printf("\n\t                                                                                   _-_-  _/|______||__     ");
							printf("\n\t                                                                                _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                   _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                     ___                   ");
							printf("\n\t                                                                                         _-_-  _/|______||__     ");
							printf("\n\t                                                                                      _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                         _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
							
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                           ___                   ");
							printf("\n\t                                                                                               _-_-  _/|______||__     ");
							printf("\n\t                                                                                            _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                               _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                      `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                ___                   ");
							printf("\n\t                                                                                                    _-_-  _/|______||__     ");
							printf("\n\t                                                                                                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                    _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                     ___                   ");
							printf("\n\t                                                                                                         _-_-  _/|______||__     ");
							printf("\n\t                                                                                                      _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                         _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                                `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                         ___                   ");
							printf("\n\t                                                                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							if(row==0) 
							{
								if(userCompetingOrder[0] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 23))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas1<15000) && (totalTime1 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								else if(userCompetingOrder[0] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 23))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas2<20000) && (totalTime2 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 23))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas3<25000) && (totalTime3 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								
								printf("\n\n\t\t\tPress <ENTER> to move to the next competition!!");
							}
							else if(row == 1)
							{									
								if(userCompetingOrder[1] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 30))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas1<15000) && (totalTime1 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								else if(userCompetingOrder[1] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 30))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas2<20000) && (totalTime2 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 30))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas3<25000) && (totalTime3 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								printf("\n\n\t\t\tPress <ENTER> to move to the next competition!!");
							}
							else
							{									
								if(userCompetingOrder[2] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 19))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas1<15000) && (totalTime1 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}
								else if(userCompetingOrder[2] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 19))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas2<20000) && (totalTime2 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 19))
									{
										SetConsoleTextAttribute ( h1,  FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas3<25000) && (totalTime3 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}								
								printf("\n\n\t\t\tThree competitions are finished!!");
								printf("\n\n\t\t\tPress <ENTER> to continue!!");
							}								
							getch();
							system("cls");
						}
						//computer competing order 3
						else
						for(row=0;row<3;row++)
						{   
							//users determine order of competing cars
							printf("\n\n\t\t\t\tFollowing you determine which car you want to compete in the first competition");  
							printf("\n\n\t\t\t\tCompetition %d",computerCompetingOrder1[row]);
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
							printf("\n\n\t\t\t\tcomputer: Car-%d",computerCompetingOrder3[row]);
							SetConsoleTextAttribute ( h1, FOREGROUND_RED| FOREGROUND_INTENSITY); //foreground colour								
							printf("\n\n\t\t\t\t    User: Car-");
							scanf("%d",&userCompetingOrder[row]);
							fflush(stdin);
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN |FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							printf("\n\n\n\t\t\t\tPress <ENTER> to start!!!");
							getch();
							system("cls");
							//animation - competing
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t                    ");
							printf("\n\t   _/|______||__     ");
							printf("\n\t  / ,-. -|-  ,-.`-.  ");
							printf("\n\t  `( o )----( o )-'  ");
							printf("\n\t    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour	
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t_                     ");
							printf("\n\t_-  _/|______||__     ");
							printf("\n\t_  / ,-. -|-  ,-.`-.  ");
							printf("\n\t_- `( o )----( o )-'  ");
							printf("\n\t     `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t___                     ");
							printf("\n\t_-_-  _/|______||__     ");
							printf("\n\t-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t_-_- `( o )----( o )-'  ");
							printf("\n\t       `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  ___                      ");
							printf("\n\t  _-_-   _/|______||__     ");
							printf("\n\t-_-__   / ,-. -|-  ,-.`-.  ");
							printf("\n\t  _-_-  `( o )----( o )-'  ");
							printf("\n\t          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t	___                     ");
							printf("\n\t    _-_-  _/|______||__     ");
							printf("\n\t _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t    _-_- `( o )----( o )-'  ");
							printf("\n\t           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	  ___                     ");
							printf("\n\t      _-_-  _/|______||__     ");
							printf("\n\t   _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t      _-_- `( o )----( o )-'  ");
							printf("\n\t             `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	    ___                     ");
							printf("\n\t        _-_-  _/|______||__     ");
							printf("\n\t     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t        _-_- `( o )----( o )-'  ");
							printf("\n\t               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	      ___                     ");
							printf("\n\t          _-_-  _/|______||__     ");
							printf("\n\t       _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t          _-_- `( o )----( o )-'  ");
							printf("\n\t                 `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	        ___                     ");
							printf("\n\t            _-_-  _/|______||__     ");
							printf("\n\t         _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t            _-_- `( o )----( o )-'  ");
							printf("\n\t                   `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t             ___                     ");
							printf("\n\t             _-_-  _/|______||__     ");
							printf("\n\t          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t             _-_- `( o )----( o )-'  ");
							printf("\n\t                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	            ___                     ");
							printf("\n\t                _-_-  _/|______||__     ");
							printf("\n\t             _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                _-_- `( o )----( o )-'  ");
							printf("\n\t                       `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	              ___                     ");
							printf("\n\t                  _-_-  _/|______||__     ");
							printf("\n\t              _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                  _-_- `( o )----( o )-'  ");
							printf("\n\t                         `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                ___                     ");
							printf("\n\t                    _-_-  _/|______||__     ");
							printf("\n\t                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                    _-_- `( o )----( o )-'  ");
							printf("\n\t                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t==================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                 ___                     ");
							printf("\n\t                     _-_-  _/|______||__     ");
							printf("\n\t                  _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                     _-_- `( o )----( o )-'  ");
							printf("\n\t                            `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                    ___                     ");
							printf("\n\t                        _-_-  _/|______||__     ");
							printf("\n\t                     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                        _-_- `( o )----( o )-'  ");
							printf("\n\t                               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                       ___                     ");
							printf("\n\t                           _-_-  _/|______||__     ");
							printf("\n\t                        _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                           _-_- `( o )----( o )-'  ");
							printf("\n\t                                  `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                          ___                     ");
							printf("\n\t                              _-_-  _/|______||__     ");
							printf("\n\t                           _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                              _-_- `( o )----( o )-'  ");
							printf("\n\t                                     `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                             ___                     ");
							printf("\n\t                                 _-_-  _/|______||__     ");
							printf("\n\t                              _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                 _-_- `( o )----( o )-'  ");
							printf("\n\t                                        `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                ___                     ");
							printf("\n\t                                    _-_-  _/|______||__     ");
							printf("\n\t                                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                    _-_- `( o )----( o )-'  ");
							printf("\n\t                                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                   ___                     ");
							printf("\n\t                                       _-_-  _/|______||__     ");
							printf("\n\t                                    _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                       _-_- `( o )----( o )-'  ");
							printf("\n\t                                              `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                       ___                     ");
							printf("\n\t                                           _-_-  _/|______||__     ");
							printf("\n\t                                        _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                           _-_- `( o )----( o )-'  ");
							printf("\n\t                                                  `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t  	                                           ___                     ");
							printf("\n\t                                               _-_-  _/|______||__     ");
							printf("\n\t                                            _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                               _-_- `( o )----( o )-'  ");
							printf("\n\t                                                      `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                               ___                     ");
							printf("\n\t                                                   _-_-  _/|______||__     ");
							printf("\n\t                                                _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                   _-_- `( o )----( o )-'  ");
							printf("\n\t                                                          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                    ___                     ");
							printf("\n\t                                                        _-_-  _/|______||__     ");
							printf("\n\t                                                     _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                        _-_- `( o )----( o )-'  ");
							printf("\n\t                                                               `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                         ___                     ");
							printf("\n\t                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\tt   	                                                              ___                     ");
							printf("\n\tt                                                                  _-_-  _/|______||__     ");
							printf("\n\tt                                                               _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\tt                                                                  _-_- `( o )----( o )-'  ");
							printf("\n\tt                                                                         `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\tt===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                   ___                     ");
							printf("\n\t                                                                       _-_-  _/|______||__     ");
							printf("\n\t                                                                   _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                       _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                              `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                         ___                   ");
							printf("\n\t                                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                    `-'      `-'      ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                               ___                   ");
							printf("\n\t                                                                                   _-_-  _/|______||__     ");
							printf("\n\t                                                                                _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                   _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                          `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                     ___                   ");
							printf("\n\t                                                                                         _-_-  _/|______||__     ");
							printf("\n\t                                                                                      _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                         _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
							
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                           ___                   ");
							printf("\n\t                                                                                               _-_-  _/|______||__     ");
							printf("\n\t                                                                                            _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                               _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                      `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                ___                   ");
							printf("\n\t                                                                                                    _-_-  _/|______||__     ");
							printf("\n\t                                                                                                 _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                    _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                           `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                     ___                   ");
							printf("\n\t                                                                                                         _-_-  _/|______||__     ");
							printf("\n\t                                                                                                      _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                         _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                                `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							system("cls");
						
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
							printf("\n\t   	                                                                                                         ___                   ");
							printf("\n\t                                                                                                             _-_-  _/|______||__     ");
							printf("\n\t                                                                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
							printf("\n\t                                                                                                             _-_- `( o )----( o )-'  ");
							printf("\n\t                                                                                                                    `-'      `-'     ");
							SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
							printf("\n\t===================================================================================================================================");
							SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
							Sleep(50);
							if(row==0) 
							{
								if(userCompetingOrder[0] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=0;
									}
									if((totalGas1<15000) && (totalTime1 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result1=1;
									}
								}
								else if(userCompetingOrder[0] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=0;
									}
									if((totalGas2<20000) && (totalTime2 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result1=1;
									}
								}
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=0;
									}
									if((totalGas3<25000) && (totalTime3 > 30))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result1=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result1=1;
									}
								}
								printf("\n\n\t\t\tPress <ENTER> to move to the next competition!!");
							}
							else if(row == 1)
							{									
								if(userCompetingOrder[1] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas1<15000) && (totalTime1 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								else if(userCompetingOrder[1] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas2<20000) && (totalTime2 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=0;
									}
									if((totalGas3<25000) && (totalTime3 > 19))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result2=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result2=1;
									}
								}
								printf("\n\n\t\t\tPress <ENTER> to move to the next competition!!");
							}
							else
							{									
								if(userCompetingOrder[2] == 1)
								{
									if((totalGas1<15000) && (totalTime1 <= 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas1<15000) && (totalTime1 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=1;
									}
									if(totalGas1>15000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}
								else if(userCompetingOrder[2] == 2)
								{
									if((totalGas2<20000) && (totalTime2 <= 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas2<20000) && (totalTime2 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=1;
									}
									if(totalGas2>20000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}
								else
								{
									if((totalGas3<25000) && (totalTime3 <= 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: User");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=0;
									}
									if((totalGas3<25000) && (totalTime3 > 23))
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner: Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										result3=1;
									}
									if(totalGas3>25000) 
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tWinner:Computer");
										SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY); //foreground colour
										printf("\n\n\t\t\tThe user has run out of all his gas before finishing 2 km!");
										result3=1;
									}
								}
								printf("\n\n\t\t\tThree competitions are finished!!");
								printf("\n\n\t\t\tPress <ENTER> to continue!!");
							}								
							getch();
							system("cls");
						}
						
						totalResult = result1+result2+result3;	//final results calculations
						
						do
						{
							printf("\n\n\n\t\t\t\tPress 'a' to go back to car menu and press 'b' to exit.");
							choice = _getch();  //restrict user to enter one character only
							fflush(stdin);
							if(choice == 'a')
							{
								flag = 2;
								system("cls"); //clear screen
							}
							else if(choice == 'b')
							flag = 7;
							else 
							{
								system("cls");  //clear screen
								printf("\n\t\t\t\tYou have entered an invalid letter!");
								printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
								flag = 1;
							}
						}while(flag < 2);
					}
					else
					{
						printf("\n\n\n\n\n\n\n\n\n\n");
						printf("\n\n\n\t\t\t\t                         SORRY! You cannot veiw this page yet!");
						printf("\n\n\n\t\t\t\t      We have noticed that you have not set your three cars' characteristics yet!!");
						printf("\n\n\n\t\t\t\t          Press <ENTER> to go back to car menu and finish setting your cars!!!");
						flag=3;
						getch();
						system("cls");
					}
					z4=2;
					break;

			/*Final results printed*/
				case'g':
				case'G':
					if(z4==2)
					{
						printf("\n\n\n\n\t\t\t\t\t\t 0:user wins 1:computer wins");
						//computer competing order 1
						if(randNum == 1)
						{
							if((totalResult==0)|| (totalResult==1)) //if user wins
							{
								for(row=0;row<3;row++)
								{
									printf("\n\n\t\t\t\t\t Competition #      User Car   vs     Computer Car");
									printf("\n\n\t\t\t\t\t      %d             Car-%d              Car-%d ",computerCompetingOrder1[row],userCompetingOrder[row],computerCompetingOrder1[row]);
								}
								printf("\n\n\t\t\t\t\t===============================");
								printf("\n\n\t\t\t\t\t Competition #      Result");
								printf("\n\n\t\t\t\t\t      1               %d",result1);
								printf("\n\n\t\t\t\t\t      2               %d",result2);
								printf("\n\n\t\t\t\t\t      3               %d",result3);
								printf("\n\n\t\t\t\t\t Final Result:  User WINS!!!!!!");
							}
							else //if computer wins
							{
								for(row=0;row<3;row++)
								{
									printf("\n\n\t\t\t\t\t Competition #      User Car   vs     Computer Car");
									printf("\n\n\t\t\t\t\t      %d             Car-%d              Car-%d ",computerCompetingOrder1[row],userCompetingOrder[row],computerCompetingOrder1[row]);								
								}
								printf("\n\n\t\t\t\t\t===============================");
								printf("\n\n\t\t\t\t\t Competition #      Result");
								printf("\n\n\t\t\t\t\t      1               %d",result1);
								printf("\n\n\t\t\t\t\t      2               %d",result2);
								printf("\n\n\t\t\t\t\t      3               %d",result3);
								printf("\n\n\t\t\t\t\t Final Result:  Computer wins");
							}
						}
						//computer competing order 2
						else if(randNum == 2)
						{
							if((totalResult==0)|| (totalResult==1)) //if user wins
							{
								for(row=0;row<3;row++)
								{
									printf("\n\n\t\t\t\t\t Competition #      User Car   vs     Computer Car");
									printf("\n\n\t\t\t\t\t      %d             Car-%d              Car-%d ",computerCompetingOrder1[row],userCompetingOrder[row],computerCompetingOrder2[row]);
								}
								printf("\n\n\t\t\t\t\t===============================");
								printf("\n\n\t\t\t\t\t Competition #      Result");
								printf("\n\n\t\t\t\t\t      1               %d",result1);
								printf("\n\n\t\t\t\t\t      2               %d",result2);
								printf("\n\n\t\t\t\t\t      3               %d",result3);
								printf("\n\n\t\t\t\t\t Final Result:  User WINS!!!!!!");
							}
							//ifcomputer wins
							else
							{
								for(row=0;row<3;row++)
								{
									printf("\n\n\t\t\t\t\t Competition #      User Car   vs     Computer Car");
									printf("\n\n\t\t\t\t\t      %d             Car-%d              Car-%d ",computerCompetingOrder1[row],userCompetingOrder[row],computerCompetingOrder2[row]);								
								}
								printf("\n\n\t\t\t\t\t===============================");
								printf("\n\n\t\t\t\t\t Competition #      Result");
								printf("\n\n\t\t\t\t\t      1               %d",result1);
								printf("\n\n\t\t\t\t\t      2               %d",result2);
								printf("\n\n\t\t\t\t\t      3               %d",result3);
								printf("\n\n\t\t\t\t\t Final Result:  Computer wins");
							}
						}
						//computer competing order 3
						else
						{
							if((totalResult==0)|| (totalResult==1)) //if user wins
							{
								for(row=0;row<3;row++)
								{
									printf("\n\n\t\t\t\t\t Competition #      User Car   vs     Computer Car");
									printf("\n\n\t\t\t\t\t      %d             Car-%d              Car-%d ",computerCompetingOrder1[row],userCompetingOrder[row],computerCompetingOrder3[row]);
								}
								printf("\n\n\t\t\t\t\t===============================");
								printf("\n\n\t\t\t\t\t Competition #      Result");
								printf("\n\n\t\t\t\t\t      1               %d",result1);
								printf("\n\n\t\t\t\t\t      2               %d",result2);
								printf("\n\n\t\t\t\t\t      3               %d",result3);
								printf("\n\n\t\t\t\t\t Final Result:  User WINS!!!!!!");
							}
							//if computer wins
							else
							{
								for(row=0;row<3;row++)
								{
									printf("\n\n\t\t\t\t\t Competition #      User Car   vs     Computer Car");
									printf("\n\n\t\t\t\t\t      %d             Car-%d              Car-%d ",computerCompetingOrder1[row],userCompetingOrder[row],computerCompetingOrder3[row]);								
								}
								printf("\n\n\t\t\t\t\t===============================");
								printf("\n\n\t\t\t\t\t Competition #      Result");
								printf("\n\n\t\t\t\t\t      1               %d",result1);
								printf("\n\n\t\t\t\t\t      2               %d",result2);
								printf("\n\n\t\t\t\t\t      3               %d",result3);
								printf("\n\n\t\t\t\t\t Final Result:  Computer wins");
							}
						}
						do
						{
							printf("\n\n\n\t\t\t\tPress 'a' to go back to car menu and press 'b' to exit.");
							choice = _getch();  //restrict user to enter one character only
							fflush(stdin);
							if(choice == 'a')
							{
								flag = 2;
								system("cls"); //clear screen
							}
							else if(choice == 'b')
							flag = 7;
							else 
							{
								system("cls");  //clear screen
								printf("\n\t\t\t\tYou have entered an invalid letter!");
								printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
								flag = 1;
							}
						}while(flag < 2);
					}
					else
					{
						printf("\n\n\n\n\n\n\n\n\n\n");
						printf("\n\n\n\t\t\t\t               SORRY! You cannot veiw this page yet!");
						printf("\n\n\n\t\t\t\t      We have noticed that you have not started competing!!");
						printf("\n\n\n\t\t\t\t              Press <ENTER> to go back to car menu!!!");
						flag=3;
						getch();
						system("cls");
					}
					break;

			/*Return to Main Menu*/
				case'h':
				case'H':
					flag = 6;
					break;

			     /*Exit*/
				case'i':
				case'I':
					flag = 7;
					break;

				default:
					printf("\n\n\n\t\t\t\t\tSORRY!You have enter an invalid letter!!");
					printf("\n\n\n\t\t\t\t\tPress <ENTER> to return to the CAR MENU!!");
					getch();
					system("cls");
					flag=2;
					break;
				} //end of car menu
			}while(flag<6);
			break;

	/*Multi Players*/
		case'B':
		case'b':
			do
			{
				system("color 80");
				do
				{	
					system("color 80");			
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("\n\t\t\t\t\t\tWelcome!!!!Please enter the number of users joining to");
					printf("\n\n\t\t\t\t\t\t               compete this game:");
					scanf("%d",&userNumber);
					fflush(stdin);
					if(userNumber>0)
					flag=2;
					else
					{
						printf("\n\n\n\t\t\t\t\tSORRY!You have enter an invalid letter!!");
						printf("\n\n\n\t\t\t\t\tPress <ENTER> to try again!!");
						getch();
						system("cls");
						flag=1;	
					}
				}while(flag<2);
				
				printf("\n\n\t\t\t\t        Press <ENTER> to start the game!!!");
				getch();
				system("cls");
				do
				{
					system("color 80");
					printf("\n\n\n\n\n\n\n");
					printf("\n\t\t\t [CAR MENU]\n\n");
					printf("\n\t\t\t\t||");
					printf("\n\t\t\t\t||  a] Set Time");
					printf("\n\t\t\t\t||");
					printf("\n\t\t\t\t =====");
					printf("\n\t\t\t\t      ||");
					printf("\n\t\t\t\t      ||  b] View Time");
					printf("\n\t\t\t\t      ||");
					printf("\n\t\t\t\t       =====");
					printf("\n\t\t\t\t            ||");
					printf("\n\t\t\t\t            ||  c] Users' car setting");
					printf("\n\t\t\t\t            ||");
					printf("\n\t\t\t\t             =====");
					printf("\n\t\t\t\t                  ||");
					printf("\n\t\t\t\t                  ||  d] Start Competing!!!");
					printf("\n\t\t\t\t                  ||");
					printf("\n\t\t\t\t                   =====");
					printf("\n\t\t\t\t                        ||");
					printf("\n\t\t\t\t                        ||  e] See results");
					printf("\n\t\t\t\t                        ||");
					printf("\n\t\t\t\t                         =====");
					printf("\n\t\t\t\t                              ||");
					printf("\n\t\t\t\t                              ||  f] Reset Number of users");
					printf("\n\t\t\t\t                              ||");
					printf("\n\t\t\t\t                               =====");
					printf("\n\t\t\t\t                                    ||");
					printf("\n\t\t\t\t                                    ||  g] Return to Main Menu");
					printf("\n\t\t\t\t                                    ||");
					printf("\n\t\t\t\t                                     =====");
					printf("\n\t\t\t\t                                          ||");
					printf("\n\t\t\t\t                                          ||  h] Exit");
					printf("\n\t\t\t\t                                          ||");
					printf("\n\t\t\t\t                                           =====");
					printf("\n\t\t\t\t                                                ||");
					printf("\n\t\t\t\t                                                ||");
					printf("\n\t\t\t\t                                                ||  Your choice:");
					car2Menu = _getch();
					fflush(stdin);
					system("cls");
					switch(car2Menu)
					{
					/*Time set*/
						case'a':
						case'A':
							system("color 81");//background and foreground color
							do
							{
								system("color 81");	//background and foreground color					
								printf("\n\n\t\t\t\tFollowing please set the time limit for the competitors");
								printf("\n\n\t\t\t\t                TIME(s):");
								scanf("%d",&userTime);
								fflush(stdin);
								if(userTime>0)
								flag=2;
							else
							{
								printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice that time has to be bigger than 0!!");
								printf("\n\n\t\t\tPress <ENTER> to try again!!");
								getch();
								system("cls");
								flag = 1;
							}
							}while(flag<2);
							
							printf("\n\n\t\t\t\tYour Time is %ds!",userTime);
							do
							{
								system("color 81");	//background and foreground color
								printf("\n\n\n\t\t\t\tPress 'a' to go back to CAR MENU and press 'b' to exit the game.");
								choice = _getch();  //restrict user to enter one character only
								fflush(stdin);
								if(choice == 'a')
								{
									flag = 2;
									system("cls"); //clear screen
								}
								else if(choice == 'b')
								flag = 7;
								else 
								{
									system("cls");  //clear screen
									printf("\n\t\t\t\tYou have entered an invalid letter!");
									printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
									flag = 1;
								}
							}while(flag < 2);
							break;

					/*View Time*/
						case'b':
						case'B':
							system("color 85"); //background and foreground color
							printf("\n\n\t\t\t\tTime: %d s",userTime);
							do
							{
								system("color 85"); //background and foreground color
								printf("\n\n\n\t\t\t\tPress 'a' to go back to CAR MENU and press 'b' to exit the game.");
								choice = _getch();  //restrict user to enter one character only
								fflush(stdin);
								if(choice == 'a')
								{
									flag = 2;
									system("cls"); //clear screen
								}
								else if(choice == 'b')
								flag = 7;
								else 
								{
									system("cls");  //clear screen
									printf("\n\t\t\t\tYou have entered an invalid letter!");
									printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
									flag = 1;
								}
							}while(flag < 2);
							break;

							/*Setting Menu*/
						case'c':
						case'C':
							do
							{
								system("color 30");
								printf("\n\n\n\n\n\n");
								printf("\n\t\t\t\t\t\t\t                [SETTING]");
								printf("\n\n\n");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   || a]  Enter/Edit Car Name");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   || b]  Enter/Edit initial velocity");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   || c]  Enter/Edit final velocity");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   || d]  Enter/Edit acceleration");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   || e]  View all information");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   || f]  Return to Car Menu");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   || g]  Exit");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||");
								printf("\n\t\t\t\t\t\t\t   ||        Your Choice:");
								setting2Menu = _getch();
								fflush(stdin);
								system("cls");
								switch(setting2Menu)
								{
									/*Enter/Edit Car Name*/
									case'a':
									case'A':
										system("color 31");
										printf("\n\n\t\t\t\tFollowing please enter your car's name and press <ENTER>!");
										for(row=1;row<userNumber+1;row++)
										{
											printf("\n\n\t\t\t\t\t\tUser %d:",row);
											scanf("%[^\n]",userCarName[row]);
											fflush(stdin);
										}
										do
										{
											printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
											choice = _getch();  //restrict user to enter one character only
											fflush(stdin);
											if(choice == 'a')
											{
												flag = 2;
												system("cls"); //clear screen
											}
											else if(choice == 'b')
											flag = 7;
											else 
											{
												system("cls");  //clear screen
												printf("\n\t\t\t\tYou have entered an invalid letter!");
												printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
												flag = 1;
											}
										}while(flag < 2);
										z1=1;
										break;

										/*Enter/Edit Car's inital velocity*/
									case'b':
									case'B':
										system("color 31"); //background and foreground color
										printf("\n\n\t\t\t\tFollowing please enter your car's initial velocity(m/s) and press <ENTER>!");
										for(row=1;row<userNumber+1;row++)
										{
											do
											{		
												system("color 31"); //background and foreground color									
												printf("\n\n\t\t\t\t\t\tUser %d:",row);
												scanf("%d",&userInitialVelocity[row]);
												fflush(stdin);
												if(userInitialVelocity[row]>0)
												flag=2;
												
												else
												{
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice that velocity has to be bigger than 0!!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
											}while(flag<2);	
										}									
										do
										{
											system("color 31"); //background and foreground color
											printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
											choice = _getch();  //restrict user to enter one character only
											fflush(stdin);
											if(choice == 'a')
											{
												flag = 2;
												system("cls"); //clear screen
											}
											else if(choice == 'b')
											flag = 7;
											else 
											{
												system("cls");  //clear screen
												printf("\n\t\t\t\tYou have entered an invalid letter!");
												printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
												flag = 1;
											}
										}while(flag < 2);
										z2=1;
										break;

										/*Enter/Edit Car's final velocity*/
									case'c':
									case'C':
										system("color 31");
										if(z2==1)
										{
											printf("\n\n\t\t\t\tFollowing please enter your car's final velocity(m/s) and press <ENTER>!");
											for(row=1;row<userNumber+1;row++)
											{
												do
												{	
													system("color 31"); //background and foreground color										
													printf("\n\n\t\t\t\t\t\tUser %d:",row);
													scanf("%d",&userFinalVelocity[row]);
													fflush(stdin);
													if(userFinalVelocity[row]<userInitialVelocity[row])
													{
														printf("\n\n\t\t\t\tSORRY! You have entered an invalid number!!");
														printf("\n\n\t\t\t\tPlease notice that final velocity has to be bigger than the initial velocity!!");
														printf("\n\n\t\t\t\tPress <ENTER> to retry again!");
														getch();
														system("cls");
														flag=1;
													}
													else
													flag=2; 
												}while(flag<2);
											}
											do
											{
												system("color 31"); //background and foreground color
												printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
												choice = _getch();  //restrict user to enter one character only
												fflush(stdin);
												if(choice == 'a')
												{
													flag = 2;
													system("cls"); //clear screen
												}
												else if(choice == 'b')
												flag = 7;
												else 
												{
													system("cls");  //clear screen
													printf("\n\t\t\t\tYou have entered an invalid letter!");
													printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
													flag = 1;
												}
											}while(flag < 2);
											z3=1;
										}
										else
										{
											printf("\n\n\n\t\t\t\t\tSORRY!You cannot view this page yet!");
											printf("\n\n\n\t\t\t\t\tWe have noticed you have not entered your initial velocity!");
											printf("\n\n\n\t\t\t\t\tPress <ENTER> to return the SETTING MENU!!");
											getch();
											system("cls");
											flag=2;
										}
										break;

										/*Enter/Edit Acceleration*/
									case'd':
									case'D':
										system("color 31");
										printf("\n\n\t\t\t\tFollowing please enter your car's acceleration(m/s/s) and press <ENTER>!");
										for(row=1;row<userNumber+1;row++)
										{
											do
											{		
												system("color 31"); //background and foreground color									
												printf("\n\n\t\t\t\t\t\tUser %d:",row);
												scanf("%d",&userAcceleration[row]);
												fflush(stdin);
												if(userAcceleration[row]>0)
												flag=2;
												else
												{									
													printf("\n\n\t\t\tSORRY! You have enter an invalid number!!Notice that Acceleration has to be bigger than 0!");
													printf("\n\n\t\t\tPress <ENTER> to try again!!");
													getch();
													system("cls");
													flag = 1;
												}
										    }while(flag<2);
											
										}
										do
										{
											system("color 31"); //background and foreground color
											printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
											choice = _getch();  //restrict user to enter one character only
											fflush(stdin);
											if(choice == 'a')
											{
												flag = 2;
												system("cls"); //clear screen
											}
											else if(choice == 'b')
											flag = 7;
											else 
											{
												system("cls");  //clear screen
												printf("\n\t\t\t\tYou have entered an invalid letter!");
												printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
												flag = 1;
											}
										}while(flag < 2);
										z4=1;
										break;

										/*View Users' Cars setting*/
									case'e':
									case'E':
										system("color 35");
										if((z1==1) && (z2==1) && (z3==1) && (z4==1))
										{
											for(row=1;row<userNumber+1;row++)
											{
												printf("\n\n\n\t\t");
												printf("\n\t\t\t\t\tUser %d:         Car Name: %s",row,userCarName[row]);
												printf("\n\t\t\t\t\t             Acceleration: %d m/s/s",userAcceleration[row]);
												printf("\n\t\t\t\t\t         Initial Velocity: %d m/s Final velocity: %d m/s",userInitialVelocity[row],userFinalVelocity[row]);
											}
											do
											{
												system("color 35");
												printf("\n\n\n\t\t\t\tPress 'a' to go back to setting menu and press 'b' to exit the game.");
												choice = _getch();  //restrict user to enter one character only
												fflush(stdin);
												if(choice == 'a')
												{
													flag = 2;
													system("cls"); //clear screen
												}
												else if(choice == 'b')
												flag = 7;
												else 
												{
													system("cls");  //clear screen
													printf("\n\t\t\t\tYou have entered an invalid letter!");
													printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
													flag = 1;
												}
											}while(flag < 2);
										}
										if((z1!=1) || (z2!=1) || (z3!=1) || (z4!=1))
										{
											printf("\n\n\n\t\t\t\t\tSORRY!You cannot view this page yet!");
											printf("\n\n\n\t\t\t\t\tWe have noticed you have not finish all your information!");
											printf("\n\n\n\t\t\t\t\tPress <ENTER> to return to the SETTING MENU!!");
											getch();
											system("cls");
											flag=2;
										}
										break;

										/*Return to Car Menu*/
									case'f':
									case'F':
										flag = 4;
										break;

										/*Exit the game*/
									case'g':
									case'G':
										flag = 7;
										break;

									default:
										system("color 35");
										printf("\n\n\n\t\t\t\t\tSORRY!You have entered an invalid letter!");
										printf("\n\n\n\t\t\t\t\tPress <ENTER> to return to the SETTING MENU!!");
										getch();
										system("cls");
										flag=2;
										break;
								} //end of setting2 Menu
							}while(flag < 4); //if flag<4,restart do-while, others go next
							break; 
						
						/*Start Competing*/ 
						case'd':
						case'D':		
						//Animation	
							system("color 0D"); 
							if((z1==1) && (z2==1) && (z3==1) && (z4==1))	
							{																	  						                  
								printf("\n\t\t\t\t\t 333333333333333  "); 
								printf("\n\t\t\t\t\t3:::::::::::::::33 "); 
								printf("\n\t\t\t\t\t3::::::33333::::::3");
								printf("\n\t\t\t\t\t3333333     3:::::3");
								printf("\n\t\t\t\t\t            3:::::3");
								printf("\n\t\t\t\t\t            3:::::3");
								printf("\n\t\t\t\t\t    33333333:::::3 ");
								printf("\n\t\t\t\t\t    3:::::::::::3  ");
								printf("\n\t\t\t\t\t    33333333:::::3 ");
								printf("\n\t\t\t\t\t            3:::::3");
								printf("\n\t\t\t\t\t            3:::::3");
								printf("\n\t\t\t\t\t            3:::::3");
								printf("\n\t\t\t\t\t3333333     3:::::3");
								printf("\n\t\t\t\t\t3::::::33333::::::3");
								printf("\n\t\t\t\t\t3:::::::::::::::33 ");
								printf("\n\t\t\t\t\t 333333333333333   ");
								Sleep(400);
								system("cls");
	
								printf("\n\t\t\t\t\t 222222222222222    ");  
								printf("\n\t\t\t\t\t2:::::::::::::::22  ");
								printf("\n\t\t\t\t\t2::::::222222:::::2 ");
								printf("\n\t\t\t\t\t2222222     2:::::2 ");
								printf("\n\t\t\t\t\t            2:::::2 ");
								printf("\n\t\t\t\t\t            2:::::2 ");
								printf("\n\t\t\t\t\t         2222::::2  ");
								printf("\n\t\t\t\t\t    22222::::::22   ");
								printf("\n\t\t\t\t\t  22::::::::222     ");
								printf("\n\t\t\t\t\t 2:::::22222        ");
								printf("\n\t\t\t\t\t2:::::2             ");
								printf("\n\t\t\t\t\t2:::::2             ");
								printf("\n\t\t\t\t\t2:::::2       222222");
								printf("\n\t\t\t\t\t2::::::2222222:::::2");
								printf("\n\t\t\t\t\t2::::::::::::::::::2");
								printf("\n\t\t\t\t\t22222222222222222222");
								Sleep(400);
								system("cls");
								
								printf("\n\t\t\t\t\t  1111111   ");  
								printf("\n\t\t\t\t\t 1::::::1   ");
								printf("\n\t\t\t\t\t1:::::::1   ");
								printf("\n\t\t\t\t\t111:::::1   ");
								printf("\n\t\t\t\t\t   1::::1   ");
								printf("\n\t\t\t\t\t   1::::1   ");
								printf("\n\t\t\t\t\t   1::::1   ");
								printf("\n\t\t\t\t\t   1::::l   ");
								printf("\n\t\t\t\t\t   1::::l   ");
								printf("\n\t\t\t\t\t   1::::l   ");
								printf("\n\t\t\t\t\t   1::::l   ");
								printf("\n\t\t\t\t\t   1::::l   ");
								printf("\n\t\t\t\t\t111::::::111");
								printf("\n\t\t\t\t\t1::::::::::1");
								printf("\n\t\t\t\t\t1::::::::::1");
								printf("\n\t\t\t\t\t111111111111");
								Sleep(400);
								system("cls");
								
	
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t                    ");
								printf("\n\t   _/|______||__     ");
								printf("\n\t  / ,-. -|-  ,-.`-.  ");
								printf("\n\t  `( o )----( o )-'  ");
								printf("\n\t    `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour	
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t_                     ");
								printf("\n\t_-  _/|______||__     ");
								printf("\n\t_  / ,-. -|-  ,-.`-.  ");
								printf("\n\t_- `( o )----( o )-'  ");
								printf("\n\t     `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t___                     ");
								printf("\n\t_-_-  _/|______||__     ");
								printf("\n\t-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t_-_- `( o )----( o )-'  ");
								printf("\n\t       `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t  ___                      ");
								printf("\n\t  _-_-   _/|______||__     ");
								printf("\n\t-_-__   / ,-. -|-  ,-.`-.  ");
								printf("\n\t  _-_-  `( o )----( o )-'  ");
								printf("\n\t          `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t	___                     ");
								printf("\n\t    _-_-  _/|______||__     ");
								printf("\n\t _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t    _-_- `( o )----( o )-'  ");
								printf("\n\t           `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	  ___                     ");
								printf("\n\t      _-_-  _/|______||__     ");
								printf("\n\t   _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t      _-_- `( o )----( o )-'  ");
								printf("\n\t             `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t  	    ___                     ");
								printf("\n\t        _-_-  _/|______||__     ");
								printf("\n\t     _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t        _-_- `( o )----( o )-'  ");
								printf("\n\t               `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	      ___                     ");
								printf("\n\t          _-_-  _/|______||__     ");
								printf("\n\t       _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t          _-_- `( o )----( o )-'  ");
								printf("\n\t                 `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t  	        ___                     ");
								printf("\n\t            _-_-  _/|______||__     ");
								printf("\n\t         _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t            _-_- `( o )----( o )-'  ");
								printf("\n\t                   `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t             ___                     ");
								printf("\n\t             _-_-  _/|______||__     ");
								printf("\n\t          _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t             _-_- `( o )----( o )-'  ");
								printf("\n\t                    `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	            ___                     ");
								printf("\n\t                _-_-  _/|______||__     ");
								printf("\n\t             _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                _-_- `( o )----( o )-'  ");
								printf("\n\t                       `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	              ___                     ");
								printf("\n\t                  _-_-  _/|______||__     ");
								printf("\n\t              _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                  _-_- `( o )----( o )-'  ");
								printf("\n\t                         `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                ___                     ");
								printf("\n\t                    _-_-  _/|______||__     ");
								printf("\n\t                 _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                    _-_- `( o )----( o )-'  ");
								printf("\n\t                           `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t==================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                 ___                     ");
								printf("\n\t                     _-_-  _/|______||__     ");
								printf("\n\t                  _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                     _-_- `( o )----( o )-'  ");
								printf("\n\t                            `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                    ___                     ");
								printf("\n\t                        _-_-  _/|______||__     ");
								printf("\n\t                     _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                        _-_- `( o )----( o )-'  ");
								printf("\n\t                               `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                       ___                     ");
								printf("\n\t                           _-_-  _/|______||__     ");
								printf("\n\t                        _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                           _-_- `( o )----( o )-'  ");
								printf("\n\t                                  `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                          ___                     ");
								printf("\n\t                              _-_-  _/|______||__     ");
								printf("\n\t                           _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                              _-_- `( o )----( o )-'  ");
								printf("\n\t                                     `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                             ___                     ");
								printf("\n\t                                 _-_-  _/|______||__     ");
								printf("\n\t                              _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                 _-_- `( o )----( o )-'  ");
								printf("\n\t                                        `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                ___                     ");
								printf("\n\t                                    _-_-  _/|______||__     ");
								printf("\n\t                                 _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                    _-_- `( o )----( o )-'  ");
								printf("\n\t                                           `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                   ___                     ");
								printf("\n\t                                       _-_-  _/|______||__     ");
								printf("\n\t                                    _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                       _-_- `( o )----( o )-'  ");
								printf("\n\t                                              `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                       ___                     ");
								printf("\n\t                                           _-_-  _/|______||__     ");
								printf("\n\t                                        _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                           _-_- `( o )----( o )-'  ");
								printf("\n\t                                                  `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t  	                                           ___                     ");
								printf("\n\t                                               _-_-  _/|______||__     ");
								printf("\n\t                                            _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                               _-_- `( o )----( o )-'  ");
								printf("\n\t                                                      `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                               ___                     ");
								printf("\n\t                                                   _-_-  _/|______||__     ");
								printf("\n\t                                                _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                   _-_- `( o )----( o )-'  ");
								printf("\n\t                                                          `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                    ___                     ");
								printf("\n\t                                                        _-_-  _/|______||__     ");
								printf("\n\t                                                     _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                        _-_- `( o )----( o )-'  ");
								printf("\n\t                                                               `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                         ___                     ");
								printf("\n\t                                                             _-_-  _/|______||__     ");
								printf("\n\t                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                             _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                    `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\tt   	                                                              ___                     ");
								printf("\n\tt                                                                  _-_-  _/|______||__     ");
								printf("\n\tt                                                               _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\tt                                                                  _-_- `( o )----( o )-'  ");
								printf("\n\tt                                                                         `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\tt===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                                   ___                     ");
								printf("\n\t                                                                       _-_-  _/|______||__     ");
								printf("\n\t                                                                   _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                                       _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                              `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                                         ___                   ");
								printf("\n\t                                                                             _-_-  _/|______||__     ");
								printf("\n\t                                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                                             _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                                    `-'      `-'      ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                                               ___                   ");
								printf("\n\t                                                                                   _-_-  _/|______||__     ");
								printf("\n\t                                                                                _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                                                   _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                                          `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                                                     ___                   ");
								printf("\n\t                                                                                         _-_-  _/|______||__     ");
								printf("\n\t                                                                                      _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                                                         _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                                                `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
								
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                                                           ___                   ");
								printf("\n\t                                                                                               _-_-  _/|______||__     ");
								printf("\n\t                                                                                            _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                                                               _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                                                      `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                                                                ___                   ");
								printf("\n\t                                                                                                    _-_-  _/|______||__     ");
								printf("\n\t                                                                                                 _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                                                                    _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                                                           `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                                                                     ___                   ");
								printf("\n\t                                                                                                         _-_-  _/|______||__     ");
								printf("\n\t                                                                                                      _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                                                                         _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                                                                `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								system("cls");
							
								printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
								printf("\n\t   	                                                                                                         ___                   ");
								printf("\n\t                                                                                                             _-_-  _/|______||__     ");
								printf("\n\t                                                                                                          _-_-__  / ,-. -|-  ,-.`-.  ");
								printf("\n\t                                                                                                             _-_- `( o )----( o )-'  ");
								printf("\n\t                                                                                                                    `-'      `-'     ");
								SetConsoleTextAttribute ( h1, FOREGROUND_GREEN| FOREGROUND_INTENSITY); //foreground colour
								printf("\n\t===================================================================================================================================");
								SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_INTENSITY); //foreground colour
								Sleep(50);
								
								printf("\n\n\t\t\t\t\t\t\tWinner has been decided!!!");
								printf("\n\n\t\t\t\t\t\t\tPress <ENTER> to return to CAR MENU and see the results!!");
								getch(); //hold screen
								do
								{
									printf("\n\n\n\t\t\t\tPress 'a' to go back to CAR MENU and press 'b' to exit the game.");
									choice = _getch();  //restrict user to enter one character only
									fflush(stdin);
									if(choice == 'a')
									{
										flag = 2;
										system("cls"); //clear screen
									}
									else if(choice == 'b')
									flag = 7;
									else 
									{
										system("cls");  //clear screen
										printf("\n\t\t\t\tYou have entered an invalid letter!");
										printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
										flag = 1;
									}
								}while(flag < 2);
								k=1;
							}
							else
							{							
								printf("\n\n\n\t\t\t\t\tSORRY!You cannot view this page yet!");
								printf("\n\n\n\t\t\t\t\tWe have noticed you have not finished all your information yet!");
								printf("\n\n\n\t\t\t\t\tPress <ENTER> to return the CAR MENU!!");
								getch();
								system("cls");
								flag=2;
							}
							break;

							/*view Results*/
						case'e':
						case'E':
							system("color 0F");							
							if(k==1)
							{																	
								for(row=1;row<userNumber+1;row++)
								{
									userTime1[row] = (userFinalVelocity[row]-userInitialVelocity[row])/userAcceleration[row];
									userDistance1[row] = ((userFinalVelocity[row]*userFinalVelocity[row])-(userInitialVelocity[row]*userInitialVelocity[row]))/2/userAcceleration[row];
									if(userTime1[row]>userTime)
									{
										userRealFinalVelocity[row] = userTime*userAcceleration[row]+userInitialVelocity[row];
										userTotalDistance[row] = ((userRealFinalVelocity[row]*userRealFinalVelocity[row])-(userInitialVelocity[row]*userInitialVelocity[row]))/2/userAcceleration[row];								
									}
									else
									{
										userDistance2[row] = (userTime-userTime1[row])*userFinalVelocity[row];
										userTotalDistance[row] = userDistance1[row]+userDistance2[row];
									}									
								}
								winner=userTotalDistance[1];
											
								for(row=2;row<userNumber+1;row++)
								{
									if(winner<userTotalDistance[row])
									winner=userTotalDistance[row];																								
								}
	
								for(row=1;row<userNumber+1;row++)
								{			
									printf("\n\n\t\t\t\tName    Distance(m)");		
									printf("\n\n\t\t\t\t %s         %d",userCarName[row],userTotalDistance[row]);	
									if(userTotalDistance[row] == winner)
									{
										SetConsoleTextAttribute ( h1, FOREGROUND_RED | FOREGROUND_INTENSITY); //foreground colour								
										printf("   WINNER!!!");	
										SetConsoleTextAttribute ( h1, FOREGROUND_RED |FOREGROUND_BLUE | FOREGROUND_GREEN|FOREGROUND_INTENSITY); //foreground colour
									}
								}

								do
								{
									printf("\n\n\n\t\t\t\tPress 'a' to go back to CAR MENU and press 'b' to exit the game.");
									choice = _getch();  //restrict user to enter one character only
									fflush(stdin);
									if(choice == 'a')
									{
										flag = 2;
										system("cls"); //clear screen
									}
									else if(choice == 'b')
									flag = 7;
									else 
									{
										system("cls");  //clear screen
										printf("\n\t\t\t\tYou have entered an invalid letter!");
										printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
										flag = 1;
									}
								}while(flag < 2);
							}
							else
							{
								printf("\n\n\n\t\t\t\t\tSORRY!You cannot view this page yet!");
								printf("\n\n\n\t\t\t\t\tWe have noticed you have not start competing!");
								printf("\n\n\n\t\t\t\t\tPress <ENTER> to return the CAR MENU!!");
								getch();
								system("cls");
								flag=2;
							}
							break;

							/*Reset Number of users*/
						case'f':
						case'F':
							flag = 5;
							break;

							/*Return to Main Menu*/
						case'g':
						case'G':
							flag = 6;
							break;

							/*Exit the game*/
						case'h':
						case'H':
							flag = 7;
							break;

						default:
							printf("\n\n\n\t\t\t\t\tSORRY!You have entered an invalid letter!");
							printf("\n\n\n\t\t\t\t\tPress <ENTER> to go back to CAR MENU!");
							getch();
							system("cls");
							flag=2;
							break;
					} //end of car2 menu
				}while(flag<5); //if flag<5,restart do-while, others go next
			}while(flag<6); //if flag<6,restart do-while, others go next
			break;

			/*How to play*/
		case'c':
		case'C':
			printf("\n\n\n\n\n");
			printf("\n\t\t\t\t __   __  _______  _     _    _______  _______    _______  ___      _______  __   __ ");  
			printf("\n\t\t\t\t|  | |  ||       || | _ | |  |       ||       |  |       ||   |    |   _   ||  | |  |");
			printf("\n\t\t\t\t|  |_|  ||   _   || || || |  |_     _||   _   |  |    _  ||   |    |  |_|  ||  |_|  |");
			printf("\n\t\t\t\t|       ||  | |  ||       |    |   |  |  | |  |  |   |_| ||   |    |       ||       |");
			printf("\n\t\t\t\t|       ||  |_|  ||       |    |   |  |  |_|  |  |    ___||   |___ |       ||_     _|");
			printf("\n\t\t\t\t|   _   ||       ||   _   |    |   |  |       |  |   |    |       ||   _   |  |   |  ");
			printf("\n\t\t\t\t|__| |__||_______||__| |__|    |___|  |_______|  |___|    |_______||__| |__|  |___|  ");
			printf("\n\n\n");
			printf("\n\n\t\t\t\t1.Singer Player(user vs computer):");
			printf("\n\n\t\t\t\tThe Car Race is set in 2km. Competitors should try to use the least time to run the distance before gas is run out.");
			printf("\n\n\t\t\t\tThree cars with the same characteristics would be provided for both user and computer.");
			printf("\n\n\t\t\t\tUser will determine three cars' initial and final velocity and acceleration based on the cars' characteristics provided.");
			printf("\n\n\t\t\t\tUser will comepte with computer for three times and the one wins the most is the winner.");
			printf("\n\n\t\t\t\tNotice that all three cars can be used more than once during the competition.");
			printf("\n\n\t\t\t\tThe ranking of three cars' characteristics is Car-1 < Car-2 < Car-3");
			printf("\n\n");
			printf("\n\n\t\t\t\t2.Multi Player(users vs users)");
			printf("\n\n\t\t\t\tThe Car Race is set in time limit. Users can determine how long the Car Race should be.");
			printf("\n\n\t\t\t\tAll Competitors should try to run as far as possible before time is run out.");
			printf("\n\n\t\t\t\tUsers can determine their cars' name, initial and final velocity and acceleration.");
			printf("\n\n\t\t\t\tUsers can win the game by technically manipulating their cars' velocity and acceleration.");
			printf("\n\n\t\t\t\tNotice there is no limited velocity and acceleration for the cars.");
			do
			{
				printf("\n\n\n\t\t\t\tPress 'a' to go back to MAIN MENU and press 'b' to exit the game.");
				choice = _getch();  //restrict user to enter one character only
				fflush(stdin);
				if(choice == 'a')
				{
					flag = 2;
					system("cls"); //clear screen
				}
				else if(choice == 'b')
				flag = 7;
				else 
				{
					system("cls");  //clear screen
					printf("\n\t\t\t\tYou have entered an invalid letter!");
					printf("\n\t\t\t\tPlease try again and enter letter 'a' or 'b'!");
					flag = 1;
				}
			}while(flag < 2);
			break;

			/*Exit the game*/
		case'd':
		case'D':
			flag = 7;
			break;
			
		default:
			printf("\n\n\n\t\t\t\t\tSORRY!You have entered an invalid letter!");
			printf("\n\n\n\t\t\t\t\tPress <ENTER> to go back to MAIN MENU!");
			getch();
			system("cls");
			flag=2;
			break;
		} //end of main menu
	}while(flag<7); //if flag<7,restart do-while, others exit
	system("cls");
	printf("\n\n\n\t\t\t\tPress <ENTER> to exit!");
	getch();
	return 0;
}//end main



	

	
