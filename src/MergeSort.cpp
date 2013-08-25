#include "MergeSort.h"

void MergeSort::msort(VerboseVector& list)
{
	msort( list, 0, list.size()-1 );
}

void MergeSort::msort(VerboseVector& list, int l, int r)
{
	if (l == r) return; // 1 element? sorted!

	int mid = (l+r)/2;

	// sort left
	msort( list, l, mid );
	// sort right
	msort( list, mid+1, r );


	// merge - first copy the parts
	std::vector<int> left;
	std::vector<int> right;

	for (int i = l; i <= mid; i++)
	{
		left.push_back( list[i] );
	}
	for (int i = mid+1; i <=r; i++)
	{
		right.push_back( list[i] );
	}

	int i = l;
	int rc = right.size();
	int lc = left.size();

	r = l = 0;
	while (r < rc && l < lc)
	{
		if (right[r] < left[l])
		{
			list[i++] = right[r++];
		}
		else
		{
			list[i++] = left[l++];
		}
	}

	while (r < rc) list[i++] = right[r++];
	while (l < lc) list[i++] = left[l++];

	list[list.size()-1];
}
