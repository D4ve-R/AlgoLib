#ifndef SORTING_H
#define SORTING_H

namespace AlgoLib
{
	namespace Sorting
	{
		template <typename Cont>
		int quickSortHelper(Cont& a, int left, int right)
		{
			auto pivot = a[right];
			int i = (left - 1);
			for (int j = left; j <= right - 1; ++j)
			{
				if (a[j] <= pivot)
				{
					++i;
					std::swap(a[i], a[j]);
				}
			}
			std::swap(a[i + 1], a[right]);
			return (i + 1);
		}

		template <typename Cont>
		void QuickSort(Cont& arr, int left, int right)
		{
			if (left < right)
			{
				int pivot = quickSortHelper(arr, left, right);
				QuickSort(arr, left, pivot - 1);
				QuickSort(arr, pivot + 1, right);
			}
		}

		template <typename Cont>
		void Merge(Cont& a, Cont& b, int low, int middle, int high)
		{
			int leftIter, rightIter, tmp;
			leftIter = tmp = low;
			rightIter = middle + 1;
			while (leftIter <= middle && rightIter <= high)
			{
				if (a[leftIter] <= a[rightIter])
				{
					b[tmp] = a[leftIter];
					++leftIter;
				}
				else
				{
					b[tmp] = a[rightIter];
					++rightIter;
				}
				++tmp;
			}
			while (leftIter <= middle)
			{
				b[tmp] = a[leftIter];
				++tmp;
				++leftIter;
			}
			while (rightIter <= high)
			{
				b[tmp] = a[rightIter];
				++tmp;
				++rightIter;
			}
			for (int i = low; i < tmp; ++i)
			{
				a[i] = b[i];
			}
		}

		template <typename Cont>
		void MergeSort(Cont& a, Cont& b, int low, int high)
		{
			if (low < high)
			{
				int middle = (low + high) / 2;
				MergeSort(a, b, low, middle);
				MergeSort(a, b, middle + 1, high);
				Merge(a, b, low, middle, high);
			}
		}

		template <typename Cont>
		void maxHeap(Cont& a, int n, int rootIdx)
		{
			int max = rootIdx;
			int leftIdx = 2 * rootIdx + 1;
			int rightIdx = 2 * rootIdx + 2;
			if (rightIdx < n && a[max] < a[rightIdx])
				max = rightIdx;
			if (leftIdx < n && a[max] < a[leftIdx])
				max = leftIdx;
			if (max != rootIdx)
			{
				std::swap(a[rootIdx], a[max]);
				maxHeap(a, n, max);
			}
		}

		template <typename Cont>
		void HeapSort(Cont& a, int n)
		{
			for (int i = n / 2 - 1; i >= 0; --i)
				maxHeap(a, n, i);
			for (int i = n - 1; i > 0; --i)
			{
				std::swap(a[0], a[i]);
				maxHeap(a, i, 0);
			}
		}
	}
}

#endif