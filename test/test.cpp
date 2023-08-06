#include "../matrix.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {
    std::fstream filetest {"./test/Testing.txt"};
}

template <class Type>
matrix<Type> filescan(Type& det);

template <class Type>
matrix_square<Type> filescan_S(Type& det);

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

template <class Type>
matrix<Type> filescan(Type& det){
    unsigned int n, m;
    filetest >> n >> m;

    matrix<Type> A(n, m);
    filetest >> A >> det;
    
    return A;
}

template <class Type>
matrix_square<Type> filescan_S(Type& det){
    unsigned int n;
    filetest >> n;

    matrix_square<Type> A(n);
    filetest >> A >> det;

    return A;
}

TEST(TestGroupName, Subtest_1){
    double det;
    matrix_square<double> A = filescan_S(det);
    
    ASSERT_DOUBLE_EQ(A.det(), det);
    std::cout << A;
}

TEST(TestGroupName, Subtest_2){
    double det;
    matrix_square<double> A = filescan_S(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
    std::cout << A;
}

TEST(TestGroupName, Subtest_3){
    double det;
    matrix_square<double> A = filescan_S(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
    std::cout << A;
}

TEST(TestGroupName, Subtest_4){
    double det;
    matrix_square<double> A = filescan_S(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
    std::cout << A;
}

TEST(TestGroupName, Subtest_5){
    double det;
    matrix_square<double> A = filescan_S(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
    std::cout << A;
}

TEST(TestGroupName, Subtest_6){
    double rg;
    matrix<double> A = filescan(rg);
    ASSERT_DOUBLE_EQ(A.rang(), rg);
    std::cout << A;
}

TEST(TestGroupName, Subtest_7){
    double rg;
    matrix<double> A = filescan(rg);
    ASSERT_DOUBLE_EQ(A.rang(), rg);
    std::cout << A;
}

TEST(TestGroupName, Subtest_8){
    double rg;
    matrix<double> A = filescan(rg);
    ASSERT_DOUBLE_EQ(A.rang(), rg);
    std::cout << A;
}

TEST(TestGroupName, Subtest_9){
    double rg;
    matrix<double> A = filescan(rg);
    ASSERT_DOUBLE_EQ(A.rang(), rg);
    std::cout << A;
}

TEST(TestGroupName, Subtest_10){
    double rg;
    matrix<double> A = filescan(rg);
    ASSERT_DOUBLE_EQ(A.rang(), rg);
    std::cout << A;
}