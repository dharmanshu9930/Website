#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct process
{
    int nodeId;
    int nodeLvalue;
    int nodeRvalue;
    int nodeLmark;
    int nodeRmark;
    int nodeArea;
} * PROCESS;

typedef struct event
{
    int eventSource;
    int eventTarget;
    int eventType;
    int eventFlag;
    int eventValue;
    struct event *eventNext;
} * EVENT;

EVENT initialization(EVENT evt)
{
    evt = (EVENT)malloc(sizeof(struct event));
    evt->eventNext = NULL;
    return evt;
}

int isEmpty(EVENT evt)
{
    if(evt->eventNext == NULL){
        return 1;
    }
    return 0;
}

PROCESS generateValues(PROCESS S, int n, int iFlag)
{
    S = (PROCESS)malloc(n*sizeof(struct process));

    switch (iFlag)
    {
    case 0:
        printf("\n");
        printf("\t");
        printf("Input Generation: SORTED SEQUENCE!");
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            int val = i + 1;
            S[i].nodeId = i;
            if (i == 0)
            {
                S[i].nodeLvalue = INT_MIN;
                S[i].nodeRvalue = val;
                S[i].nodeLmark = 0;
                S[i].nodeRmark = 1;
                S[i].nodeArea = -1;
            }
            else if (i == n - 1)
            {
                S[i].nodeLvalue = val;
                S[i].nodeRvalue = INT_MAX;
                S[i].nodeLmark = 1;
                S[i].nodeRmark = 0;
                S[i].nodeArea = 0;
            }
            else
            {
                S[i].nodeLvalue = val;
                S[i].nodeRvalue = val;
                S[i].nodeLmark = 0;
                S[i].nodeRmark = 0;
                S[i].nodeArea = 0;
            }
        }
        break;
    case 1:
        printf("\n");
        printf("\t");
        printf("Input Generation: RANDOM!");
        printf("\n");
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            int val = rand() / 1000;
            S[i].nodeId = i;
            if (i == 0)
            {
                S[i].nodeLvalue = INT_MIN;
                S[i].nodeRvalue = val;
                S[i].nodeLmark = 0;
                S[i].nodeRmark = 1;
                S[i].nodeArea = -1;
            }
            else if (i == n - 1)
            {
                S[i].nodeLvalue = val;
                S[i].nodeRvalue = INT_MAX;
                S[i].nodeLmark = 1;
                S[i].nodeRmark = 0;
                S[i].nodeArea = 0;
            }
            else
            {
                S[i].nodeLvalue = val;
                S[i].nodeRvalue = val;
                S[i].nodeLmark = 0;
                S[i].nodeRmark = 0;
                S[i].nodeArea = 0;
            }
        }
        break;
    case 2:
        printf("\n");
        printf("\t");
        printf("Input Generation: WORST CASE!");
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            int val = n - i;
            S[i].nodeId = i;
            if (i == 0)
            {
                S[i].nodeLvalue = INT_MIN;
                S[i].nodeRvalue = val;
                S[i].nodeLmark = 0;
                S[i].nodeRmark = 1;
                S[i].nodeArea = -1;
            }
            else if (i == n - 1)
            {
                S[i].nodeLvalue = val;
                S[i].nodeRvalue = INT_MAX;
                S[i].nodeLmark = 1;
                S[i].nodeRmark = 0;
                S[i].nodeArea = 0;
            }
            else
            {
                S[i].nodeLvalue = val;
                S[i].nodeRvalue = val;
                S[i].nodeLmark = 0;
                S[i].nodeRmark = 0;
                S[i].nodeArea = 0;
            }
        }
        break;
    }
    return S;
}

void print(PROCESS S, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (S[i].nodeArea >= 0)
        {
            printf("%d",S[i].nodeLvalue);
        }
        else
        {
            printf("%d",S[i].nodeRvalue);
        }
        printf("\t");
    }
}

