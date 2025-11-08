
.global customTextWriterASMSetup
customTextWriterASMSetup:
    # Save LR/volatiles
    mflr    r0
    stwu    r1, -0x20(r1)
    stw     r0, 0x24(r1)

    bl drawCustomDebugText__FPiPQ2_4sead8Viewport

    # Restore LR/stack
    lwz     r0, 0x24(r1)
    addi    r1, r1, 0x20
    mtlr    r0

    # Original instruction
    lmw     r18, 0x90(r1)
    b loc_0289DF8C # really hacky
