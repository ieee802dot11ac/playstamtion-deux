#include <gsKit/include/gsKit.h>
#include <stdio.h>

void flipScreen(GSGLOBAL* gsGlobal)
{	
	gsKit_queue_exec(gsGlobal);
	gsKit_sync_flip(gsGlobal);
}

GSGLOBAL* init_graphics()
{
	GSGLOBAL* gsGlobal = gsKit_init_global();

	gsGlobal->PrimAlphaEnable = GS_SETTING_ON;
	//gsGlobal->PrimAAEnable = GS_SETTING_ON;

	gsKit_set_primalpha(gsGlobal, GS_SETREG_ALPHA(0, 1, 0, 1, 0), 0);

	dmaKit_init(D_CTRL_RELE_OFF, D_CTRL_MFD_OFF, D_CTRL_STS_UNSPEC, D_CTRL_STD_OFF, D_CTRL_RCYC_8, 1 << DMA_CHANNEL_GIF);
	dmaKit_chan_init(DMA_CHANNEL_GIF);

	gsKit_set_clamp(gsGlobal, GS_CMODE_REPEAT);

	gsKit_vram_clear(gsGlobal);

	gsKit_init_screen(gsGlobal);

	gsKit_mode_switch(gsGlobal, GS_ONESHOT);

	return gsGlobal;

}

int main(int argc, char** argv) {
	printf("aaaaaaaaaaaaaaa");
	GSGLOBAL* gsGlobal = init_graphics();
	return 0;
}
