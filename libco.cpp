#include "vmsys.h"
#if defined(__clang__)
  #pragma clang diagnostic ignored "-Wparentheses"

  /* placing code in section(text) does not mark it executable with Clang. */
  #undef  LIBCO_MPROTECT
  #define LIBCO_MPROTECT
#endif

#if defined(__clang__) || defined(__GNUC__)
  #if defined(__i386__)
    #include "libco_archs/x86.c"
  #elif defined(__amd64__)
    #include "libco_archs/amd64.c"
  #elif defined(__arm__)
    #include "libco_archs/arm.c"
  #elif defined(__aarch64__)
    #include "libco_archs/aarch64.c"
  #elif defined(__powerpc64__) && defined(_CALL_ELF) && _CALL_ELF == 2
    #include "libco_archs/ppc64v2.c"
  #elif defined(_ARCH_PPC) && !defined(__LITTLE_ENDIAN__)
    #include "libco_archs/ppc.c"
  #elif defined(_WIN32)
    #include "libco_archs/fiber.c"
  #else
    #include "libco_archs/sjlj.c"
  #endif
#elif defined(_MSC_VER)
  #if defined(_M_IX86)
    #include "libco_archs/x86.c"
  #elif defined(_M_AMD64)
    #include "libco_archs/amd64.c"
  #else
    #include "libco_archs/fiber.c"
  #endif
#else
  #error "libco: unsupported processor, compiler or operating system"
#endif
