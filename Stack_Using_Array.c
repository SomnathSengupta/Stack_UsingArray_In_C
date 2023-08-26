#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int* arr;
};
int isEmpty(struct Stack* ptr) // To check if the stack is empty or not.
{
    if (ptr -> top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct Stack* ptr) // To check if the stack is Full or not.
{
    if (ptr -> top == ptr -> size - 1){
        return 1;
    }
    return 0;
}
void push(struct Stack* ptr, int value) // This Function will push the value.
{
    if (isFull(ptr)) // Checking Stack Overflow Condition.
    {
        printf("Stack Overflow Ocuuring.\n");
        return;
    }
    printf("%d is pushing inside the stack...\n", value);
    ptr -> top++;
    ptr -> arr[ptr -> top] = value;
}
void pop(struct Stack* ptr)
{
    if (isEmpty(ptr)) // Checking Stack Underflow Condition.
    {
        printf("Stack Underflow Occuring.\n");
        return;
    }
    int val = ptr -> arr[ptr -> top];
    ptr -> top--;
    printf("%d Popped Out From The Stack.\n", val);
}
void display(struct Stack* ptr) // This Function will display the Stack Elements.
{
    if (isEmpty(ptr)){
        printf("Stack is Empty\n");
    }
    for(int i = 0; i <= ptr -> top; i++){
        printf("Element: %d\n", ptr -> arr[i]);
    }
}
int peek(struct Stack* ptr, int position) // Peeking the top elements of specified postion from top.
{
    if ((ptr -> top - position + 1) < 0)
    {
        printf("You have enterd invalid position.\n");
        return -1;
    }
    return ptr -> arr[ptr -> top - position + 1];
}
int main()
{
    struct Stack* sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp -> size = 6;
    sp -> top = -1;
    sp -> arr = (int*)malloc(sp -> size * sizeof(int));
    // Doing The Operations.
    pop(sp);
    push(sp, 2);
    push(sp, 3);
    push(sp, 5);
    push(sp, 10);
    push(sp, 23);
    push(sp, 6);
    push(sp, 1);
    pop(sp);
    pop(sp);
    display(sp);
    printf("%d",peek(sp, 2));
    return 0;
}