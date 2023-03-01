#include "../matrix.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

std::fstream filetest {"./Test/Testing.txt"};

int main(int argc, char **argv){

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

template <typename T>
matrix fscan(T& det){
    size_t n, m;
    filetest >> n >> m;
    
    matrix A(n, m);
    for(row i = A.data.begin(); i < A.data.end(); ++i){
        for(col j = i->begin(); j < i->end(); ++j){
            filetest >> *j;
        }
    }
    filetest >> det;
 
    return A;
}

TEST(TestGroupName, Subtest_1){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_2){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_3){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_4){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_5){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(), det);
}

TEST(TestGroupName, Subtest_6){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_7){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_8){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_9){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(), rg);
}

TEST(TestGroupName, Subtest_10){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(), rg);
}
