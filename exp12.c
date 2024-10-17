#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phoneNumber[15];
};

int binarySearch(struct Contact phonebook[], int size, char targetName[]) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        int result = strcmp(targetName, phonebook[mid].name);

        if (result == 0) {
            return mid;
        }
        if (result > 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    struct Contact phonebook[] = {
        {"Alice", "123-456-7890"},
        {"Bob", "234-567-8901"},
        {"Charlie", "345-678-9012"},
        {"David", "456-789-0123"},
        {"Eve", "567-890-1234"}
    };
    int size = sizeof(phonebook) / sizeof(phonebook[0]);
    char targetName[50];
    printf("Enter the name of the contact you are looking for: ");
    scanf("%s", targetName);
    
    int index = binarySearch(phonebook, size, targetName);
    
    if (index != -1) {
        printf("Contact found: %s, Phone Number: %s\n", phonebook[index].name, phonebook[index].phoneNumber);
    } else {
        printf("Contact not found.\n");
    }
    return 0;
}