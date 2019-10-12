// Card.cpp : Card.h�� �Լ� ����

#include <array>
#include <string>
#include "Card.h"
using namespace std;

// ī���� ���ڿ� K, Q, J�� �̸��� ��� String
const array<string, 14> Card::card_face
{ "" ,"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "King", "Queen", "Jack" };
// ī���� ���� (�����̵�, ��Ʈ, ���̾Ƹ��, Ŭ��)�� ��� String
const array<string, 4> Card::card_suit
{ "Spades", "Hearts", "Diamonds", "Clubs" };

// ������ : enum�� �̿��� face�� suit ����
Card::Card(int face_, int suit_ ) : face(face_), suit(suit_) {}

// ī���� ������ "[Face] of [Suit]" ������ string���� return
string Card::toString()
{
	string tmp;
	tmp = card_face[face] + " of " + card_suit[suit];
	return tmp;
}

// ī���� ���� return
int Card::getFace() const { return face; };
// ī���� ���� return
int Card::getSuit() const { return suit; };