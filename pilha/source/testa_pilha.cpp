/*
Nome: Victor Eduardo Fernandes Castor
Matricula: 170115127
Data: 14/09/18
Projeto Pilha
*/

#include <gtest/gtest.h>
#include "pilha.c"

/*Conjunto dos testes*/

TEST(CreateStack, Dynamic) {
    int size = 5;
    int code = 1;
    pilha *ponteiro = NULL;
    ASSERT_NE(ponteiro, CreateStack(size, code));
}


TEST(CreateStack, Estatic) {
    int size = 5;
    int code = 0;
    pilha *ponteiro = NULL;
    ASSERT_NE(ponteiro, CreateStack(size, code));
}

TEST(DestroyStack, Dynamic) {
    int size = 5;
    int code = 1;
    pilha *ponteiro = CreateStack(size, code);
    ASSERT_EQ(0, DestroyStack(ponteiro));
}

TEST(Push, Dynamic) {
    int size = 1;
    int code = 1;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(0, push(2, ponteiro, size, code));
    EXPECT_EQ(-1, push(6, ponteiro, size, code));
    DestroyStack(ponteiro);
}


TEST(Push, Estatic) {
    int size = 1;
    int code = 0;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(0, push(2, ponteiro, size, code));
    push(7, ponteiro, size, code);
    EXPECT_EQ(-1, push(6, ponteiro, size, code));
}

TEST(StackSize, Dynamic) {
    int size = 2;
    int code = 1;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(0, StackSize(ponteiro, size, code));
    push(12, ponteiro, size, code);
    EXPECT_EQ(1, StackSize(ponteiro, size, code));
    push(23, ponteiro, size, code);
    push(92, ponteiro, size, code);
    EXPECT_EQ(2, StackSize(ponteiro, size, code));
    DestroyStack(ponteiro);
}


TEST(StackSize, Estatic) {
    int size = 2;
    int code = 0;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(0, StackSize(ponteiro, size, code));
    push(11, ponteiro, size, code);
    EXPECT_EQ(1, StackSize(ponteiro, size, code));
    push(22, ponteiro, size, code);
    EXPECT_EQ(2, StackSize(ponteiro, size, code));
    push(33, ponteiro, size, code);
    EXPECT_EQ(2, StackSize(ponteiro, size, code));
}


TEST(Pop, Dynamic) {
    int size = 2;
    int code = 1;
    pilha *ponteiro = CreateStack(size, code);
    push(12, ponteiro, size, code);
    EXPECT_EQ(0, pop(ponteiro, code));
    EXPECT_EQ(-1, pop(ponteiro, code));
    DestroyStack(ponteiro);
}

TEST(Pop, Estatic) {
    int size = 2;
    int code = 0;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(-1, pop(ponteiro, code));
    push(12, ponteiro, size, code);
    EXPECT_EQ(0, pop(ponteiro, code));
    pop(ponteiro, code);
    EXPECT_EQ(-1, pop(ponteiro, code));
}

TEST(IsFull, Dynamic) {
    int size = 1;
    int code = 1;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(0, IsFull(ponteiro, size, code));
    push(3, ponteiro, size, code);
    EXPECT_EQ(1, IsFull(ponteiro, size, code));
    pop(ponteiro, code);
    EXPECT_EQ(0, IsFull(ponteiro, size, code));
    DestroyStack(ponteiro);
}


TEST(IsFull, Estatic) {
    int size = 1;
    int code = 0;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(0, IsFull(ponteiro, size, code));
    push(3, ponteiro, size, code);
    EXPECT_EQ(1, IsFull(ponteiro, size, code));
    pop(ponteiro, code);
    EXPECT_EQ(0, IsFull(ponteiro, size, code));
}


TEST(IsEmpty, Dynamic) {
    int size = 1;
    int code = 1;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(1, IsEmpty(ponteiro, size, code));
    push(3, ponteiro, size, code);
    EXPECT_EQ(0, IsEmpty(ponteiro, size, code));
    pop(ponteiro, code);
    EXPECT_EQ(1, IsEmpty(ponteiro, size, code));
    DestroyStack(ponteiro);
}

TEST(IsEmpty, Estatic) {
    int size = 1;
    int code = 0;
    pilha *ponteiro = CreateStack(size, code);
    EXPECT_EQ(1, IsEmpty(ponteiro, size, code));
    push(3, ponteiro, size, code);
    EXPECT_EQ(0, IsEmpty(ponteiro, size, code));
    pop(ponteiro, code);
    EXPECT_EQ(1, IsEmpty(ponteiro, size, code));
}

TEST(Top, Dynamic) {
    int size = 3;
    int code = 1;
    pilha *ponteiro = CreateStack(size, code);
    push(69, ponteiro, size, code);
    EXPECT_EQ(69, top(ponteiro, size, code));
    push(937637, ponteiro, size, code);
    EXPECT_EQ(937637, top(ponteiro, size, code));
    pop(ponteiro, code);
    EXPECT_EQ(69, top(ponteiro, size, code));
    pop(ponteiro, code);
    EXPECT_EQ(-1, top(ponteiro, size, code));
    DestroyStack(ponteiro);
}

TEST(Top, Estatic) {
    int size = 3;
    int code = 0;
    pilha *ponteiro = CreateStack(size, code);
    push(69, ponteiro, size, code);
    EXPECT_EQ(69, top(ponteiro, size, code));
    push(937637, ponteiro, size, code);
    EXPECT_EQ(937637, top(ponteiro, size, code));
    pop(ponteiro, code);
    EXPECT_EQ(69, top(ponteiro, size, code));
    pop(ponteiro, code);
    EXPECT_EQ(-1, top(ponteiro, size, code));
}

TEST(SetSize, Dynamic) {
    int size = 2;
    int code = 1;
    pilha *ponteiro = CreateStack(size, code);
    push(1, ponteiro, size, code);
    push(2, ponteiro, size, code);
    push(3, ponteiro, size, code);
    EXPECT_EQ(2, top(ponteiro, size, code));
    EXPECT_EQ(0, SetSize(ponteiro, 3, &size));
    push(3, ponteiro, size, code);
    EXPECT_EQ(3, top(ponteiro, size, code));
    SetSize(ponteiro, 2, &size);
    EXPECT_EQ(2, top(ponteiro, size, code));
    DestroyStack(ponteiro);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
