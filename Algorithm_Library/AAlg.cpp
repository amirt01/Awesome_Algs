#include "pch.h"

// Purpose: Recursive template method for applying the merge sort algorithm.
// Pre: C-style array of template type T; constant size_t reference to the size
//      of the array
// Post: Sorted C-syle array in desending order
// Return: None

// Pseudocode:
// 1) If the size of the inputted array is < 2: return
// 2) Calculate the sizes of the left and right sub arrays
// 3) Dynamically allocate memory for the left and right arrays
// 4) Copy the left and right sub arrays from the input array into the new
//    array
// 5) Recursively call this function by passing in the new left and right
//    arrays and their sizes
// 6) Merge the left and right arrays into the real array in descending order
template<typename T>
void MergeSort(T array[], const size_t& size) {
	// If the size of the inputted array is < 2: return
	if (size < 2) { return; }

	// Calculate the sizes of the left and right sub arrays
	const size_t lSize = size / 2;      // half the size of the full array
	const size_t rSize = size - lSize;  // full array size minus the left
										// half incase of odd numbers

	// Dynamically allocate the left and right arrays
	std::unique_ptr<T[]> lArray(new T[lSize]);
	std::unique_ptr<T[]> rArray(new T[rSize]);

	// Copy left and right sub arrays of the input array into the new arrays
	std::copy(array, array + lSize, lArray.get());
	std::copy(array + lSize, array + size, rArray.get());

	// Sort the left and right arrays
	MergeSort(lArray.get(), lSize);
	MergeSort(rArray.get(), rSize);

	// Merge the left and right arrays to the input array using the comparison
	// function first > second in order to maintain a Desending order.
	std::merge(lArray.get(), lArray.get() + lSize,
		rArray.get(), rArray.get() + rSize,
		array, [](const auto& first, const auto& second) {
			return first > second;
		});
}