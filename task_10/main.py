def det4(r0, r1, r2, r3):
    def det3(r0, r1, r2):
        def det2(r0, r1):
            return r0[0]*r1[1] - r0[1]*r1[0]

        return (r0[0]*det2(r1[1:], r2[1:])
                - r0[1]*det2(r1[::2], r2[::2])
                + r0[2]*det2(r1[:2], r2[:2]))

    return (
        r0[0] * det3(r1[1:], r2[1:], r3[1:])
        - r0[1] * det3(
            (r1[0], r1[2], r1[3]),
            (r2[0], r2[2], r2[3]),
            (r3[0], r3[2], r3[3])
        )
        + r0[2] * det3(
            (r1[0], r1[1], r1[3]),
            (r2[0], r2[1], r2[3]),
            (r3[0], r3[1], r3[3])
        )
        - r0[3] * det3(r1[:3], r2[:3], r3[:3])
    )
