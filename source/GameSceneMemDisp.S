.text

.global GameSceneMemDisp_hook

GameSceneMemDisp_hook:
	li r4,0x0
	stb r4,0x159(r3)
	stw r4,0x15C(r3)
	blr

