#include "Header.h"
/*
Author:Ebenezer Abate
Course: CPT_S Lab secion 07
TA: Selina N.
Date: 04/21/23

Description:
This is the other .c file that contains the necessary functions that will be called in the main.c function.
This file consists of all the declaration.
It also contains necessary functions to print the welcome screen as well as initializing struct values.
*/
//This ^^^^^^^^^^^ is the hardest part of the PA. 
/* shuffle cards in deck */

//Fix the problem of the existence of k and a in straight counting--alloted time: 15 min

void shuffle(int wDeck[4][13])
{	
	
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	for (row = 0; row <= 3; row++) {
		for (column = 0; column <= 12; column++)
		{
			wDeck[row][column] = 0;
		}

	}
	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}
void draw(const int wDeck[][13], const char* wFace[], const char* wSuit[],Card* draw_card) {
	int row = 0;
	int column = 0;
	int card = (rand() % 52) + 1;
	
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					draw_card->face_index = column;
					draw_card->suit_index = row;
					
				}
			}
		}
	
}
/* deal cards in deck */
//modifying it to deal only 5 cards
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[],Hand* card_hands)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	
	/* deal each of the 52 cards */
	for (card = 1; card <= 5; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{	
					card_hands->cards[card-1].face_index = column;
					card_hands->cards[card-1].suit_index = row;
					if (!card_hands->identifier)printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					else printf("%5s of %-8s%c", "-----", "-----", card % 2 == 0 ? '\n' : '\t');

				}
			}
		}
		
	}
}
//3. implement this

int ones = 0; int twos = 0; int threes = 0; int fours = 0; int fives = 0; int sixs = 0;
////Ask the player to hit any key to continue on to roll the five dice
//if (rolls != 0)printf("Hit any key to continue on to roll the five dice\n");
//else {
//	if (rounds % 2 == 0)printf("It is now Player 1's turn\n\nPlayer 1: Hit any key to continue on to roll the five dice\n");
//	else printf("It is now Player 2's turn\n\nPlayer 2: Hit any key to continue on to roll the five dice\n");
//}
//int counter = 0;
//int n;
//int reset_sum[6] = { 0 };
//int* sum[6] = { &ones, &twos, &threes, &fours, &fives, &sixs };
//
//
//for (int i = 0; i < 5; i++) {
//
//
//	if (rerolls[i] == 0) {
//
//		n = rand() % 6;
//		memory_array[i] = n;
//
//	}
//	//Roll the five dice and display the face values of each die; enumerate each
//	printf("%s", dices[memory_array[i]]);
//
//	(*sum[memory_array[i]])++;
//
//
//
//}
int sumof1s = 0, Three_of_a_kind = 0;
int sumof2s = 0, Four_of_a_kind = 0;
int sumof3s = 0, Full_house = 0;
int sumof4s = 0, Small_straight = 0;
int sumof5s = 0, Large_straight = 0;
int sumof6s = 0, Yahtzee = 0;
int chance = 0;
//initialize an array of pointer consisting of addresses of our score trackers for every possible point
int* sumof[6] = { &sumof1s,&sumof2s,&sumof3s,&sumof4s,&sumof5s,&sumof6s };
//same thing as above but including all of them
int* scorecard_iterator[13] = { &sumof1s,&sumof2s,&sumof3s,&sumof4s,&sumof5s,&sumof6s,&Three_of_a_kind ,&Four_of_a_kind,&Full_house,&Small_straight,&Large_straight,&Yahtzee,&chance };

int Fullhouse_indicator = 0;
int counter_for_threekinds_and_fourkinds = 0;
int sequence_count = 0, seeker = 0;
//control the easier operations i.e., sumofs and ofakinds, straights
//but will only be for one round

//loop to keep incrementing and manipulating our scorecard values

