#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

int size = 0;
struct node *head;

insert_after(int a)
{
    struct node *temp, *var = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;

    if(head == NULL)
        head = temp;
    else
    {
        while(var->next != NULL)
            var = var->next;
        var->next = temp;
    }
    size++;
}

insert_before(int ib)
{
    struct node *temp;
    if(head == NULL)
        printf("\nThere is no data.\n\n");
    else
    {
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = ib;
        temp->next = head;
        head = temp;
        size++;
    }
}

insert_middle(int pos, int data)
{
    struct node *temp, *var = head;
    int i;
    if(head == NULL)
        printf("\nThere is no data.\n\n");
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        if(pos == 1)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            for(i=2; i<pos; i++)
                var= var->next;
            temp->next = var->next;
            var->next = temp;
        }
        size++;
    }
}


bad_data(int bd)
{
    struct node *var, *ag;
    var = head;
    if(var == NULL)
        printf("\nThere is no data.\n\n");
    else
    {
        if(head->data == bd)
        head = head->next;
    else
    {
        while(var != NULL)
        {
            if(bd == var->data)
            {
                ag->next = var->next;
                return;
            }
            else
            {
                ag = var;
                var = var->next;
            }
        }
    }
    size--;
    }
}

bad_position(int pos)
{
    int i;
    struct node* temp = head, *temp2;
    if(head == NULL)
        printf("\nThere is no data.\n\n");
    else
    {
        if(pos == 1)
            head = head->next;
        else
        {
            for(i=1; i<pos-1; i++)
                temp = temp->next;
            temp2 = temp;
            temp = temp->next;
            temp2->next = temp->next;
        }
        size--;
    }
}

khoj(int s)
{
    struct node *var;
    var = head;
    while(var != NULL)
    {
        if(s == var->data)
        {
            printf("\n\nFound.\n");
            return;
        }
        else
            var = var->next;
    }
    if(var == NULL)
        printf("\nNot Found.\n\n");
}

gunbo()
{
    if(head == NULL)
        printf("\nThere is no data.\n\n");
    else
    {
        int cnt=0;
        struct node *var;
        var = head;
        while(var !=NULL)
        {
            cnt++;
            var = var->next;
        }
        printf("\n\nNumber Of Data:  %d\n", cnt);
    }
}

jog()
{
    int p = 0;
    struct node *i = head;
    while(i != NULL)
    {
        p = p + i->data;
        i = i->next;
    }
    return p;
}

display()
{
    struct node *i = head;
    while(i != NULL)
    {
        printf("%d   ", i->data);
        i = i->next;
    }
}

reverse_display()
{
    struct node *i = head, *temp, *hr =NULL;
    while(i != NULL)
    {
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = i->data;
        temp->next = hr;
        hr = temp;
        i = i->next;
    }
    while(hr != NULL)
    {
        printf("%d   ", hr->data);
        hr = hr->next;
    }
}

update(int pos, int value)
{
    int i;
    struct node* temp = head, *temp2;
    if(pos>0 && pos<=size)
    {
        for(i=1; i<pos; i++)
            temp = temp->next;
        temp-> data = value;
    }
    else
    {
        printf("Position to update:  ");
        scanf("%d", &pos);
        printf("New value:  ");
        scanf("%d", &value);
        update(pos, value);
    }
}

main()
{
    head = NULL;
    int a, h, b, i, t, bd, pos, ia, ib, w, x, value;

    printf("Number Of Data:  ");
    scanf("%d", &a);
    printf("Type your data.\n");
    for(i=0; i<a; i++)
    {
        scanf("%d", &b);
        insert_after(b);
    }
    printf("\nYour data:  ");
    display();
    while(1)
    {
        printf("\n\n1.  To display.\n2.  To insert at the first & display.\n3.  To insert at the end & display.\n4.  To insert at middle & display.\n5.  To delete any number & display.\n6.  To delete any position & display.\n7.  To search any number.\n8.  To count the linked list.\n9.  To add all data of the linked list.\n10. To update any position & display.\n11. To display in opposite direction.\n12. To exit.\n\nYour choice:  ");
        scanf("%d", &h);
        switch(h)
        {
            case 1:
                {
                    display();
                    break;
                }
            case 2:
                {
                    printf("The number: ");
                    scanf("%d", &ib);
                    insert_before(ib);
                    printf("\nYour data:  ");
                    display();
                    break;
                }
            case 3:
                {
                    printf("The number: ");
                    scanf("%d", &ia);
                    insert_after(ia);
                    printf("\nYour data:  ");
                    display();
                    break;
                }
            case 4:
                {
                    printf("The position to insert new:  ");
                    scanf("%d", &w);
                    printf("The new data to insert:  ");
                    scanf("%d", &x);
                    insert_middle(w, x);
                    printf("\nYour data:  ");
                    display();
                    break;
                }
            case 5:
                {
                    printf("The number you wanna delete:  ");
                    scanf("%d", &bd);
                    bad_data(bd);
                    printf("\nYour data:  ");
                    display();
                    break;
                }
            case 6:
                {
                    printf("The position you wanna delete:  ");
                    scanf("%d", &pos);
                    bad_position(pos);
                    printf("\nYour data:  ");
                    display();
                    break;
                }
            case 7:
                {
                    printf("The number you wanna search:  ");
                    scanf("%d", &t);
                    khoj(t);
                    break;
                }
            case 8:
                {
                    gunbo();
                    break;
                }
            case 9:
                {
                    printf("The sum of the data of the linked list:  %d", jog());
                    break;
                }
            case 10:
                {
                    printf("Position to update:  ");
                    scanf("%d", &pos);
                    printf("New value:  ");
                    scanf("%d", &value);
                    update(pos, value);
                    printf("\nYour data:  ");
                    display();
                    break;
                }
            case 11:
                {
                    reverse_display();
                    break;
                }
            case 12:
                printf("\nAre you sure to exit?  (y/n)\n\n");
                if(getch() == 'y' || getch() == 'Y')
                {
                    printf("\t\tThank You for using this code.\n\n");
                    return;
                }
                else
                    break;
        }
    }
}
