#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    /*
    String is immutable, so if we were to modify this, we would need to create another instance;
    */
    const char *chars;
    size_t length;
} String;

void stringSize(String *string) {
    string->length = strlen(string->chars);
}

String newString(char *initialStringValue) {
    String newString = {initialStringValue};
    stringSize(&newString);
    return newString;
}

String invertString(String *string) {
    char *invertedString = (char*)malloc(string->length + 1);
    for(int i = 0; i < string->length; i++) {
        invertedString[i] = string->chars[string->length - i - 1];
    }
    invertedString[string->length] = '\0';
    String otherString = newString(invertedString);
    return otherString;
}

String concatString(String *first_string, String *other_string) {
    char *concatened_string = (char*)malloc(first_string->length + other_string->length + 1);
    for(int i = 0; i < first_string->length; i++) {
        concatened_string[i] = first_string->chars[i];
    }
    for(int i = 0; i < other_string->length; i++) {
        concatened_string[first_string->length + i] = other_string->chars[i];
    }
    concatened_string[first_string->length + other_string->length] = '\0';
    String concatenedString = newString(concatened_string);
    return concatenedString;
}

bool containString(String *main_string, String *substring) {
    for(int i = 0; i < main_string->length; i++) {
        int j;
        for (j = 0; j < substring->length; j++) {
            if (main_string->chars[i + j] == substring->chars[j]) {
                break;
            }
        }
        if (j == substring->length) {
            return true;
        }
    }
    return false;
}

String subString(String *main_string, int start_index) {
    char *substr = (char*)malloc(main_string->length - start_index + 1);
    int charCount = 0;
    for(int i = 0; i < main_string->length; i++ ) {
        if (i >= start_index) {
            substr[charCount] = main_string->chars[i];
            charCount++;
        }
    }
    substr[main_string->length - start_index] = '\0';
    String subst = newString(substr);
    return subst;
}

String subStringTo(String *main_string, int start_index, int end_index) {
    if(end_index > main_string->length) {
        end_index = main_string->length;
    }
    char *substr = (char*)malloc(end_index - start_index + 1);
    int charCount = 0;
    for(int i = start_index; i < end_index; i++ ) {
        if (i >= main_string->length) {
            break;
        }
        substr[charCount] = main_string->chars[i];
        charCount++;
    }
    substr[charCount] = '\0';
    String subst = newString(substr);
    return subst;
}


int main() {
    String myString = newString("Kamuridesu");    
    String substring = subString(&myString, 0);
    printf("%s\n", substring.chars);
    String other_substring = subStringTo(&myString, 0, 7);
    printf("%s\n", other_substring.chars);

    // bool contains = containString(&myString, &substring);
    // printf("%d\n", contains);
    // printf("%s\n", myString.chars);
    // printf("%d\n", myString.length);
    // String inverted = invertString(&myString);
    // printf("%s\n", inverted.chars);
    String otherString = newString(" yay");
    // String concatened = concatString(&myString, &otherString);
    // printf("%s\n", concatened.chars);
    return 0;
}