#include "Header.h"
//1. Please finish the showdown functionality by sending the two pointers of the player hands--alloted time: 30 minutes/one cycle
//   -- create a point system to see who wins i.e., every type will have a point based on the the order 
//			- if both have the same point then possibly make a showdown happen that is shuffle then deal by letting the players now and so you wouldn't tell them who won but instead suggest for them to play again
//2. Please finish the random generator of the dealer hand drawing mechanism--alloted time: 45 minutes/one and a half cycle
int main(void)
{	
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };
	//initialize card struct for each array and pass pointer into our deal function
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
	
	int continue_playing = 2;
	/* initalize deck array */

	int deck[4][13] = { 0 };

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
		int number_of_redraw = 0;
		getchar();

		fgets(yes_or_no, MAX, stdin);

		if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y') {
			printf("How many cards would you like to draw? Enter a number from 1 to 3?\n");

			scanf("%d", &number_of_redraw);
			while (number_of_redraw < 1 || number_of_redraw>3) {
				printf("Please only enter values from 1 to 3 including 1 and 3! Try again\n");
				scanf("%d", &number_of_redraw);
			}

			printf("Which cards do you want to replace? Please enter the index? from 1 to 5 including 1 and 5: and enter by separating using space\n");
			char user_input[9] = { '0' };
			getchar();
			fgets(user_input, MAX, stdin);
			system("clear||cls");
			//debugging

			for (int j = 0; j < (number_of_redraw * 2) - 1; j += 2) {

				while (!(isdigit(user_input[j])) || (strlen(user_input) > 2 && !((user_input[j + 1] == ' ') || (user_input[j + 1] == '\n')))) {
					printf("The input you have entered is not in a correct format please reenter using a proper format!");
					fgets(user_input, MAX, stdin);


				}

			}
			for (int i = 0; i < (number_of_redraw * 2) - 1; i++) {

				if ((i % 2) == 0) {
					int entry = user_input[i] - '0';
					draw(deck, face, suit, &draw_card);
					card_hands_player1.cards[entry - 1] = draw_card;
				}
			}



		}
		//print all the updated values of the card struct using a loop
		for (int i = 0; i < 5; i++) {
			printf("\nCards:%s of %s, \n", face[card_hands_player1.cards[i].face_index], suit[card_hands_player1.cards[i].suit_index]);
		}
		
		int player1_score;
		int dealer_score;
		player1_score =play(&card_hands_player1);
		dealer_score = play(&card_hands_dealer);

		if (player1_score > dealer_score)printf("Player1 has won this round. Congratulations\n");
		if (player1_score < dealer_score)printf("The Dealer has won this round. Good job, computer\n");
		else printf("Time for a showdown! Since neither has won.\n");

		
		
		printf("Player1\n");
		for (int i = 0; i < 5; i++) {
			printf("%5s of %-8s%c", face[card_hands_player1.cards[i].face_index], suit[card_hands_player1.cards[i].suit_index], i % 2 == 0 ? '\n' : '\t');
		}
		printf("\n");
		printf("Player2\n");
		for (int i = 0; i < 5; i++) {
			printf("%5s of %-8s%c", face[card_hands_dealer.cards[i].face_index], suit[card_hands_dealer.cards[i].suit_index], i % 2 == 0 ? '\n' : '\t');
		}


		display_continue();
		scanf("%d", &continue_playing);
		system("clear||cls");


	}

		return 0;
}


