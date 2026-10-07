"""Random stress tests: compare each C++ solution against a slow, obviously-correct Python version.

Usage:  python3 stress/stress_test.py <dir-with-compiled-binaries> [rounds]
Binaries are expected to be named like the .cpp files without extension (p01_fit_the_part, ...).
"""
import os
import random
import subprocess
import sys

BIN = sys.argv[1]
ROUNDS = int(sys.argv[2]) if len(sys.argv) > 2 else 300


def run(name, inp):
    return subprocess.run([os.path.join(BIN, name)], input=inp, capture_output=True, text=True, check=True).stdout.strip()


# ---------- P01: rotate with zip/reversed, collect placements as frozensets ----------
def gen_p01():
    R, C = random.randint(1, 6), random.randint(1, 6)
    grid = ["".join(random.choice("..#") for _ in range(C)) for _ in range(R)]
    h, w = random.randint(1, 4), random.randint(1, 4)
    pat = [["." for _ in range(w)] for _ in range(h)]
    pat[random.randrange(h)][random.randrange(w)] = "*"
    for _ in range(random.randint(0, h * w)):
        pat[random.randrange(h)][random.randrange(w)] = "*"
    pat = ["".join(r) for r in pat]
    return f"{R} {C}\n" + "\n".join(grid) + f"\n{h} {w}\n" + "\n".join(pat) + "\n", (R, C, grid, pat)


def brute_p01(data):
    R, C, grid, pat = data
    placements = set()
    p = pat
    for _ in range(4):
        cells = [(i, j) for i, row in enumerate(p) for j, ch in enumerate(row) if ch == "*"]
        mi, mj = min(i for i, _ in cells), min(j for _, j in cells)
        cells = [(i - mi, j - mj) for i, j in cells]
        for r in range(R):
            for c in range(C):
                if all(r + i < R and c + j < C and grid[r + i][c + j] == "." for i, j in cells):
                    placements.add(frozenset((r + i, c + j) for i, j in cells))
        p = ["".join(col) for col in zip(*p[::-1])]  # rotate 90 clockwise
    return str(len(placements))


# ---------- P02: minute-by-minute simulation ----------
def gen_p02():
    R, C = random.randint(1, 6), random.randint(1, 6)
    grid = ["".join(random.choice("SSSX#") for _ in range(C)) for _ in range(R)]
    return f"{R} {C}\n" + "\n".join(grid) + "\n", (R, C, grid)


def brute_p02(data):
    R, C, grid = data
    g = [list(r) for r in grid]
    minutes = 0
    while True:
        new = [(i, j) for i in range(R) for j in range(C) if g[i][j] == "S" and any(
            0 <= i + di < R and 0 <= j + dj < C and g[i + di][j + dj] == "X"
            for di, dj in ((1, 0), (-1, 0), (0, 1), (0, -1)))]
        if not new:
            break
        for i, j in new:
            g[i][j] = "X"
        minutes += 1
    return str(-1 if any("S" in r for r in g) else minutes)


# ---------- P03: tick-by-tick simulation, one time unit at a time ----------
def gen_p03():
    n, k = random.randint(1, 8), random.randint(1, 3)
    cust = [(random.randint(0, 10), random.randint(1, 5), random.randint(0, 1)) for _ in range(n)]
    return f"{n} {k}\n" + "\n".join(f"{a} {d} {v}" for a, d, v in cust) + "\n", (n, k, cust)


def brute_p03(data):
    n, k, cust = data
    free_at = [0] * (k + 1)
    res = [None] * n
    t = 0
    while any(r is None for r in res):
        for ctr in range(1, k + 1):
            if free_at[ctr] <= t:
                waiting = [i for i in range(n) if res[i] is None and cust[i][0] <= t]
                if not waiting:
                    break
                i = min(waiting, key=lambda i: (-cust[i][2], cust[i][0], i))
                res[i] = (ctr, t + cust[i][1])
                free_at[ctr] = t + cust[i][1]
        t += 1
    return "\n".join(f"{c} {f}" for c, f in res)


# ---------- P04: flood fill from scratch with BFS ----------
def gen_p04():
    R, C = random.randint(1, 7), random.randint(1, 7)
    grid = ["".join(random.choice("WLL") for _ in range(C)) for _ in range(R)]
    return f"{R} {C}\n" + "\n".join(grid) + "\n", (R, C, grid)


