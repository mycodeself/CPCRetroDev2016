#include "hud.h"

#define BORDER_LEFT_VMEM cpctm_screenPtr(CPCT_VMEM_START, 0, 160)
#define BORDER_RIGHT_VMEM cpctm_screenPtr(CPCT_VMEM_START, 78, 160)
#define BORDER_TOP0_VMEM cpctm_screenPtr(CPCT_VMEM_START, 2, 160)
#define BORDER_TOP1_VMEM cpctm_screenPtr(CPCT_VMEM_START, 40, 160)
#define BORDER_BOT0_VMEM cpctm_screenPtr(CPCT_VMEM_START, 2, 196)
#define BORDER_BOT1_VMEM cpctm_screenPtr(CPCT_VMEM_START, 40, 196)

void drawBorder()
{
  cpct_drawSolidBox(BORDER_LEFT_VMEM, 3, 2, 40);
  cpct_drawSolidBox(BORDER_RIGHT_VMEM, 3, 2, 40);
  cpct_drawSolidBox(BORDER_TOP0_VMEM, 3, 38, 4);
  cpct_drawSolidBox(BORDER_TOP1_VMEM, 3, 38, 4);
  cpct_drawSolidBox(BORDER_BOT0_VMEM, 3, 38, 4);
  cpct_drawSolidBox(BORDER_BOT1_VMEM, 3, 38, 4);
}

void drawHUB()
{
  drawBorder();
}