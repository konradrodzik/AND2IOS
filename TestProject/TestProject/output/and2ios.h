@interface ActivityMain : UIView {
	UIImageView *nameCollisionImage;
	UILabel *nameCollisionTitle;
	UIButton *createNewView;
	UILabel *textInRelative;
}

@property(nonatomic, readonly) UIImageView *nameCollisionImage;
@property(nonatomic, readonly) UILabel *nameCollisionTitle;
@property(nonatomic, readonly) UIButton *createNewView;
@property(nonatomic, readonly) UILabel *textInRelative;

-(id) initWithFrame:(CGRect)rect;
-(void) createNewViewMethod:(id)sender;
@end

@interface ActivitySub : UIView {
	UIImageView *nameCollisionImage;
	UILabel *nameCollisionTitle;
	UIButton *createNewView;
}

@property(nonatomic, readonly) UIImageView *nameCollisionImage;
@property(nonatomic, readonly) UILabel *nameCollisionTitle;
@property(nonatomic, readonly) UIButton *createNewView;

-(id) initWithFrame:(CGRect)rect;
-(void) createNewViewMethod2:(id)sender;
@end

