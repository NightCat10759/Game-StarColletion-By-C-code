/* 		這是一個收集星星的遊戲，由鍵盤輸入來操作。												*/
/* 		地圖上會隨機生成星星和 1 ， 走過的地方就會從 0 變成 1	   								*/
/*		勝利條件 : 收集到全部星星就獲勝															*/
/*		失敗條件 : 踩到 1 也就是已經踩到的地方就會 Gameover	,或者超過限制的步數也判輸。			*/
/*		This is a Collect game,using keyboard to controll  	.									*/
/*		The Star * and '1' will be randomly spawned on the map.									*/
/*		How to win	:	collect all the star *.													*/
/*		How to lose	:	when you stand on '1' you lose	and you can't over the limit steps.		*/

#include <stdio.h>
#include <stdlib.h>	/* 亂數相關函數 */
#include <time.h>	/* 時間相關函數 */

#define SpaceHeight 3 //Array Border
#define	SpaceWidth 3 //Array Border
#define BorderOne SpaceHeight-1 // walk height limit
#define BorderSEC SpaceWidth-1  // walk width limit
#define BorderZero 0 // the most left or top place
char Space[ SpaceHeight ][ SpaceWidth ];	// MAP
int PlayerPositionOne = 0 ; // Player Y position
int PlayerPositionTwo = 0 ; // Player X position
int score = 0 ; // Game score == '*'
int TotalStep = 0 ; 
int WinScore = 0 ; // how much score can you win
const int StarAmount = 4 ;
const int TrapAmount = 4 ;
const int LimitStep = 20 ;	
const int OneStep = 1 ; // how long do player moving
const char AlreadyStand = '1'; 

void Help(){
			printf("\n");
	printf("    	這是一個收集星星的遊戲，由鍵盤輸入來操作。\n");
	printf("	地圖上會隨機生成星星和 '1' ， 走過的地方就會從 '0' 變成 '1'\n");
	printf("	勝利條件 : 收集到全部星星就獲勝	\n");
	printf("	失敗條件 : 踩到 '1'也就是已經踩到的地方就會 GAMEOVER,	\n");
	printf("	或者超過限制的步數也判輸。\n");
	printf("	This is a Collection game, using keyboard to controll  movement.	\n");
	printf("	The Star * and '1' will be randomly spawned on the map,	\n");
	printf("	And when you walk through the '0' it will turn into '1'.	\n");
	printf("	How to WIN	:	Collected all the star * YOU WIN	\n");
	printf("	How to LOSE	:	When you stand on '1' YOU LOSE, \n");
	printf("	and you can't over the LIMIT STEPS.\n\n");
		printf("\n");
}
/*		Judge that whether player standding on '1'  and get star * 			*/
bool judge(int One,int Two){
	
	if( Space [ One ][ Two ] == AlreadyStand){
		printf("GameOver You Stand on '1' !!!!!\n");
		return false;
	}else{
		TotalStep++;
			if( Space [ One ][ Two ] == '*'){
				score++;
			}
		return true;
	}
}
/*		Judge that whether player standding on '1' and get star * 			*/

/*			win or not 			*/ 
bool WIN(int score){
	if( score == WinScore ){
			printf("YOU WIN!!!\n");
			return false;
	}else if( TotalStep == LimitStep)
	{
		printf("GameOver Because your step is over the limit step.\n");
		return false;
	}else{
		return true;
	}
} 
/*			win or not			 */ 