//for (int j = 0; j < 6; j++) {
//
//
//
//	*sumof[j] = *sum[j] * (j + 1);
//
//	chance += *sumof[j];
//
//
//	switch (*sum[j])
//	{
//	case 1:
//		//if it occurs only once in our five dices combination
//		//sequence_count only truly helps out with figuring out sequentiality in small straight and large straight
//		sequence_count++;
//
//		break;
//	case 2:
//		sequence_count++;
//		Fullhouse_indicator = 1;
//		break;
//	case 3:
//		counter_for_threekinds_and_fourkinds = 3;
//		break;
//	case 4:
//		counter_for_threekinds_and_fourkinds = 4;
//		break;
//	case 5:
//		Yahtzee = 50;
//		break;
//	}
//}
//if (counter_for_threekinds_and_fourkinds == 3) {
//	Three_of_a_kind = chance;
//}
//else if (counter_for_threekinds_and_fourkinds == 4) {
//	Four_of_a_kind = chance;
//}
//if (Three_of_a_kind > 0 && Fullhouse_indicator) Full_house = 25;
//if (sequence_count > 3) {
//	for (int i = 0; i < 6; i++) {
//		if (*sum[i] > 0) {
//			seeker++;
//		}
//		else { if (seeker < 4) seeker = 0; }
//	}
//
//	if (seeker > 3) {
//		Small_straight = 30;
//	}
//	if (seeker > 4) {
//		Large_straight = 40;
//	}
//}
void contains_pair(Hand* card_hands) {
	int i;
	int count = 0;
	for (int j = 0; j < 4; j++) {
		for (i = j + 1; i < 5; i++) {
			if ((card_hands->cards[j].face_index == card_hands->cards[i].face_index)) {

				if (!count)card_hands->pair = 1;
				else card_hands->pair = 0;
				count++;

			}
		}
	}

}
void contains_two_pairs(Hand* card_hands) {
	int i;
	int face_count = 0;
	int save_combo[5];
	int iterator;
	//initialize save combo array
	for (int i = 0; i < sizeof(save_combo) / 4; i++) {
		save_combo[i] = -1;
	}
	
	for (int j = 0; j < 4; j++) {
		for (i = j + 1; i < 5; i++) {
			/*printf("Change: %d for two pairs player%d\n", card_hands->two_pair, card_hands->identifier + 1);*/
			if ((card_hands->cards[j].face_index == card_hands->cards[i].face_index)) {
				save_combo[j] = card_hands->cards[i].face_index;
			}
		}
	}
	int size = sizeof(save_combo) / 4;
	
	for (int iter = 0; iter <size-1 ; iter++) {
		
		for (iterator = iter + 1; iterator < size; iterator++) {
			if (save_combo[iter] != -1&&save_combo[iterator]!=-1) {
				if (save_combo[iter] == save_combo[iterator])card_hands->two_pair = 0;
				else if (save_combo[iter] != save_combo[iterator])card_hands->two_pair = 1;
			}
		}
	}
	
}
void contains_three_of_a_kind(Hand* card_hands) {
	int i;
	int similarity_counter = 0;
	int first_pair = 0;
	int comparer = 0;
	int counter = 0;
	for (int j = 0; j < 4; j++) {
		for (i = j + 1; i < 5; i++) {
			if (card_hands->cards[j].face_index == card_hands->cards[i].face_index) {
				if (!similarity_counter)first_pair = card_hands->cards[j].face_index;
				else if (similarity_counter)comparer = card_hands->cards[j].face_index;
				//this line is very iffy; it is completely dependent upon the initialization of our struct, unless we initialize each of the poker hand rankings to zero we have to make the if comparison
				//to some other integer, another integer like -1 but again that is if we set it.

				//we aren't supposed to be looking for three pairs just three of the same type of cards, we are not supposed to set this to zero instead we are supposed to increase it and see if it reaches to 3 with the first pair
				if (first_pair == comparer) {
					counter++;
				}
				if (counter == 2)card_hands->three_kinds = 1;
				if (counter != 2)card_hands->three_kinds = 0;
				similarity_counter++;

			}

		}
	}

}
void contains_four_of_a_kind(Hand* card_hands) {
	int i;
	int similarity_counter = 0;
	int suit_count = 0;
	int first_pair = 0;
	int comparer = 0;
	int counter = 0;
	for (int j = 0; j < 4; j++) {
		for (i = j + 1; i < 5; i++) {
			if (card_hands->cards[j].face_index == card_hands->cards[i].face_index) {
				if (!similarity_counter)first_pair = card_hands->cards[i].face_index;
				else if (similarity_counter)comparer = card_hands->cards[i].face_index;
				//this line is very iffy; it is completely dependent upon the initialization of our struct, unless we initialize each of the poker hand rankings to zero we have to make the if comparison
				//to some other integer, another integer like -1 but again that is if we set it.
				if (first_pair == comparer) {
					counter++;
				}
				if (counter == 3)card_hands->three_kinds = 1;
				if (counter != 3)card_hands->three_kinds = 0;
				similarity_counter++;

			}
		}
	}

}
void contains_full_house(Hand* card_hands) {
	int i;
	for (int j = 0; j < 4; j++) {
		for (i = j + 1; i < 5; i++) {
			if (card_hands->three_kinds == 1 && card_hands->pair == 1) {
				card_hands->full_house = 1;

			}
		}
	}

}
void contains_flush(Hand* card_hands) {
		int i;
	
		for (i = 1; i < 5; i++) {
			if (card_hands->cards[0].suit_index == card_hands->cards[i].suit_index) {
				if (card_hands->flush) card_hands->flush = 1;
			}
			else card_hands->flush = 0;
		}

}
void sort(Hand* card_hands) {
	int smallest = 0;
	int sorter[5] = { 5,4,3,2,1 };
	for (int j = 0; j < 5; j++) {
		sorter[j] = card_hands->cards[j].face_index;
	}
	for (int j = 0; j < 5; j++) {
		int min = INT_MAX;
		for (int i = j; i < 5; i++) {
			if (sorter[i] < min) {
				min = sorter[i];
				smallest = i;
			}
		}
		//swap
		sorter[smallest] = sorter[j];
		sorter[j] = min;
	}
}
void contains_straight(Hand* card_hands) {
	
	int sorter[5] = { 5,4,3,2,1 };
	int smallest = 0;
	int contains_both = -1;
	int k_exists = 0;
	int ace_exists = 0;
	//rearranging it properly if it contains both a king and an ace in the same hand
	for (int i = 0; i < 5; i++) {
		if (card_hands->cards[i].face_index == 0)k_exists = 1;
		if (card_hands->cards[i].face_index == 12)ace_exists = 1;
		if (k_exists && ace_exists)contains_both = 1;
	}
	//rearranging it properly if it contains both a king and an ace in the same hand
	for (int j = 0; j < 5; j++) {
	
		if (contains_both == 1 && card_hands->cards[j].face_index >= 10) {
			sorter[j] = card_hands->cards[j].face_index-13;
		}
		else sorter[j] = card_hands->cards[j].face_index;
	}
	for (int j = 0; j < 5; j++) {
		int min = INT_MAX;
		for (int i = j; i < 5; i++) {
			if (sorter[i] < min) {
				min = sorter[i];
				smallest = i;
			}
		}
		//swap
		sorter[smallest] = sorter[j];
		sorter[j] = min;
	}
	
	for (int i = 0; i < 4; i++) {
		if ((sorter[i] + 1) == sorter[i + 1] ) {
			
			if (card_hands->straight)card_hands->straight = 1;
			
			
		}
		else card_hands->straight = 0;
		
	}
	
	if (card_hands->straight == 1) {
		printf("The hand of the player is straight congrats!\n");
	}
	
	}
