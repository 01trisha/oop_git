#include <iostream>
#include <gtest/gtest.h>
#include "../scr/circularbuffer.h"

//конструктор по умолчанию
TEST(CircularBufferTest, ConstructorWithoutParametersTest) {
	Buffer::CircularBuffer buffer;

	EXPECT_EQ(buffer.size(), 0);
	EXPECT_EQ(buffer.capacity(), 0);
	EXPECT_TRUE(buffer.is_linearized());
}
//конструктор копирования
TEST(CircularBufferTest, ConstructorCopyTest) {
	Buffer::CircularBuffer buffer(5);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);
	buffer.push_back(4);
	buffer.push_back(5);

	Buffer::CircularBuffer buffer1(buffer);

	EXPECT_EQ(buffer1.capacity(), 5);

	for (int i = 0; i < buffer.capacity(); i++) {
		EXPECT_EQ(buffer1[i], buffer[i]);
	}
}
//конструктор с заданной глубиной
TEST(CircularBufferTest, ConstructorWithParameterTest) {
	Buffer::CircularBuffer buffer(5);

	EXPECT_EQ(buffer.size(), 0);
	EXPECT_EQ(buffer.capacity(), 5);
	EXPECT_TRUE(buffer.is_linearized());
}
//конструктор с заданной грубиной и элементами
TEST(CircularBufferTest, ConstructorWithParametersTest) {
	Buffer::CircularBuffer buffer(5, 3);

	EXPECT_EQ(buffer.size(), 5);
	EXPECT_EQ(buffer.capacity(), 5);
	EXPECT_TRUE(buffer.is_linearized());

	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(buffer[i], 3);
	}
}
//проверка оператор []
TEST(CircularBufferTest, IndexOperatorTest) {
	Buffer::CircularBuffer buffer(3);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);

	EXPECT_EQ(buffer[0], 1);
	EXPECT_EQ(buffer[1], 2);
	EXPECT_EQ(buffer[2], 3);

	const Buffer::CircularBuffer buffer2(buffer);

	EXPECT_EQ(buffer2[0], 1);
	EXPECT_EQ(buffer2[1], 2);
	EXPECT_EQ(buffer2[2], 3);
}
//проверка доступа по индексу (at)
TEST(CircularBufferTest, AccessMethodTest) {
	Buffer::CircularBuffer buffer(3);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);

	EXPECT_EQ(buffer.at(0), 1);
	EXPECT_EQ(buffer.at(1), 2);
	EXPECT_EQ(buffer.at(2), 3);
	EXPECT_THROW(buffer.at(-1), std::out_of_range);
	EXPECT_THROW(buffer.at(3), std::out_of_range);

	const Buffer::CircularBuffer buffer2(buffer);

	EXPECT_EQ(buffer2.at(0), 1);
	EXPECT_EQ(buffer2.at(1), 2);
	EXPECT_EQ(buffer2.at(2), 3);
	EXPECT_THROW(buffer2.at(-1), std::out_of_range);
	EXPECT_THROW(buffer2.at(3), std::out_of_range);
}
//проверка первого элемента
TEST(CircularBufferTest, FrontTest) {
	Buffer::CircularBuffer buffer(5);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);
	buffer.push_back(4);

	EXPECT_EQ(buffer.front(), 1);

	const Buffer::CircularBuffer buffer2(buffer);

	EXPECT_EQ(buffer2.front(), 1);
}
//проверка последнего элемента
TEST(CircularBufferTest, BackTest) {
	Buffer::CircularBuffer buffer(5);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);
	buffer.push_back(4);

	EXPECT_EQ(buffer.back(), 4);

	const Buffer::CircularBuffer buffer2(buffer);

	EXPECT_EQ(buffer2.back(), 4);
}
//проверка линеаризации 
TEST(CircularBufferTest, LinearizeTest) {
	Buffer::CircularBuffer buffer(3);
	EXPECT_EQ(buffer.linearize(), nullptr);

	buffer.push_back(0);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3); //перезапись 0
	buffer.push_back(4); //перезапись 1

	EXPECT_FALSE(buffer.is_linearized());

	buffer.linearize();

	EXPECT_TRUE(buffer.is_linearized());

	EXPECT_EQ(buffer[0], 2);
	EXPECT_EQ(buffer[1], 3);
	EXPECT_EQ(buffer[2], 4);
}
//rotate и resize
TEST(CircularBufferTest, RotateTest) {
	Buffer::CircularBuffer buffer(10);
	buffer.push_back(0);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);
	buffer.push_back(4);
	buffer.push_back(5);
	buffer.push_back(6);
	buffer.push_back(7);
	buffer.push_back(8);
	buffer.push_back(9);
	buffer.resize(7);

	buffer.rotate(2);

	EXPECT_EQ(buffer[0], 2);
	EXPECT_EQ(buffer[1], 3);
	EXPECT_EQ(buffer[2], 4);
	EXPECT_EQ(buffer[3], 5);
	EXPECT_EQ(buffer[4], 6);
	EXPECT_EQ(buffer[5], 0);
	EXPECT_EQ(buffer[6], 1);
	EXPECT_EQ(buffer[7], 7);

	buffer.rotate(5);
	buffer.rotate(9);

	EXPECT_EQ(buffer[0], 9);
	EXPECT_EQ(buffer[1], 0);
	EXPECT_EQ(buffer[2], 1);
	EXPECT_EQ(buffer[3], 2);
	EXPECT_EQ(buffer[4], 3);
	EXPECT_EQ(buffer[5], 4);
	EXPECT_EQ(buffer[6], 5);
	EXPECT_EQ(buffer[7], 6);
	EXPECT_EQ(buffer[8], 7);
	EXPECT_EQ(buffer[9], 8);
}
//пустой ли буфер 
TEST(CircularBufferTest, EmptyTest) {
	Buffer::CircularBuffer buffer(3);

	EXPECT_TRUE(buffer.empty());

	buffer.push_back(1);

	EXPECT_FALSE(buffer.empty());
}
//полный ли буфер
TEST(CircularBufferTest, FullTest) {
	Buffer::CircularBuffer buffer(3);

	buffer.push_back(1);

	EXPECT_FALSE(buffer.full());

	buffer.push_back(2);
	buffer.push_back(2);

	EXPECT_TRUE(buffer.full());
}
//сколько сталось свободынх ячеек
TEST(CircularBufferTest, ReserveTest) {
	Buffer::CircularBuffer buffer(3);
	
	EXPECT_EQ(buffer.reserve(), 3);

	buffer.push_back(1);

	EXPECT_EQ(buffer.reserve(), 2);

	buffer.push_back(1);
	buffer.push_back(1);

	EXPECT_EQ(buffer.reserve(), 0);
}
//установка новой емкости
TEST(CircularBufferTest, SetCapacityTest) {
	Buffer::CircularBuffer buffer(5);
	buffer.push_back(1);
	buffer.set_capacity(7);

	EXPECT_EQ(buffer.capacity(), 7);

	buffer.set_capacity(3);

	EXPECT_EQ(buffer.capacity(), 3);
}

