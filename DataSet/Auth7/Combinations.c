#include <stdio.h>
 
// Type marker stick: using bits to indicate what's chosen.  The stick can't
// handle more than 32 items, but the idea is there; at worst, use array instead


typedef unsigned long marker;
marker one = 1;
 
void comb(int pool, int need, marker chosen, int at)
{
		if (pool < need + at) return; // not enough bits left
 
	if (!need) {
			//got all we needed; print the thing.  if other actions are
			//desired, we could have passed in a callback function.
		for (at = 0; at < pool; at++)
			if (chosen & (one << at)) printf("%d ", at);
		printf("\n");
		return;
	}
	// if we choose the current item, "or" (|) the bit to mark it so.
	comb(pool, need - 1, chosen | (one << at), at + 1);
	comb(pool, need, chosen, at + 1);  // or don't choose it, go to next
}

void comb1(int *pool, int atPool, int n, int k, int *selected, int atSelected) {
		if (n <= atSelected)
				return;
		if (atSelected == k) {
				for (atSelected = 0 ; atSelected < k ; atSelected++)
						printf("%d, ", selected[atSelected]);
				printf("\n");
				return;
		}

		selected[atSelected] = pool[atPool];
		comb1(pool, atPool+1, n, k, selected, atSelected+1);
		comb1(pool, atPool+1, n, k, selected, atSelected);
} 

int main()
{
	comb(5, 3, 0, 0);
	return 0;
}

/*

#include <stdio.h>
 
void comb(int m, int n, unsigned char *c)
{
	int i;
	for (i = 0; i < n; i++) c[i] = n - i;
 
	while (1) {
		for (i = n; i--;)
			printf("%d%c", c[i], i ? ' ': '\n');
 
			// this check is not strictly necessary, but if m is not close to n,
		   //it makes the whole thing quite a bit faster
		if (c[i]++ < m) continue;
 
		for (i = 0; c[i] >= m - i;) if (++i >= n) return;
		for (c[i]++; i; i--) c[i-1] = c[i] + 1;
	}
}
 
int main()
{
	unsigned char buf[100];
	comb(5, 3, buf);
	return 0;
}
*/
