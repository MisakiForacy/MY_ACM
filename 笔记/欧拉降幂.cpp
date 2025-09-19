/**
 * 求解a^k mod p
 * p 为质数，但是k非常大，数量级为10^1e5
 * 可以将k换成 k mod phi(p)
 * phi(p) 为 p 的欧拉函数值 
 */