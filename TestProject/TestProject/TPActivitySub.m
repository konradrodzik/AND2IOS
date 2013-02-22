//
//  Created by Blazej Marcinkiewicz on 22.02.2013.
//


#import "TPActivitySub.h"
#import "TPTestViewController.h"
#import "TPActivityMain.h"


@implementation TPActivitySub {

}

- (void)createNewViewMethod2:(id)sender {
    [super createNewViewMethod2:sender];
    TPActivityMain *view = [[TPActivityMain alloc] initWithFrame:CGRectZero];
    [self.delegate switchToView:view];
}

@end
