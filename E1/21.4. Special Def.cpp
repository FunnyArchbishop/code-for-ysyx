/*
 *  #pragma预处理指示供编译器实现一些非标准的特性，
 *  C标准没有规定#pragma后面应该写什么以及起什么作用，
 *  由编译器自己规定。有的编译器用#pragma定义一些特殊功能寄存器名，有的编译器用#pragma定位链接地址，本书不做深入讨论。
 *  如果编译器在代码中碰到不认识的#pragma指示则忽略它，
 *  例如gcc的#pragma指示都是#pragma GCC ...这种形式，
 *  用别的编译器编译则忽略这些指示。 
 */
#include<cstdio>
#include<assert.h>
extern "C" {
/* assert.h standard header */
#undef assert	/* remove existing definition */

#ifdef NDEBUG
	#define assert(test)	((void)0)
#else		/* NDEBUG not defined */
	void _Assert(char *);
	/* macros */
	#define _STR(x) _VAL(x)
	#define _VAL(x) #x
	#define assert(test)	((test) ? (void)0 \
		: _Assert(__FILE__ ":" _STR(__LINE__) " " #test))
#endif
}

int main()
{
    int x = 3;
    assert(x == 3);
    assert(x != 3);
    return 0;
}