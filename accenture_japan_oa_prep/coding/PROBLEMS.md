# Coding Practice Set: 12 OA-Style Problems

These are original problems written to match the patterns reported in past Accenture Japan OAs:
long, story-style statements, grid and simulation problems, and standard DSA at easy to medium-hard level.
They are **not** leaked questions. Nobody can reliably tell you this year's paper.

**How to use this set**

1. Give yourself **35 minutes per problem**. Read the statement once, slowly, and write down the rules before you code.
2. Code it in your OA language. Test it on the sample (`tests/<name>.in` → `tests/<name>.ans`).
3. Only then open the hints, and after that `solutions/<name>.cpp`.
4. Check all solutions at once with `bash run_samples.sh`.
   For a few problems, `stress/stress_test.py` compares the fast solution with a slow brute-force version on random inputs.
   It is worth learning this technique: a brute force plus a random generator finds the bugs that samples miss.

| # | Problem | Pattern | Level |
|---|---------|---------|-------|
| 01 | Fit the Part | Grid + rotation + removing duplicates | Hard (closest to the reported "fit the shape" question) |
| 02 | Outage Spread | Multi-source BFS | Easy–Medium |
| 03 | Help Desk Simulation | Event simulation + heaps | Medium–Hard (wordy) |
| 04 | Enclosed Lakes | Connected components | Easy–Medium |
| 05 | K Distinct | Sliding window | Easy–Medium |
| 06 | Subarray Sum K | Prefix sum + hash map | Medium |
| 07 | Meeting Rooms | Sorting + sweep line | Easy–Medium |
| 08 | Ship Within D Days | Binary search on the answer | Medium |
| 09 | Grid Paths | 2-D DP | Easy |
| 10 | Course Order | Topological sort | Medium |
| 11 | Session Log | Parsing + per-user state | Medium (wordy) |
| 12 | Cheapest Route | Dijkstra + path reconstruction | Medium |

---

## P01: Fit the Part

A factory floor is an `R × C` grid. `.` is a free cell and `#` is a cell blocked by a machine.
A new part must be placed on the floor. Its shape is given as an `h × w` pattern where `*` is part of the part and `.` is empty.
The pattern may have empty rows or columns around the shape.

The part may be **rotated by 0°, 90°, 180° or 270°** (it cannot be flipped). A placement is valid if every `*` cell lands on a free cell inside the floor.

Print the number of **distinct placements**. Two placements are the same if they cover exactly the same set of floor cells.
For example, a 2×2 square looks the same in all four rotations, so it must not be counted four times.

**Input:** `R C`, then `R` rows, then `h w`, then `h` rows of the pattern (at least one `*`).
**Constraints:** `1 ≤ R, C ≤ 50`, `1 ≤ h, w ≤ 10`.

```
Input                 Output
4 5                   30
.....
.#...
.....
...#.
3 3
...
**.
.*.
```

<details><summary>Hints</summary>

- Turn the pattern into a list of `(row, col)` cells. Then **normalize** it: subtract the minimum row and minimum column so the shape starts at (0,0). This also removes the empty border.
- Rotate 90° clockwise with `(r, c) → (c, −r)`, then normalize again.
- Put the 4 normalized rotations into a `set` so that symmetric shapes are counted only once.
- Try every top-left offset for every distinct rotation: `O(4 · R · C · cells)`.
- **Traps:** empty border rows in the pattern, symmetric shapes, and going outside the grid.
</details>

---

## P02: Outage Spread

A data centre is an `R × C` grid: `S` is a healthy server, `X` is a failed server, `#` is an empty rack.
Every minute, each failed server makes all healthy servers next to it (up, down, left, right) fail.
Print the number of minutes until no healthy server is left, or `-1` if some server never fails. If there are no healthy servers at the start, print `0`.

**Constraints:** `1 ≤ R, C ≤ 1000`.

```
Input        Output
3 4          2
XSS#
S#SS
SSSX
```

<details><summary>Hints</summary>

Put **all** `X` cells into the BFS queue at distance 0 before you start. That is multi-source BFS.
The answer is the largest distance. If any `S` is never reached, print −1. Running a separate BFS from each `X` is too slow (TLE).
</details>

---

## P03: Help Desk Simulation

A help desk has `k` counters numbered `1..k` and serves `n` customers. Customer `i` arrives at time `a_i`, needs `d_i` minutes, and has a flag `v_i` (1 = VIP).

Rules:
- Whenever a counter is free and someone is waiting, the counter serves a waiting customer right away.
- The customer chosen is a VIP over a non-VIP. Among those, the one who arrived first. If still tied, the smaller input index.
- If several counters are free at the same moment, the **lowest-numbered** counter takes the next customer first.
- A counter that becomes free at time `t` can serve a customer who arrives at time `t`.

For every customer, in input order, print the counter that served them and the time their service finished.

**Constraints:** `1 ≤ n ≤ 2·10^5`, `1 ≤ k ≤ 10^5`, `0 ≤ a_i ≤ 10^9`, `1 ≤ d_i ≤ 10^9`.

```
Input        Output
5 2          1 5
0 5 0        2 4
1 3 0        2 6
2 2 1        1 9
2 4 0        2 7
6 1 1
```

<details><summary>Hints</summary>

- Keep three structures: a heap of busy counters `(free_time, id)`, an ordered set of free counter ids, and a heap of waiting customers ordered by `(VIP first, arrival, index)`.
- Main loop at time `t`: move counters whose free time is ≤ t into the free set, move customers whose arrival is ≤ t into the waiting heap, then pair them while both are non-empty.
- Then **jump** `t` to the next event (the next counter free time or the next arrival). Never step one minute at a time, because times go up to 10^9.
- Finish times can reach 2·10^9, so use `long long`.
</details>

