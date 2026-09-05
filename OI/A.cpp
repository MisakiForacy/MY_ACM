int f(int x) {
    if (x == 0) return 1;
    return f(x - 1) + 1;
}

f(3) -> f(2) + 1 -> (f(1) + 1) + 1 -> ((1 + 1) + 1) + 1