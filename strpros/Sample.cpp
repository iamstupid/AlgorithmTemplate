#include "_SA.h"
#include "UT_str_cpy.h"
AT_SAC<> SABuilder;
using namespace fastIO;
using namespace stringUtils;
inline void rds(char* p,ul& l){l=0; while(*p=getc(),*p>'z' || *p<'a'); ++p; while(*p=getc(),++l,*p<='z' && *p>='a') ++p; *p=0; }
char s[100011];
ul v[300033],sa[300033],rk[100011],h[100011],l;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	rds(s,l);
	dscpy(s,v);
	SABuilder(v,sa,rk,h,l,256);
	fon(i,l) pru(sa[i]+1),putc(' ');
	putc('\n');
	fox(i,1,l) pru(h[i]),putc(' ');
	putc('\n',1);
	return 0;
}
