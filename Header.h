#pragma once
/*
Author:Ebenezer Abate
Course: CPT_S Lab secion 07
TA: Selina N.
Date: 04/21/23

Description: This is the header file(.h) that contains all the constants and any other defintions we need for both the main.c
and functions.c files to work properly*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000
typedef struct card {
	int face_index;
	int suit_index;
	
}Card;
typedef struct hand {
	Card cards[5];
	int identifier;
	int pair;
	int two_pair;
	int three_kinds;
	int four_kinds;
	int full_house;
	int flush;
	int straight;
}Hand;

void shuffle(int wDeck[4][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[],Hand* card_hands);
void draw(const int wDeck[][13], const char* wFace[], const char* wSuit[],Card* draw_card);
void contains_pair(Hand* card_hands);
void contains_two_pairs(Hand* card_hands);
void contains_three_of_a_kind(Hand* card_hands);
void contains_four_of_a_kind(Hand* card_hands);
void contains_full_house(Hand* card_hands);
void contains_flush(Hand* card_hands);
void contains_straight(Hand* card_hands);
void display_menu(void);
void print_rule();
void display_continue();
int play(Hand* card_hands);
void sort(Hand* card_hands);
void draw_for_dealer(const int wDeck[][13], const char* wFace[], const char* wSuit[],Hand* card_hands);
