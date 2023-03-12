#include "../matrix.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

std::fstream filetest {"./Test/Testing.txt"};

int main(int argc, char **argv){

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

template <typename T>
void matrix::filescan(T& det){
    filetest >> n >> m;
    
    matrix *this(n, m);
    filetest >> *this;
    filetest >> det;
 
    return A;
}

template <typename T>
void matrix_square::filescan(T& det){
    filetest >> n >> m;
    
    matrix_square *this(n, m);
    filetest >> *this;
    filetest >> det;
 
    return A;
}

TEST(TestGroupName, Subtest_1){
    double det;
    matrix_square A.filescan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_2){
    double det;
    matrix_square A = filescan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_3){
    double det;
    matrix_square A = filescan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_4){
    double det;
    matrix_square A = filescan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_5){
    double det;
    matrix_square A = filescan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_6){
    size_t rg;
    matrix A = filescan(rg);
    std::cout << rg;
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_7){
    size_t rg;
    matrix A.filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_8){
    size_t rg;
    matrix A.filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_9){
    size_t rg;
    matrix A.filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_10){
    size_t rg;
    matrix A->filescan(rg);
    ASSERT_EQ(A.rang(), rg);
}