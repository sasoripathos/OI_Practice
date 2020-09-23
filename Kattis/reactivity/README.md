# [Reactivity Series](https://open.kattis.com/problems/reactivity)

Want to have a unique series containing all the metals, the lab results need to form a DAG which contains a unique path that go through all nodes. So DFS check cycle and record the longest path length staring from each node. If no cycle and there is a path with length n, there is a unique series.