int swapValues(int *x, int *y)
{
    int min, flg = 0;
    if (*x <= *y)
    {
        min = *x;
    }
    else
    {
        min = *y;
        *y = *x;
        *x = min;
        flg = 1;
    }
    return flg;
}

EVENT insert(EVENT evt, int eSource, int eTarget, int eType, int eFlag, int eValue)
{
    EVENT new, prev = evt, curr;
    new = (EVENT)malloc(sizeof(struct event));
    new->eventSource = eSource;
    new->eventTarget = eTarget;
    new->eventType = eType;
    new->eventFlag = eFlag;
    new->eventValue = eValue;
    new->eventNext = NULL;

    if (prev->eventNext == NULL)
    {
        prev->eventNext = new;
        return evt;
    }
    else
    {
        curr = prev;
        while (curr->eventNext != NULL)
        {
            curr = curr->eventNext;
        }
        curr->eventNext = new;
    }
    return evt;
}

EVENT extractTopEvent(EVENT evt, EVENT tp)
{
    EVENT del = evt, nxt, atop = tp;
    atop = atop->eventNext;

    if (del->eventNext != NULL)
    {
        del = del->eventNext;
        if (del->eventNext != NULL)
        {
            nxt = del->eventNext;
            evt->eventNext = nxt;
        }
        else
        {
            evt->eventNext = NULL;
        }

        atop->eventSource = del->eventSource;
        atop->eventTarget = del->eventTarget;
        atop->eventType = del->eventType;
        atop->eventFlag = del->eventFlag;
        atop->eventValue = del->eventValue;
        atop->eventNext = NULL;
        free(del);
    }
    else
    {
        printf("\n");
        printf("\t");
        printf("ERROR: No events found!!");
        tp->eventNext = NULL;
        atop->eventNext = NULL;
    }
    return tp;
}

EVENT destroyEvents(EVENT evt)
{
    EVENT del = evt, nxt;
    if (del->eventNext == NULL)
    {
        return evt;
    }
    else
    {
        del = del->eventNext;
        while (del->eventNext != NULL)
        {
            nxt = del;
            free(nxt);
            del = del->eventNext;
        }
        free(del);
        evt->eventNext == NULL;
        return evt;
    }
}

void handleSendEvents(EVENT evt, EVENT curr)
{
    EVENT cuNext = curr->eventNext;

    evt = insert(evt, cuNext->eventTarget, cuNext->eventSource, 0, cuNext->eventFlag, cuNext->eventValue);
}

