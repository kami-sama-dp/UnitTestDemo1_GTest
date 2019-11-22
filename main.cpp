#include "iostream"
#include "test.h"
#include "gtest/gtest.h"

using namespace std;
class MyEnviroment: public testing::Environment{
public:
    virtual void SetUp() {
        std::cout << "MyEnviroment set up" << std::endl;
    }
    virtual void TearDown(){
        std::cout << "MyEnviroment tear down" << std::endl;
    }
};

class MyTestSuite:public testing::Test{
public:
    static void SetUpTestSuite(){
        cout << "在suite之前setUp" << endl;
    }

    static void TearDownTestSuite(){
        cout << "在suite之后tearDown"  << endl;

    }
};

class MyTestCase:public testing::Test{
public:
    virtual void SetUp(){
        cout << " case 之前setUp" << endl;
    }

    virtual void TearDown(){
        cout << "case之后TearDown" << endl;
    }

};

TEST(TestCase, test1){
    ASSERT_EQ(12, add(4, 8));  /* ASSERT_* 系列的断言，当检查点失败时，退出当前函数 */
}

TEST(TestCase, test2){
    EXPECT_EQ(5, add(2, 3));  /* EXPECT_* 系列的断言，当检查点失败时，继续往下执行。*/
}

TEST(TestCase1, test3){
    EXPECT_EQ(3, add(1, 2));
}

TEST_F(MyTestSuite, test0){
    EXPECT_EQ(2, add(1, 1));
}

TEST_F(MyTestSuite, test1){
    EXPECT_EQ(3, add(1, 2));
}

TEST_F(MyTestCase, test4){
    EXPECT_EQ(4, add(2, 2));
}

TEST_F(MyTestCase, test5){
    EXPECT_EQ(4, add(2, 2));
}

int main(int argc, char **argv){
    testing::AddGlobalTestEnvironment(new MyEnviroment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}