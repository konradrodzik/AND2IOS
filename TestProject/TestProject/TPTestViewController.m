//
//  Created by Blazej Marcinkiewicz on 22.02.2013.
//


#import "TPTestViewController.h"
#import "and2ios.h"
#import "TPActivityMain.h"
#import "TPActivitySub.h"

@interface TPTestViewController()

@end

@implementation TPTestViewController {

}


- (void)loadView {

    TPActivityMain *activityMain = [[TPActivityMain alloc] initWithFrame:CGRectZero];
    activityMain.delegate = self;
    self.view = activityMain;
    
//    self.view.backgroundColor = [UIColor redColor];

}

- (void)switchToView:(UIView *)view {
    if ([view isKindOfClass:[TPActivityMain class]]) {
        ((TPActivityMain *)view).delegate = self;
    } else if ([view isKindOfClass:[TPActivitySub class]]) {
        ((TPActivitySub *)view).delegate = self;
    }
    self.view = view;
}

@end