void handleRecieveEvents(PROCESS S, EVENT evt, EVENT curr, int round)
{
    EVENT cuNext = curr->eventNext;
    int flag = cuNext->eventFlag, recievedValue = cuNext->eventValue;

    if (flag == 1)
    {
        flag = 0;
        int swap = swapValues(&recievedValue, &S[cuNext->eventSource].nodeLvalue);
        if (swap)
        {
            flag = 4;
            if (S[cuNext->eventSource].nodeLmark == 1 && S[cuNext->eventTarget].nodeRmark == 1)
            {
                S[cuNext->eventSource].nodeLmark = 0;
                S[cuNext->eventSource].nodeArea += 1;
                S[cuNext->eventSource].nodeLmark = 1;
                S[cuNext->eventSource].nodeArea -= 1;
                flag = 5;
            }
            else
            {
                if (S[cuNext->eventSource].nodeLmark == 1)
                {
                    S[cuNext->eventSource].nodeLmark = 0;
                    S[cuNext->eventSource].nodeArea += 1;
                    flag = 2;
                }
                if (S[cuNext->eventTarget].nodeRmark == 1)
                {
                    S[cuNext->eventSource].nodeLmark = 1;
                    S[cuNext->eventSource].nodeArea -= 1;
                    flag = 3;
                }
            }
        }
        evt = insert(evt, cuNext->eventSource, cuNext->eventTarget, 1, flag, recievedValue);
    }
    else
    {
        if (flag == 5)
        {
            ;
        }
        else
        {
            if (flag == 2)
            {
                S[cuNext->eventSource].nodeRmark = 1;
            }
            if (flag == 3)
            {
                S[cuNext->eventSource].nodeRmark = 0;
            }
        }

        S[cuNext->eventSource].nodeRvalue = recievedValue;
        int swap = swapValues(&S[cuNext->eventSource].nodeLvalue, &S[cuNext->eventSource].nodeRvalue);
        if (swap)
        {
            int temp = S[cuNext->eventSource].nodeRmark;
            S[cuNext->eventSource].nodeRmark = S[cuNext->eventSource].nodeLmark;
            S[cuNext->eventSource].nodeLmark = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    int round = 1;
    PROCESS S = NULL;
    EVENT E, eTop, aTop;
    srand(1000);
    printf("No of Process: ");
    printf("%d",5);

    E = initialization(E);
    eTop = initialization(eTop);
    aTop = initialization(aTop);
    eTop->eventNext = aTop;

    S = generateValues(S, 5, 1);
    printf("\n");
    printf("\t");
    printf("Initial : ");

    for (int i = 0; i < 5; i++)
    {
        if((S[i].nodeLvalue == INT_MIN))
        { 
            printf("X");
        }
        else{
            printf("%d",S[i].nodeLvalue);
        }

        printf("|");

        if (S[i].nodeRvalue == INT_MAX)
        {
            printf("X");
        }
        else
        {
            printf("%d",S[i].nodeRvalue);
        }

        printf(" (");
        printf("%d",S[i].nodeLmark);
        printf("|");
        printf("%d",S[i].nodeRmark);
        printf("|");
        printf("%d",S[i].nodeArea);
        printf(") ");
    }

    while (round < 5)
    {
        printf("\n");
        printf("\t");
        printf("Step - ");
        printf("%d",round);
        printf(" ");

        for (int i = 0; i < 5 - 1; i++)
        {
            if (i == 0)
            {
                E = insert(E, i, i + 1, 1, 1, S[i].nodeRvalue);
            }
            else if (i > 0 && i < 5 - 1)
            {
                E = insert(E, i, i + 1, 1, 1, S[i].nodeRvalue);
            }
        }
        while (!isEmpty(E))
        {
            eTop = extractTopEvent(E, eTop);

            if (eTop->eventNext->eventType == 1)
            {
                handleSendEvents(E, eTop);
            }
            else
            {
                if (eTop->eventNext->eventType == 0)
                {
                    handleRecieveEvents(S, E, eTop, round);
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            if (S[i].nodeLvalue == INT_MIN)
            {
                printf("X");
            }
            else
            {
                printf("%d",S[i].nodeLvalue);
            }
            
            printf("|");
            
            if (S[i].nodeRvalue == INT_MAX)
            {
                printf("X");
            }
            else
            {
                printf("%d",S[i].nodeRvalue);
            }

            printf(" (");
            printf("%d",S[i].nodeLmark);
            printf("|");
            printf("%d",S[i].nodeRmark);
            printf("|");
            printf("%d",S[i].nodeArea);
            printf(") ");
        }
        round++;
    }

    printf("\n");
    printf("\t");
    printf("Step - ");
    printf("%d",round);
    printf(" ");

    for (int i = 0; i < 5; i++)
    {
        if (S[i].nodeLvalue == INT_MIN)
        {
            printf("X");
        }
        else
        {
            printf("%d",S[i].nodeLvalue);
        }

        printf("|");
        
        if (S[i].nodeRvalue == INT_MAX)
        {
            printf("X");
        }
        else
        {
            printf("%d",S[i].nodeRvalue);
        }

        printf(" (");
        printf("%d",S[i].nodeLmark);
        printf("|");
        printf("%d",S[i].nodeRmark);
        printf("|");
        printf("%d",S[i].nodeArea);
        printf(") ");
    }

    printf("\n");
    printf("\t");
    printf("SOLUTION : ");
    print(S, 5);

    E = destroyEvents(E);
    eTop = destroyEvents(eTop);

    free(S);
    free(E);
    free(eTop);

    printf("\n");

    return 0;
}
