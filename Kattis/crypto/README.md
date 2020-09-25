# [Cryptographic Keys](https://open.kattis.com/problems/crypto)

N has a tailing zero in base k form iff N mod k = 0. So the key must be a factor of N. Since we need the smallest k with most tailing zeros, the key must be the smallest prime factor of N which has the highest power. To factorize N within 10<sup>12</sup>, I just need primes within 10<sup>6</sup>.