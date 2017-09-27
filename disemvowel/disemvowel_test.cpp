#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char* disemvoweled_str = disemvowel((char*) ""); 
  ASSERT_STREQ("", disemvoweled_str);
  free(disemvoweled_str);
}

TEST(Disemvowel, HandleNoVowels) {
  char* disemvoweled_str = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", disemvoweled_str);
  free(disemvoweled_str);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* disemvoweled_str = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", disemvoweled_str);
  free(disemvoweled_str);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* disemvoweled_str = disemvowel((char*) "Morris, Minnesota"); 
  ASSERT_STREQ("Mrrs, Mnnst", disemvoweled_str);
  free(disemvoweled_str);
}

TEST(Disemvowel, HandlePunctuation) {
  char* disemvoweled_str = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", disemvoweled_str);
  free(disemvoweled_str);
}

TEST(Disemvowel, HandleLongString) {
  char *str, *disemvoweled_str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  disemvoweled_str = disemvowel(str);
  ASSERT_STREQ("xyz", disemvoweled_str);
  
  free(disemvoweled_str);
  free(str);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
