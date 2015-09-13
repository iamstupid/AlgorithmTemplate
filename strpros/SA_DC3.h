#ifdef ifnext
namespace SuffixArray{
	template<ul maxsize=100011> struct DC3{
	private:
		inline ul max(ul a,ul b){
			return a>b?a:b;
		}
		#define N maxsize
		char s[N*3];
		ul v[N*3],qa[N*3],qb[N*3],sav[N*3],sa[N*3];
		inline bool cmp1(ul* v,ul a,ul b){ return v[a]==v[b] && v[a+1]==v[b+1] && v[a+2]==v[b+2]; }
		inline bool cmp21(ul* v,ul a,ul b){ return v[a]<v[b] || ( v[a]==v[b] && sav[a+1]<sav[b+1] ); }
		inline bool cmp2(ul d,ul* v,ul a,ul b){ if(d==1) return cmp21(v,a,b); else return  v[a]<v[b] || ( v[a]==v[b] && cmp21(v,a+1,b+1) );}
		inline void radixsort(ul* v,ul* q,ul* sa,ul n,ul m){
			static int c[N];
			fon(i,m) c[i]=0;
			fon(i,n) ++c[v[q[i]]];
			fox(i,1,m) c[i]+=c[i-1];
			fdne(i,n-1) sa[--c[v[q[i]]]]=q[i];
		}
		
		#define f(x) (qx=(x)/3,qxa=qx*3,(x)-qxa==1?qx:qx+na)
		#define rf(x) ((x)<na?3*(x)+1:3*((x)-na)+2)
		void dc3(ul* v,ul* sa,ul n,ul m){
			ul i,j,k,*nv=v+n+3,*nsa=sa+n+3,na=(n+2)/3,nbc=0,lab;
			ul qx,qxa;
			v[n]=v[n+1]=v[n+2]=0;
			fon(i,n) if(i%3) qa[nbc++]=i; if(n%3==1) qa[nbc++]=n;
			radixsort(v+2,qa,qb,nbc,m);
			radixsort(v+1,qb,qa,nbc,m);
			radixsort(v  ,qa,qb,nbc,m);
			for(i=lab=0;i<nbc;++lab,i=j+1){
				for(j=i;j<nbc-1 && cmp1(v,qb[j],qb[j+1]);++j);
				for(k=i;k<=j;++k) nv[f(qb[k])]=lab;
			}
			if(lab<nbc) dc3(nv,nsa,nbc,lab); else fon(i,nbc) nsa[nv[i]]=i;
			for(i=j=0;i<nbc;++i) if(nsa[i]<na) qb[j++]=3*nsa[i];
			radixsort(v  ,qb,qa,na ,m);
			fon(i,nbc) sav[qb[i]=rf(nsa[i])]=i;
			for(i=lab=0,j=(n%3==1);i<na && j<nbc;){
				sa[lab++]=cmp2(qb[j]%3,v,qa[i],qb[j])?qa[i++]:qb[j++];
			}
			while(i<na)   sa[lab++]=qa[i++];
			while(j<nbc)  sa[lab++]=qb[j++];
		}
		ul rk[N],h[N];
		inline void getRankHeight(ul n){
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
	public:
		inline void operator()(ul* v,ul* sa,ul n,ul m){
		/**
		 * @param v    original string (can be s string of numbers)
		 * @param sa   computed suffix array
		 * @param n    length of v
		 * @param m    charset size
		 */
			dc3(v,sa,n,m);
		}
	}
}
#endif
