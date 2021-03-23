#include <stdio.h>

/**
 * 函数表解决过多分支的问题 
 */ 

typedef bool (*ProcessNextFuncPtr)(const ItemState& current, ItemState& next);

struct ActionProcess
{
    Action act;
    ProcessNextFuncPtr processFunc;
};

ActionProcess actMap[] = {
    { FARMER_GO, ProcessFarmerGo },
    { FARMER_GO_TAKE_WOLF, ProcessFarmerGoTakeWolf },
    { FARMER_GO_TAKE_SHEEP, ProcessFarmerGoTakeSheep },
    { FARMER_GO_TAKE_VEGETABLE, ProcessFarmerGoTakeVegetable },
    { FARMER_BACK, ProcessFarmerBack },
    { FARMER_BACK_TAKE_WOLF, ProcessFarmerBackTakeWolf },
    { FARMER_BACK_TAKE_SHEEP, ProcessFarmerBackTakeSheep },
    { FARMER_BACK_TAKE_VEGETABLE, ProcessFarmerBackTakeVegetable }
};

ItemState next;
for(int i = 0; i < sizeof(actMap)/sizeof(actMap[0]); i++)
{
    if(actMap[i].act == action)
    {
        actMap[i].processFunc(current, next);
        break;
    }
}