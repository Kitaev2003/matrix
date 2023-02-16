#include "../matrix.hpp"

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
    for(size_t i = 0; i < A.height; ++i){
        for(size_t j = 0; j < A.width; ++j){
            filetest >> A.data[i][j];
        }
    }
    filetest >> det;
    
    return A;
}

TEST(TestGroupName, Subtest_1){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_2){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_3){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_4){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_5){
    double det;
    matrix A = fscan(det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_6){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(A), rg);
}

TEST(TestGroupName, Subtest_7){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(A), rg);
}

TEST(TestGroupName, Subtest_8){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(A), rg);
}

TEST(TestGroupName, Subtest_9){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(A), rg);
}

TEST(TestGroupName, Subtest_10){
    size_t rg;
    matrix A = fscan(rg);
    ASSERT_EQ(A.rang(A), rg);
}
