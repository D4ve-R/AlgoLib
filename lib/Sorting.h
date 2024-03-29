#ifndef SORTING_H
#define SORTING_H

#include <cstddef>

namespace AlgoLib
{
	namespace Sorting
	{
		template <typename Cont>
		int quickSortHelper(Cont& a, int left, int right)
		{
			auto pivot = a[right];
			int i = (left - 1);
			for (unsigned int j = left; j <= right - 1; ++j)
			{
				if (a[j] <= pivot)
					std::swap(a[++i], a[j]);
			}
			std::swap(a[i + 1], a[right]);
			return (i + 1);
		}

		template <typename Cont>
		void quickSort(Cont& a, int left, int right)
		{
			if (left < right)
			{
				int pivot = quickSortHelper(arr, left, right);
				quickSort(a, left, pivot - 1);
				quickSort(a, pivot + 1, right);
			}
		}

		template <typename Cont>
		void merge(Cont& a, Cont& b, unsigned int low, unsigned int middle, unsigned int high)
		{
			unsigned int leftIter, rightIter, tmp;
			leftIter = tmp = low;
			rightIter = middle + 1;
			while (leftIter <= middle && rightIter <= high)
			{
				if (a[leftIter] <= a[rightIter])
					b[tmp++] = a[leftIter++];
				else
					b[tmp++] = a[rightIter++];
			}
			while (leftIter <= middle)
			{
				b[tmp++] = a[leftIter++];
			}
			while (rightIter <= high)
			{
				b[tmp++] = a[rightIter++];
			}
		}

		template <typename Cont>
		void mergeSort(Cont& a, Cont& b, unsigned int low, unsigned int high)
		{
			if (low < high)
			{
				unsigned int middle = (low + high) / 2;
				mergeSort(a, b, low, middle);
				mergeSort(a, b, middle + 1, high);
				merge(a, b, low, middle, high);
			}
		}

		template <typename Cont>
		void maxHeap(Cont& a, std::size_t n, unsigned int rootIdx)
		{
			unsigned int max = rootIdx;
			unsigned int leftIdx = 2 * rootIdx + 1;
			unsigned int rightIdx = 2 * rootIdx + 2;
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
		void heapSort(Cont& a, std::size_t n)
		{
			for (int i = n / 2 - 1; i >= 0; --i)
				maxHeap(a, n, i);
			for (int i = n - 1; i > 0; --i)
			{
				std::swap(a[0], a[i]);
				maxHeap(a, i, 0);
			}
		}

		template <typename Cont>
		void shellSort(Cont& a, std::size_t n)
		{
			int h = 1;
			while (h < n)
			{
				// Hibbard
				h = 2 * h + 1;
			}
			for (int gap = h; gap > 0; gap = (gap - 1)/2)
			{
				for (int i = gap; i < n; ++i)
				{
					auto tmp = a[i];
					int j = i;
					for (; j >= gap && tmp < a[j - gap]; j -= gap)
					{
						a[j] = a[j - gap];
					}
					a[j] = tmp;
				}
			}
		} 
	}
}

#endif
