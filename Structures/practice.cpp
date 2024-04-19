#include <stdio.h>
#include <string.h>

// Define the structure
struct MyStruct {
    int intValue;
    float floatValue;
    char charArray[50]; // Change the size according to your requirement
};

int main() {
    // Declare a structure variable and use designated initializers
    struct MyStruct data = {
        .intValue = 42,
        .floatValue = 3.14
    };

    // Initialize the character array separately
    strcpy(data.charArray, "Hello, World!");

    // Display the values
    printf("Integer Value: %d\n", data.intValue);
    printf("Float Value: %.2f\n", data.floatValue);
    printf("String Value: %s\n", data.charArray);

    struct MyStruct* ptr=&data;
    printf("Integer Value: %d\n", ptr->intValue);
    printf("Float Value: %.2f\n", ptr->floatValue);
    printf("String Value: %s\n", ptr->charArray);

    return 0;
}

