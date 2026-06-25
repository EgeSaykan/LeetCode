import numpy as np

# def find_recurrence_coeffs(r, y):
#     if len(y) < 4:
#         raise ValueError("Need at least 4 sequence values.")

#     A = []
#     b = []

#     for n in range(r-1, len(y)):
#         A.append([y[n-i]for i in range(r-1, 0, -1)])
#         b.append(y[n])
#     print("A: ", A)

#     A = np.array(A, dtype=float)
#     b = np.array(b, dtype=float)

#     coeffs, residuals, rank, s = np.linalg.lstsq(A, b, rcond=None)
#     for i in range(len(coeffs)):
#         print(f"coeffs[{i}]: {coeffs[i]}")
#         coeffs[i] = round(coeffs[i])
#     return tuple(coeffs)

def find_recurrence_coeffs(r, y, knowns):
    A = []
    b = []
    r -= 1

    unknown_idx = [i for i, c in enumerate(knowns) if c is None]

    for n in range(r, len(y)):
        rhs = y[n]

        row = []

        for i in range(r):
            val = y[n - i - 1]

            if knowns[i] is None:
                row.append(val)
            else:
                rhs -= knowns[i] * val

        A.append(row)
        b.append(rhs)

    A = np.array(A, dtype=np.float64)
    b = np.array(b, dtype=np.float64)

    unknowns = np.linalg.lstsq(A, b, rcond=None)[0]

    coeffs = list(knowns)

    for idx, value in zip(unknown_idx, unknowns):
        coeffs[idx] = round(value)

    return coeffs

knowns = [-11, 1, None, None, None, 6, 4] # c1, c2, ... c6, c7
coefs = find_recurrence_coeffs(8, [
    7, 28, 140, 658, 3164, 15106, 72302, 345775
], knowns)
print(f"Recurrence coefficients: {coefs}")
