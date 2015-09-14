#define _SA_H__release
#ifdef _SA_H__release
#ifndef Any_str_SA
#include "SA_DC3.h"
#endif
#else
#ifndef Any_str_SA
#include "SA_RD.h"
#endif
#endif
#define AT_SAC SuffixArray :: Any_str_SA
