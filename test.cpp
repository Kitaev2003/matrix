#include "matrix.hpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

matrix& fscan(double* det){
    size_t n, m;
    std::ifstream filetest;
    filetest.open("Testing.txt", std::ios::in);

    filetest >> n >> m;
    
    matrix A(n, m);

    for(size_t i = 0; i < A.height; ++i){
        for(size_t j = 0; j < A.width; ++j){
            filetest >> A.data[i][j];
        }
    }
    filetest >> *det;
    filetest.close();

    return A;
}

TEST(TestGroupName, Subtest_1){
    double det;
    matrix A = fscan(&det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_2) {
    double det;
    matrix A = fscan(&det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_3) {
    double det;
    matrix A = fscan(&det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_4) {
    double det;
    matrix A = fscan(&det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}

TEST(TestGroupName, Subtest_5) {
    double det;
    matrix A = fscan(&det);
    ASSERT_DOUBLE_EQ(A.det(A), det);
}