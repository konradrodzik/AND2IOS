//
//  Created by Blazej Marcinkiewicz on 22.02.2013.
//


#import <Foundation/Foundation.h>
#import "and2ios.h"

@protocol TPViewControllerDelegate;


@interface TPActivityMain : ActivityMain

@property (nonatomic, weak) id<TPViewControllerDelegate> delegate;
@end
