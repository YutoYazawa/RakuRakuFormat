// stredit.h (RakuRakuFormat)
//
// Yuto.Yazawa (008900012151b5yr@gl.pen-kanagawa.ed.jp)
//
// This software is released under the MIT License, see LICENSE.

#include <assert.h>
#include <string.h>

char* getstr(const char* target, size_t begin, size_t length, char* result, size_t result_size)
{
    assert(target != NULL);
    assert(result != NULL);
    assert(length + 1 <= result_size);

    if (begin < strlen(target)) {

        // target[begin] を起点に、length の文字数分だけコピー
        strncpy(result, target + begin, length);

        // 末尾のヌル文字を付加
        // strncpy() によってすでに付加されている可能性はある。
        // また、result[length] よりも手前にすでにヌル文字があるかもしれない。
        result[length] = '\0';
    }
    else {
        // begin が target の末尾以降の位置にあるときは、
        // 空文字列を返す
        result[0] = '\0';
    }
    return result;
}
