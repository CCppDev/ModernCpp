#include <iostream>

int main() {
    char utf8c = u8'a'; // C++17标准
    // char utf8c = u8'好'; // 编译不通过
    const char * utf8c2 = u8"好";
    char16_t utf16c = u'好';
    char32_t utf32c = U'好';
    char utf8[] = u8"你好世界";
    char16_t utf16[] = u"你好世界";
    char32_t utf32[] = U"你好世界";
    return 0;
}
