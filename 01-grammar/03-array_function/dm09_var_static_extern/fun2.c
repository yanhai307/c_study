//
// Created by YANHAI on 2019/5/20.
//

static int va = 18;

static int getG(void)
{
    return va;
}

int getO(void)
{
    return getG();
}