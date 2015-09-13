#include <cstdio>
#include <malloc.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#define fon(i,s)    for(int i=0;i<s; ++i)
#define fone(i,s)   for(int i=0;i<=s;++i)
#define fox(i,f,t)  for(int i=f;i<t; ++i)
#define foxe(i,f,t) for(int i=f;i<=t;++i)
#define fdn(i,s)    for(int i=s;i;   --i)
#define fdne(i,s)   for(int i=s;~i;  --i)
#define fdx(i,f,t)  for(int i=f;i>t; --i)
#define fdxe(i,f,t) for(int i=f;i>=t;--i)
#define pi 3.14159265358979323846264
typedef long long ll;
typedef unsigned long long ull;
typedef int il;
typedef unsigned int ul;
namespace fastIO{
	inline char getc(){ static char buf[qbs];static int q=qbs; if(qbs==q) fread(buf,qbs,1,stdin),q=0; return buf[q++]; }
	inline void rdu(ul& a){ a=0; char p=getc(); while(p>'9' || p<'0') p=getc(); while(p<='9'&&p>='0') a=a*10+p-'0',p=getc(); }
	inline void rdu(ull& a){ a=0; char p=getc(); while(p>'9' || p<'0') p=getc(); while(p<='9'&&p>='0') a=a*10+p-'0',p=getc(); }
	template<class T> inline void rdu(T& a,T& b){ rdu(a),rdu(b); }
	template<class T> inline void rdu(T& a,T& b,T& c){ rdu(a,b),rdu(c); }
	template<class T> inline void rdu(T& a,T& b,T& c,T& d){ rdu(a,b),rdu(c,d);}
	inline void putc(char p,bool e=0){ static char buf[qbs+10];static int q=0; if(~p) buf[q++]=p; if(e&&q || qbs==q) fwrite(buf,q,1,stdout),q=0; }
	inline void pru(ul a){if(a>=10) pru(a/10); putc(a%10+'0');}
	inline void pru(ull a){if(a>=10) pru(a/10); putc(a%10+'0');}
	inline void printstr(char* p){while(*p)putc(*p++);}
}
namespace basicDCMath{
	inline ull ladd(ull a,ull b,ull p){ return a+=b,a=a-ifnext(a>b,p),a-ifnext(a>p,p); }
	inline ull lmul(ull a,ull b,ull p){ return (a*b-((ull)((long double)a*b/p)*p)); }
	inline ull lpow(ull a,ull b,ull p){ ull k=1; for(;b;b>>=1,a=lmul(a,a,p)) if(b&1) k=lmul(k,a,p); return k; }
	inline ull lfpm(ull a,ull b,ull p){ ull k=1; for(;b;b>>=1,a=a*a%p) if(b&1) k=k*a%p; return k; }
	inline ul lmul(ul a,ul b,ul p){ return (ull)a*b%p; }
	inline ul lfpm(ul a,ul b,ul p){ ul k=1;for(;b;b>>=1,a=lmul(a,a,p)) if(b&1) k=lmul(k,a,p); return k;}
	inline void linv(ul* q,ul p,ul m){ q[1]=1; foxe(i,2,p) q[i]=((ull)(m-m/i)*q[m%i])%m; }
}

