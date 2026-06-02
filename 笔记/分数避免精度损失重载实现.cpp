struct frac
{
    LL x, y;
    bool operator < (const frac&T) const {
        return x * T.y < T.x * y;
    }
};