void display_menu(void) {
	printf("================MENU===============\n"
		"1.Enter '1' to view the game rules.\n"
		"2.Enter '2' to play the game.\n"
		"3.Enter '3' if you wish to quit the game.\n");



}
void print_rule(void) {
	printf("Play begins with each player being dealt five cards, one at a time, all face down. The remaining deck is placed aside, often protected by placing a chip or other marker on it. Players pick up the cards and hold them in their hands, being careful to keep them concealed from the other players, then a round of betting occurs.            \n"
		"If more than one player remains after the first round, the \"draw\" phase begins.Each player specifies how many of their cards they wish to replace and discards them.The deck is retrieved, and each player is dealt in turn from the deck the same number of cards they discarded so that each player again has five cards.                   \n"
		"A second \"after the draw\" betting round occurs beginning with the player to the dealer's left or else beginning with the player who opened the first round (the latter is common when antes are used instead of blinds). This is followed by a showdown, if more than one player remains, in which the player with the best hand wins the pot.\n");
}
void display_continue(void) {
	printf("\n1. Enter '1' to exit the game.\n"
		"\n2. Enter '2' to continue playing.\n");
}
int play(Hand* card_hands) {
	int total_score = 0;
	contains_pair(card_hands);
	contains_two_pairs(card_hands);
	contains_three_of_a_kind(card_hands);
	contains_straight(card_hands);
	contains_flush(card_hands);
	contains_full_house(card_hands);
	char* rep[7] = { "pair","two pair","three kinds","straight","flush","full_house","four_kinds" };
	int points_array[7] = { card_hands->pair,card_hands->two_pair,card_hands->three_kinds,card_hands->straight,card_hands->flush,card_hands->full_house,card_hands->four_kinds };
	for (int i = 0; i < sizeof(points_array) / 4; i++) {
		if (points_array[i] == 1) {
			total_score += (i + 1);
			printf("Points for player%d: %d and which one it is: %s\n", card_hands->identifier + 1, i+1,rep[i]);
		}
	}
	printf("Total for player%d: %d\n", card_hands->identifier + 1, total_score);
	return total_score;


}