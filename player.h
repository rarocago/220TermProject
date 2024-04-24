//
//  player.h
//  cs220term_project
//  Ramon Aroca
//
//  https://www.tutorialspoint.com/objective_c/objective_c_overview.htm
//  https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Introduction/Introduction.html#//apple_ref/doc/uid/TP40011210

#ifndef player_h
#define player_h

// Class declaration
@interface player : NSObject

// Property declaration
@property (strong, nonatomic) NSString *name;
@property (assign, nonatomic) NSInteger score;

// Method declaration
- (instancetype)initWithName:(NSString *)name;

@end

// Class implementation
@implementation player

// Initializer
- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        _name = name;
        _score = 0;
    }
    return self;
}

@end

#endif /* player_h */
