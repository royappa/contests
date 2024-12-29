#include <cstdio>

int debug = 0;
void mysort(int *a)
{
	for (int i = 1; i < 5; i++)
	{
		int j = i - 1;
		int tmp = a[i];
		while (j >= 0 && a[j] > tmp)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}

char *getkind(int *ranks, int *aranks, int *suits)
{
	if (suits[0] == suits[4])
	{
//for (int c = 0; c < 5; c++) printf("%d ", aranks[c]); printf("\n");
		if (aranks[0] == 10 && aranks[1] == 11 && aranks[2] == 12 && aranks[3] == 13 && aranks[4] == 14)
		{
			return "royal flush";
		}
		else if (ranks[0]+4 == ranks[4] || aranks[0]+4 == aranks[4])
		{
			return "straight flush";
		}
	}
	if (ranks[0] == ranks[3] || ranks[1] == ranks[4])
	{
		return "four of a kind";
	}
	if ((ranks[0] == ranks[2] && ranks[3] == ranks[4]) || (ranks[0] == ranks[1] && ranks[2] == ranks[4]))
	{
		return "full house";
	}
	if (suits[0] == suits[4])
	{
		return "flush";
	}
	if (ranks[0]+4 == ranks[4] || aranks[0]+4 == aranks[4])
	{
		return "straight";
	}
	if (ranks[0] == ranks[2] || ranks[1] == ranks[3] || ranks[2] == ranks[4])
	{
		return "three of a kind";
	}
	if ((ranks[0] == ranks[1] && ranks[2] == ranks[3]) ||
		(ranks[1] == ranks[2] && ranks[3] == ranks[4]) ||
		(ranks[0] == ranks[1] && ranks[3] == ranks[4]))
	{
		return "two pairs";
	}
	if (ranks[0] == ranks[1] || ranks[1] == ranks[2] || ranks[2] == ranks[3] || ranks[3] == ranks[4])
	{
		return "pair";
	}
	return "high card";
}

int main()
{
	char buf[1024];
	int hand[5][2];
	int ranks[5], aranks[5], suits[5];

	int t;
	scanf("%d", &t);
	// S=0,H=1,D=2,C=3
	int suit_map[] = {'a','b',3,2,'e','f','g',1,'i','j','k','l','m','n','o','p','q','r',0};
	// A=1,K=13,Q=12,J=11,T=10
	int rank_map[] = {1,'b','c','d','e','f','g','h','i',11,13,'l','m','n','o','p',12,'r','s',10};

	while (t-- > 0)
	{
		for (int c = 0; c < 5; c++)
		{
			char card[3];
			scanf("%s", card);
			char rr = card[0], ss = card[1];
			int suit = suit_map[int(ss-'A')];
			int rank = (rr >= '0' && rr <= '9') ? (rr-'0') : rank_map[int(rr-'A')];
			hand[c][0] = rank;
			ranks[c] = rank;
			aranks[c] = rank == 1 ? 14 : rank;
			hand[c][1] = suit;
			suits[c] = suit;
		}
		if (debug)
		{
			for (int c = 0; c < 5; c++)
			{
				printf("%2d %2d\n", hand[c][0], hand[c][1]);
			}
			printf("***\n");
		}
		char *res = NULL;

		mysort(ranks);
		mysort(aranks);
		mysort(suits);
		printf("%s\n", getkind(ranks, aranks, suits));


	}
	return 0;
}
