//
//  main.c
//  seven_segment_display
//
//  Created by Nicholas Morris on 18/12/18.
//  Copyright © 2018 Nicholas Morris. All rights reserved.
//

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_DIGITS 10
#define SEGMENTS 7

//Digit array for each 4x4 digit multiplied by max number of digits
char digits[4][MAX_DIGITS*4];


void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

//1 indicates segments is on, 0 indicates nothing should be there
int segments[10][SEGMENTS] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1} //9
};
//Map each part of the segment for the character
int segment_map[7][3] = {
    //row, col, sign
    {0, 1, '_'},
    {1, 2, '|'},
    {2, 2, '|'},
    {2, 1, '_'},
    {2, 0, '|'},
    {1, 0, '|'},
    {1, 1, '_'}
};


int main(int argc, const char * argv[]) {
   
    
    
    
    char ch;
    int position = 0;
    //Clear array
    clear_digits_array();
    //Prompt for number
    printf("Enter a number: ");
    //Keep getting characters from user until new line
    while((ch = getchar()) != '\n'){
        //If the character is a digit process it
        if(isdigit(ch)){
            process_digit(ch - '0', position);
            //Move to the next digit position
            position += 4;
        }
    }
    //Print the digit
    print_digits_array();
    
    return 0;
    
    
}
/*******************************************************************
 *                                                                 *
 * Clear_digits_array does not return a value                      *
 * It iterates through the digit array and makes every entry ' '   *
 *                                                                 *
 *******************************************************************/

void clear_digits_array(void){
    for(int i = 0; i < 4; i++){
        for(int j= 0; j<MAX_DIGITS*4; j++){
            digits[i][j] = ' ';
        }
    }
    
}
/**********************************************************************
 *                                                                    *
 *                         process_digit                              *
 * Input: Integer digit from user input and integer position in array *
 * Iterates through all possible segments and checks if the digit     *
 * input has a symbol there. If it does it checks what the symbol     *
 * should be from segment_map, and checks it's position by            *
 * finding the row and column it belongs to. This is added to the     *
 * digit array.                                                       *
 *                                                                    *
 **********************************************************************/
void process_digit(int digit, int position){
    for(int i = 0; i<SEGMENTS; i++){
        if(segments[digit][i]){
            //Check the row of symbol
            int row = segment_map[i][0];
            //Check column of symbol
            int column = segment_map[i][1] + position;
            digits[row][column] = (char)segment_map[i][2];
        }
    }
    
}
/*******************************************************************
 *                                                                 *
 * Prints the digit array by iterating through each row and column *
 *                                                                 *
 *******************************************************************/
void print_digits_array(void){
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j<MAX_DIGITS*4; j++){
            putchar(digits[i][j]);
            
        }
        printf("\n");
    }
    
}








