//
//  Created by Blazej Marcinkiewicz on 22.02.2013.
//


#import <Foundation/Foundation.h>

@protocol TPViewControllerDelegate
- (void)switchToView:(UIView *)view;
@end

@interface TPTestViewController : UIViewController <TPViewControllerDelegate>
@end
