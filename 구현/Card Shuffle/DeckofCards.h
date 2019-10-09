// DeckofCards.h : class DeckofCards ���� 

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <array>
#include "Card.h"

class DeckofCards
{
public:
	// �⺻ ������ : deck�� ��Ŀ�� ������ ��� ī�尡 ���徿 ����ִ� ���� (52��)���� ����
	DeckofCards(); 

	void shuffle(); // ī�� ����
	Card dealCard(); // ī�� �ֱ�
	bool moreCard(); // ī�带 �� �� �� �ִ��� Ȯ��
private:
	std::array<Card, 52> deck; // 52���� ī�尡 ��� ��
	size_t currentCard; // ������ �� ī��
};

#endif