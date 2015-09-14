#ifndef LibraryLoaded_bdtz
#include "../bdtz.h"
#endif
#ifndef LibraryLoaded_stringUtils
#define LibraryLoaded_stringUtils
#endif
#ifndef stringUtils_hasFunctional_dscpy
namespace stringUtils{
#define stringUtils_hasFunctional_dscpy
	inline void dscpy(char* f,ul* t){
		while(*f) *t++=*f++;
	}
	inline void dscpy(ul* f,ul* t){
		while(*f) *t++=*f++;
	}
}
#endif
