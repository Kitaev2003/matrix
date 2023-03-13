#include "../matrix.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

std::fstream filetest {"./test/Testing.txt"};

template <typename T>
matrix filescan(T& det);

template <typename T>
matrix_square filescan_S(T& det);

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

template <typename T>
matrix filescan(T& det){
    unsigned int n, m;
    filetest >> n >> m;

    matrix A(n, m);
    filetest >> A >> det;
    
    return A;
}

template <typename T>
matrix_square filescan_S(T& det){
    unsigned int n;
    filetest >> n;

    matrix_square A(n);
    filetest >> A >> det;

    return A;
}

TEST(TestGroupName, Subtest_1){
    double det;
    matrix_square A = filescan_S(det);
    
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_2){
    double det;
    matrix_square A = filescan_S(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_3){
    double det;
    matrix_square A = filescan_S(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_4){
    double det;
    matrix_square A = filescan_S(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_5){
    double det;
    matrix_square A = filescan_S(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_6){
    size_t rg;
    matrix A = filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_7){
    size_t rg;
    matrix A = filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_8){
    size_t rg;
    matrix A = filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_9){
    size_t rg;
    matrix A = filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_10){
    size_t rg;
    matrix A = filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}