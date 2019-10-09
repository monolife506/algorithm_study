// DeckofCards.cpp : class DeckofCards ���� �Լ� ���� 

#include <array>
#include <cstdlib>
#include "DeckofCards.h"
#include "Card.h"
using namespace std;

// �⺻ ������ : deck�� ��Ŀ�� ������ ��� ī�尡 ���徿 ����ִ� ���� (52��)���� ����
DeckofCards::DeckofCards()
{
	int count{ 0 };
	for (size_t i = 0; i < Card::card_suit.size(); i++)
	{
		for (size_t j = 1; j < Card::card_face.size(); j++)
		{
			deck[count++] = Card(j, i);
		}
	}

	currentCard = 0;
}

// ī�带 �����ϰ� ó������ ������ ������
void DeckofCards::shuffle()
{
	size_t shuffle_point;
	static Card shuffle_card;
	for (size_t shifter = 0; shifter < 52; shifter++)
	{
		shuffle_point = rand() % 52;
		shuffle_card = deck[shuffle_point];
		deck[shuffle_point] = deck[shifter];
		deck[shifter] = shuffle_card;
	}

	currentCard = 0;
}

// ī�带 ���� ��
Card DeckofCards::dealCard()
{
	if (currentCard <= 51)
	{
		return deck[currentCard++];
	}
	else
	{
		throw out_of_range("All cards in deck are given.");
	}
}

// ī�带 �� �� �� �ִ��� Ȯ��
bool DeckofCards::moreCard()
{
	if (currentCard >= 52)
	{
		return false;
	}
	else
	{
		return true;
	}
}