def brute_p04(data):
    R, C, grid = data
    seen = set()
    lakes, largest = 0, 0
    for i in range(R):
        for j in range(C):
            if grid[i][j] == "W" and (i, j) not in seen:
                comp, todo = [], [(i, j)]
                seen.add((i, j))
                while todo:
                    a, b = todo.pop()
                    comp.append((a, b))
                    for x, y in ((a + 1, b), (a - 1, b), (a, b + 1), (a, b - 1)):
                        if 0 <= x < R and 0 <= y < C and grid[x][y] == "W" and (x, y) not in seen:
                            seen.add((x, y))
                            todo.append((x, y))
                if not any(a in (0, R - 1) or b in (0, C - 1) for a, b in comp):
                    lakes += 1
                    largest = max(largest, len(comp))
    return f"{lakes} {largest}"


# ---------- P05..P09: O(n^2) / exhaustive versions ----------
def gen_p05():
    k = random.randint(1, 4)
    s = "".join(random.choice("abcde") for _ in range(random.randint(1, 15)))
    return f"{k}\n{s}\n", (k, s)


def brute_p05(data):
    k, s = data
    return str(max(j - i for i in range(len(s)) for j in range(i + 1, len(s) + 1) if len(set(s[i:j])) <= k))


def gen_p06():
    n, k = random.randint(1, 12), random.randint(-5, 5)
    a = [random.randint(-3, 3) for _ in range(n)]
    return f"{n} {k}\n" + " ".join(map(str, a)) + "\n", (k, a)


def brute_p06(data):
    k, a = data
    return str(sum(1 for i in range(len(a)) for j in range(i + 1, len(a) + 1) if sum(a[i:j]) == k))


def gen_p07():
    n = random.randint(1, 8)
    iv = []
    for _ in range(n):
        s = random.randint(0, 10)
        iv.append((s, s + random.randint(1, 5)))
    return f"{n}\n" + "\n".join(f"{s} {e}" for s, e in iv) + "\n", iv


def brute_p07(iv):
    return str(max(sum(1 for s, e in iv if s <= t < e) for t in range(0, 16)))


def gen_p08():
    n = random.randint(1, 8)
    w = [random.randint(1, 10) for _ in range(n)]
    d = random.randint(1, n)
    return f"{n} {d}\n" + " ".join(map(str, w)) + "\n", (d, w)


def brute_p08(data):
    d, w = data
    cap = max(w)
    while True:
        days, load = 1, 0
        for x in w:
            if load + x > cap:
                days, load = days + 1, 0
            load += x
        if days <= d:
            return str(cap)
        cap += 1


def gen_p09():
    R, C = random.randint(1, 6), random.randint(1, 6)
    grid = ["".join(random.choice("...#") for _ in range(C)) for _ in range(R)]
    return f"{R} {C}\n" + "\n".join(grid) + "\n", (R, C, grid)


def brute_p09(data):
    R, C, grid = data

    def ways(i, j):
        if i >= R or j >= C or grid[i][j] == "#":
            return 0
        if (i, j) == (R - 1, C - 1):
            return 1
        return ways(i + 1, j) + ways(i, j + 1)

    return str(ways(0, 0) % 1_000_000_007)


CASES = {
    "p01_fit_the_part": (gen_p01, brute_p01),
    "p02_outage_spread": (gen_p02, brute_p02),
    "p03_help_desk": (gen_p03, brute_p03),
    "p04_enclosed_lakes": (gen_p04, brute_p04),
    "p05_k_distinct": (gen_p05, brute_p05),
    "p06_subarray_sum_k": (gen_p06, brute_p06),
    "p07_meeting_rooms": (gen_p07, brute_p07),
    "p08_ship_within_days": (gen_p08, brute_p08),
    "p09_grid_paths": (gen_p09, brute_p09),
}

if __name__ == "__main__":
    random.seed(2026)
    for name, (gen, brute) in CASES.items():
        for r in range(ROUNDS):
            inp, data = gen()
            got, want = run(name, inp), brute(data)
            if got != want:
                print(f"MISMATCH in {name}\n--- input ---\n{inp}--- expected ---\n{want}\n--- got ---\n{got}")
                sys.exit(1)
        print(f"{name}: {ROUNDS} random tests OK")
