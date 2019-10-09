// Card.h : class Card ����

#ifndef CARD_H
#define CARD_H

#include <array>
#include <string>

// ī���� Face (����)�� ǥ���ϴµ� ���̴� enum
enum Face {Ace = 1, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, King, Queen, Jack};
// ī���� Suit (����)�� ǥ���ϴµ� ���̴� enum
enum Suit {Spade, Heart, Diamond, Club};

class Card
{
public:
	static const std::array<std::string, 14> card_face; // ī���� ���ڿ� K, Q, J�� �̸��� ��� String
	static const std::array<std::string, 4> card_suit; // ī���� ���� (�����̵�, ��Ʈ, ���̾Ƹ��, Ŭ��)�� ��� String

	Card(int = Ace, int = Spade); // ������ : enum�� �̿��� face�� suit ����
	std::string toString(); // ī���� ������ "[Face] of [Suit]" ������ string���� return
private:
	int face; // ī���� Face (����)
	int suit; // ī���� Suit (����)
};

#endif