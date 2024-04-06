# quartic-real
Computes real solutions of quartic polynomials. Not well tested, do not use.

# Performances
Twice as fast as https://github.com/sasamil/Quartic according to my tests.

# Explanation
https://en.wikipedia.org/wiki/Quartic_function#General_formula_for_roots

# Info
Doesn't work if s=0. All real values are computed, but only the smallest positive root is returned. If no solutions exist, it returns 65536. So solutions must be < 65536 in norm. The aim of this code is ray-tracing algebraic objects.

