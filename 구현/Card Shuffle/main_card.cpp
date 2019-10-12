#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <array>
#include "Card.h"
#include "DeckofCards.h"
using namespace std;

namespace deck_match
{
	enum define {zero, one, two, triple, straight, flush, quads};
	array<string, 7> define_str{"No pair", "One pair", "Two pairs", "Three of a kind", "Straight", "Flush", "Four of a kind"};
}

// sort�� ���ڷ� ���� �� �Լ�
bool cmp(Card& A, Card& B)
{
	if (A.getFace() != B.getFace())
		return A.getFace() < B.getFace();
	else
		return A.getSuit() < B.getSuit();
}

short definedeck(array<Card, 5> & deck)
{
	// ���� ����
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 1; j < 4; j++)
		{
			if (deck[i].getFace() != deck[i + j].getFace())
				break;
			else if (j == 3)
				return deck_match::quads;
		}
	}

	// �÷��� ����
	for (size_t i = 0; i < 4; i++)
	{
		if (deck[i].getSuit() != deck[i + 1].getSuit())
			break;
		else if (i == 3)
			return deck_match::flush;
	}

	// ��Ʈ����Ʈ ����
	for (size_t i = 0; i < 4; i++)
	{
		// J -> A�� ��쵵 ����Ѵ�
		if (deck[i].getFace() + 1 != deck[i + 1].getFace() || deck[i].getFace() - 12 != deck[i + 1].getFace())
			break;
		else if (i == 3)
			return deck_match::straight;
	}

	// Ʈ���� ����
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 1; j < 3; j++)
		{
			if (deck[i].getFace() != deck[i + j].getFace())
				break;
			else if (j == 2)
				return deck_match::triple;
		}
	}

	// �����/����� ����
	int pair_counter{ 0 };
	for (size_t i = 0; i < 4; i++)
	{
		if (deck[i].getFace() == deck[i + 1].getFace())
			pair_counter++;
	}

	if (pair_counter == 2)
		return deck_match::two;
	else if (pair_counter == 1)
		return deck_match::one;

	// ������ �ƹ��͵� ��ġ�Ǵ� ���� ���ٸ�, �� ���� ����
	return deck_match::zero;
}

int main()
{
	// DeckofCards class ���� �� ���� ����
	srand(static_cast<unsigned int>(time(0)));
	DeckofCards d; d.shuffle();
	
	// deck1�� ī�� 5���� �ְ� sort��
	array<Card, 5> deck1;
	for (size_t i = 0; i < 5; i++)
		deck1[i] = d.dealCard();
	sort(deck1.begin(), deck1.end(), cmp);

	// deck2�� ī�� 5���� �ְ� sort��
	array<Card, 5> deck2;
	for (size_t j = 0; j < 5; j++)
		deck2[j] = d.dealCard();
	sort(deck2.begin(), deck2.end(), cmp);

	// deck1�� deck2�� ī����� ������
	cout << "deck1�� �� :\n";
	for (size_t i = 0; i < 5; i++)
	{
		cout << deck1[i].toString();
		cout << ((i != 4) ? ", " : "\n");
	}
	cout << "deck2�� �� :\n";
	for (size_t i = 0; i < 5; i++)
	{
		cout << deck2[i].toString();
		cout << ((i != 4) ? ", " : "\n");
	}
	cout << "\n";

	// �� ���� ���� ����� ������
	cout << "deck1�� ���� : " << deck_match::define_str[definedeck(deck1)] << "\n";
	cout << "deck2�� ���� : " << deck_match::define_str[definedeck(deck2)] << "\n";
	cout << "\n";

	if (definedeck(deck1) > definedeck(deck2))
		cout << "deck1 �¸�!";
	else if (definedeck(deck1) < definedeck(deck2))
		cout << "deck2 �¸�!";
	else
		cout << "���º�!";
	cout << endl;
}