#include "and2ios.h"

#import "and2ios.h"

@interface ActivityMain()
@property(nonatomic, strong) UIView *var_00614030;
@property(nonatomic, strong) UIImageView *nameCollisionImage;
@property(nonatomic, strong) UILabel *nameCollisionTitle;
@property(nonatomic, strong) UIButton *createNewView;
@property(nonatomic, strong) UIView *var_01b08320;
@property(nonatomic, strong) UILabel *textInRelative;
@end

@implementation ActivityMain {
}

@synthesize var_00614030;
@synthesize nameCollisionImage;
@synthesize nameCollisionTitle;
@synthesize createNewView;
@synthesize var_01b08320;
@synthesize textInRelative;

-(id) initWithFrame:(CGRect)rect {
	if(self = [super initWithFrame:rect]) {
		self.backgroundColor = [UIColor whiteColor];
		var_00614030= [[UIView alloc] initWithFrame:CGRectZero];
		[self addSubview:var_00614030];
		var_00614030.userInteractionEnabled = YES;
		[var_00614030 setFrame:CGRectMake(0, 0, 0, 0)];
		
		nameCollisionImage= [[UIImageView alloc] initWithFrame:CGRectZero];
		[var_00614030 addSubview:nameCollisionImage];
		[nameCollisionImage setFrame:CGRectMake(15, 15, 0, 0)];
		[nameCollisionImage setImage:[UIImage imageNamed:@"name_collision_image"]];
		[var_00614030 addSubview:nameCollisionImage];
		
		nameCollisionTitle = [[UILabel alloc] initWithFrame:CGRectZero];
		[nameCollisionTitle setTextColor:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
		[nameCollisionTitle setBackgroundColor:[UIColor colorWithRed:1 green:0 blue:0 alpha:1]];
		[nameCollisionTitle setText:@"Name Collision"];
		[var_00614030 addSubview:nameCollisionTitle];
		[nameCollisionTitle setFrame:CGRectMake(15, 100, 0, 0)];
		
		createNewView = [UIButton buttonWithType:UIButtonTypeRoundedRect];
		createNewView.frame = CGRectMake(15, 150, 0, 0);
		[createNewView setTitle:@"Create new View" forState:UIControlStateNormal];
		[createNewView addTarget:self action:@selector(createNewViewMethod:) forControlEvents:UIControlEventTouchUpInside];
		[var_00614030 addSubview:createNewView];
		
		var_01b08320= [[UIView alloc] initWithFrame:CGRectZero];
		[var_00614030 addSubview:var_01b08320];
		var_01b08320.userInteractionEnabled = YES;
		[var_01b08320 setFrame:CGRectMake(15, 300, 100, 100)];
		
		textInRelative = [[UILabel alloc] initWithFrame:CGRectZero];
		[textInRelative setTextColor:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
		[textInRelative setBackgroundColor:[UIColor colorWithRed:1 green:0 blue:0 alpha:1]];
		[textInRelative setText:@"Text inside Relative layout"];
		[var_01b08320 addSubview:textInRelative];
		[textInRelative setFrame:CGRectMake(10, 10, 0, 0)];
		
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
	[var_00614030 sizeToFit];
	[var_00614030 setFrame:CGRectMake(0, 0, var_00614030.frame.size.width, var_00614030.frame.size.height)];
	[nameCollisionImage sizeToFit];
	[nameCollisionImage setFrame:CGRectMake(15, 15, nameCollisionImage.frame.size.width, nameCollisionImage.frame.size.height)];
	[nameCollisionTitle sizeToFit];
	[nameCollisionTitle setFrame:CGRectMake(15, 100, nameCollisionTitle.frame.size.width, nameCollisionTitle.frame.size.height)];
	[createNewView sizeToFit];
	[createNewView setFrame:CGRectMake(15, 150, createNewView.frame.size.width, createNewView.frame.size.height)];
	[var_01b08320 setFrame:CGRectMake(15, 300, var_01b08320.frame.size.width, var_01b08320.frame.size.height)];
	[textInRelative sizeToFit];
	[textInRelative setFrame:CGRectMake(10, 10, textInRelative.frame.size.width, textInRelative.frame.size.height)];
}

-(void) createNewViewMethod:(id)sender {
	NSLog(@"createNewViewMethod clicked");
}


@end

@interface ActivitySub()
@property(nonatomic, strong) UIView *var_01b07090;
@property(nonatomic, strong) UIImageView *nameCollisionImage;
@property(nonatomic, strong) UILabel *nameCollisionTitle;
@property(nonatomic, strong) UIButton *createNewView;
@end

@implementation ActivitySub {
}

@synthesize var_01b07090;
@synthesize nameCollisionImage;
@synthesize nameCollisionTitle;
@synthesize createNewView;

-(id) initWithFrame:(CGRect)rect {
	if(self = [super initWithFrame:rect]) {
		self.backgroundColor = [UIColor whiteColor];
		var_01b07090= [[UIView alloc] initWithFrame:CGRectZero];
		[self addSubview:var_01b07090];
		var_01b07090.userInteractionEnabled = YES;
		[var_01b07090 setFrame:CGRectMake(0, 0, 0, 0)];
		
		nameCollisionImage= [[UIImageView alloc] initWithFrame:CGRectZero];
		[var_01b07090 addSubview:nameCollisionImage];
		[nameCollisionImage setFrame:CGRectMake(15, 15, 0, 0)];
		[nameCollisionImage setImage:[UIImage imageNamed:@"ic_launcher"]];
		[var_01b07090 addSubview:nameCollisionImage];
		
		nameCollisionTitle = [[UILabel alloc] initWithFrame:CGRectZero];
		[nameCollisionTitle setTextColor:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
		[nameCollisionTitle setBackgroundColor:[UIColor colorWithRed:1 green:0 blue:0 alpha:1]];
		[nameCollisionTitle setText:@"Second Screen!!!1111oneoneeleven!!"];
		[var_01b07090 addSubview:nameCollisionTitle];
		[nameCollisionTitle setFrame:CGRectMake(15, 100, 0, 0)];
		
		createNewView = [UIButton buttonWithType:UIButtonTypeRoundedRect];
		createNewView.frame = CGRectMake(15, 150, 0, 0);
		[createNewView setTitle:@"Create new View" forState:UIControlStateNormal];
		[createNewView addTarget:self action:@selector(createNewViewMethod2:) forControlEvents:UIControlEventTouchUpInside];
		[var_01b07090 addSubview:createNewView];
		
    }
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
	[var_01b07090 sizeToFit];
	[var_01b07090 setFrame:CGRectMake(0, 0, var_01b07090.frame.size.width, var_01b07090.frame.size.height)];
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

