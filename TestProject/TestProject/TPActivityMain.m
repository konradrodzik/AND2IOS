//
//  Created by Blazej Marcinkiewicz on 22.02.2013.
//


#import "TPActivityMain.h"
#import "TPTestViewController.h"
#import "TPActivitySub.h"


@implementation TPActivityMain {

}

-(void) createNewViewMethod:(id)sender {
    [super createNewViewMethod:sender];
    TPActivitySub *sub = [[TPActivitySub alloc] initWithFrame:CGRectZero];
    [self.delegate switchToView:sub];
}


@end
