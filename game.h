//
//  game.h
//  cs220term_project
//  Ramon Aroca
//
//  https://www.tutorialspoint.com/objective_c/objective_c_overview.htm
//  https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Introduction/Introduction.html#//apple_ref/doc/uid/TP40011210

#import "player.h"

#ifndef game_h
#define game_h

// Class declaration
@interface Game : NSObject

// Property declaration
@property (strong, nonatomic) NSMutableArray<player *> *players;
@property (assign, nonatomic) NSInteger targetNumber;
@property (strong, nonatomic) NSMutableArray<NSNumber *> *validNumbers;

// Method declaration
- (player *)playerLogin:(NSString *)username;
- (void)startGame:(player *)player;
- (NSNumber *)playRound:(player *)player;
- (void)calculateScore:(player *)player withGuess:(NSInteger)guess;

@end

// Class implementation
@implementation Game

// Initialization of game
- (instancetype)init {
    self = [super init];
    if (self) {
        _validNumbers = [NSMutableArray new];
        _players = [NSMutableArray new];
        for (int i = 0; i < 5; i++) {
            
            // Select random number in range [1-100] and add it to list of valid numbers
            [_validNumbers addObject:@(arc4random_uniform(99) + 1)];
        }
        
        // Select random number in range [1-1000] as target
        _targetNumber = arc4random_uniform(999) + 1;
    }
    return self;
}

// playerLogin method checks if a user already exists, creates a new one if it doesn't
- (player *)playerLogin:(NSString *)username {
    for (player *i_player in self.players) {
            if ([i_player.name isEqualToString:username]) {
                return i_player;
            }
        }
        // If player not found, create a new one
        player *newPlayer = [[player alloc] initWithName:username];
        [self.players addObject:newPlayer];
        return newPlayer;
}

// startGame method controls the running of the game
- (void)startGame:(player *)player {
    NSNumber *guess = 0;
    NSLog(@"Target number is: %ld", (long)self.targetNumber);
    for (int round = 1; round <= 4; round ++) {
        NSLog(@"Round %d out of 4", round);
        guess = [self playRound:player];
    }
    [self calculateScore:player withGuess:[guess longValue]];
}

// playRound method controls the running of a round
- (NSNumber *)playRound:(player *)player {
    NSInteger n1 = 0, n2 = 0, result = 0;
    NSString *myOperator;
    char num1[50], num2[50], arithOperator[50];

    NSLog(@"Available numbers: %@", self.validNumbers);
    while (YES) {
        printf("Enter your first number: ");
        fgets(num1, 50, stdin);
        n1 = atoi(num1);

        printf("Enter the operator (+, -, *, /): ");
        fgets(arithOperator, 50, stdin);
        myOperator = [NSString stringWithUTF8String:arithOperator];
        myOperator = [myOperator stringByTrimmingCharactersInSet:[NSCharacterSet newlineCharacterSet]];

        printf("Enter your second number: ");
        fgets(num2, 50, stdin);
        n2 = atoi(num2);

        // Check if numbers are valid and contained in the list
        if (![self.validNumbers containsObject:@(n1)] || ![self.validNumbers containsObject:@(n2)]) {
            NSLog(@"Invalid number, try again");
            continue;  // Forces the loop to restart
        }
        // Validate operator
        if ([myOperator isEqualToString:@"+"] || [myOperator isEqualToString:@"-"] ||
            [myOperator isEqualToString:@"*"] || [myOperator isEqualToString:@"/"]) {
            if ([myOperator isEqualToString:@"/"] && n2 == 0) {
                NSLog(@"Division by zero is not allowed.");
                continue;  // Forces the loop to restart
            }
            break;  // Valid input; exit the loop
        } else {
            NSLog(@"Invalid operator. Please enter a valid arithmetic operator.");
        }
    }
    // Perform the operation
    if ([myOperator isEqualToString:@"+"]) {
        result = n1 + n2;
    } else if ([myOperator isEqualToString:@"-"]) {
        result = n1 - n2;
    } else if ([myOperator isEqualToString:@"*"]) {
        result = n1 * n2;
    } else if ([myOperator isEqualToString:@"/"]) {
        result = n1 / n2;
    }

    if (result) {
        [self.validNumbers addObject:@(result)];  // Adding result to valid numbers
        NSLog(@"Result added to valid numbers: %@", @(result));
    }

    return @(result);
}

// calculateScore method calculates the score the user got out of 1000.
- (void)calculateScore:(player *)player withGuess:(NSInteger)guess {
    NSInteger Score = 1000 - labs(guess - self.targetNumber);
    player.score += Score;
    NSLog(@"%@ scored %ld points out of a possible 1000 this round. Total score is %ld", player.name, Score, player.score);
}

@end

#endif /* game_h */