TEST(CircularBufferTest, ResizeTest) {
	Buffer::CircularBuffer buffer(10);
	buffer.push_back(1);
	buffer.push_back(1);
	buffer.push_back(1);
	buffer.push_back(1);
	buffer.push_back(1);

	buffer.resize(3);
	EXPECT_EQ(buffer.size(), 3);

	buffer.resize(10, 1);

	EXPECT_EQ(buffer.size(), 10);

	buffer.resize(16, 2);

	EXPECT_EQ(buffer.size(), 16);
	for (int i = 0; i <= 9; i++)
		EXPECT_EQ(buffer[i], 1);
	for (int i = 10; i <= 15; i++)
		EXPECT_EQ(buffer[i], 2);
}
//проверка оператора =
TEST(CircularBufferTest, AssidgnmentTest) {
	Buffer::CircularBuffer buffer1(5, 1);
	Buffer::CircularBuffer buffer2;
	buffer1 = buffer1;
	buffer2 = buffer1;

	EXPECT_EQ(buffer1.capacity(), buffer2.capacity());
	EXPECT_EQ(buffer1.size(), buffer2.size());

	for (int i = 0; i < buffer1.size(); ++i) {
		EXPECT_EQ(buffer1[i], buffer2[i]);
	}
}
//проверка swap
TEST(CircularBufferTest, SwapTest) {
	Buffer::CircularBuffer buffer1(5, 1);
	Buffer::CircularBuffer buffer2(3, 2);

	Buffer::CircularBuffer originalBuffer1 = buffer1;
	Buffer::CircularBuffer originalBuffer2 = buffer2;

	buffer1.swap(buffer2);

	EXPECT_EQ(buffer1.capacity(), originalBuffer2.capacity());
	EXPECT_EQ(buffer1.size(), originalBuffer2.size());

	for (int i = 0; i < buffer1.size(); ++i) {
		EXPECT_EQ(buffer1[i], originalBuffer2[i]);
	}

	EXPECT_EQ(buffer2.capacity(), originalBuffer1.capacity());
	EXPECT_EQ(buffer2.size(), originalBuffer1.size());

	for (int i = 0; i < buffer2.size(); ++i) {
		EXPECT_EQ(buffer2[i], originalBuffer1[i]);
	}
}
//проверка пушбеков
TEST(CircularBufferTest, PushBackTest) {
	Buffer::CircularBuffer buffer(3);
	buffer.push_back(0);
	buffer.push_back(1);
	buffer.push_back(2);

	EXPECT_EQ(buffer[0], 0);
	EXPECT_EQ(buffer[1], 1);
	EXPECT_EQ(buffer[2], 2);
	EXPECT_EQ(buffer.size(), 3);

	buffer.push_back(3);

	EXPECT_EQ(buffer[0], 1);
	EXPECT_EQ(buffer[1], 2);
	EXPECT_EQ(buffer[2], 3);
	EXPECT_EQ(buffer.size(), 3);
	EXPECT_EQ(buffer.capacity(), 3);
}
//проверка пушфронта
TEST(CircularBufferTest, PushFrontTest) {
	Buffer::CircularBuffer buffer(3);
	buffer.push_back(2);
	buffer.push_back(3);

	buffer.push_front(1);

	EXPECT_EQ(buffer[0], 1);
	EXPECT_EQ(buffer[1], 2);
	EXPECT_EQ(buffer[2], 3);
	EXPECT_EQ(buffer.size(), 3);

	buffer.push_front(0);

	EXPECT_EQ(buffer[0], 0);
	EXPECT_EQ(buffer[1], 1);
	EXPECT_EQ(buffer[2], 2);
	EXPECT_EQ(buffer.size(), 3);
	EXPECT_EQ(buffer.capacity(), 3);
}
//проверка попбека
TEST(CircularBufferTest, PopBackTest) {
	Buffer::CircularBuffer buffer(3);
	buffer.push_back(0);
	buffer.push_back(1);
	buffer.push_back(2);

	EXPECT_EQ(buffer.size(), 3);
	EXPECT_EQ(buffer[0], 0);
	EXPECT_EQ(buffer[1], 1);
	EXPECT_EQ(buffer[2], 2);

	buffer.pop_back();

	EXPECT_EQ(buffer.size(), 2);
	EXPECT_EQ(buffer[0], 0);
	EXPECT_EQ(buffer[1], 1);
}
//проверка попфронта
TEST(CircularBufferTest, PopFrontTest) {
	Buffer::CircularBuffer buffer(3);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);

	buffer.pop_front();

	EXPECT_EQ(buffer[0], 2);
	EXPECT_EQ(buffer.size(), 2);
}
//проверка вставки элемента по индексу
TEST(CircularBufferTest, InsertTest) {
	Buffer::CircularBuffer buffer(5);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);

	buffer.insert(1, 4);

	EXPECT_EQ(buffer[1], 4);

	buffer.insert(0, 5);

	EXPECT_EQ(buffer[0], 5);

	buffer.insert(4, 6);

	EXPECT_EQ(buffer[4], 6);
	EXPECT_EQ(buffer.size(), 5);

	EXPECT_THROW(buffer.insert(7, 7), std::out_of_range);
}
//проверка удаления [firt, last]
TEST(CircularBufferTest, EraseTest) {
	Buffer::CircularBuffer buffer(5);
	buffer.push_back(1);
	buffer.push_back(2);
	buffer.push_back(3);
	buffer.push_back(4);
	buffer.push_back(5);

	buffer.erase(1, 4);

	EXPECT_EQ(buffer.size(), 2);

	buffer.push_front(1);
	buffer.push_front(2);
	buffer.push_front(3);
	buffer.push_front(4);
	buffer.push_front(5);
	buffer.push_front(6);
	buffer.erase(1, 4);

	EXPECT_EQ(buffer.size(), 2);

	buffer.erase(0, 2);

	EXPECT_EQ(buffer.size(), 0);

	EXPECT_THROW(buffer.erase(8, 7), std::out_of_range);
}
//проверка оператора ==
TEST(CircularBufferTest, EqualsTest) {
	Buffer::CircularBuffer buffer1(3);
	buffer1.push_back(1);
	buffer1.push_back(2);
	buffer1.push_back(3);

	Buffer::CircularBuffer buffer2(3);
	buffer2.push_back(1);
	buffer2.push_back(2);
	buffer2.push_back(3);

	EXPECT_TRUE(buffer1 == buffer2);

	buffer2.pop_back();

	EXPECT_FALSE(buffer1 == buffer2);
}
//проверка !=
TEST(CircularBufferTest, NotEqualsTest) {
	Buffer::CircularBuffer buffer1(3);
	buffer1.push_back(1);
	buffer1.push_back(2);
	buffer1.push_back(3);

	Buffer::CircularBuffer buffer2(3);
	buffer2.push_back(1);
	buffer2.push_back(2);
	buffer2.push_back(1);

	EXPECT_TRUE(buffer1 != buffer2);

	buffer2[2] = 3;

	EXPECT_FALSE(buffer1 != buffer2);
}
//проверка clear
TEST(CircularBufferTest, ClearTest) {
    Buffer::CircularBuffer buffer(5);
    
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);
    
    EXPECT_EQ(buffer.size(), 3);
    EXPECT_FALSE(buffer.empty());
    
    buffer.clear();
    
    EXPECT_EQ(buffer.size(), 0);
    EXPECT_TRUE(buffer.empty());
    
    EXPECT_THROW(buffer.at(0), std::out_of_range);
}


int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}