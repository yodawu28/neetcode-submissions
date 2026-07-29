"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals = sorted(intervals, key=lambda item: item.start)

        rooms = []

        for interval in intervals:
            if not len(rooms):
                rooms.append(interval)
            else:
                flag = True
                for room in rooms:
                    if interval.start >= room.end:
                        room.start = interval.start
                        room.end = interval.end
                        flag = False
                        break

                if flag:
                    rooms.append(interval)

        return len(rooms)

