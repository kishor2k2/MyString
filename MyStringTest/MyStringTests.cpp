#include "gtest/gtest.h"
#include "../MyString/MyString.h"

TEST(MyStringTests, DefaultConstructorTest) {
    MyString s;
    EXPECT_EQ(s.length(), 0);
    EXPECT_TRUE(s.empty());
}

TEST(MyStringTests, ParameterizedConstructorTest) {
    MyString s("Dummy");
    EXPECT_EQ(s.length(), 5);
    EXPECT_FALSE(s.empty());
    EXPECT_STREQ(s.c_str(), "Dummy");
}

TEST(MyStringTests, CopyConstructorTest) {
    MyString original("Dummy");
    MyString copy(original);
    EXPECT_EQ(copy.length(), 5);
    EXPECT_STREQ(copy.c_str(), "Dummy");
}

TEST(MyStringTests, MoveConstructorTest) {
    MyString original("Dummy");
    MyString moved(std::move(original));
    EXPECT_EQ(moved.length(), 5);
    EXPECT_STREQ(moved.c_str(), "Dummy");
    EXPECT_TRUE(original.empty());
}

TEST(MyStringTests, CopyAssignmentOperatorTest) {
    MyString s1("Dummy");
    MyString s2;
    s2 = s1;
    EXPECT_EQ(s2.length(), 5);
    EXPECT_STREQ(s2.c_str(), "Dummy");
}

TEST(MyStringTests, MoveAssignmentOperatorTest) {
    MyString s1("Dummy");
    MyString s2;
    s2 = std::move(s1);
    EXPECT_EQ(s2.length(), 5);
    EXPECT_STREQ(s2.c_str(), "Dummy");
    EXPECT_TRUE(s1.empty());
}

TEST(MyStringTests, IndexOperatorNonConstTest) {
    MyString s("Dummy");
    EXPECT_EQ(s[0], 'D');
    EXPECT_EQ(s[4], 'y');
}

TEST(MyStringTests, IndexOperatorConstTest) {
    const MyString s("Dummy");
    EXPECT_EQ(s[0], 'D');
    EXPECT_EQ(s[4], 'y');
}

TEST(MyStringTests, LengthTest) {
    MyString s("Dummy");
    EXPECT_EQ(s.length(), 5);
}

TEST(MyStringTests, SizeTest) {
    MyString s("Dummy");
    EXPECT_EQ(s.size(), 5);
}

TEST(MyStringTests, EmptyTest) {
    MyString s;
    EXPECT_TRUE(s.empty());
    s = "Dummy";
    EXPECT_FALSE(s.empty());
}

TEST(MyStringTests, CStrTest) {
    MyString s("Dummy");
    EXPECT_STREQ(s.c_str(), "Dummy");
}

TEST(MyStringTests, OutputOperatorTest) {
    MyString s("Dummy");
    std::ostringstream oss;
    oss << s;
    EXPECT_EQ(oss.str(), "Dummy");
}
