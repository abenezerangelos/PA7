#include "Header.h"
//1. Please finish the showdown functionality by sending the two pointers of the player hands--alloted time: 30 minutes/one cycle
//   -- create a point system to see who wins i.e., every type will have a point based on the the order 
//			- if both have the same point then possibly make a showdown happen that is shuffle then deal by letting the players now and so you wouldn't tell them who won but instead suggest for them to play again
// 
// 
//2. Please finish the random generator of the dealer hand drawing mechanism--alloted time: 45 minutes/one and a half cycle
/*
Author:Ebenezer Abate
Course: CPT_S Lab secion 07
TA: Selina N.
Date: 04/12/23

Description:
This is the main.c file which consists of all the I/0 function calls i.e., printf() and scanf() we will also have all the function calls
for the function declarations in battleship.c.*/
int main(void)
{	
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };
	//initialize card struct for each array and pass pointer into our deal function
	
	
	int continue_playing = 2;
	/* initalize deck array */

	int deck[4][13] = { 0 };
	int rounds = 0;
	int collected = 0;
	srand((unsigned)time(NULL)); /* seed random-number generator */
	do {
		display_menu();
		scanf("%d", &continue_playing);
		system("clear||cls");
		if (continue_playing == 1) {
			print_rule();
		}
	} while (continue_playing == 1);
	
	while (continue_playing == 2) {
		//initialization, very important
		Hand card_hands_player1;
		card_hands_player1.identifier = 0;
		card_hands_player1.pair = -1;
		card_hands_player1.two_pair = -1;
		card_hands_player1.three_kinds = -1;
		card_hands_player1.four_kinds = -1;
		card_hands_player1.straight = -1;
		card_hands_player1.flush = -1;
		card_hands_player1.full_house = -1;
		Card draw_card;
		Hand card_hands_dealer;
		card_hands_dealer.identifier = 1;
		card_hands_dealer.pair = -1;
		card_hands_dealer.two_pair = -1;
		card_hands_dealer.three_kinds = -1;
		card_hands_dealer.four_kinds = -1;
		card_hands_dealer.straight = -1;
		card_hands_dealer.flush = -1;
		card_hands_dealer.full_house = -1;


		printf("Player's cards: \n");
		shuffle(deck);
		//deal to user player
		deal(deck, face, suit, &card_hands_player1);
		printf("\nDealer's cards:\n");
		//1.deal to the dealer/computer--missing
		//2.let player draw

		/*deal(deck, face, suit, &card_hands_dealer);*/
		shuffle(deck);

		deal(deck, face, suit, &card_hands_dealer);

		
		
		printf("\nWould you like to draw cards. Please enter 'y' or 'n'.\n");
	

		char yes_or_no[MAX];

		char number_of_redraw[MAX];
		if (!collected)collected=getchar();
		fgets(yes_or_no, MAX, stdin);
		

		/*for (int i = 0; i < (int)strlen(yes_or_no); i++)printf("\nStrings:-%c-\n", yes_or_no[i]);*/
		
		while (yes_or_no[0] != 'y' && yes_or_no[0] != 'n') {
			printf("Please enter something that is correct the given input was not correct!");
			fgets(yes_or_no, MAX, stdin);
		}

		if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y') {
			printf("How many cards would you like to draw? Enter a number from 1 to 3?\n");

			fgets(number_of_redraw, MAX, stdin);
			int draw_number = number_of_redraw[0] - '0';
			/*printf("What is going on:-%s- and a character: -%c-", number_of_redraw, number_of_redraw[0]);*/
			while (draw_number< 1 || draw_number>3) {
				printf("Please only enter values from 1 to 3 including 1 and 3! Try again\n");
				fgets(number_of_redraw, MAX, stdin);
				draw_number = number_of_redraw[0] - '0';
			}

			printf("Which cards do you want to replace? Please enter the index? from 1 to 5 including 1 and 5: and enter by separating using space\n");
			char user_input[9] = { '0' };
			
			fgets(user_input, 9, stdin);
			/*system("clear||cls");*/
			//debugging

			for (int j = 0; j < ( draw_number* 2) - 1; j += 2) {
				/*printf("value: %d, truth value: %d", user_input[j], user_input <= 0);*/
				int temp_int = user_input[j] - '0';
				while ((!(isdigit(user_input[j]))) ||(temp_int<=0)|| (((user_input[j + 1] != ' ') && (user_input[j + 1] != '\n')))) {
					/*printf("DEBUG: -%c-", user_input[j + 1]);*/
					printf("The input you have entered is not in a correct format please reenter using a proper format!");
					fgets(user_input, 9, stdin);
					temp_int = user_input[j] - '0';


				}

			}
			for (int i = 0; i < (draw_number * 2) - 1; i++) {

				if ((i % 2) == 0) {
					int temp = user_input[i] - '0';
					int entry = temp - 1;
					draw(deck, face, suit, &draw_card);
					card_hands_player1.cards[entry - 1] = draw_card;
				}
			}



		}
		//print all the updated values of the card struct using a loop
		
		
		int player1_score;
		int dealer_score;
		int showdown=0;
		player1_score =play(&card_hands_player1);
		dealer_score = play(&card_hands_dealer);

		if (player1_score > dealer_score)printf("\nPLAYER1 HAS WON THIS ROUND. CONGRATULATIONS\n");
		else if (player1_score < dealer_score)printf("\nTHE DEALER HAS WON THIS ROUND. GOOD JOB, COMPUTER\n");
		else {
			printf("\nTIME FOR A SHOWDOWN! SINCE NO ONE HAS WON.\n");
			showdown = 1;
			
		}

		
		
		printf("\nPlayer1\n");
		for (int i = 0; i < 5; i++) {
			printf("%5s of %-8s%c", face[card_hands_player1.cards[i].face_index], suit[card_hands_player1.cards[i].suit_index], i % 2 == 0 ? '\n' : '\t');
		}
		printf("\n");
		printf("\nPlayer2\n");
		for (int i = 0; i < 5; i++) {
			printf("%5s of %-8s%c", face[card_hands_dealer.cards[i].face_index], suit[card_hands_dealer.cards[i].suit_index], i % 2 == 0 ? '\n' : '\t');
		}

		if (!showdown) {
			char temporary[MAX];
			display_continue();
			fgets(temporary, MAX, stdin);
			while (!isdigit(temporary[0])||!(temporary[0]-'0'>0 && temporary[0]-'0'<3)) {
				printf("Please enter something proper");
				fgets(temporary, MAX, stdin);
			}
			continue_playing = temporary[0] - '0';

			
			
		}
		if (showdown) {
			system("pause");
		}
		system("clear||cls");
		rounds++;
		
	}

		return 0;
}


