class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> rooms(n, 0);              // Count of meetings per room
        vector<long long> occupied(n, 0);     // When each room is free (time)

        for (auto& m : meetings) {
            int start = m[0], end = m[1];
            int duration = end - start;

            int selectedRoom = -1;

            // Try to find the first free room at current start time
            for (int i = 0; i < n; ++i) {
                if (occupied[i] <= start) {
                    selectedRoom = i;
                    occupied[i] = start + duration;
                    rooms[i]++;
                    break;
                }
            }

            // If no room was free, pick the one that gets free earliest
            if (selectedRoom == -1) {
                long long earliest = LLONG_MAX;
                for (int i = 0; i < n; ++i) {
                    if (occupied[i] < earliest) {
                        earliest = occupied[i];
                        selectedRoom = i;
                    }
                }
                occupied[selectedRoom] += duration;
                rooms[selectedRoom]++;
            }
        }

        // Find the room with max meetings
        int maxUsedRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (rooms[i] > rooms[maxUsedRoom])
                maxUsedRoom = i;
        }

        return maxUsedRoom;
    }
};
