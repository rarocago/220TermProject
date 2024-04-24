//
//  circleCalculator.h
//  cs220term_project
//  Ramon Aroca
//
//  https://www.tutorialspoint.com/objective_c/objective_c_overview.htm
//  https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Introduction/Introduction.html#//apple_ref/doc/uid/TP40011210

#ifndef circleCalculator_h
#define circleCalculator_h

// Class declaration
@interface circleCalculator : NSObject

// Property declaration
@property (nonatomic) double radius;

// Method declaration
- (double)circumference;
-(double)area;

@end

// Class implementation
@implementation circleCalculator
@synthesize radius;

// Circumference method
// Returns the circumference of the circle
- (double)circumference {
    return 2 * M_PI * self.radius;
}

// Area method
// Returns the area of the circle
-(double)area {
    return M_PI * (self.radius * self.radius);
}

@end

#endif /* circleCalculator_h */
