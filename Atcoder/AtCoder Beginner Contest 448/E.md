A : $\lfloor \frac{N}{m} \rfloor \bmod 10007$
B : $\lfloor \frac{N \bmod (m \cdot 10007)}{m} \rfloor$

证明A式=B式

设 $q = \lfloor \frac{N}{m} \rfloor$，$r = N \bmod m (0 \leq r < m)$ ，则 $N = m q + r$。把 $q$ 写成 $q = 10007 t + s$，且 $0 \leq s < 10007$（即 $s = q \bmod 10007$）。

则
$$N = m(10007 t + s) + r = m\cdot10007\cdot t + (m s + r).$$

因此
$$N \bmod (m\cdot10007) = m s + r.$$

两边除以 m 并向下取整得
$$\left\lfloor\frac{N \bmod (m\cdot10007)}{m}\right\rfloor = \left\lfloor\frac{m s + r}{m}\right\rfloor = s + \left\lfloor\frac{r}{m}\right\rfloor = s.$$

而
$$\left\lfloor\frac{N}{m}\right\rfloor \bmod 10007 = q \bmod 10007 = s.$$

因此
$$\left\lfloor\frac{N}{m}\right\rfloor \bmod 10007=\left\lfloor\frac{N \bmod (m\cdot10007)}{m}\right\rfloor.$$

证毕。