---

## P04: Enclosed Lakes

A map is an `R × C` grid of `W` (water) and `L` (land). Water cells connected up, down, left or right form one body of water.
A body of water is a **lake** only if none of its cells is on the outer edge of the map (otherwise it is sea).
Print the number of lakes and the size of the largest lake (print `0 0` if there are none).

**Constraints:** `1 ≤ R, C ≤ 1000`.

```
Input       Output
5 6         2 3
LLLLLW
LWWLLW
LWLLWL
LLLWWL
LLLLLL
```

<details><summary>Hints</summary>

Flood-fill each body of water. While you do it, record its size and whether any cell touches the edge.
On a 1000×1000 grid, recursive DFS can overflow the stack, so use an explicit stack or BFS.
</details>

---

## P05: Longest Substring with at Most K Distinct Characters

Given `k` and a string `s`, print the length of the longest substring that has at most `k` different characters.
**Constraints:** `|s| ≤ 10^6`.

```
Input     Output
2         3
eceba
```

<details><summary>Hints</summary>Sliding window. Grow the right end. While the number of different characters is more than k, move the left end forward. Keep a frequency array and a distinct counter. Total time O(n).</details>

---

## P06: Subarray Sum Equals K

Given `n` integers (they **may be negative**) and `k`, count the contiguous subarrays whose sum is exactly `k`.
**Constraints:** `n ≤ 2·10^5`, `|a_i| ≤ 10^9`.

```
Input            Output
6 3              7
1 2 1 -1 3 0
```

<details><summary>Hints</summary>

The sum of a[l..r] is `pre[r] − pre[l−1]`. For each r, count how many earlier prefixes equal `pre[r] − k`, using a hash map that starts as `{0: 1}`.
Sliding window does **not** work here because of the negative numbers. This is a common trap in MCQs and coding questions.
</details>

---

## P07: Minimum Meeting Rooms

Given `n` meetings `[s, e)`, print the minimum number of rooms needed. A meeting that ends at 10 and one that starts at 10 can use the same room.

```
Input       Output
4           3
0 30
5 10
10 20
15 25
```

<details><summary>Hints</summary>Make an event `(s, +1)` and an event `(e, −1)` for each meeting. Sort them; at equal times the −1 comes first. The answer is the highest running total. Another way: sort by start time and keep a min-heap of end times.</details>

---

## P08: Ship Within D Days

Packages with weights `w_1..w_n` must be shipped **in order**. Each day the truck carries a run of consecutive packages whose total weight is at most its capacity.
Print the smallest capacity that ships everything within `D` days.

```
Input                    Output
10 5                     15
1 2 3 4 5 6 7 8 9 10
```

<details><summary>Hints</summary>"Find the smallest value that works" and "if X works, every larger value also works" means **binary search on the answer** over `[max(w), sum(w)]`, with a greedy O(n) check. Look for this pattern every time a question says "minimum maximum" or "minimum capacity / speed / time".</details>

---

## P09: Grid Paths

You start at the top-left of an `R × C` grid and must reach the bottom-right, moving only **right or down**. `#` cells are blocked.
Print the number of paths modulo `10^9+7` (print 0 if the start or the end is blocked).

```
Input    Output
3 3      2
...
.#.
...
```

<details><summary>Hints</summary>`dp[i][j] = dp[i−1][j] + dp[i][j−1]`, and blocked cells are 0. One row of memory is enough. Apply the mod at every addition.</details>

---

## P10: Course Order

There are `n` courses numbered `1..n`, and `m` rules of the form `a b` meaning "course a must be finished before course b".
Print an order to take all the courses. If several orders work, print the **lexicographically smallest** one. If no order works (there is a cycle), print `IMPOSSIBLE`.

```
Input    Output
5 4      1 2 3 4 5
1 3
2 3
3 4
2 5
```

<details><summary>Hints</summary>Kahn's algorithm, but use a **min-heap** instead of a queue to get the lexicographically smallest order. If fewer than n nodes come out, there is a cycle.</details>

---

## P11: Session Log

A server writes `n` log lines in time order, all on the same day: `HH:MM:SS user ACTION`, where ACTION is `LOGIN` or `LOGOUT`.
- A `LOGIN` while the user is already logged in is ignored.
- A `LOGOUT` while the user is not logged in is ignored.
- A user still logged in at the end is treated as logging out at `23:59:59`.

Print every user who appears in the log, in alphabetical order, with their total logged-in seconds.

```
Input                        Output
7                            arjun 5400
09:00:00 mei LOGIN           ken 0
09:30:00 arjun LOGIN         mei 7199
10:00:00 mei LOGOUT
10:15:00 arjun LOGIN
11:00:00 arjun LOGOUT
12:00:00 ken LOGOUT
23:00:00 mei LOGIN
```

<details><summary>Hints</summary>This one is about reading carefully, not about algorithms. List every rule as an `if` before you code. Users with 0 seconds must still be printed (ken). Use `map` to get sorted output for free.</details>

---

## P12: Cheapest Delivery Route

There are `n` towns and `m` two-way roads, each with a cost. Print the cheapest total cost from town `s` to town `t` on the first line and the route on the second line, or `-1` if `t` cannot be reached.
(The test data has a single cheapest route.)

```
Input        Output
5 6 1 5      7
1 2 4        1 3 2 4 5
1 3 1
3 2 2
2 4 1
3 4 5
4 5 3
```

<details><summary>Hints</summary>Dijkstra with a min-heap. Skip outdated heap entries (`if d != dist[v] continue`). Save `parent[v]` whenever you improve a distance, then walk back from t and reverse. Use `long long` for distances. BFS is only correct when every edge has the same weight.</details>
