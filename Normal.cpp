#include<QtGlobal>
#include<QTime>
int nrand()
{
	int ans=0;
	for(int i=0;i<12;i++)
		ans+=qrand();
	ans-=6;
	ans=qAbs(ans);
	return ans;
}
