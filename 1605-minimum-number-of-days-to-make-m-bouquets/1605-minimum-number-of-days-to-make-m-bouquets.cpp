class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // Check if it's even possible to create m bouquets with k flowers each
        long long int totalFlowers = static_cast<long long int>(m) * k;
        if (totalFlowers > n) {
            return -1;
        }

        // Find the maximum bloom day
        int maxBloomDay = INT_MIN;
        for (int bloom : bloomDay) {
            maxBloomDay = max(maxBloomDay, bloom);
        }

        // Binary search for the minimum waiting day
        int low = 1, high = maxBloomDay;
        // Search from 1 (inclusive) to avoid potential division by zero
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Check if it's possible to create m bouquets with k flowers each on the 'mid' day
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                // Update potential answer (minimum waiting day)
                high = mid - 1;
            } else {
                // If not possible, search in days with later blooms (higher values)
                low = mid + 1;
            }
        }
        return low; // Return the minimum waiting day (first day where bouquets can be made)
    }

private:
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int waitingDay) {
        int bouquets = 0, currentFlowers = 0;
        for (int bloom : bloomDay) {
            // If a flower blooms on or before the waiting day, add it to the current count
            if (bloom <= waitingDay) {
                currentFlowers++;
            } else {
                // If not, reset the current flower count
                currentFlowers = 0;
            }
            // If we have enough flowers for a bouquet, create one and reset the count
            if (currentFlowers == k) {
                bouquets++;
                currentFlowers = 0;
            }
            // Early return if we can already create m bouquets
            if (bouquets >= m) {
                return true;
            }
        }
        // Return false if we couldn't create m bouquets after iterating through all flowers
        return false;
    }
};