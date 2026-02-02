.include "macros.S"

.rodata
normalOctostrikerDieDemoState:       .string "StateTornado::cDieDemo"
hijackedOctostrikerDieDemoState:     .string "StateTornado::cNopDemo"

.text

.global controlInkSplatter

controlInkSplatter:
# So here's a bit of a hack

# The game determines on whether or not to play the screen ink splatter effect
# that occurs after defeating an Octostriker if its current state name is "StateTornado::cDieDemo",
# as part of the game's XLink system for linking ingame actions to visual and sound effects.
# We only want the effect to play if the player is in a regular Octostriker stage, so we
# hijack to be something else if those conditions aren't met.

    SaveVolatileRegisters
    bl isInOctostrikerStage
    cmpwi r3, 0 # Are we not in an Octostriker stage?
    beq malformDieDemoStateName # If true, mess up the state name so the effect won't play
    b loadOriginalStateName

malformDieDemoStateName:
    RestoreVolatileRegisters
    lis r12, hijackedOctostrikerDieDemoState@ha
    addi r12, r12, hijackedOctostrikerDieDemoState@l
    stw r12, 0xC(r1)
    blr

loadOriginalStateName:
    RestoreVolatileRegisters
    lis r12, normalOctostrikerDieDemoState@ha
    addi r12, r12, normalOctostrikerDieDemoState@l
    stw r12, 0xC(r1)
    blr






