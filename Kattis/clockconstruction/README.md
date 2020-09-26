# [Clock Construction](https://open.kattis.com/problems/clockconstruction)

Observation 1: for each image, we know the pixels in different status cannot in the same group.

Observation 2: if in all images, pixel A and B can be in the same group and pixel B and C can be in the same group. Then to minimize the group numbers. We can put A, B, C in the same group.

So for the first image, I can divide pixels into at most 2 groups. Then when I see a new image, I will re-evaluate all the existing groups and further divide the pixels in to different groups based on their status in the new image. Since the total size of all groups are H * W, the time complexity is O(H * W * N) assuming the set operations like insert and remove are constant time (since in that case, all the set operations needed for a new image is about O(H * W)).