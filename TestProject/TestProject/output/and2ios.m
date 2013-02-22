#include "and2ios.h"

#import "and2ios.h"

@interface ActivityMain()
@property(nonatomic, strong) UIView *var_01907a00;
@property(nonatomic, strong) UIImageView *nameCollisionImage;
@property(nonatomic, strong) UILabel *nameCollisionTitle;
@property(nonatomic, strong) UIButton *createNewView;
@property(nonatomic, strong) UIView *var_01908b20;
@property(nonatomic, strong) UILabel *textInRelative;
@end

@implementation ActivityMain {
}

@synthesize var_01907a00;
@synthesize nameCollisionImage;
@synthesize nameCollisionTitle;
@synthesize createNewView;
@synthesize var_01908b20;
@synthesize textInRelative;

-(id) initWithFrame:(CGRect)rect {
	if(self = [super initWithFrame:rect]) {
		self.backgroundColor = [UIColor whiteColor];
		var_01907a00= [[UIView alloc] initWithFrame:CGRectZero];
		[self addSubview:var_01907a00];
		var_01907a00.userInteractionEnabled = YES;
		[var_01907a00 setFrame:CGRectMake(0, 0, 0, 0)];
		
		nameCollisionImage= [[UIImageView alloc] initWithFrame:CGRectZero];
		[var_01907a00 addSubview:nameCollisionImage];
		[nameCollisionImage setFrame:CGRectMake(15, 15, 0, 0)];
		[nameCollisionImage setImage:[UIImage imageNamed:@"name_collision_image"]];
		[var_01907a00 addSubview:nameCollisionImage];
		
		nameCollisionTitle = [[UILabel alloc] initWithFrame:CGRectZero];
		[nameCollisionTitle setTextColor:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
		[nameCollisionTitle setBackgroundColor:[UIColor colorWithRed:1 green:0 blue:0 alpha:0]];
		[nameCollisionTitle setText:@"Name Collision"];
		[var_01907a00 addSubview:nameCollisionTitle];
		[nameCollisionTitle setFrame:CGRectMake(15, 100, 0, 0)];
		
		createNewView = [UIButton buttonWithType:UIButtonTypeRoundedRect];
		createNewView.frame = CGRectMake(15, 150, 0, 0);
		[createNewView setTitle:@"Create new View" forState:UIControlStateNormal];
		[createNewView addTarget:self action:@selector(createNewViewMethod:) forControlEvents:UIControlEventTouchUpInside];
		[var_01907a00 addSubview:createNewView];
		
		var_01908b20= [[UIView alloc] initWithFrame:CGRectZero];
		[var_01907a00 addSubview:var_01908b20];
		var_01908b20.userInteractionEnabled = YES;
		[var_01908b20 setFrame:CGRectMake(15, 300, 100, 100)];
		
		textInRelative = [[UILabel alloc] initWithFrame:CGRectZero];
		[textInRelative setTextColor:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
		[textInRelative setBackgroundColor:[UIColor colorWithRed:1 green:0 blue:0 alpha:1]];
		[textInRelative setText:@"Text inside Relative layout"];
		[var_01908b20 addSubview:textInRelative];
		[textInRelative setFrame:CGRectMake(10, 10, 0, 0)];
		
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
	var_01907a00.frame = self.bounds;
	[nameCollisionImage sizeToFit];
	[nameCollisionImage setFrame:CGRectMake(15, 15, nameCollisionImage.frame.size.width, nameCollisionImage.frame.size.height)];
	[nameCollisionTitle sizeToFit];
	[nameCollisionTitle setFrame:CGRectMake(15, 100, nameCollisionTitle.frame.size.width, nameCollisionTitle.frame.size.height)];
	[createNewView sizeToFit];
	[createNewView setFrame:CGRectMake(15, 150, createNewView.frame.size.width, createNewView.frame.size.height)];
	[var_01908b20 sizeToFit];
	[var_01908b20 setFrame:CGRectMake(15, 300, var_01908b20.frame.size.width, var_01908b20.frame.size.height)];
	[textInRelative sizeToFit];
	[textInRelative setFrame:CGRectMake(10, 10, textInRelative.frame.size.width, textInRelative.frame.size.height)];
}

-(void) createNewViewMethod:(id)sender {
	NSLog(@"createNewViewMethod clicked");
}


@end

@interface ActivitySub()
@property(nonatomic, strong) UIView *var_01906310;
@property(nonatomic, strong) UIImageView *nameCollisionImage;
@property(nonatomic, strong) UILabel *nameCollisionTitle;
@property(nonatomic, strong) UIButton *createNewView;
@end

@implementation ActivitySub {
}

@synthesize var_01906310;
@synthesize nameCollisionImage;
@synthesize nameCollisionTitle;
@synthesize createNewView;

-(id) initWithFrame:(CGRect)rect {
	if(self = [super initWithFrame:rect]) {
		self.backgroundColor = [UIColor whiteColor];
		var_01906310= [[UIView alloc] initWithFrame:CGRectZero];
		[self addSubview:var_01906310];
		var_01906310.userInteractionEnabled = YES;
		[var_01906310 setFrame:CGRectMake(0, 0, 0, 0)];
		
		nameCollisionImage= [[UIImageView alloc] initWithFrame:CGRectZero];
		[var_01906310 addSubview:nameCollisionImage];
		[nameCollisionImage setFrame:CGRectMake(15, 15, 0, 0)];
		[nameCollisionImage setImage:[UIImage imageNamed:@"ic_launcher"]];
		[var_01906310 addSubview:nameCollisionImage];
		
		nameCollisionTitle = [[UILabel alloc] initWithFrame:CGRectZero];
		[nameCollisionTitle setTextColor:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
		[nameCollisionTitle setBackgroundColor:[UIColor colorWithRed:1 green:0 blue:0 alpha:1]];
		[nameCollisionTitle setText:@"Second Screen!!!1111oneoneeleven!!"];
		[var_01906310 addSubview:nameCollisionTitle];
		[nameCollisionTitle setFrame:CGRectMake(15, 100, 0, 0)];
		
		createNewView = [UIButton buttonWithType:UIButtonTypeRoundedRect];
		createNewView.frame = CGRectMake(15, 150, 0, 0);
		[createNewView setTitle:@"Create new View" forState:UIControlStateNormal];
		[createNewView addTarget:self action:@selector(createNewViewMethod2:) forControlEvents:UIControlEventTouchUpInside];
		[var_01906310 addSubview:createNewView];
		
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
	var_01906310.frame = self.bounds;
	[nameCollisionImage sizeToFit];
	[nameCollisionImage setFrame:CGRectMake(15, 15, nameCollisionImage.frame.size.width, nameCollisionImage.frame.size.height)];
	[nameCollisionTitle sizeToFit];
	[nameCollisionTitle setFrame:CGRectMake(15, 100, nameCollisionTitle.frame.size.width, nameCollisionTitle.frame.size.height)];
	[createNewView sizeToFit];
	[createNewView setFrame:CGRectMake(15, 150, createNewView.frame.size.width, createNewView.frame.size.height)];
}

-(void) createNewViewMethod2:(id)sender {
	NSLog(@"createNewViewMethod2 clicked");
}


@end

