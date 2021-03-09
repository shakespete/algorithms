#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

bool binarySearch(int target, const std::vector<int>& nums) {
    size_t floorIndex = 0;
    size_t ceilingIndex = nums.size();

    while (floorIndex < ceilingIndex) {
        size_t distance = ceilingIndex - floorIndex;
        size_t halfDistance = distance / 2;
        size_t guessIndex = floorIndex + halfDistance;

        int guessValue = nums[guessIndex];

        if (guessValue == target) {
            return true;
        }

        if (guessValue > target) {
            ceilingIndex = guessIndex;
        }
        else {
            floorIndex = guessIndex + 1;
        }
    }

    return false;
}

int main(int argc, const char * argv[]) {
    return 0;
}
