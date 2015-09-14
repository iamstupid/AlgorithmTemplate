#ifndef LibraryLoaded_bdtz
#include "../bdtz.h"
#endif
#ifndef stringUtils_hasFunctional_dscpy
#include "UT_str_cpy.h"
#endif
#ifndef LibraryLoaded_RD
#define LibraryLoaded_RD
#ifndef Any_str_SA
#define Any_str_SA RD
#endif
namespace SuffixArray{
	template<ul maxsize=100011,ul maxcharsetsize=1024> struct RD{
	private:
		inline ul max(ul a,ul b){
			return (int)a>(int)b?a:b;
		}
		#define N maxsize
		ul qx[N];
		inline void radixsort(ul* v,ul* q,ul* sa,ul n,ul m){
			static int c[N];
			fon(i,m) c[i]=0;
			fon(i,n) ++c[v[q[i]]];
			fox(i,1,m) c[i]+=c[i-1];
			fdne(i,n-1) sa[--c[v[q[i]]]]=q[i];
		}
		void rd(ul* v,ul* sa,ul n,ul m){
			ul *x=v,*q=qx;
			radixsort(x,q,sa,n,m);
			for(ul k=1;k<=n;k<<=1){
				register ul p=0;
				fdxe(i,n-1,n-k) q[p++]=i;
				fon(i,n) if(sa[i]>=k) q[p++]=sa[i]-k;
				radixsort(x,q,sa,n,m);
				std::swap(x,q);
				p=1,x[sa[0]]=0;
				fox(i,1,n) x[sa[i]]=((q[sa[i-1]]==q[sa[i]])&&(q[sa[i]+k]==q[sa[i-1]+k]))?p-1:p++;
				if(p>=n) break;
				m = p;
			}
		}
		inline void getRankHeight(ul n,ul* v,ul* sa,ul* rk,ul* h){
			register ul j;
			fon(i,n) rk[sa[i]]=i;
			fon(i,n){
				if(rk[i]){
					j=0;if(i) j=max(0,h[rk[i-1]]-1);
					while(i+j<n && sa[rk[i]-1]+j<n && v[i+j]==v[sa[rk[i]-1]+j])++j;
					h[rk[i]]=j;
				}
			}
		}
		inline void clear(){
			fon(i,N) qx[i]=i;
		}
		ul kq[N];
	public:
		inline void operator()(ul* v,ul* sa,ul n,ul m){
		/**
		 * @param v    original string (can be s string of numbers)
		 * @param sa   computed suffix array triple space required
		 * [ optional
		 * @param rk   rank array
		 * @param h    height array
		 * ]
		 * @param n    length of v
		 * @param m    charset size
		 */
			if(m>maxcharsetsize) return;
			clear();
			stringUtils::dscpy(v,kq);
			rd(kq,sa,n,m);
		}
		inline void operator()(ul* v,ul* sa,ul* rk,ul* h,ul n,ul m){
			if(m>maxcharsetsize) return;
			clear();
			stringUtils::dscpy(v,kq);
			rd(kq,sa,n,m);
			getRankHeight(n,v,sa,rk,h);
		}
	};
}
#endif