/*		main program	*/
int main(){
	while(true){	
	
	bool exit=true;
	/*	設定亂數種子	*/ 
	srand(time(NULL));
	/*	設定亂數種子	*/ 
	
	/*			Reset the setting				*/
	WinScore	= 0;
	score		= 0;
	TotalStep	= 0;
	PlayerPositionOne	= 0; 
 	PlayerPositionTwo	= 0; 
	/*			Reset the setting				*/
		
	/*	create SPACE	*/
	for(int i=0 ; i < SpaceHeight ; i++){
		for(int j=0 ; j < SpaceWidth ; j++){
			Space [i][j] = '0';
		}
	}
	/*	create SPACE	*/
	
	
	
	/*	create trap	== 1 */
	for(int i=0 ; i < TrapAmount ; i++){
		int TRAP1 = rand() % BorderOne;
		int TRAP2 = rand() % BorderSEC;
		Space[TRAP1][TRAP2] = AlreadyStand;
	}

	/*	create trap	== 1 */ 
	
	/*	create STARS == SCORE	*/
	for(int i=0 ; i < StarAmount ; i++){
		int STAR1 = rand() % BorderOne;
		int STAR2 = rand() % BorderSEC;
		Space[STAR1][STAR2] ='*';
	}
	/*	create STARS == SCORE	*/
	
		
	/*			create PLAYER 	on left corner	*/
	Space [PlayerPositionOne] [PlayerPositionTwo] = AlreadyStand;
	/*			create PLAYER 	on left corner	*/
	
	/*			計算勝利分數		*/
	for(int i=0 ; i < SpaceHeight ; i++){
		for(int j=0 ; j < SpaceWidth ; j++){
			if( Space[i][j] == '*')
				{
					WinScore++;
				}
		}
	}
	/*			計算勝利分數		*/
	
	/*			遊戲介紹			*/
	Help();
	char JoinTheGame;
	printf("	Do you want to START the game ?(Any)or(N,n)____\b\b");
	scanf(" %c", &JoinTheGame);
	printf( "\n\n\n" );
		if(JoinTheGame=='N'||JoinTheGame=='n'){
			printf(" Thanks for playing");
			break ;
		}
	/*			遊戲介紹			*/
	
	/*				Main game					*/
	while( exit ){
		char Control;
		/*		print the MAP		*/
		for(int i=BorderZero ; i < SpaceHeight ; i++){
		printf( "				" );
			for(int j=BorderZero ; j < SpaceWidth ; j++){
				printf(" %c",Space[i][j]);
			}
		printf( "\n" );
		}
		/*		print the MAP		*/
		
		/*		Print about Score	*/
		printf("\n\n WinScore need %d\n", WinScore);
		printf(" Your score = %d\n\n", score);
		printf(" LimiSteps  is %d\n\n", LimitStep);
		printf(" Your steps is %d\n\n", TotalStep);
		/*		Print about Score	*/
		
		//		Win		//
		if( !WIN(score) ){
			break ;
		}else if( TotalStep == LimitStep ){
			printf("GameOver Because you use up the step.\n");
			break ;
		}
		//		Win		//

		/*		print about interface		*/
		printf(" L = Go Left\n");
		printf(" R = Go Right\n");
		printf(" U = Go Up\n");
		printf(" D = Go Down\n");
		printf(" Q = Go Quit\n");
		printf(" H = HELP\n");
		printf("\n");
		printf(" Input your move ____\b\b");
		scanf(" %c", &Control);
		/*		print about interface		*/
		
		/*		*******	CONTROL	*******			*/
		switch(Control){
			int NextStep;
			case 'W':
				score = WinScore;
				exit  = WIN(score);
				break ;
			case 'H':
				Help();
				break ;
			case 'L':
				//left
				NextStep = PlayerPositionTwo - OneStep;
				if( NextStep >= BorderZero ){
					exit = judge(PlayerPositionOne,NextStep);
					Space [ PlayerPositionOne ][ NextStep ] = AlreadyStand;
					PlayerPositionTwo = NextStep;
				}else{
					exit = judge(PlayerPositionOne,BorderSEC);
					Space [ PlayerPositionOne ][ BorderSEC ] = AlreadyStand;
					PlayerPositionTwo = BorderSEC;
				}
				break ;
			case 'R':
				//right
				NextStep = PlayerPositionTwo + OneStep;
				if( NextStep < SpaceWidth ){
					exit = judge(PlayerPositionOne,NextStep);
					Space [ PlayerPositionOne ][ NextStep ] = AlreadyStand;
					PlayerPositionTwo=NextStep;
				}else{
					exit = judge(PlayerPositionOne,BorderZero);
					Space [ PlayerPositionOne ][ BorderZero ] = AlreadyStand;
					PlayerPositionTwo = BorderZero;
				}
				break ;
			case 'U':
				//up
				NextStep = PlayerPositionOne - OneStep;
				if( NextStep >= BorderZero ){
					exit = judge(NextStep,PlayerPositionTwo);
					Space [ NextStep ][ PlayerPositionTwo ] = AlreadyStand;
					PlayerPositionOne = NextStep;
				}else{
					exit = judge(BorderOne,PlayerPositionTwo);
					Space [ BorderOne ][ PlayerPositionTwo ] = AlreadyStand;
					PlayerPositionOne = BorderOne;
				}
				break ;
			case 'D':	
				//down
				NextStep = PlayerPositionOne + OneStep;
				if( NextStep < SpaceHeight ){
					exit=judge(NextStep,PlayerPositionTwo);
					Space [ NextStep ][ PlayerPositionTwo ] = AlreadyStand;
					PlayerPositionOne = NextStep;
				}else{
					exit=judge(BorderZero,PlayerPositionTwo);
					Space [ BorderZero ][ PlayerPositionTwo ] = AlreadyStand;
					PlayerPositionOne = BorderZero;
				}
				break ;
			case 'Q':
				char quit;
				printf( "Do you want to QUIT	??(y)" );
				scanf(" %c", &quit);
				if(quit=='y'){
					exit=false;
				}
				break ;
			default :
				printf( "It's not working" );
				break ;
		}
	/*			*******	CONTROL	*******			*/
			printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" );
	} 
	/*					Main game						*/
	/*			Quit the game		*/
	char QuitOutside;
	printf("Do you want to continue?(Any)or(N,n)");
	scanf(" %c", &QuitOutside);
		if(QuitOutside=='N'||QuitOutside=='n'){
			printf("Thanks for playing");
			break ;
		}
	/*			Quit the game		*/
	}
	return 0;
}
