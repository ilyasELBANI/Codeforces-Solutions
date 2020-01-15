#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
#include <bitset>
using namespace std;
struct Slot {
	unsigned char m_day;
	int m_start;
	int m_teacher;
};

typedef struct Slot Slot;

#define MAXN 1000

struct AdjList {
	int m_count;
	int m_members[MAXN];
};

typedef struct AdjList AdjList;

int S, N1, N2, K1, K2, D1, D2, T1, T2, N, C;

Slot FCSlots [MAXN], ICSlots[MAXN];

AdjList neighbours[MAXN * 2 + 2];
int cap[MAXN * 2 + 2][MAXN * 2 + 2];
int rescap[MAXN * 2 + 2][MAXN * 2 + 2];
int conflicts[MAXN][MAXN];

unsigned char masks[6][20] = {{1, 2, 4, 8, 16, 32},
	{3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48},
	{7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56},
	{15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58, 60},
	{31, 47, 55, 59, 61, 62},
	{63}
};
int countmasks[] = {6, 15, 20, 15, 6, 1};

int queue[MAXN * 2 + 2];
int parent[MAXN * 2 + 2];

unsigned char glomask;

void readData()
{
	int day, hour, min, c, i, j;
	size_t ret;

	glomask = 0;

	ret = scanf("%d%d%d%d%d", &S, &N1, &K1, &D1, &T1);
	D1 *= 60;
	for (i = 0; i < N1; ++i) {
		ret = scanf("%d%d%d%d", &day, &hour, &min, &FCSlots[i].m_teacher);
		FCSlots[i].m_day =  ((unsigned char)1) << (day - 1);
		FCSlots[i].m_start = 60 * hour + min;
		glomask |= FCSlots[i].m_day;
	}

	ret = scanf("%d%d%d%d", &N2, &K2, &D2, &T2);
	D2 *= 60;
	for (i = 0; i < N2; ++i) {
		ret = scanf("%d%d%d%d", &day, &hour, &min, &ICSlots[i].m_teacher);
		ICSlots[i].m_day = ((unsigned char)1) << (day - 1);
		ICSlots[i].m_start = 60 * hour + min;
		glomask |= ICSlots[i].m_day;
	}

	for (i = 0; i < T1; ++i)
		for (j = 0; j < T2; ++j)
			conflicts[i][j] = 0;

	scanf("%d", &C);
	for (c = 0; c < C; ++c) {
		scanf("%d%d", &i, &j);
		conflicts[i][j] = 1;
	}

	(void)ret;
}

int overlaps (Slot fcslot, Slot icslot)
{
	static const int delta = 5;
	if (conflicts[fcslot.m_teacher][icslot.m_teacher]) {
		return 1;
	}

	if (icslot.m_day != fcslot.m_day)
		return 0;
	if (icslot.m_start >= fcslot.m_start + D1 + delta || fcslot.m_start >= icslot.m_start + D2 + delta)
		return 0;

	return 1;
}

void buildGraph()
{
	int i, j;
	N = N1 + N2 + 2; //add source and sink

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			cap[i][j] = 0;

	for (i = 0; i < N; ++i)
		neighbours[i].m_count = 0;

	//source
	neighbours [0].m_count = N1;
	for (i = 0; i < N1; ++i) {
		neighbours[0].m_members[i] = i + 1;
		cap[0][i + 1] = K1;
	}

	//others
	for (i = 0; i < N1; ++i) {
		for (j = 0; j < N2; ++j) {

			if (!overlaps(FCSlots[i], ICSlots[j])) {

				neighbours[i + 1].m_members[neighbours[i + 1].m_count] = j + N1 + 1;
				neighbours[i + 1].m_count++;

				neighbours[j + N1 + 1].m_members[neighbours[j + N1 + 1].m_count] = i + 1;
				neighbours[j + N1 + 1].m_count++;

				cap[i + 1][j + N1 + 1] = K1;
			}
		}
	}

	for (j = 0; j < N2; ++j) {
		cap[j + N1 + 1][N - 1] = K2;
	}


}

int getBitCount(unsigned char mask)
{
	unsigned char crt = 1;
	int count = 0, i;
	for (i = 0; i < 6; ++i) {
		if (mask & crt)
			count++;
		crt <<= 1;
	}
	return count;
}


int FlowWithMask(unsigned char mask)
{

	int first, last, crtnode, nei, flow = 0, min, i, j;

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			rescap[i][j] = cap[i][j];


	while (1)
	{
		first = last = 0;
		memset(parent, -1, N * sizeof(int));

		queue[first] = 0;

		while (first <= last) {
			crtnode = queue[first];

			if (rescap[crtnode][N - 1] > 0) {
				parent[N - 1] = crtnode;
				break;
			}

			for (j = 0; j < neighbours[crtnode].m_count; ++j) {
				nei = neighbours[crtnode].m_members[j];

				//discard unsuitable nodes
				if (parent[nei] != -1) continue;
				if (rescap[crtnode][nei] == 0) continue;
				if (nei <= N1 && !(FCSlots[nei - 1].m_day & mask)) continue;
				if (nei > N1 && !(ICSlots[nei - 1 - N1].m_day & mask)) continue;

				last++;
				queue[last] = nei;
				parent[nei] = crtnode;
			}
			first++;
		}

		if (parent[N - 1] == -1) {
			return 0;
		}

		crtnode = N - 1;
		min = S - flow;
		while (crtnode != 0) {
			nei = parent[crtnode];
			if (rescap[nei][crtnode] < min)
				min = rescap[nei][crtnode];
			crtnode = nei;
		}

		flow += min;

		crtnode = N - 1;
		while (crtnode != 0) {
			nei = parent[crtnode];
			rescap[nei][crtnode] -= min;
			rescap[crtnode][nei] += min;
			crtnode = nei;
		}
		cout << "+>" << min << endl;
		if (flow == S)
			return 1;
	}
}

void MaxFlow()
{
	int i, j;

	for (i = 0; i < 6; ++i)
		for (j = 0; j < countmasks[i]; ++j)
		{
			if ((glomask & masks[i][j]) == masks[i][j] && FlowWithMask(masks[i][j])) {
				printf("%d\n", i + 1);
			}

		}
	printf("0\n");
}


int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	readData();
	buildGraph();
	MaxFlow();

	return 0;
}

