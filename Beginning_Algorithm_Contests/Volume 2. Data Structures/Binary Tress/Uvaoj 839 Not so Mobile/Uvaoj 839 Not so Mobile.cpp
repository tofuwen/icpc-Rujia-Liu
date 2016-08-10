#include <cstdio>
using namespace std;

struct gadget{
	int wl, dl, wr, dr;
	gadget* lch;
	gadget* rch;
	gadget(int wl, int dl, int wr, int dr):wl(wl),dl(dl),wr(wr),dr(dr){}
};

gadget* makeGadget(int& x){
	int wl, dl, wr, dr;
	scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
	gadget* root = new gadget(wl, dl, wr, dr);
	root->lch = root->rch = NULL;
	if(wl == 0){
		int xl;
		root->lch = makeGadget(xl);
		root->wl = xl;
	}
	if(wr == 0){
		int xr;
		root->rch = makeGadget(xr);
		root->wr = xr;
	}
	x = root->wl + root->wr;
	return root;
}

bool check(gadget* root){
	// if(root == NULL)
	// 	return true;
	if(root->wl*root->dl != root->wr*root->dr)
		return false;
	bool ok1 = true, ok2 = true;
	if(root->lch)
		ok1 = check(root->lch);
	if(root->rch)
		ok2 = check(root->rch);
	return ok1 && ok2;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d", &T);
	for(int cc=0;cc<T;cc++){
		if(cc)
			printf("\n");
		int x;
		gadget* root = makeGadget(x);
		if(check(root))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}