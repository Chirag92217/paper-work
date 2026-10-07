# Accenture Japan (Digital Consultant): OA Prep Kit

Based on past IIT experiences, the OA usually has **technical MCQs (about 20: OS, CN, DSA, DBMS, Cloud, sometimes Security/React)**
plus **1 to 3 coding problems** (anywhere from Codeforces Div-2 B level up to a hard grid/shape problem).
The exact format changes every year, so this kit prepares you for the whole range instead of guessing one paper.

| File | What it is |
|---|---|
| [`coding/PROBLEMS.md`](coding/PROBLEMS.md) | 12 original OA-style problems (grid, simulation, BFS, DP, graphs) with hints |
| `coding/solutions/` | Tested C++ solutions (checked on samples and on random tests against brute force) |
| `coding/cpp_oa_template.cpp` | Starter template: grid BFS + DSU |
| [`mcq/MCQ_BANK.md`](mcq/MCQ_BANK.md) | 98 MCQs with answers and explanations |
| [`CORE_CS_CHEATSHEET.md`](CORE_CS_CHEATSHEET.md) | One-page revision of OS / CN / DBMS / OOP / DSA / Cloud / Security / AI |
| [`mcq/mock_test.html`](mcq/mock_test.html) | Interactive timed mock test drawing from the same bank (open in a browser, or use the hosted link). Rebuild with `python3 mcq/build_bank.py` after editing `questions.json` |

---

## 7-Day Plan (about 4–5 hours/day)

| Day | Coding (2–2.5 h) | MCQ / theory (1.5–2 h) | Check |
|---|---|---|---|
| 1 | P02, P04, P09 (BFS / components / DP), then type the template from memory | OS: processes, threads, scheduling numericals, deadlock | MCQ bank: OS section |
| 2 | P05, P06, P07 (window / prefix / sweep) | CN: OSI, TCP/UDP, ports, subnetting, HTTP | MCQ bank: CN section |
| 3 | P08, P10, P12 (binary search on answer / topo / Dijkstra) | DBMS: normal forms, joins, transactions + write 10 SQL queries by hand | MCQ bank: DBMS + OOP |
| 4 | **P03 and P11 (wordy simulations)**: write the rules list before coding | OOP + DSA complexity table | MCQ bank: DSA |
| 5 | **P01 (rotate-and-fit)**, then one more grid problem from the list below | Cloud, Docker/K8s, Security, GenAI basics | MCQ bank: Cloud, Security, Web/AI |
| 6 | **Full mock:** 20 MCQs (mock test) + 2 unseen problems in 90 minutes total | Review every wrong MCQ and write down *why* you got it wrong | — |
| 7 | Redo any problem you failed. No new topics. | Read the cheat sheet twice. Sleep properly. | Mock test again (new random set) |

**Only 3 days?** Day 1 = Days 1+2, Day 2 = Days 3+4 (skip P10/P12), Day 3 = P01 + full mock + cheat sheet.

### Extra practice (well-known problems with the same patterns)

- **Grid / BFS:** LeetCode 994 Rotting Oranges, 200 Number of Islands, 1020 Number of Enclaves, 542 01 Matrix, 1091 Shortest Path in Binary Matrix
- **Rotation / grid implementation:** LeetCode 48 Rotate Image, 1886 Determine Whether Matrix Can Be Obtained By Rotation, 54 Spiral Matrix, 289 Game of Life
- **Simulation / heaps:** LeetCode 621 Task Scheduler, 1834 Single-Threaded CPU, 1882 Process Tasks Using Servers
- **Window / prefix:** 3 Longest Substring Without Repeating Characters, 560 Subarray Sum Equals K, 209 Minimum Size Subarray Sum
- **Binary search on answer:** 1011 Capacity To Ship Packages, 875 Koko Eating Bananas
- **Graphs / DP:** 207/210 Course Schedule, 743 Network Delay Time, 63 Unique Paths II, 322 Coin Change
- Also do a few **Codeforces Div-2 A/B implementation** problems to get used to long statements.

---

## OA-Day Strategy

**Before you start**
- Check the platform, the language versions, whether you can switch between sections, and whether wrong MCQ answers lose marks (negative marking).
- If they allow it, open a scratch file with your template.

**MCQs**
- Do the MCQs first if the sections are separate and timed, because they are quick marks. Spend at most about 60–75 seconds per question, flag the hard ones and come back.
- Numericals (scheduling, page faults, subnetting) are easy marks if you write them out. Do not do them in your head.
- Do not guess randomly if there is negative marking. Without negative marking, never leave a question blank.

**Coding**
1. Read **all** problems first (2–3 min). Solve the easiest first.
2. For long, story-style statements, **turn the text into a numbered rules list** and check the sample against it **by hand** before coding. Past Accenture Japan problems were hard partly because they were hard to read.
3. Check the constraints to pick the complexity: n ≤ 10^5 → O(n log n); grid ≤ 1000×1000 → O(R·C); n ≤ 20 → bitmask/backtracking.
4. Edge cases to test: n = 1, everything blocked or empty, duplicate values, negative numbers, overflow (use `long long`), shapes with empty borders, ties.
5. **Partial marks count.** If the full solution is not working with 15 minutes left, submit a brute force that passes the small tests.
6. Avoid recursive DFS on large grids (stack overflow). Use BFS or an explicit stack.

---

## Score Targets Before the OA

- [ ] Mock MCQ test **≥ 16/20** on two different random sets
- [ ] Solved P01, P03 and P11 alone in ≤ 40 minutes each
- [ ] Can write grid BFS, Dijkstra, topological sort, DSU and binary search on answer from memory without bugs
- [ ] Can do scheduling (FCFS/SJF/RR), page-replacement and subnetting numericals in under 2 minutes each

Run the coding samples with `cd coding && bash run_samples.sh`, and the stress tests with
`python3 coding/stress/stress_test.py coding/bin` (after building with `run_samples.sh`).
