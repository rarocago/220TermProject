//
//  main.m
//  cs220term_project
//  Ramon Aroca
//
//  https://www.tutorialspoint.com/objective_c/objective_c_overview.htm
//

#import <Foundation/Foundation.h>
#import "circleCalculator.h"
#import "player.h"
#import "game.h"

/*
//  Calculator using blocks
//  This simple calculator does basic arithmetic using blocks
//  This program is used to showcase blocks in objective-c
*/

void myBlocks(void) {
    @autoreleasepool {
        while (true) {
            
            // Display possible commands
            NSLog(@"Select an operation from the list below:");
            printf("1. Addition");
            printf("\n%s", "2. Substraction");
            printf("\n%s", "3. Multiplication");
            printf("\n%s", "4. Division");
            printf("\n%s", "5. Quit");
            printf("\n%s", "Input> ");
            
            // Get the user input and cast it into NS objects so NS procedures can be used on them
            char operator[50], num1[50], num2[50];
            fgets(operator, 50, stdin);
            NSString *inputString = [NSString stringWithUTF8String:operator];
            
            // Trim newline character from user input and make it lowercase
            inputString = [inputString stringByTrimmingCharactersInSet:[NSCharacterSet newlineCharacterSet]];
            inputString = [inputString lowercaseString];
            
            // Exit if quit is entered
            if ([inputString isEqualToString:@"5"] || [inputString isEqualToString:@"quit"]) {
                break;
            }
            
            // Get numbers for operation
            printf("Enter first number: ");
            fgets(num1, 50, stdin);
            printf("Enter second number: ");
            fgets(num2, 50, stdin);
            int n1 = atoi(num1), n2 = atoi(num2);
            
            // Definitions of Blocks
            int (^Addition)(int, int) = ^(int x, int y) {
                return x + y;
            };
            
            int(^Substraction)(int, int) = ^(int x, int y) {
                return x - y;
            };
            
            int(^Multiplication)(int, int) = ^(int x, int y) {
                return x * y;
            };
            
            int(^Division)(int, int) = ^(int x, int y) {
                return x / y;
            };
            
            // Compare user inputs to commands and call the blocks
            if ([inputString isEqualToString:@"1"] || [inputString isEqualToString:@"addition"]) {
                NSLog(@"The result is %d", Addition(n1, n2));
            } else if ([inputString isEqualToString:@"2"] || [inputString isEqualToString:@"substraction"]) {
                NSLog(@"The result is %d", Substraction(n1, n2));
            } else if ([inputString isEqualToString:@"3"] || [inputString isEqualToString:@"multiplication"]) {
                NSLog(@"The result is %d", Multiplication(n1, n2));
            } else if ([inputString isEqualToString:@"4"] || [inputString isEqualToString:@"division"]) {
                NSLog(@"The result is %d", Division(n1, n2));
            } else {
                NSLog(@"Invalid command. Try again");
            }
        }
    }
}

/*
//  Circle Calculator using classes
//  This simple program calculates the circumference and area of a circle given the radius
//  circleCalculator class definition is in circleCalculator
//  This program is used to showcase classes and messaging in objective-c
*/

void myClasses(void) {
    @autoreleasepool {
        
        // Create circleCalculator object
        circleCalculator *userCircle = [[circleCalculator alloc] init];
        
        // Control flow of the program
        while (true) {
            NSLog(@"Enter radius of circle you want as a float (e.g 5.0). Enter 0 to exit");
            printf("Input> ");
            char userRadius[50];
            fgets(userRadius, 50, stdin);
            if (atoi(userRadius) == 0) {
                break;
            }
            userCircle.radius = atoi(userRadius);
            
            // This is an example of a message to an object
            double circumference = [userCircle circumference];
            double area = [userCircle area];
            NSLog(@"Circumference: %.2f", circumference);
            NSLog(@"Area: %.2f", area);
        }
    }
}

/*
//  Numeric Conquest
//  In this game your goal is to get a number as close as possible to the target number using the 5
//  available numbers and any of the basic arithmetic operations.
//  player.h contains the class declaration for player
//  game.h contains the class declaration for game
*/

void myGame(void) {
    @autoreleasepool {
        NSLog(@"Welcome to Numeric Conquest! The goal of the game is to get a number as close as possible to the target number using the 5 available numbers and any of the basic arithmetic operations (+, -, *, /)");
        
        // Initialize check to play again
        NSString *continueResponse;
        
        // Run the game
        do {
            Game *game = [[Game alloc] init];
            printf("Enter your username: ");
            char username[100];
            fgets(username, sizeof(username), stdin);
            NSString *trimmedUsername = [NSString stringWithUTF8String:username];
            trimmedUsername = [trimmedUsername stringByTrimmingCharactersInSet:[NSCharacterSet newlineCharacterSet]];
            player *myPlayer = [game playerLogin:trimmedUsername];
            NSLog(@"Welcome, %@! Your current score is %ld.", myPlayer.name, (long)myPlayer.score);
            [game startGame:myPlayer];
            
            // Check if the user wants to continue playing or not
            char continuePlaying[10];
            printf("Do you want to play again? (yes/no): ");
            fgets(continuePlaying, sizeof(continuePlaying), stdin);
            continueResponse = [NSString stringWithUTF8String:continuePlaying];
            continueResponse = [continueResponse stringByTrimmingCharactersInSet:[NSCharacterSet newlineCharacterSet]];

        } while ([continueResponse caseInsensitiveCompare:@"yes"] == NSOrderedSame);
    }
}

// Control the running of all 3 programs
int main(int argc, const char * argv[]) {
    NSLog(@"Select one of the following programs to run: ");
    printf("1. Calculator using blocks");
    printf("\n%s", "2. Circle calculator using classes");
    printf("\n%s", "3. Game :)");
    printf("\n%s", "Input> ");
    char instructions[50];
    fgets(instructions, 50, stdin);
    if (atoi(instructions) == 1) {
        myBlocks();
    } else if (atoi(instructions) == 2) {
        myClasses();
    } else if (atoi(instructions) == 3) {
        myGame();
    } else {
        NSLog(@"Incorrect command entered. Please run the program again");
    }
}
