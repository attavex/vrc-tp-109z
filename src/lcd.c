#include "main.h"

void lcdAuton_Pages(int selectVal)
{
    if (selectVal == 0)
    {
        lcdSetText(uart1, 1, "LAMBERT ROBOTICS");
        lcdSetText(uart1, 2, "[None]    [PICK]");
    }
    if (selectVal == 1)
    {
        lcdSetText(uart1, 1, "  Cap & No Park ");
        lcdSetText(uart1, 2, "    [Select]    ");
    }
    if (selectVal == 2)
    {
        lcdSetText(uart1, 1, "  No Cap & Park ");
        lcdSetText(uart1, 2, "    [Select]    ");
    }
    if (selectVal == 3)
    {
        lcdSetText(uart1, 1, "   Cap & Park   ");
        lcdSetText(uart1, 2, "    [Select]    ");
    }
}

/**
 * Global Variable Reminders
 * Pos0 : Type of Autonomous - 1 = Cap/No Park - 2 = No Cap/Park - 3 = Cap/Park
 * Pos1 : Back/Front - 1 = Back - 2 = Front
 * Pos2 : Side - 1 = Blue - 2 = Red
**/

void lcdAuton()
{
    lcdSetBacklight(uart1, 1);
    lcdSetText(uart1, 1, "  Select Auton  ");
    lcdSetText(uart1, 2, "[Done]      [>>]");
    int lcdAutonPage = 0;
    while (true)
    {
        lcdAuton_Pages(lcdAutonPage);
        if (lcdReadButtons(uart1) == 4){
            lcdAutonPage += 1;
        }
            
        if (lcdAutonPage > 0 && lcdAutonPage < 4)
        {
            if (lcdReadButtons(uart1) == 1)
            {
                 lcdAutonPage -= 1;
            }
               
        }
        else if(lcdReadButtons(uart1) == 1) {
            lcdAutonPage = 0;
            break;
        }
        if (lcdReadButtons(uart1) == 2)
        {
            break;
        }
        if (lcdReadButtons(uart1) > 0)
        {
            delay(250);
        }
        delay(10);
    }
    selectAuton[0] = lcdAutonPage;
    if (selectAuton[0] == 1 || selectAuton[0] == 2 || selectAuton[0] == 3)
    {
            selectAuton[1] = lcdAutonPage;
            if(selectAuton[0] == 1 || selectAuton[0] == 2 || selectAuton[0] == 3) { 
                lcdSetText(uart1, 1, " Back or Front? ");
                lcdSetText(uart1, 2, "[B]         [FR]");
                wait(250);
                while (true)
                {
                    if (lcdReadButtons(uart1) == 1)
                    {
                        lcdAutonPage = 1;
                        break;
                    }
                    else if (lcdReadButtons(uart1) == 4)
                    {
                        lcdAutonPage = 2;
                        break;
                    }
                    delay(10);
                }
                selectAuton[1] = lcdAutonPage;
                printf("%d\n", selectAuton[1]);
            }
    }
    if (selectAuton[1] == 1 || selectAuton[1] == 2)
    {
            selectAuton[1] = lcdAutonPage;
            if(selectAuton[0] == 1 || selectAuton[0] == 2 || selectAuton[0] == 3) { 
                lcdSetText(uart1, 1, "   What side?   ");
                lcdSetText(uart1, 2, "[BL]         [R]");
                wait(250);
                while (true)
                {
                    if (lcdReadButtons(uart1) == 1)
                    {
                        lcdAutonPage = 1;
                        break;
                    }
                    else if (lcdReadButtons(uart1) == 4)
                    {
                        lcdAutonPage = 2;
                        break;
                    }
                    delay(10);
                }
                selectAuton[2] = lcdAutonPage;
                printf("%d\n", selectAuton[2]);
            }
    }
}   