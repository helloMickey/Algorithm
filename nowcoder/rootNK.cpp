/*
求x的y次方对z取模(x^y)mod z：蒙格马利快速幂模算法
X^Y可以看作Y个X相乘，即然有积模分解公式，
那么我们就可以把Y个X相乘再取模的过程分解开来，
比如：(17^25)%29则可分解为：( ( 17 * 17 ) % 29 * ( 17 * 17 ) % 29 *...)
*/